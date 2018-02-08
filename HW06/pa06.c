#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pa06.h"
#define MAX_LEN 80

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
  
  
  
  //Find the indexs of SELECT and WHERE
  for(int i = 0; i < num; i++)
  {
    if(strcmp(query[i],"SELECT") == 0)
    {
      sel_ind = i;
    }
    else if(strcmp(query[i], "WHERE") == 0)
    {
      con_ind = i;
    }
    else if(strcmp(query[i], "AND") == 0)
    {
      con_log = 1;
      num_and ++; 
    }
    else if(strcmp(query[i], "OR") == 0)
    {
      con_log = 0;
      num_or ++;
    }
  }
  
  
 
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
  num_con = result->condition_num;
  
  
  
  //Memory allocate for objects
  field_num = con_ind - sel_ind;//Number of selected fields
  result->field = ConstructField();//Memory allocate for field object pointer
  result->conditions = malloc(sizeof(Condition *) * num_con);//Meomory allocate for conditions
  for(int k = 0; k < num_con; k++)
  {
    result->conditions[k] = malloc(sizeof(Condition));
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
      result->field->id = 1;
    }
    
    if(strcmp(query[j], "name") == 0)
    {
      result->field->name = 1;
    }
    
    if(strcmp(query[j], "major") == 0)
    {
      result->field->major = 1;
    }
    
    if(strcmp(query[j], "year") == 0)
    {
      result->field->year = 1;
    }    

    if(strcmp(query[j], "enrollment") == 0)
    {
      result->field->enrollment = 1;
    }
    
    if(strcmp(query[j], "age") == 0)
    {
      result->field->age = 1;
    }
  }
  
  return result;
    

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
  int count = 0;
  int stu_num = db->number;
  int con_num = res->condition_num;
  int che_and = 0;
  int che_or = 0;
  int loop_num = 0;
  
  //Memoery allocate for the object
  exe = malloc(sizeof(ExecuteResult));
  exe->arr = malloc(sizeof(int) * stu_num);

  //Find all matched student's indexs
  for(int k = 0; k < stu_num; k++)
  {
    for(int i = 0; i < stu_num; i++)//loop for students
    {
      Student * stu = db->students[i];
      for(int j = 0; j < con_num; j++)//loop for conditions
      {
        Condition * con = res->conditions[j];
        if(strcmp(res->logic, "AND") == 0)
        {
          che_and = che_and + Compare(stu, con);
        }
        else if(strcmp(res->logic, "OR") == 0)
        {
          che_or = che_or + Compare(stu, con);
        }
        loop_num ++;
      }
      if(che_and == loop_num)//If meet AND logic, assign student's index
      {
        exe->arr[k] = i;
        count ++;
      }
      else if(che_or > 0)//If meet OR logic, assign student's index
      {
        exe->arr[k] = i;
        count ++;
      }
      che_and = 0;//Reset AND condition 
      che_or = 0;//Reset OR condition
      loop_num = 0;
    }
  }
  exe->len = count;
  return exe;
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
  fp = fopen(filename, "r+");
  fseek(fp, 0, SEEK_SET);
  if(fp == NULL)
  {
    printf("Failed to open file\n");
  }
  else
  {
    for(int i = 0; i < (execute_res->len); i++)
    {
      int ind = execute_res->arr[i];
      if(info->id == true)
      {
        fprintf(fp, "id:%d ", db->students[ind]->id);
      }
      else if(info->name == true)
      {
        fprintf(fp, "\bname:%s ", db->students[ind]->name);
      }
      else if(info->major == true)
      {
        fprintf(fp, "\bmajor:%s ", db->students[ind]->major);
      }
      else if(info->year == true)
      {
        fprintf(fp, "\byear:%s ", db->students[ind]->year);
      }
      else if(info->enrollment == true)
      {
        fprintf(fp, "\benrollment:%s ", db->students[ind]->enrollment);
      }      
      else if(info->age == true)
      {
        fprintf(fp, "\bage:%d ", db->students[ind]->age);
      }
    }
    fclose(fp);
  }
}

#endif










