# Parallel Sorting Algorithms using OpenMP

You can either run the `sort.cpp` file in your terminal or use the provided Colab notebook to test the functionality.  
This project implements and compares the performance of **Parallel and Sequential Bubble Sort** and **Merge Sort** using OpenMP for parallelization.

---

## ✨ Features

- ✅ **Parallel Bubble Sort** using OpenMP  
- ✅ **Parallel Merge Sort** using OpenMP tasks  
- ✅ **Performance Comparison** between Sequential and Parallel versions  
- ✅ **OpenMP Optimizations** with `parallel for`, `task`, and `critical` where required  

---

## 📋 Prerequisites

- **G++ with OpenMP Support** (e.g., `g++-14`)
- **Operating System**: Tested on macOS and Ubuntu

---

## 💻 Installation & Setup

### 🖥 macOS (Homebrew)

```bash
brew install gcc
g++-14 --version   # Verify installation
```

### 🐧 Linux (Ubuntu/Debian)
```bash
   sudo apt update
   sudo apt install g++ libomp-dev
   g++ --version      # Verify installation
```

### 🧢 Fedora
```bash
   sudo dnf install gcc gcc-c++ libomp-devel
   g++ --version      # Verify installation
```

### 🚀 Running the Code
1. Compile the Program
```bash
g++ -fopenmp sort.cpp -o sort_prog
```
2. Execute the Program
```bash
./sort_prog
```

