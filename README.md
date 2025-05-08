# 🧠 Computer Architecture Assignments

This repository contains two computer architecture assignments focused on advanced processor simulation and multimedia SIMD emulation:

1. **Tomasulo Algorithm Simulation using DLXview**
2. **Emulation of MIPS MSA (Multimedia SIMD Architecture) using Docker, QEMU, and Inline Assembly**

---

## 🔧 Assignment 1: Tomasulo Algorithm with DLXview

This assignment explores **dynamic instruction scheduling** using the Tomasulo algorithm on a DLX-like processor simulator.

### Part 1: Resource Optimization

- The goal is to determine the **minimum number of reservation stations and buffers** needed so that the instruction pipeline never stalls.
- A small looped program is analyzed using the **DLXview** tool.
- Students must configure DLXview with specific latencies and simulate execution to identify the optimal configuration.

### Part 2: Neural Network Implementation

- A small **feedforward neural network** with two perceptron neurons and five inputs is implemented in **DLX assembly**.
- The network includes weighted sums, bias addition, and threshold activation.
- The final implementation is submitted as two DLX files.

---

## 🖥️ Assignment 2: MIPS MSA Emulation with QEMU & Docker

This assignment focuses on **emulating MIPS64 SIMD instructions** using inline assembly and the MIPS MSA instruction set.

### Environment Setup

- Students use **Docker** to run a Linux environment on Windows.
- The MIPS64 cross-compiler and **QEMU** emulator are installed inside the Docker container.

### Task Overview

- Two C programs are provided (`ex13.c` and `ex14.c`) that operate on image and vector data.
- Each program is implemented in:
  - A **scalar** version
  - A **SIMD version using MIPS MSA instructions**

### Objectives

- Learn to use **inline assembly** with the MIPS MSA instruction set.
- Understand how SIMD instructions can replace scalar loops.
- Validate correctness by comparing outputs of scalar and SIMD versions.
- Complete the missing SIMD implementation in one of the exercises.

### Deliverables

- Completed source files for all program versions.
- Execution output files for validation.
- A brief report (PDF) with screenshots and a summary of findings.

---

## 📁 Repository Structure

- `Tomasulo/` – DLXview configuration files and assembly code
- `MIPS64-MSA/` – C programs, compiled binaries, and output logs
- `report.pdf` – Summary report with screenshots and explanations

---

## 👨‍💻 Skills

- Dynamic scheduling and reservation station analysis  
- Processor simulation with DLXview  
- SIMD programming and instruction-level parallelism  
- Docker-based cross-compilation  
- Inline assembly with MIPS64 and QEMU emulation

