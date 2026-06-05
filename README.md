# bithbox

A minimalist, high-performance command-line utility multiplexer written in pure C. Inspired by BusyBox, `bithbox` packs standard system commands into a single binary executable, saving disk space and optimizing execution through smart `argv[0]` evaluation.

## How It Works

Instead of compiling separate binaries for every system tool, `bithbox` compiles into a single executable. Symbolic links (symlinks) like `ls`, `cat`, and `echo` point directly to this binary. 

When invoked, `bithbox` reads the command name from `argv[0]`, shifts the argument vector, and transparently routes the execution to the correct internal applet function.

---

## Preview

![bithbox Preview](Screencast_20260605_210335.gif)

---

## Features

- **Zero External Dependencies:** Built using pure C and standard POSIX headers.
- **Microscopic Footprint:** Aggressive dead code elimination during compilation for ultimate space-saving.
- **Smart Multiplexing:** Detects direct binary execution (`./bithbox echo ...`) and symlink invocation natively.
- **Modular Applet System:** Designed with a clean code structure, making it incredibly easy to scale and add new custom tools.

---

## Supported Applets

| Command | Description | Implementation Details |
| :--- | :--- | :--- |
| `echo` | Prints arguments to standard output | Preserves clean spacing and trailing newlines |
| `cat` | Reads and outputs file content | Character-by-character buffering via `stdio.h` |
| `ls` | Lists directory contents | Directory stream traversal via POSIX `dirent.h` |

---

## Project Structure

```text
bithbox/
├── README.md          # Project documentation
├── Makefile           # Build automation and symlink generation
├── bithbox.h          # Global header for applet declarations
├── main.c             # Core multiplexer & routing table
└── applets/           # Source directory for internal commands
    ├── echo.c
    ├── cat.c
    └── ls.c

Build & Installation
Prerequisites

Ensure you have a C compiler (gcc or clang) and make installed on your Linux environment.
Quick Start

    Clone the repository:
    Bash

    git clone [https://github.com/redbith/bithbox.git](https://github.com/redbith/bithbox.git)
    cd bithbox

    Compile the project and automatically generate symbolic links:
    Bash

    make

    (Optional) If you want to clean build artifacts and remove symlinks:
    Bash

    make clean

Verification & Testing

Once compiled, you can interact with bithbox in two different ways:
1. Direct Multiplexer Execution

Pass the command name explicitly as the first argument to the main binary:
Bash

./bithbox echo "Hello from bithbox multiplexer"
./bithbox ls /usr/bin

2. Symlink Execution (The BusyBox Illusion)

Invoke the automatically generated symbolic links directly. The binary will sense its own filename and adjust its behavior instantly:
Bash

./echo "This feels like a native standalone command"
./ls
./cat Makefile

Roadmap

Future iterations of bithbox aim to implement:

    [ ] pwd - Print working directory.

    [ ] touch - Change file timestamps / create empty files.

    [ ] mkdir - Create standard directories.

    [ ] Static compilation flags (-static) for freestanding embedded systems.

License

This project is licensed under the MIT License. See the LICENSE file for details.
