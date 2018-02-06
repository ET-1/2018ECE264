#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TEST_STRUCT
#include "pe04.h"
#else
#include "pe04_ans.h"
#endif

#ifndef TEST_CONNECT
/*  
	Complete this function. 
	In this function, you should:
	1. Allocate appripriate memory for database using malloc.
	2. Read the content of file and store it to the StudentDatabase object.
		To read the file, you may want to use the following functions:
			fopen(), fclose(), fgetc(), fscanf(), feof().
		You can use fseek(fptr, 0, SEEK_SET) to go to the beginning of a file. 
	3. You should return a pointer to StudentDatabase object.
*/
StudentDatabase * Connect(char * filename) {
	FILE * fp;
//	int c;
	int stu_num = 0;
	fp = fopen(filename, "r");//open the file with read only mode
	if(fp == NULL)
	{
	  return NULL;
	}
	else
	{
	fseek(fp, 0, SEEK_SET);//go to the beginning of the file
	
	//count the TAB over the file to calculate the student numbers
	while( !feof(fp))
	{
	  if(fgetc(fp) == '\n')
	  {
	    stu_num = stu_num + 1;
	  }
	}
	

	StudentDatabase * db = NULL;
	db = malloc(sizeof(StudentDatabase));//allocate memory for the db
	db->students = malloc(sizeof(Student*)*stu_num);
	for(int ind = 0; ind < stu_num; ind ++)
	{
	  db->students[ind] = malloc(sizeof(Student));
	}	
	db->number = stu_num;

//	Student ** stu = db -> students;
	fseek(fp, 0, SEEK_SET);//go to the beginning of the file
//	#ifdef debug2
//	#endif
	//read every line and store the corresponding element for every student
	while( !feof(fp))
	{
	  for (int idx = 0; idx < stu_num; idx ++) 
	  {
	     //db->students[idx]->id;
	     fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^,],%d\n", &(db->students[idx]->id), db-> students[idx]->name, db->students[idx]->major, db->students[idx]->year, db->students[idx]->enrollment, &(db->students[idx]->age));
	  
	  }
	}
	fclose(fp);//close the file

	return db;
	}
}
#endif

#ifndef TEST_CLOSE
/* 
	You have to complete this function
	Free the memory you allocated in Connect() using free()
	studb is a pointer to the database. 
*/
void Close(StudentDatabase * studb) {
	int stu_num = studb->number;
	for(int idx = 0; idx < stu_num; idx++)
	{
	  free(studb->students[idx]);
	}
	free(studb->students);
	free(studb);
	
}
#endif

#ifndef TEST_SEARCH
/* 
	You have to complete this function.
	1. studb is a pointer to StudentDatbase object.
	2. name is the name of the student you are looking for.
	3. If the "name" is in the database, you should return a pointer 
	to the Student object of that student. Otherwise, you should return NULL. 
 */
Student * SearchByName(StudentDatabase * studb, char * name) {
	int stu_num = studb -> number;
	int position = -1;
	Student * stu;
	//find the name and its corresponding position in studentdatabase
	for (int idx = 0; idx < stu_num; idx ++) 
	{
	  stu = studb -> students[idx];
	  if(strcmp(name, stu->name) == 0)
	  {
       	    position = idx;
	  }
	  
	}
	
	if(position == -1)
	{
	  return NULL;//not found
	}
	else
	{
	  return studb->students[position];//found and return student information
	}
}
#endif

/* This function prints info of a student. */
void PrintStudent(Student * stu) {
	printf("ID:%d, Name:%s, Major:%s, Enrollment:%s, Year:%s, Age:%d\n",
		stu -> id, stu -> name, stu -> major, stu -> enrollment, stu -> year, stu -> age);
}

/* This function prints all students' info in database. */
void PrintDatabase(StudentDatabase * studb) {
	int stu_num = studb -> number;
	for (int idx = 0; idx < stu_num; idx ++) {
		Student * stu = studb -> students[idx];
		PrintStudent(stu);
	}
}
