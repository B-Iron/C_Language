/*******************************************************************************
 * file: diff.c
 * Main driver for file diff functinality
 * Author:
 * Sources: None
 ******************************************************************************/
#include <stdio.h>
#include "diff_utils.h"

/*******************************************************************************
 * function: main
 * sends command line options to diff_utils and returns result
 ******************************************************************************/
int main(int argc,char** argv){
    return diff_files_cmdline(argc,argv);
}
