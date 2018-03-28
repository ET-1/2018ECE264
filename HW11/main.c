#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe11.h"
#define MAX_LENGTH 100

int main(int argc, char **argv) 
{
  FILE * fptr;
  char oneline[MAX_LENGTH];
  char * space = " ";
  char * token;
  int v = 0;
  int i = 0;
  int position = 0;
  
  struct node * head;
  head = NULL;
  
  
  if(argc != 2)
  {
    return EXIT_FAILURE;
  }
   
  else
  {
    fptr = fopen(argv[1], "r");
    
    if(fptr == NULL)
    {
      return EXIT_FAILURE;
    }
    else
    {
      fseek(fptr, 0, SEEK_SET);
      
      while(fgets(oneline, MAX_LENGTH, fptr) != NULL)
      {
      	token = strtok(oneline, space);
      	
      	if(strcmp(token, "insF") == 0)//Insert to the first
      	{
      	  position = 0;
      	  while(token != NULL)
      	  {
      	    token = strtok(NULL, space);
      	    position ++;
      	    
      	    if(position == 1)
      	    {
      	      v = atoi(token);
      	    }
      	  }
      	  
      	  struct node * n;
      	  n = malloc(sizeof(nodeType));
      	  n->value = v;
      	  n->next = NULL;
      	  insertFirst(&head, n);
      	  print(&head);
      	  
      	}
      	
      	else if(strcmp(token, "insL") == 0)//Insert to the last
      	{
      		position = 0;
      	  while(token != NULL)
      	  {
      	    token = strtok(NULL, space);
      	    position ++;
      	    
      	    if(position == 1)
      	    {
      	      v = atoi(token);
      	    }
      	  }
      	  
      	  struct node * n;
      	  n = malloc(sizeof(nodeType));   	  
      	  n->value = v;
      	  n->next = NULL;
      	  insertLast(&head, n);
      	  print(&head);
      	}
      	
      	else if(strcmp(token, "insA") == 0)//Insert to specific point
      	{
      	  position = 0;
      	  while(token != NULL)
      	  {
      	    token = strtok(NULL, space);
      	    position ++;
      	    
      	    if(position == 1)
      	    {
      	      v = atoi(token);
      	    }
      	    else if(position == 2)
      	    {
      	    	i = atoi(token);
      	    }      	    
      	  }
      	  
      	  if(i <= getLength(&head) && i >= 0)
      	  {
      	  	struct node * n;
      	  	n = malloc(sizeof(nodeType));
      	  	n->value = v;
      	  	n->next = NULL;      	  
      	  	insertAt(&head, n, i);
      	  }      	  
      	  		print(&head);        	  
      	}
      	
      	else if(strcmp(token, "delFM") == 0)//Delete the first match
      	{
      		position = 0;
      	  while(token != NULL)
      	  {
      	    token = strtok(NULL, space);
      	    position ++;
      	    
      	    if(position == 1)
      	    {
      	      v = atoi(token);
      	    }      	    
      	  }
      	  deleteFirstMatch(&head, v);
      	  print(&head);
      	}
      	
      	else if(strcmp(token, "delAM") == 0)//Delete all matches
      	{
      		position = 0;
      	  while(token != NULL)
      	  {
      	    token = strtok(NULL, space);
      	    
      	    position ++;
      	    
      	    if(position == 1)
      	    {
      	      v = atoi(token);
      	    }      	    
      	  }

      	  deleteAllMatches(&head, v);
      	  print(&head);      	        	      	
      	}
      	
      	else if(strcmp(token, "delA") == 0)//Delete the specific point
      	{
      		position = 0;
      	  while(token != NULL)
      	  {      	  
      	    token = strtok(NULL, space);
      	    position ++;
      	    
      	    if(position == 1)
      	    {
      	      i = atoi(token);
      	    }      	    
      	    
      	  }
      	  
      	  if(i <= (getLength(&head) - 1) && i >= 0)
      	  {
      	  	deleteAt(&head, i);

      	  }
      	  	print(&head);      	  
      	}
      	
      	else if(strcmp(token, "L") == 0)//Print the length of linklist
      	{
      	  int length = getLength(&head);
      	  printf("%d\n", length);
      	}
      	  	
      }
    }
    
  }
  fclose(fptr);    	
	freeMemory(&head);
	return EXIT_SUCCESS;
}
