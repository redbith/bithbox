# bithbox

A minimalist, high-performance command-line utility multiplexer written in pure C. Inspired by BusyBox, `bithbox` packs standard system commands into a single binary executable, saving disk space and optimizing execution through smart `argv[0]` evaluation.

## How It Works

Instead of compiling separate binaries for every system tool, `bithbox` compiles into a single executable. Symbolic links (symlinks) like `ls`, `cat`, and `echo` point directly to this binary.

When invoked, `bithbox` reads the command name from `argv[0]`, shifts the argument vector, and transparently routes execution to the correct internal applet function.

---

## Preview

[![bithbox Preview](https://i.hizliresim.com/kpamq0g.gif)](https://hizliresim.com/kpamq0g)
---

## Features

- **Zero External Dependencies:** Built using pure C and standard POSIX headers.
- **Microscopic Footprint:** Aggressive dead code elimination during compilation for ultimate space-saving.
- **Smart Multiplexing:** Detects direct binary execution (`./bithbox echo ...`) and symlink invocation natively.
- **Modular Applet System:** Designed with a clean code structure, making it incredibly easy to scale and add new custom tools.

---

## Supported Applets

| Command | Description | Implementation Details |
|----------|-------------|------------------------|
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
└── applets/
    ├── echo.c
    ├── cat.c
    └── ls.c
```

---

## Build & Installation

### Prerequisites

Ensure you have a C compiler (`gcc` or `clang`) and `make` installed on your Linux environment.

### Quick Start

1. Clone the repository:

```bash
git clone https://github.com/redbith/bithbox.git
cd bithbox
```

2. Compile the project and automatically generate symbolic links:

```bash
make
```

3. (Optional) Remove build artifacts and generated symlinks:

```bash
make clean
```

---

## Verification & Testing

Once compiled, you can interact with `bithbox` in two different ways.

### 1. Direct Multiplexer Execution

Pass the command name explicitly as the first argument to the main binary:

```bash
./bithbox echo "Hello from bithbox multiplexer"
./bithbox ls /usr/bin
```

### 2. Symlink Execution (The BusyBox Illusion)

Invoke the automatically generated symbolic links directly:

```bash
./echo "This feels like a native standalone command"
./ls
./cat Makefile
```

The binary detects its invocation name through `argv[0]` and dispatches execution to the matching internal applet.

---

## Roadmap

Future iterations of `bithbox` aim to implement:

- [ ] `pwd` — Print working directory.
- [ ] `touch` — Change file timestamps or create empty files.
- [ ] `mkdir` — Create standard directories.
- [ ] Static compilation support (`-static`) for freestanding and embedded environments.
- [ ] Additional POSIX-compatible applets.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
