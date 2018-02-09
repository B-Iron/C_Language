/*******************************************************************************
 * File: Test driver for diff solution
 * Author: Catherine Olschanowsky
 * Purpose: This file is meant to be given to the students to help guide 
 * thier development and encourage test driven development patterns
 *
 * The tests in this directory are NOT sufficient for getting any better than 
 * a C on this programming assignment. They are a good place to start, but if
 * you want a higher grade you should write additional tests and test from 
 * the command line.
 *
 * A note on test drivers: In general one should not write their own test
 * driver, there are other tools for this. However, we have not yet learned
 * enough of C to use any of them. This driver approximates test-driven 
 * development, but in industry and in a research lab you will be expected to 
 * use a standard framework.
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "diff_utils.h"


/*******************************************************************************
 * main: All tests are written from this function and all output is 
 * controlled here.
 ****************************************************************************/
int main(int argc, char** argv){

  // Test1: Diff 2 short files that are an exact match
  FILE *file1,*file2;

  if((file1 = fopen("etc/test01a","r"))==NULL){
    fprintf(stderr,"TEST1: Failure to read input file: etc/test01a\n");
    return 1;
  }
  if((file2 = fopen("etc/test01b","r"))==NULL){
    fprintf(stderr,"TEST1: Failure to read input file: etc/test01b\n");
    fclose(file1);
    return 1;
  }

  int pos = diff_lines(file1,file2);
  if(pos >= 0){
    fprintf(stderr,"TEST1: Failure, files match, but return value is %d\n",pos);
    fclose(file1);
    fclose(file2);
    return 1;
  }

  fclose(file1);
  fclose(file2);
  // end of TEST1
  
  // Test2: Diff 2 short files that don't match
  if((file1 = fopen("etc/test02a","r"))==NULL){
    fprintf(stderr,"TEST2: Failure to read input file: etc/test02a\n");
    return 1;
  }
  if((file2 = fopen("etc/test02b","r"))==NULL){
    fprintf(stderr,"TEST2: Failure to read input file: etc/test02b\n");
    fclose(file1);
    return 1;
  }

  pos = diff_lines(file1,file2);
  if(pos != 4){
    fprintf(stderr,"TEST2: Failure, expected 4 got %d\n",pos);
    fclose(file1);
    fclose(file2);
    return 1;
  }

  fclose(file1);
  fclose(file2);
  // end of TEST2
  
  // Test3: Diff 2 multiline files that match
  if((file1 = fopen("etc/test03a","r"))==NULL){
    fprintf(stderr,"TEST3: Failure to read input file: etc/test03a\n");
    return 1;
  }
  if((file2 = fopen("etc/test03b","r"))==NULL){
    fprintf(stderr,"TEST3: Failure to read input file: etc/test03b\n");
    fclose(file1);
    return 1;
  }

  pos = diff_files(file1,file2);
  if(pos != 2){
    fprintf(stderr,"TEST3: Failure, expected 2 got %d\n",pos);
    fclose(file1);
    fclose(file2);
    return 1;
  }

  fclose(file1);
  fclose(file2);
  // end of TEST3
 
  // Test4: Test the command line parsing portion of the code
  int argc_t = 1;
  char *arg1 = "etc/testnotthere1";
  char *arg2 = "etc/testnotthere2";
  char ** argv_t = malloc(3*sizeof(char*));
  argv_t[0] = "diff_testdriver";
  argv_t[1] = arg1;
  argv_t[2] = arg2;

  // test for a gracefull error when the number of command line
  // arguments is wrong
  int result = diff_files_cmdline(argc_t,argv_t);
  if(result != -2){
    fprintf(stderr,"TEST4: Failure, expected to fail on argument count\n");
    return 1;
  }

  // test for a gracefull error when the first file doesn't exist
  argc_t = 3;
  result = diff_files_cmdline(argc_t,argv_t);
  if(result != -2){
    fprintf(stderr,"TEST4: Failure, expected to fail missing file\n");
    return 1;
  }

  // test for a gracefull error when the second file doesn't exist
  argv_t[1] = "etc/test01a";
  result = diff_files_cmdline(argc_t,argv_t);
  if(result != -2){
    fprintf(stderr,"TEST4: Failure, expected to fail missing file\n");
    return 1;
  }

  // test for success
  argv_t[2] = "etc/test01a";
  result = diff_files_cmdline(argc_t,argv_t);
  if(result != 0){
    fprintf(stderr,"TEST4: Failure, expected match\n");
    return 1;
  }


  fprintf(stderr,"*** SUCCESS: All unit tests pass ***\n");
  return 0;
}
