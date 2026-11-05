# C and C++ Practice Projects

Small console exercises exploring language fundamentals and CMake project organization.

| Project | Topics | CMake target |
| --- | --- | --- |
| MotorTest | Classes, composition, references, pointers and const member functions | `MotorTest` |
| SquareRotation | 2D rotation and plotting vertices on a character grid | `SquareRotation` |
| Struct_Pointer | C structures, dynamic allocation, arrays and pointer parameters | `Struct_Pointer`, `Struct_Pointer_2` |
| Union | Union storage and byte-level representation | `Union` |
| XMacro | Preprocessor lists generating functions, names and enum entries | `XMacro` |

## Build

From this directory, with CMake 3.15+ and a C/C++ compiler:

```sh
cmake -S . -B build
cmake --build build --config Debug
```

Executables are placed in `build/bin`, or a configuration subdirectory such as `build/bin/Debug` with multi-configuration generators. For example, run `MotorTest` there (`MotorTest.exe` on Windows).

The optional presets require CMake 3.21+ and Ninja:

```sh
cmake --preset debug
cmake --build build/debug
```

## Learning notes

These examples retain the original practice implementations. The union example depends on compiler extensions, integer representation and byte order; it is not a portable hardware register driver. SquareRotation uses the non-standard `M_PI` macro, which some compiler configurations do not expose. MotorTest uses a non-owning motor pointer whose lifetime and initialization require care when extending the example.

The source was imported without generated build output, executable binaries or editor-specific workspace files. The exercises have not been built as part of this import.
