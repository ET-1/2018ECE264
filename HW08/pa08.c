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
    if((index == len))
    {
      for(int i = 0; i < len; i++)
      {
        if(string[i] == '.')
        {
          dot = true;
        }
      }
      
      //If the length of the string is larger than 3, print out each string 
      if(dot == true)
      { 
        for(int i = 0; i < len; i++)
        {
          printf("%c", string[i]);
        }
        printf("\n");
      }
      return;
    }
    else
    { 
      for(int pos = 1; pos <= (len -2); pos++)
      {
        if((index == pos) && (dot != true))
        {
          string[index] = '.';
          createDouble(string, var, index + 1, true, len);
        }
        else
        {
          for(sel = start; sel <= end; sel++)
          {
            string[index] = sel + '0';
            //var->digit_start = var->digit_start + 1;
            createDouble(string, var, index + 1, false, len);
          }
        }
      }
    }
      
}

  

#endif

#ifndef CVID
void createVID(char * string,VIDVar * var,int index,int len)
{
	
}
#endif

