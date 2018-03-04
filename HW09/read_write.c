#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa09.h"

#ifndef CONNECT

StudentDatabase * ReadDatabase(char * filename) 
{
	StudentDatabase* db = NULL;
	int count = 0;
	int num_stu = 0;
	Student * temp = NULL;
	temp = malloc(sizeof(Student));
	//TODO 1. Open the file in read and binary format
  FILE * fptr;
  fptr = fopen(filename, "rb");
  if(fptr == NULL)//Fail to connect to database
  {
    printf("Fail to connect to db\n");
  }
  
  else//Success to connect to database
  {
	  //TODO 2. Allocate memory for db
    db = malloc(sizeof(StudentDatabase));
  
  
	  //TODO 3. Find number to entries of Student structure
    while((count = fread(temp, sizeof(Student), 1, fptr)) == 1)
    {
      num_stu = num_stu + 1;
    }
	
	
	  //TODO 4. Set the value of db->number to the number of students
    db->number = num_stu;

	
	  // TODO 5. Allocate the memory for the db->students structure
	  db->students = malloc(sizeof(Student) * (db->number));
	
    for(int i = 0; i < (db->number); i++)
  	{
 	   db->students[i] = malloc(sizeof(Student));
  	}
  
	
		//TODO 6. Read the file again from start and assign value to each student in the data base
 	  fseek(fptr, 0, SEEK_SET);
 	  
 	  for(int j = 0; j < (db->number); j++)
 	  {
 	    fread(db->students[j], sizeof(Student), 1, fptr);
 	  }
  
	}
	//close the file
  fclose(fptr);
  free(temp);
  //return the StudentDatabase
	return db;
}

#endif

#ifndef WRITE_DB
//This function is to write to a file in binary format
int WriteDatabase(char *filename, StudentDatabase * db) 
{
  int count = 0;
  FILE * fptr;
  int write_flag = 0;
	//TODO 1. Open the file in write and binary format
	fptr = fopen(filename, "wb");
	
	if(fptr == NULL)//Fail to open file
	{
	  printf("Fail to open a file\n");
	  return 0;
	}
	
	else//Success to open file
	{
	
		//TODO 2. check if the StudentDatabase is not null
		if(db == NULL)//Database is empty
		{
	 	  printf("Empty database\n");
	 	  fclose(fptr);
	 	  return 0;
		}
		
		
		//TODO 3. write into the file and if not possible return 0
		else//Database is not empty
		{  
		  for(int i = 0; i < (db->number); i++)//Write all student into file in binary 
		  {
		    write_flag = fwrite(db, sizeof(Student), 1, fptr);
		    
		    if(write_flag == 1)//Compare the written size
		    {
		      count ++;
		    }
		  }
		  
		  if(count == (db->number))//Check if total written size fit the students number 
		  {
		    fclose(fptr);
		    return 1;
		  }
		  else
		  {
		    fclose(fptr);
		    return 0;
		  }
		  
		}
	
	}


}
#endif














