#include <stdio.h>
#include <stdlib.h>
#include "pa08.h"

#ifndef CDOUBLE
void createDouble(char * string,DoubleVar* var,int index,bool dot,int len)
{
  int sel = 0;
  int start = var->digit_start;
  int end = var->digit_end;
    
    //Do the recursion starting from start to end
    if(index == len)
    {
      //If the length of the string is larger than 3, print out each string  
      for(int i = 0; i < len; i++)
      {
        printf("%c", string[i]);
      }
      printf("\n");
      return;
    }
    else
    {
      for(sel = start; sel <= end; sel++)
      {
        
        string[index] = sel + '0';
        createDouble(string, var, index + 1, false, len);
      }
      
    }
}

  

#endif

#ifndef CVID
void createVID(char * string,VIDVar * var,int index,int len)
{
	
}
#endif

