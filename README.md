# Simple Shell

A simple shell implementation in C. This project demonstrates the basics of command parsing, process creation, and environment handling in a Unix-like operating system.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Contributing](#contributing)
- [License](#license)

## Features
- Execute commands found in the `PATH`.
- Built-in commands:
  - `exit`
  - `env`
  - `echo`
  - `setenv`
  - `cd`
- Support for command execution with absolute and relative paths.
- Simple command parsing and execution.

## Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/simple-shell.git
    ```
2. Navigate to the project directory:
    ```sh
    cd simple-shell
    ```
3. Compile the source code:
    ```sh
    gcc -o simple_shell shell.c
    ```

## Usage
Run the shell:
```sh
./simple_shell
