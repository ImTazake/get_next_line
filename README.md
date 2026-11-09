*This project has been created as part of the 42 curriculum by tisilva.*

# Get Next Line

## Description

Get Next Line is a project from the 42 curriculum that consists of implementing a function capable of reading a file descriptor line by line.

The main goal is to understand how file descriptors, static variables, memory allocation and buffer management work in C.

The function returns one line at a time, including the newline character (`\n`) when present. It also handles multiple calls until the end of the file is reached.

## Table of Contents

1. [Description](#description)
2. [Instructions](#instructions)
3. [Usage](#usage)
4. [Features](#features)
5. [Resources](#resources)

## Instructions

### Compilation

To compile the mandatory part:

```bash
make
```

To compile the bonus part:

```bash
make bonus
```

To remove object files:

```bash
make clean
```

To remove object files and the compiled library:

```bash
make fclean
```

To recompile the project:

```bash
make re
```

### Usage

Include the appropriate header in your source file:

```c
#include "get_next_line.h"
```

For the bonus:

```c
#include "get_next_line_bonus.h"
```

Function prototype:

```c
char *get_next_line(int fd);
```

The function returns:
- A line read from the file descriptor.
- `NULL` when there is nothing left to read or an error occurs.

The returned line must be freed by the caller.

## Features

- Reads files one line at a time.
- Supports different buffer sizes through `BUFFER_SIZE`.
- Handles lines with and without a newline character.
- Uses dynamic memory allocation.
- Bonus: supports multiple file descriptors simultaneously.

## Resources

- 42 Get Next Line subject.
- Linux manual pages: `read(2)`, `open(2)`, `close(2)`, `malloc(3)`, `free(3)`.
- C programming documentation.
- AI tools were used to support learning, understand concepts and debug errors.