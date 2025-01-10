
# Simple Shell
![](https://kurume-4th-ranger-club.com/wp-content/uploads/2020/07/bash_logo_eyecatch-1024x576.png)


Simple Shell is a project that implements a basic UNIX shell in C. This shell allows users to execute simple commands with no arguments, without support for pipes, redirections, or any other advanced features. It provides a command-line interface that waits for a user to input a command, executes it, and handles errors, including EOF (End of File) conditions.



## Requirements

- Ubuntu 20.04 LTS or any Linux distribution that supports POSIX-compliant shells.
- gcc for compiling C code.
- The shell uses the execve system call to execute external commands.


## Features

- Displays a simple prompt.
- The shell waits for the user to input a command to execute.
- Executes simple commands (without arguments).
- Checks if the command exists before execution.
- Handles EOF (Ctrl+D) to exit the shell.
- Displays an error message if the command is not found.


## Installation

Clone the repository from GitHub:
```bash
  git clone https://github.com/SoliraZ/holbertonschool-simple_shell.git
```

Navigate to the project directory:
```bash
  cd holbertonschool-simple_shell
```

Compile the project with gcc:
```bash
 gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


## Usage/Examples

1- Run the shell with the following command:
```bash
./hsh
```

2- Once the shell is running, it will prompt you for input. For example
The shell will execute the command and display the output:
```bash
$ ls
file1.txt  file2.txt  file3.txt
```

4- If the command is not found, it will show an error message:
```bash
./hsh: 1: command: not found
```

5- To exit the shell, type exit:
```bash
$ exit
```
6- If you press Ctrl+D, the shell will also terminate.


## Limitations

- It does not handle pipes, redirections, or any other advanced features.



## Authors
![](https://flat-badgen.vercel.app/badge/icon/github?icon=github&label)

This project was developed as part of the Holberton School.

- [@Saru3450](https://github.com/saru3450)
- [@SoliraZ](https://github.com/SoliraZ)
- [@Myri-fid](https://github.com/myri-fid)

## Flowchart

![Flowchart](https://i.goopics.net/8qqz1e.png)
