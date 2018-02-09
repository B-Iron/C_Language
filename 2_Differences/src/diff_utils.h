/*******************************************************************************
 * File: diff_utils.h
 * Author:
 * This file contains the declarations of two diff functions.
 * The first compares two lines
 * The second compares two files (and uses the first)
 ******************************************************************************/
#include <stdio.h>

/*******************************************************************************
 * Function: diff_lines
 * Parameters: FILE* file1, FILE* file2
 * Reads a single line (until a newline) from each and compares each 
 * character.
 * Return value: The character position of the first difference or -1 if there 
 * is a match and a newline is hit, -2 if EOF is found in both streams in the 
 * same position.
 ******************************************************************************/
int diff_lines(FILE *file1, FILE *file2);

/*******************************************************************************
 * Function: diff_files
 * Parameters: FILE* file1, FILE* file2
 * Reads a file a line at a time and uses diff_lines to compare the by
 * character.
 * Return value: The line position of the first difference or -1 if there is a 
 * match
 ******************************************************************************/
int diff_files(FILE *file1, FILE *file2);

/*******************************************************************************
 * Function: diff_files_cmdline
 * Parameters: int argc, char** argv
 * Opens the files names in the command line arguments and diffs them until 
 * the first failure. Prints the location of the first failure.
 * Return value: 0 if the files match, -1 if the files don't match, -2 if
 * there was an error
 ******************************************************************************/
int diff_files_cmdline(int argc,char **argv);
