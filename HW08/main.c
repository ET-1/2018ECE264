#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa08.h"


int main(int argc, char *argv[]) 
{
	DoubleVar * var;
	int len = 0;
	char * string;
	var = malloc(sizeof(DoubleVar) * 1);
	if(argc < 5)//If arguments are not sufficient
	{
	  return EXIT_FAILURE;//Return failure
	} 
	else//If arguments are sufficient
	{
	  if((argc == 5) && (strcmp(argv[1], "-D") == 0))
	  {
	    //1. Setup for the parameters extracted from argv
	    var->digit_start = (int) strtol(argv [2], NULL, 10) ;
	    var->digit_end = (int) strtol(argv [3], NULL, 10) ;
	    len = (int) strtol(argv [4], NULL, 10) ;
	    string = malloc(sizeof(char) * len);
	    for(int i = 0; i < len; i++)
	    {
	      string[i] = 0;
	    }
	    
	    //2. Excute the createDouble function for Double mode
	    for(int j = 3; j < (len + 1); j++)
	    {
	      createDouble(string, var, 0, false, j);
	    }
	    free(var);
	    free(string);
	  
	  }
	  //3. Excute the createVID function for VID mode
	  
	}
	
	return EXIT_SUCCESS;
}
