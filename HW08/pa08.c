#include <stdio.h>
#include <stdlib.h>
#include "pa08.h"

#ifndef CDOUBLE
void createDouble(char * string,DoubleVar* var,int index,bool dot,int len)
{
  int sel = 0;
  int start = var->digit_start;
  int end = var->digit_end;
  if(index >= 2)
  {
    if(index < len)
    {
      for(int i = 0; i < len; i++)
      {
        printf("%c", string[i]);
      }
      printf(",");
      
    }
      return;
  }
  for(sel = start; sel < (end + 1); sel++ )
  {
    if(dot == true)
    {
      string[index] = '.';
    }
    else
    {
      string[index] = sel + '0';
    }
    
    if((index != (len - 1)) && (dot != true))
    {
      createDouble(string, var, index + 1, true, len);
    }
    else
    {
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

