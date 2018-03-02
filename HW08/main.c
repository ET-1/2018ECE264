#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa08.h"


int main(int argc, char *argv[]) 
{
	DoubleVar * var;
	VIDVar * Dvar;
	int len = 0;
	char * string;
	var = malloc(sizeof(DoubleVar) * 1);
	Dvar = malloc(sizeof(VIDVar) * 1);
	
	if(argc < 5)//If arguments are not sufficient
	{
	  return EXIT_FAILURE;//Return failure
	} 
	
	else//If arguments are sufficient
	{
	  if((argc == 5) && (strcmp(argv[1], "-D") == 0))//Go to create double mode
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
	  
	  
	  
		/*//Go to create double mode
		if((argc == 5) && (strcmp(argv[1], "-VID") == 0))//Go to create double mode
	  {
	    //1. Setup for the parameters extracted from argv
	    Dvar->lower_case_start = (int) strtol(argv [2], NULL, 10) ;
	    Dvar->lower_case__end = (int) strtol(argv [3], NULL, 10) ;
	    Dvar->upper_case_start = (int) strtol(argv [4], NULL, 10) ;
	    Dvar->upper_case_end = (int) strtol(argv [5], NULL, 10) ;
	    Dvar->digit_start = (int) strtol(argv [6], NULL, 10) ;
	    Dvar->digit_end = (int) strtol(argv [7], NULL, 10) ;
			len = (int) strtol(argv [8], NULL, 10) ;
				    
	    string = malloc(sizeof(char) * len);
	    for(int i = 0; i < len; i++)
	    {
	      string[i] = 0;
	    }
	    
	    
	    //2. Excute the createDouble function for Double mode
	    for(int j = 1; j < (len + 1); j++)
	    {
	      createDouble(string, Dvar, 0, false, j);
	    }
	    free(Dvar);
	    free(string);
	  
	  }*/
	  
	}
	
	return EXIT_SUCCESS;
}
