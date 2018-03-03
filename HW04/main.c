#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe04.h"

/* 
	1. `argc`: 
		1. If `argc` is less than 3, you should return `EXIT_FAILURE` and print "Insufficient arguments\n".
		2. When argc is 3, `argv[2]` should be "-a" and you should print all the students in database using `PrintDatabase()` function and return `EXIT_SUCCESS`. Otherwise, you should print "Wrong arguments\n" to screen and return `EXIT_FAILURE`.
		3. When argc is 4, `argv[2]` should be "-s" and you should  enter the name of the student in `argv[3]` and print information of that student and return `EXIT_SUCCESS`. If there is no such student, you should print "No this student\n" to screen and return `EXIT_SUCCESS`. Otherwise, you should print "Wrong arguments\n" to screen and return `EXIT_FAILURE`.
		4. When argc is larger than 4, you should print "Too many arguments\n" to screen and return `EXIT_FAILURE`.
	2. `argv[1]`: name of the input file (i.e., database.txt).
*/
int main(int argc, char ** argv) 
{
	char * filename;
	char * stu_name = NULL;
	StudentDatabase * db;
	Student * found;
	if (argc < 3)
	{
	  printf("Insufficient arguments\n");
	  return EXIT_FAILURE;
	  
	}
	else
	{
	  filename = argv[1];//assign filename
	  db = Connect(filename);//read the database and assign it to db
	  if(db == NULL)
	  {
	    printf("Wrong arguments\n");
	    return EXIT_FAILURE;
	  }
	  else
	  {
	    if (strcmp(argv[2], "-a") == 0)
	    {
	      if(argv[3] != NULL)
	      {
	        printf("Wrong arguments\n");
	        Close(db);
	        return EXIT_FAILURE;
	      }
	      else
	      {
	        PrintDatabase(db);//print the database db
	        Close(db);
	        return EXIT_SUCCESS;
	      }
	    }
	    else if (strcmp(argv[2], "-s") == 0)
	    {
	      if(argv[3] == NULL)
	      {
	        printf("Wrong arguments\n");
	        Close(db);
	        return EXIT_FAILURE;
	      }
	      else
	      {
	        stu_name = argv[3];//assign student name
	        found = SearchByName(db, stu_name);//return result to found
	        if(found == NULL)
	        {
	          printf("No this student\n");
	          Close(db);
	          return EXIT_SUCCESS;
	        }
	        else
	        {
	          PrintStudent(found);
	          Close(db);
	          return EXIT_SUCCESS;
	        }
	      
	      }
	    }
	    else
	    {
	      printf("Wrong arguments\n");
	      Close(db);
	      return EXIT_FAILURE;
	    }
	  }
	}
}

