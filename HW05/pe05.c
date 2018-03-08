#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"

#ifndef TEST_CPRNAME
static int CompareByName(const void * s1, const void * s2) 
{
	char * first_name = NULL;
	char * second_name = NULL;
	Student * first = *(Student **)s1;
	Student * second = *(Student **)s2;
	first_name = first->name;//name of former
	second_name = second->name;//name of later
	
	return (strcmp(second_name, first_name));//compare using ascending order
}
#endif

#ifndef TEST_NAME
<<<<<<< HEAD
void SortDatabaseByName(StudentDatabase * studb) 
{
	int stunum = 0;
	int stusize = 0;
	stunum = studb->number;
	stusize = sizeof(Student *);
	qsort(studb->students, stunum, stusize, CompareByName);// use qsort to sort the database.
	
=======
void SortDatabaseByName(StudentDatabase * db) {
	// use qsort to sort the database.
>>>>>>> c34ef714a7b81c6afc321dae5780d9f873c7b5ad
}
#endif

#ifndef TEST_CPRAGE
static int CompareByAge(const void * s1, const void * s2) 
{
	int first_age = 0;
	int second_age = 0;
	Student * first = *(Student **)s1;
	Student * second = *(Student **)s2;
	first_age = first->age;//age of former
	second_age = second->age;//age of later
	
	return (first_age - second_age);//compare using ascending order
}
#endif

#ifndef TEST_AGE
<<<<<<< HEAD
void SortDatabaseByAge(StudentDatabase * studb) 
{
	int stunum = 0;
	int stusize = 0;
	stunum = studb->number;
	stusize = sizeof(Student *);
	qsort(studb->students, stunum, stusize, CompareByAge);// use qsort to sort the database.
=======
void SortDatabaseByAge(StudentDatabase * db) {
	// use qsort to sort the database.
>>>>>>> c34ef714a7b81c6afc321dae5780d9f873c7b5ad

}
#endif

#ifndef TEST_WRITE
int WriteDatabase(char *filename, StudentDatabase * db) 
{
	FILE * fp;
	int cond = 0;
	int fail = 0;
	int stu_num = db->number;
	fp = fopen(filename, "r+");//creat new file to write the data
	
	if(fp != NULL)//successfully open file
	{
	  fseek(fp, 0, SEEK_SET);//go to the beginning of the file
	  for (int idx = 0; idx < stu_num; idx ++) 
	  {
	    Student * stu = db->students[idx];
	    cond = fprintf(fp, "ID:%d, Name:%s, Major:%s, Enrollment:%s, Year:%s, Age:%d\n", stu->id, stu->name, stu->major, stu->enrollment, stu->year, stu->age);// Write the info storing in db to filename
	    
	    if(cond < 0)
	    {
	      fail = fail + 1;//fail+1 when fprintf fails once
	    }
	  }
	  fclose(fp);//close file after writing done
	  
	  if(fail > 0)
	  {
	    return (0);
	  }
	  else
	  {
	    return (1);
	  }
	}
	else//fail to open file
	{
	  printf("Fail to open a file\n");
	  return (0);
	}	

}
#endif

