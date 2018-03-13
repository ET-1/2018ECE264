#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pe10.h"


int main(int argc, char **argv) 
{
  int length = 0;
  int skip = 0;
  int divide = 0;
  bool * arr = NULL;
  
  if(argc != 4)//If the input arguments are not 4, return FAILURE
  {
    return EXIT_FAILURE;
  }
  
  else//Otherwise, excute josephus function
  {
    length = atoi(argv[1]);
    skip = atoi(argv[2]);
    divide = atoi(argv[3]);
    arr = malloc(sizeof(bool) * length);
    
    for(int i = 0; i < length; i ++)
    {
      arr[i] = true;
    }
    
    josephus(arr, length, skip, divide);
    free(arr);    
  }

	
	return EXIT_SUCCESS;
}
