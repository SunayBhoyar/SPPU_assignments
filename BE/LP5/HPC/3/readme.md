# CUDA Parallel Reduction

This repository contains a CUDA implementation of parallel reduction operations (minimum, maximum, sum, and average) on an array of integers.

## Requirements

- NVIDIA CUDA-capable GPU
- CUDA Toolkit (version 10.0 or higher recommended)
- C++ compiler compatible with your CUDA version

## Installation Instructions

### Windows

1. **Install NVIDIA GPU Drivers**
   - Download and install the latest drivers from [NVIDIA's Driver Download page](https://www.nvidia.com/Download/index.aspx)

2. **Install CUDA Toolkit**
   - Download the CUDA Toolkit from [NVIDIA's CUDA Downloads page](https://developer.nvidia.com/cuda-downloads)
   - Select "Windows" and your version of Windows
   - Follow the installation wizard instructions
   - Make sure to install the included Visual Studio integration

3. **Install Visual Studio with C++ Development Tools**
   - Download Visual Studio from [Microsoft's website](https://visualstudio.microsoft.com/downloads/)
   - During installation, select "Desktop development with C++"

### Linux (Ubuntu/Debian)

1. **Install NVIDIA GPU Drivers**
   ```bash
   sudo apt update
   sudo apt install nvidia-driver-XXX   # Replace XXX with the driver version compatible with your GPU
   sudo reboot
   ```

2. **Install CUDA Toolkit**
   ```bash
   wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.0-1_all.deb
   sudo dpkg -i cuda-keyring_1.0-1_all.deb
   sudo apt update
   sudo apt install cuda
   ```

3. **Set up Environment Variables**
   ```bash
   echo 'export PATH=/usr/local/cuda/bin:$PATH' >> ~/.bashrc
   echo 'export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH' >> ~/.bashrc
   source ~/.bashrc
   ```

### Fedora

1. **Install NVIDIA GPU Drivers**
   ```bash
   sudo dnf update
   sudo dnf install akmod-nvidia
   sudo reboot
   ```

2. **Install CUDA Toolkit**
   ```bash
   sudo dnf config-manager --add-repo https://developer.download.nvidia.com/compute/cuda/repos/fedora37/x86_64/cuda-fedora37.repo
   sudo dnf clean all
   sudo dnf module disable nvidia-driver
   sudo dnf install cuda
   ```

3. **Set up Environment Variables**
   ```bash
   echo 'export PATH=/usr/local/cuda/bin:$PATH' >> ~/.bashrc
   echo 'export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH' >> ~/.bashrc
   source ~/.bashrc
   ```

### macOS

**Note**: CUDA support is limited on newer macOS versions and Apple Silicon. CUDA is officially supported only on Intel-based Macs running macOS 10.13 High Sierra to 10.14 Mojave.

1. **Install NVIDIA GPU Drivers**
   - Download and install the latest drivers from [NVIDIA's Driver Download page](https://www.nvidia.com/Download/index.aspx)

2. **Install CUDA Toolkit**
   - Download the CUDA Toolkit for macOS from [NVIDIA's CUDA Downloads page](https://developer.nvidia.com/cuda-downloads)
   - Follow the installation instructions

3. **Set up Environment Variables**
   ```bash
   echo 'export PATH=/Developer/NVIDIA/CUDA-XX.X/bin:$PATH' >> ~/.bash_profile
   echo 'export DYLD_LIBRARY_PATH=/Developer/NVIDIA/CUDA-XX.X/lib:$DYLD_LIBRARY_PATH' >> ~/.bash_profile
   source ~/.bash_profile
   ```
   Replace `XX.X` with your CUDA version (e.g., `12.0`).

## Compiling and Running

### Windows

1. **Using Command Line**
   ```
   nvcc parallel_reduction.cu -o parallel_reduction.exe
   parallel_reduction.exe
   ```

2. **Using Visual Studio**
   - Create a new CUDA project
   - Add the `parallel_reduction.cu` file to your project
   - Build and run the project

### Linux/macOS

```bash
nvcc parallel_reduction.cu -o parallel_reduction
./parallel_reduction
```

### Google Colab

If you don't have a local CUDA setup, you can run the code using Google Colab:

1. Go to [Google Colab](https://colab.research.google.com/)
2. Create a new notebook
3. Select "Runtime" > "Change runtime type" and set the hardware accelerator to "GPU"
4. In a code cell, add and execute:

```python
%%writefile parallel_reduction.cu
// Paste the entire CUDA code here
```

5. Then compile and run:

```bash
!nvcc parallel_reduction.cu -o parallel_reduction
!./parallel_reduction
```

## Verifying CUDA Installation

To verify your CUDA installation is working correctly:

### Windows

```
nvcc --version
nvidia-smi
```

### Linux/macOS

```bash
nvcc --version
nvidia-smi
```

## Troubleshooting

- **"NVCC not found"**: Ensure CUDA bin directory is in your PATH
- **"No CUDA-capable device is detected"**: Check that your GPU supports CUDA and drivers are installed correctly
- **Compilation errors**: Verify CUDA Toolkit installation and compiler compatibility
- **Runtime errors**: Update GPU drivers to the latest version

## File Description

- `parallel_reduction.cu`: Contains the CUDA implementation of parallel reduction operations
