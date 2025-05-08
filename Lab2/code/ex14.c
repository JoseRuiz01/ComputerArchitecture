#include <stdio.h>
#include <msa.h>

__attribute__((aligned(16))) double a[256], b[256], c[256], d[256];
__attribute__((aligned(16))) double three[] = {3.0,3.0};
__attribute__((aligned(16))) double five[] = {5.0,5.0};

int main()
{

int i,j;

// fake test image (red channel)
for (i=0; i<256; i++) {
    b[i] = c[i]= (double)(i)/10;
    d[i] = 0.0;
}

c[5] = 0.0;

//#define SIMD_VERSION

#ifdef MSA_VERSION
__asm volatile(
"		LD.D	$w7, 0(%[Rthree])	\n"
"		LD.D	$w8, 0(%[Rfive])	\n"
// YOUR CODE
"		li	$1, 256			\n" // i = 256 
"		li      $6, 0x10        	\n" // increment the address of the vectors by 16
"		move	$2, %[Ra]		\n" // &a[0]
"		move	$3, %[Rb]		\n" // &b[0]
"		move	$4, %[Rc]		\n" // &c[0]
"		move	$5, %[Rd]		\n" // &d[0]
"loop:						\n"
"		LD.D	$w0, 0($3)		\n" // load b[i] and b[i+1] into $w0
"		LD.D	$w1, 0($4)		\n" // load c[i] and c[i+1] into $w1
"		FADD.D	$w2, $w0, $w1		\n" // a[i] = b[i] + c[i] and a[i+1] = b[i+1] + c[i+1]
"		ST.D	$w2, 0($2)		\n" // store a[i] and a[i+1]
"		FCEQ.D	$w3, $w2, $w0		\n" // compare a[i] == b[i] and a[i+1] == b[i+1]
"		FMUL.D	$w4, $w2, $w7		\n" // a[i]*3 and a[i+1]*3
"		AND.V	$w5, $w4, $w3		\n" // d[i] = a[i]*3 for elements where a[i] == b[i]
"		ST.D	$w5, 0($5)		\n" // store d[i] and d[i+1]
"		FSUB.D	$w6, $w2, $w8		\n" // a[i] - 5 and a[i+1] - 5
"		ST.D	$w6, 0($3)		\n" // store b[i] and b[i+1]
"		dsubu   $1,$1,2       		\n" // decrement i - 2 as we are loading i and i+1
"		dadd    $2,$2,$6       		\n" // increment address &a
"		dadd    $3,$3,$6       		\n" // increment address &b
"		dadd    $4,$4,$6       		\n" // increment address &c
"		dadd    $5,$5,$6       		\n" // increment address &d
"		bgtz	$1, loop		\n" // continue loop if i > 0
"		nop                 		\n"
:

// Input and output registers
: [Ra] "r" (a),
  [Rb] "r" (b),
  [Rc] "r" (c),
  [Rd] "r" (d),
  [Rthree] "r" (three),
  [Rfive] "r" (five)

// Clobbered registers
: "memory", "$1", "$2", "$3", "$4", "$5", "$6"
);
#else
for (i=0; i<256; i++) {
    a[i]=b[i]+c[i];
    if (a[i]==b[i])
       d[i]=a[i]*3;
    b[i]=a[i]-5;
}
#endif


// check output
for (i=0; i<256;i++) {
    printf(" a:%lf b:%lf c:%lf d:%lf\n",a[i],b[i],c[i],d[i]);
}

return 0;
}
