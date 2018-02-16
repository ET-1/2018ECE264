#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "pe07.h"
#define MAX_LENGTH 100 //The maximum length of string


int main(int argc, char **argv) 
{
	char * filename;
	FILE * fp;
	int str_num = 0;
	filename = argv[1];
	char ** str;
	//1. Preparation process before work
	
	
	if((argc < 2) || (argc > 3))//If number of argument is not enough, failure
	{
	  printf("Wrong argument number\n");
	  return EXIT_FAILURE;
	}
	else//If number of argument is enough, divide into different cases
	{
	  fp = fopen(filename, "r");
	  if(fp == NULL)//If cannnot open the file successfully
	  {
	    printf("Wrong file name\n");
	    return EXIT_FAILURE;
	  }
	  else//If open the file successfully
	  {	    
	    fseek(fp, 0, SEEK_SET);
	  
	    while( !feof(fp))//Count the number of string in the file
	    {
	      if(fgetc(fp) == '\n')
	      {
	        str_num = str_num + 1;
	      }
	    }
	    str = malloc(sizeof(char *) * str_num);//Allocate memory for the string array 
	    for(int i = 0; i < str_num; i++)
	    {
	      str[i] = malloc(sizeof(char) * MAX_LENGTH);//Allocate memory for each string
	    }
	    
	    fseek(fp, 0, SEEK_SET);//go to the beginning of the file
	    while( !feof(fp))
	    {
	      for (int idx = 0; idx < str_num; idx ++) 
	      {
	        fscanf(fp, "%s", str[idx]);
	      }
	    }
	    fclose(fp);
	    
	    
	    
	//2. Begin the compare work
	    if(argc == 2)
	    {
	      free;
	    }
	    else if((argc == 3) && (strcmp(argv[3], "-I") == 0) )
	    {
	      free;
	    }
	    else if((argc == 3) && (strcmp(argv[3], "-D") == 0) )
	    {
	      free;
	    }
	    else if((argc == 3) && (strcmp(argv[3], "-VID") == 0) )
	    {
	      free;
	    }
	    else
	    {
	      free;
	    }
	    
	  }
	  return EXIT_SUCCESS;
	}
					

	
}
