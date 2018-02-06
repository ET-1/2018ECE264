#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"


/*
	Complete the main function and meet the followin specifications of argc and argv.
	1. argc: If argc is not 4, you should return `EXIT_FAILURE` and print "Wrong arguments\n".
	2. argv[1]: name of the input file. i.e., database.txt
	3. argv[2]: should be either "-a", or "-n".
		When argv[2] is "-a", you should sort the database by age in ascending order and print the database and return `EXIT_SUCCESS`.
		When argv[2] is "-n", you should sort the database by name in descending order and print the dataabse and return `EXIT_SUCCESS`. 
		For example, Student "Allen" should come after "Bob".
	  	If argv[2] is neither "-a" nor "-s", you should print "Wrong arguments\n" and return `EXIT_FAILURE`.
	4. argv[3]: This is the output filename. You should write the output of database into this file.
	5. print "Write to db\n" if `WriteDatabase()` work. Otherwise, print "Fail to write to db\n"

*/ 

int main(int argc, char ** argv) 
{
	char * infile;
	char * outfile;
	int write = 0;
	StudentDatabase * db = NULL;
	
	if(argc != 4)//argument is not 4
	{
	  printf("Wrong arguments\n");
	  return EXIT_FAILURE;
	}
	else//argument is 4
	{
	  
	  infile = argv[1];
	  outfile = argv[3];
	  if(strcmp(argv[2], "-a") == 0)//Sort by age mode
	  {
	    db = Connect(infile);
	    if(db == NULL)//fail to read the intput file
	    {
	      printf("Fail to connect to db\n");
	      return EXIT_FAILURE; 
	    }
	    else//read the intput file successfully
	    {
	      SortDatabaseByAge(db);//qsort the database	      
	      write = WriteDatabase(outfile, db);//write the sorting data
	      if(write == 1)//write successfully
	      {
	        PrintDatabase(db);//print out the sorting by age data
	        printf("Write to db\n");
	      }
	      else//fail to write
	      {
	        printf("Fail to write to db\n");
	      }
	      Close(db);//free the memory
	      return EXIT_SUCCESS;
	    }
	  }
	  else if(strcmp(argv[2], "-n") == 0)//Sort by name mode (level1)
	  {
	    db = Connect(infile);
	    if(db == NULL)//fail to read the intput file (level2)
	    {
	      printf("Fail to connect to db\n");
	      return EXIT_FAILURE; 
	    }//(level2)
	    else//read the intput file successfully (level2)
	    {
	      SortDatabaseByName(db);//qsort the database
	      write = WriteDatabase(outfile, db);//write the sorting data
	      if(write == 1)//write successfully (level3)
	      {
	      	PrintDatabase(db);//print out the sorting by age data
	        printf("Write to db\n");
	      }//(level3)
	      else//fail to write (level3)
	      {
	        printf("Fail to write to db\n");
	      }//(level3)
	      Close(db);//free the memory
	      return EXIT_SUCCESS;
	    }//(level2)
	  }//(level1)
	  else
	  {
	    printf("Wrong arguments\n");
	    return EXIT_FAILURE;
	  }
	}
	
}

