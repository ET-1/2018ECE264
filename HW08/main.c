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
	    free(Dvar);
	    free(string);
	  
	  }
	  
	  

		if((argc == 9) && (strcmp(argv[1], "-VID") == 0))//Go to create VID mode
	  {
	    //1. Setup for the parameters extracted from argv
	    Dvar->lower_case_start = argv[2][0];
	    Dvar->lower_case_end = argv[3][0];
	    Dvar->upper_case_start = argv[4][0];
	    Dvar->upper_case_end = argv[5][0];
	    Dvar->digit_start = argv[6][0];
	    Dvar->digit_end = argv[7][0];
			len = (int) strtol(argv [8], NULL, 10) ;
				    
	    string = malloc(sizeof(char) * len);
	    for(int u = 0; u < len; u++)
	    {
	      string[u] = 0;
	    }
	    
	    
	    //2. Excute the createVID function for VID mode
	    for(int k = 1; k < (len + 1); k++)
	    {
	      createVID(string, Dvar, 0, k);
	    }
	    free(Dvar);
	    free(var);
	    free(string);
	  
	  }
	  
	}
	
	return EXIT_SUCCESS;
}
