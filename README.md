Team members: Daniel Hernandez, Rudy Leiva

How to compile:

Linux/UNIX & Mac OS X: Open terminal, cd to the directory where the source code file is stored. Run "gcc -o fileCopying fileCopying.c" (without quotes) on the terminal window. To run the program, simply do "./fileCopying" (without quotes).

Windows 7/8.1/10: Please use the IDE software "Code Blocks" to compile and run this program.

Files included:

fileCopying.c (source code)
fileCopying (C executable file)
sample.txt (sample text file used in this program, any text file may be used)
strace1.png
strace2.png
strace3.png (strace#.png files included in zip folder demonstrate strace output)

Description/purpose of program:

Project 1: This program prompts the user for the filename of the file to copy from. The program verifies that a valid filename has been entered, otherwise it will keep prompting until a valid filename is entered. Currently, this source code / executable file and the file you want as the source file must be in the same folder/directory or the program will always tell you that the file could not be found. Next, the program asks for the filename of the destination file. If the file doesnt exist, it will be created and the data from the source file will be copied to the destination file. If the file exists, then the user has the option to write data to the end of the previous data in the file (append), overwrite the data in the file, or cancel the copy action and end the program. To demonstrate this code using an existing destination file, this source code / executable file and the destination file must be in the same folder/directory otherwise the program will proceed to create the file instead of recognizing an existing file.

System calls invoked when running this program:

execve()
brk()
access()
mmap()
open()
fstat()
close()
read()
mprotect()
arch_prctl()
munmap()
write()
(See screenshots for terminal output when running "strace ./fileCopying" without quotes)

Team member contributions to project:

Daniel Hernandez:

research C functions fopen (general concept), fgets, scanf
code to open files and check for existence of files
code development
debugging
readme file
strace screenshots

Rudy Leiva:

research C functions fopen  read/write r+/w+/append modes, fgetc, fclose
research on strace
code to write to files and options for an existing destination file
code development
debugging
comments
