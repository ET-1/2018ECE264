#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pa06.h"
#define MAX_LEN 80


<<<<<<< HEAD
#ifndef TEST_CONNECT
StudentDatabase * Connect(char * filename) 
{
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
void Close(StudentDatabase * studb) 
{
	int stu_num = studb->number;
	for(int idx = 0; idx < stu_num; idx++)
	{
	  free(studb->students[idx]);
	}
	free(studb->students);
	free(studb);
	
}
=======

#ifndef TEST_CONNECT
/* Define your Connect() here.*/
#endif

#ifndef TEST_CLOSE
/* Define your Close() here.*/
>>>>>>> c34ef714a7b81c6afc321dae5780d9f873c7b5ad
#endif

#ifndef TEST_CONSRUCT
/* 
	Construct SelectedField.
	1. This function returns a pointer to SelectedField object.
	2. Allocate memory for SelectedField object.
	3. Initialize all the fields in this object to "false".
	4. return NULL if you fail to allocate memory for SelectedField object.
*/
SelectedField * ConstructField() 
{
  //int num_field = 0;
  SelectedField * fieldcons = NULL;
  fieldcons = malloc(sizeof(SelectedField));//Allocate memory for selectedField object
  if(fieldcons != NULL)//Initialize all the fields to "false"
  {
    fieldcons->id = 0;
    fieldcons->name = 0;
    fieldcons->major = 0;
    fieldcons->year = 0;
    fieldcons->enrollment = 0;
    fieldcons->age = 0;
    return fieldcons;//Return the pointer to that object 
  }
  else
  {
    printf("Fail to allocate memory\n");
    return NULL; 
  }
}
#endif

#ifndef TEST_PARSE
/* 
	Parse the query and store the information into ParseResult object.
	1. This function returns a pointer to ParseResult object.
	2. The ParseResult object has four fields.
		1. Pointer to SelectedField object. The SelectedField  object stores the informations of which fields are selected in the query. For example, if field id is selected, you should update that field to "true".
		2. Number of condition. 
		3. Array of pointers to Condition object. 
		4. What logic does this query specify. It should be eigther AND or OR.
	3. In this function, you should parse the qeury and store the information to ParseResult object. Similar to `Connect()` function in HW04, you should allocate memory for the required objects and then update the fields in the objects. 
*/
ParseResult * ParseQuery(int num, char ** query) 
{
  //Define parameters
  ParseResult * result = NULL;
  result = malloc(sizeof(ParseResult));//Memory allocate for ParseResult pointer
  int sel_ind = 0;
  int con_ind = 0;
  int field_num = 0;
  int num_and = 0;
  int num_or = 0;
  int num_con = 0;
  int con_log = -1;//Conditions logic    AND==1  OR==0
  int num_sel = 0;
  int num_where = 0;
  
  
  //Find the indexs of SELECT and WHERE
  for(int i = 0; i < num; i++)
  {
    if(strcmp(query[i],"SELECT") == 0)
    {
      num_sel ++;
      sel_ind = i;
    }
    if(strcmp(query[i], "WHERE") == 0)
    {
      num_where ++;
      con_ind = i;
    }
    if(strcmp(query[i], "AND") == 0)
    {
      con_log = 1;
      num_and ++; 
    }
    if(strcmp(query[i], "OR") == 0)
    {
      con_log = 0;
      num_or ++;
    }
  }
  
  if((num_sel != 1) || (num_where != 1))
  {
    free(result);
    return NULL;
  }
  else
  {
 
  //Assign the AND or OR number to condition number  
  if(con_log == 1)
  {
    result->condition_num = num_and + 1;
    strcpy(result->logic, "AND");
  }
  else if(con_log == 0)
  {
    result->condition_num = num_or + 1;
    strcpy(result->logic, "OR");
  }
  else
  {
    result->condition_num = 1;
    //result->logic = NULL;
  }
  num_con = result->condition_num;
  
  
  
  //Memory allocate for objects
  field_num = con_ind - sel_ind;//Number of selected fields
  result->field = ConstructField();//Memory allocate for field object pointer
  result->conditions = malloc(sizeof(Condition *) * num_con);//Meomory allocate for conditions
  if(num_con > 0)
  {
    for(int k = 0; k < num_con; k++)
    {
      result->conditions[k] = malloc(sizeof(Condition));
    }
  }
  
  
  
  //Match the conditions
  int lstart = con_ind + 1;

  int m1 = 0;
  int m2 = 0;
  int m3 = 0;

  
//  for(int m = 0; m < num_con; m++)
//  {
    for(int l = lstart; l < num; l++)
    {
      int cond1 = (l - lstart) % 4;//Compare the position with the first condition
      if(cond1 == 0)
      {
        strcpy(result->conditions[m1]->field, query[l]);
        m1 ++;        
      }
      if(cond1 == 1)
      {
        strcpy(result->conditions[m2]->optr, query[l]);
        m2 ++;        
      }
      if(cond1 == 2)
      {
        strcpy(result->conditions[m3]->val, query[l]);
        m3 ++;        
      }
    }
//  }
  
  
  
  
  
  
  
  int fstart = sel_ind + 1;//Iteration start position
  int fstop = con_ind;//Iteration stop position
  //Match the coresponding fields and update the fields
  for(int j = fstart; j < fstop; j++)
  {
    if(strcmp(query[j], "id") == 0)
    {
      result->field->id = true;
    }
    
    if(strcmp(query[j], "name") == 0)
    {
      result->field->name = true;
    }
    
    if(strcmp(query[j], "major") == 0)
    {
      result->field->major = true;
    }
    
    if(strcmp(query[j], "year") == 0)
    {
      result->field->year = true;
    }    

    if(strcmp(query[j], "enrollment") == 0)
    {
      result->field->enrollment = true;
    }
    
    if(strcmp(query[j], "age") == 0)
    {
      result->field->age = true;
    }
  }
  
  return result;
  }

}
#endif


#ifndef TEST_COMPARE
/*
	This is a helper function we provide in this assignment.
	It checks whether a stduent meets the condition.
	You can choose not to use this function.
	Do not modify this function. If you change it, you will get zero.
*/
bool Compare(Student * stu, Condition * condition) {
	if (strcmp(condition -> field, "id") == 0) {
		int id_val = atoi(condition -> val);
		if (strcmp(condition -> optr, "<") == 0) {
			return (stu -> id < id_val);
		} else if (strcmp(condition -> optr, ">") == 0) {
			return (stu -> id > id_val);
		} else if (strcmp(condition -> optr, "=") == 0) {
			return stu -> id == id_val;
		} else if (strcmp(condition -> optr, ">=") == 0) {
			return (stu -> id >= id_val);
		} else if (strcmp(condition -> optr, "<=") == 0) {
			return (stu -> id <= id_val);
		}
	} else if (strcmp(condition -> field, "age") == 0) {
		int age_val = atoi(condition -> val);
		if (strcmp(condition -> optr, "<") == 0) {
			return (stu -> age < age_val);
		} else if (strcmp(condition -> optr, ">") == 0) {
			return (stu -> age > age_val);
		} else if (strcmp(condition -> optr, "=") == 0) {
			return (stu -> age == age_val);
		} else if (strcmp(condition -> optr, ">=") == 0) {
			return (stu -> age >= age_val);
		} else if (strcmp(condition -> optr, "<=") == 0) {
			return (stu -> age <= age_val);
		}
	} else {
		if (strcmp(condition -> field, "name") == 0	) {
			if (strcmp(stu -> name, condition -> val) == 0) {
				return true;	
			}
			return false;	
		} else if (strcmp(condition -> field, "major") == 0 ) {
			if (strcmp(stu -> major, condition -> val) == 0){
				return true;	
			}
			return false;	
		} else if (strcmp(condition -> field, "year") == 0 ) {
			if (strcmp(stu -> year, condition -> val) == 0){
				return true;	
			}
			return false;	
		} else if (strcmp(condition -> field, "enrollment") == 0 ) {
			if (strcmp(stu -> enrollment, condition -> val) == 0){
				return true;	
			}
			return false;	
		}
	} 
	return false;
}
#endif

#ifndef TEST_EXECUTE
/*
	1.This function takes two arguments:
		1. pointer to `StudentDatabase` object.
		2. pointer to `ParseResult` object.	
	2. This function returns a pointer to `ExecuteResult` object.
	3. The `ExecuteResult` object has two fields: First, an array of matched Student's index. Second, length of the array. 
*/
ExecuteResult * ExecuteQuery(StudentDatabase * db, ParseResult * res) 
{
  //Define parameters
  ExecuteResult * exe = NULL;
  ExecuteResult * exe1 = NULL;
  int stu_num = db->number;
  int con_num = res->condition_num;
  int che_and = -1;
  int che_or = -1;
  int count = 0;
  int iter = 0;
  int che_non = -1;
  
  
  //Memoery allocate for the object
  //Find all matched student's indexs
    exe = malloc(sizeof(ExecuteResult));
    exe->arr = malloc(sizeof(int) * stu_num);
    
    
    for(int i = 0; i < stu_num; i++)//loop for students
    {
      Student * stu = db->students[i];
      
      
      if(con_num > 1)//If there are more than one condition
      {
        for(int j = 0; j < con_num; j++)//Repeat for conditions
        {
          Condition * con = res->conditions[j];
          if(strcmp(res->logic, "AND") == 0)
          {
            che_and = che_and + Compare(stu, con);//AND logic check
          }
          else if(strcmp(res->logic, "OR") == 0)
          {
            che_or = che_or + Compare(stu, con);//OR logic check
          }
        }       
        
        if(strcmp(res->logic, "AND") == 0)//If meet AND logic, assign student's index
        {
          if(che_and == (con_num - 1))
          {
            exe->arr[iter] = 1;
            iter ++;
            count ++;
          }
          else if(che_and != (con_num - 1))
          {
            exe->arr[iter] = 0;
            iter ++;
          }
        }
        
        else if(strcmp(res->logic, "OR") == 0)//If meet OR logic, assign student's index
        {
          if(che_or > -1)
          {
            exe->arr[iter] = 1;
            iter ++;
            count ++;
          }
          else if(che_or == -1)
          {
            exe->arr[iter] = 0;
            iter ++;
          }
        }
        
        
        che_and = -1;//Reset AND condition 
        che_or = -1;//Reset OR condition
      }
      
      
      
      
      else//If there is only one condition
      {
        che_non = Compare(stu, res->conditions[0]);
        if(che_non == 1)//AND logic check
        {
          exe->arr[iter] = 1;
          iter ++;
          count ++;
        }
        else//OR logic check
        {
          exe->arr[iter] = 0;
          iter ++;
        }
      }
    //int total = k1 + k2;
    }

    exe->len = count;//Assign total meeted requirements student number to exe object 
    exe1 = malloc(sizeof(ExecuteResult));
    exe1->arr = malloc(sizeof(int) * count);
    exe1->len = count;
    int index = 0;
    for(int k = 0; k < stu_num; k++)
    {
      if(exe->arr[k] == 1)
      {
        exe1->arr[index] = k;
        index ++; 
      }
    }
    free(exe->arr);
    free(exe);
    return exe1;
}
#endif

#ifndef TEST_FREEPARSE
/*
	Free the allocated memory in ParseResult object.
*/
void FreeParseResult(ParseResult * res) 
{
  int num = res->condition_num;
  free(res->field);
  for(int i = 0; i < num; i++)
  {
    free(res->conditions[i]);
  }
  free(res->conditions);
  free(res);
}
#endif

#ifndef TEST_FREEEXECUTE
/*
	Free the allocated memory in ExecuteResult object.
*/
void FreeExecuteResult(ExecuteResult * res) 
{
  free(res->arr);
  free(res);
}
#endif

#ifndef TEST_WRITE

/*
	1. Only write selected fields of students who meet specified conditions to output file.
	2. Print error message "Failed to open file\n" to monitor if the fopen fail. You should not have output file generated if fopen fail. 
	3. Follow this format "field:%s ", or "field:%d ". Add "\n" when you finish writing the selected fileds of a student. Please look at the files in `expected` folder to make sure you understand the format. We will use diff to test. Make sure your output format is correct.
	4. You should write the info of each student in the following order if that fields are selected. id -> name -> major -> year -> enrollment -> age.
	5. The order in selected fields does not affect the order you write to the file.  e.g., `SELECT id name WHERE ...` and `SELECT name id WHERE ...` should have the same output file.  
*/
void WriteDb(StudentDatabase * db, SelectedField * info, ExecuteResult * execute_res, char * filename) 
{
  FILE * fp = NULL;
  fp = fopen(filename, "r");
  int len = execute_res->len;
  if(fp == NULL)//If cannot open file, return Fail
  {
    printf("Failed to open file\n");
  }
  else
  {
    fclose(fp);
    fp = fopen(filename, "w");//Reopen the file with writing mode
    for(int ind = 0; ind < len; ind++)
    {

      int i = execute_res->arr[ind];//If the corresponding index is true, printout the student's information
      //if(ind == 1)
      //{
        //fputs(" ", fp);
        if(info->id == true)
        {
          fprintf(fp, "id:%d ", db->students[i]->id);
        }
        if(info->name == true)
        {
          fprintf(fp, "name:%s ", db->students[i]->name);
        }
        if(info->major == true)
        {
          fprintf(fp, "major:%s ", db->students[i]->major);
        }
        if(info->year == true)
        {
          fprintf(fp, "year:%s ", db->students[i]->year);
        }
        if(info->enrollment == true)
        {
          fprintf(fp, "enrollment:%s ", db->students[i]->enrollment);
        }      
        if(info->age == true)
        {
          fprintf(fp, "age:%d ", db->students[i]->age);
        }
        fputs("\n", fp);
      //}
    }
    fclose(fp);
  }
}

#endif










