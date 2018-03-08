#include <stdlib.h>
#include <stdio.h>
#include "pa06.h"

/*
	Complete the main function and meet the following specifications.
	In this main function you will
	1. `argv[1]`: database name (i.e., database.txt). You should pass `argv[1]` to `Connect()`.
	2. `argv[2]`: output file name. You should pass `argv[2]` to `WriteDb()`.
	3. Pass `argc`, `argv` to `ParseQuery()` and get the parse results.
	4. Call `ExecuteQuery()` function to get the result of students who meet the condition we specify in the query.
	5. Use `WriteDb()` to write a file.
	6. Free memory.
	7. You can assume all input arguments are valid. 
 */
int main(int argc, char **argv) 
{
    StudentDatabase * db = NULL;
    ParseResult * res = NULL;
    ExecuteResult * exe = NULL;
    char  infile[] = "database.txt";
    char  outfile[] = "output.txt";

    db = Connect(infile);
  //  PrintDatabase(db);
    res = ParseQuery(argc, argv);
    if(res == NULL)
    {
      Close(db);
      return EXIT_FAILURE;
    }
    else
    {
      exe = ExecuteQuery(db, res);
      WriteDb(db, res->field, exe, outfile);
      FreeParseResult(res);
      FreeExecuteResult(exe);
      Close(db);
      return EXIT_SUCCESS;
    }
}

