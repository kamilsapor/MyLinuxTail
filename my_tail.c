#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, const char* argv[])
{
	int result = -1;
	unsigned long long lines;
	char **str;
	size_t str_size;
	
	/* Parsing the arguments, if provided */
	switch(argc){
	case 1:
	  /* no arguments - txt file read from stdin, prints 3 lines */
	  lines = 3;
	  break;
	  
	case 2:
	  /* a single '--help' argument which gives some instructions on how to use the program */
	  if(strcmp(argv[1], "--help") != 0){
	    printf("'%s' is not a valid argument.\n", argv[1]);
	    puts("Try running 'my_tail --help' to see examples of using this program.");
	  }
	  else {
	    puts("This program can be used in 2 ways:");
	    puts("    1) my_tail < text_file_with_lines.txt");
	    puts("    2) my_tail -n 5 < text_file_with_lines.txt\n");
	    puts("When used like in example 1), this program prints the last 3 lines of text from the specified text file. When used like in example 2), this program prints a number of lines specified by the user after '-n' flag.");
	  }
	  return result;
	  
	case 3:
	  /* number of lines to print is provided as an argument, with -n flag */
	  if(strcmp(argv[1], "-n") != 0){
	    printf("'%s' is not a valid argument.\n", argv[1]);
	    puts("Try running 'my_tail --help' to see examples of using this program.");
	    return result;
	  }
	  lines = atoll(argv[2]);
	  if(lines < 1){
	    puts("Inappropriate number of lines given as an argument.");
	    puts("Try running 'my_tail --help' to see examples of using this program.");
	    return result;
	  }
	  break;
	  
	default:
	  /* Wrong number of arguments */
	  puts("Wrong number of arguments.");
	  puts("Try running 'my_tail --help' to see examples of using this program.");
	  return result;	
	}
	
	/* Reading text lines from standard input */
	unsigned long long i = 0;
	while(i < ULLONG_MAX){
	  if(i > 0)
	    str = (char**)realloc(str, (i+1)*sizeof(char*));
	  else
	    str = (char**)malloc(sizeof(char*));
	  str[i] = NULL;
	  result = getline((str+i), &str_size, stdin);
	  ++i;
	  if(result == -1)
	    break;
	}
	--i;
	
	/* If the specified number of lines is greater than the number provided, it is truncated */
	if(lines > i)
	  lines = i;
	
	/* Print the appropriate lines */
	for (unsigned long long j = 0; j < lines; ++j)
	  printf("%s", str[i+j-lines]);
	
	/* Free the allocated memory before ending the program */
	for (unsigned long long k = 0; k < i; ++k)
	  free(str[k]); 
	result = 0;
	
	return result;
}
