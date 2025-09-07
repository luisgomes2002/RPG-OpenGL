# Build e Execução com CMake

This project uses **CMake** for build management.
Below are instructions for compiling and running on **Linux** and **Windows.**

---

## 🔧 Prerequisites

- **CMake** (>= 3.10)
- Compiler:
  - Linux → `gcc` or `g++`
  - Windows → `MinGW` or `MSVC`
- **Git** (optional, if you want to clone the project directly)

---

## 🐧 Linux

```bash
# Clone the project (if you haven't already)
git clone https://github.com/luisgomes2002/RPG-OpenGL.git
cd projeto

# Create build folder
mkdir build && cd build

# Generate build files
cmake ..

# Compile
cmake --build .

# Run the program
./game
```

## 🪟 Windows

```bash
# Clone the project
git clone https://github.com/luisgomes2002/RPG-OpenGL.git
cd projeto

# Create build folder
mkdir build
cd build

# Generate build files
cmake .. -G "MinGW Makefiles"

# Compile
cmake --build .

# Run the program
./game.exe
```
