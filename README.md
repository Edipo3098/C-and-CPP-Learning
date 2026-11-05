# C and C++ Learning

[![Build and test](https://github.com/Edipo3098/C-and-CPP-Learning/actions/workflows/build.yml/badge.svg)](https://github.com/Edipo3098/C-and-CPP-Learning/actions/workflows/build.yml)

Hands-on C17 and C++17 exercises covering classes, pointers, containers, memory representation and preprocessor techniques. Each example is a small console program built through a shared CMake project.

## Exercises

| Project | Topics | Executable targets |
| --- | --- | --- |
| [MotorTest](MotorTest/) | Classes, composition, references, non-owning pointers and const methods | `MotorTest` |
| [SquareRotation](SquareRotation/) | 2D rotation and a character-grid visualization | `SquareRotation` |
| [Struct_Pointer](Struct_Pointer/) | C structures, allocation, arrays and pointer parameters | `Struct_Pointer`, `Struct_Pointer_2` |
| [Union](Union/) | Union storage and integer byte representation | `Union` |
| [XMacro](XMacro/) | Generating functions, names and enum entries from one list | `XMacro` |
| [Vector](Vector/) | Containers, element-wise operations, sorting and grade statistics | `VectorBasics`, `VectorOperations`, `VectorArithmetic`, `VectorGrades` |

## Build and run

Install CMake 3.15+ and a C/C++ compiler, then run:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug --parallel
ctest --test-dir build -C Debug --output-on-failure
```

Programs are placed in `build/bin`, or `build/bin/Debug` with multi-configuration generators such as Visual Studio. Run `MotorTest` there (`MotorTest.exe` on Windows). `VectorGrades` reads student names and numeric grades interactively.

Optional Ninja presets require CMake 3.21+:

```sh
cmake --preset debug
cmake --build build/debug --parallel
ctest --test-dir build/debug --output-on-failure
```

## Verification

GitHub Actions builds and runs checks on Windows and Linux in Debug and Release configurations. The 12 checks cover executable startup, motor pointer and string boundaries, and grade calculations with valid and invalid input. Local validation also passed with GCC 16.2 on Windows.

## Learning notes

- `MotorTest` keeps a non-owning motor pointer: the caller must keep the motor alive while it is used. Missing motors are checked before comparison.
- `Union` accesses only the active union member and uses `memcpy` to inspect integer bytes. Byte order depends on the machine; the example is not a hardware register driver.
- `VectorGrades` validates counts and numeric input, calculates each student's results independently and preserves fractional grades.
- These are focused learning exercises. Generated binaries, build directories and editor settings are excluded from version control.
