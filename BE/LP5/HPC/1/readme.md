# Parallel Graph Traversal using OpenMP
You can either access the code.cpp to run in the terminal \\
or you can use the collabnotebook both of them work \\
This project demonstrates parallel Depth-First Search (DFS) and Breadth-First Search (BFS) graph traversal algorithms using OpenMP for parallelization.

## Features

- **Parallel DFS**: Uses OpenMP to parallelize the recursive DFS traversal of the graph.
- **Parallel BFS**: Uses OpenMP to parallelize the traversal of the graph using BFS.
- **OpenMP Parallelization**: The code leverages OpenMP's parallel for loops and critical sections for efficient parallel execution.

## Prerequisites

- **G++ with OpenMP Support**: Ensure you have a version of G++ that supports OpenMP (e.g., `g++-14`).
- **Operating System**: The code is tested on macOS with `g++-14` installed via Homebrew.

### Installation

#### For macOS
1. **Install G++ with OpenMP Support for macOS**:
   - On macOS, you can install GCC using Homebrew:
     ```bash
     brew install gcc
     ```
   
2. **Verify G++ Installation**:
   - Check the G++ version:
     ```bash
     g++-14 --version
     ```

#### For Linux (Ubuntu/Debian)
1. **Install G++ with OpenMP Support for Linux**:
   - On Linux, you can install the required packages using `apt`:
     ```bash
     sudo apt update
     sudo apt install g++-7 libomp-dev
     ```
   
2. **Verify G++ Installation**:
   - Check the G++ version:
     ```bash
     g++ --version
     ```

#### For Fedora
1. **Install G++ with OpenMP Support for Fedora**:
   - On Fedora, use the `dnf` package manager to install GCC:
     ```bash
     sudo dnf install gcc gcc-c++ libomp-devel
     ```

2. **Verify G++ Installation**:
   - Check the G++ version:
     ```bash
     g++ --version
     ```

### Running the Code

1. **Compile the Code**:
   ```bash
   g++ -fopenmp code.cpp -o prog

1. **Running teh code**:
    ```bash
    ./prog