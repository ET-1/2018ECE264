#include <stdlib.h>
#include <stdio.h>
#include "pa06.h"

/*
	Complete the main function and meet the following specifications.
	In this main function you will
	1. Use `Connect()` function to connect to database.txt. You should hard code `database.txt` in `Connect()` function.
	2. Pass `argc`, `argv` to `ParseQuery()` and get the parse results.
	3. Call `ExecuteQuery()` function to get the result of students who meet the condition we specify in the query. 
	4. Use `WriteDb()` to write to file named `output.txt`. You should hard code this name. 
	5. Free memory.
 */
int main(int argc, char **argv) 
{
    StudentDatabase * db = NULL;
    ParseResult * res = NULL;
    ExecuteResult * exe = NULL;
    
    db = Connect("database.txt");
    res = ParseQuery(argc, argv);
    exe = ExecuteQuery(db, res);
    WriteDb(db, res->field, exe, "output.txt");
    Close(db);
    FreeParseResult(res);
    FreeExecuteResult(exe);
    return EXIT_SUCCESS;
}

