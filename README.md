****************
* HW 02
* CPSC 380
* March 3 2023
**************** 

# Simple Shell
OVERVIEW:
 A C program that uses the fork and exec system calls to create a simple terminal shell

INCLUDED FILES:

 * sshell.c - source file
 * Makefile - building and running script for syscpy
 * Output.txt - output testing file
 * README - this file


COMPILING AND RUNNING:

 From the directory HW02 containing all files, compile the .c file with the command:
### $ make clean

 Run the compiled .o file using the JSON Makefile script with the command:
### $ make run

or

You can run the .o file directly from the command line with:
### $ ./sshell.o 

Console output will then prompt the user to enter a terminal command for the program to process.

PROGRAM DESIGN AND IMPORTANT CONCEPTS:

For this project I had to use the fork() and the ececvp() functions for the first time. These presented some challenges during development, as I had to refamiliarize myself with how strings and pointers worked in C. I also used the strtok function to parse my string, and was unaware that it mutilated the input string as it parsed, this caused major bugs in development and set me behind scedule, I was however eventually able to get the program working successfelly. 


TESTING:

 
* Output.txt  - sample input/out file

My program is guarded against bad user input with error checking using errno, the program uses these to display a helpful error message in the event of an error.

To test my program I preformed many terminal commands within the program shell, and recieved only expected results.

To the extent of my knowledge and testing the program functions as intended with no  errors or warnings.



DISCUSSION:
 
 This was great project to get increase my knowledge and proficiency in the c language, as well as develop a more thurough understanding of the fork() system call. Through working on this project I was able to knock some more rust off of my C skills. That being said this project was by no means 
a walk in the park as I was unfamilliar with fork() and exec() system calls and as a result had a great learning experience from this project.  
----------------------------------------------------------------------------