# Simple Shell

![Shell](https://upload.wikimedia.org/wikipedia/commons/1/1d/Animated_GNU_Bash_Unix_Shell_Prompt.gif)

Write a simple UNIX command interpreter, "The Gates of S(h)ell".

## Name

### sh;

## Requirements

Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using using
gcc, using the options gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using \
`betty-style.pl and betty-doc.pl`\
See here:
[Betty style documentation](https://github.com/holbertonschool/Betty/wiki)

Your shell should not have any memory leaks

No more than 5 functions per file

All your header files should be included guarded

Use system calls only when you need to.

## Description

In this project we are working to write our own simple UNIX command interpreter. The function is going s to work on interactive mode, and non-interactive mode.

## General Concepts

- Unix shell
- Thompson Shell
- Ken Thompson
- Everything you need to know to star coding your own shell
- Team work
- Github contribution

## Sypnosis

* #include <unistd.h>
* #include <stdio.h>
* #include <sys/types.h>
* #include <sys/wait.h>
* #include <string.h>
* #include <stdlib.h>

## Output

Unless specified otherwise, your program muts have the exact same output as sh (/bin/sh) as well as the exact same error output.\
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See bellow)

### **Example of error with sh:**

```c $ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty"| /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
```

### **Same error with your program hsh:**
```c
$ echo "qwerty" | ./hsh
/hsh: 1: qwerty: not found $ echo "qwerty" | .l././hsh
/././hsh: 1: qwerty: not found
$
```

### **Example of non-intercative:**
```c
$ echo "/bin/ls" | ./hsh
```

## Compilation

`gcc -Wall -Werror •Wextra -pedantic -std=gnu89 *. c -0 hsh`

## List of Functions and System Calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- ill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### License

This project is licensed under the Holberto School Sofware Engineering Program
