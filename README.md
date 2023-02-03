# MyLinuxTail
Simplified implementation of Linux 'tail' command in C.

## Compiling
On Linux, open a Terminal, go to the directory of a cloned repository and run 'gcc my_tail.c -o my_tail'.

## Running
After a successful compilation, you can run the program as described below.

This program can be used in 2 ways:

	1) ./my_tail < input.txt
	
	2) ./my_tail -n 5 < input.txt
	
When used like in example 1), this program prints the last 3 lines of text from the specified text file. 

When used like in example 2), this program prints a number of lines (5) specified by the user after '-n' flag.

The above information is also available after invoking './my_tail --help' from the Terminal.

The "input.txt" file is provided as a template for testing the program. It can be modified or replaced, if necessary.
