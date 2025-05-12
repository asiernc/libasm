<div align="center">
  <h1 align="center">
    <br>libasm - x86-64 Assembly Library</br>
  </h1>
  <p align="center">
    <img src="https://img.shields.io/badge/42-libasm-red?style=flat-square" alt="42 libasm"/>
    <img src="https://img.shields.io/badge/Arch-x86__64-green?style=flat-square" alt="x86-64"/>
  </p>
</div>

## Table of Contents
- [📖 Summary](#-summary)
- [🧮 Theory](#-theory)
- [⚙️ Functions](#️-functions)
- [🚀 Usage](#-usage)
- [📦 Installation](#-installation)
- [📖 Documentation](#-documentation)

---

## 📖 Summary

**libasm** is an assembly language library for x86-64 architecture, implementing common C functions like `strlen`, `strcmp`, and system calls (`read`, `write`). Designed as part of the 42 curriculum, it demonstrates low-level programming with NASM syntax and Linux ABI conventions.

---

## 🧮 Theory

### 📜 Registers
- **RAX**: Accumulator (return values, syscall numbers)
- **RDI/RDI/RSI/RDX**: 1st/2nd/3rd/4th function arguments
- **RCX**: Counter (loop operations)
- **R8-R9**: 5th/6th arguments in System V ABI

### 🖥️ Syscalls
- Invoked via `syscall` instruction
- **RAX** stores syscall number:
  - `0` = `read`
  - `1` = `write`
  - `12` = `brk` (used by `malloc`)
- **RDI/RSI/RDX** pass arguments

### 📌 Key Concepts
- **Stack Management**: `push/pop` for preserving registers
- **String Operations**: `movsb`, `cmpsb` variants
- **Error Handling**: Negative returns → `errno` via `__errno_location`

---

## ⚙️ Functions

### 📏 String Operations
| Function   | Description                          | Key Instructions       |
|------------|--------------------------------------|------------------------|
| `ft_strlen`| Calculate string length              | `cmp byte [rdi], 0`    |
| `ft_strcmp`| Compare strings lexicographically    | `mov al, [rdi]` + `sub`|
| `ft_strcpy`| Copy string (incl. NULL-terminator)  | `mov [rdi], al` + loop |

### 💾 Memory & Syscalls
| Function   | Description                          | Key Components         |
|------------|--------------------------------------|------------------------|
| `ft_strdup`| Duplicate string (uses `malloc`)     | `malloc` + copy loop   |
| `ft_read`  | Read from file descriptor            | `syscall` + `errno`    |
| `ft_write` | Write to file descriptor             | `syscall` + error check|

---

## 🚀 Usage

### 🔧 Compilation
```sh
nasm -f elf64 ft_*.s           # Assemble elf64 for linux, macho64 for MacOS
ar rcs libasm.a ft_*.o         # Create static library
gcc main.c -L. -lasm -o tester # Link with test program
```

or inside clone folder 
```
make up
./tester
```

---

## 📖 Documentation
- https://aaronbloomfield.github.io/pdr/book/x86-64bit-ccc-chapter.pdf
- https://exercism.org/docs/tracks/x86-64-assembly/learning
- https://github.com/luamfb/intro_x86-64
- https://github.com/las-nish/NASM-Assembly-Collection/blob/main/Linux%20System%20Call.MD

---
