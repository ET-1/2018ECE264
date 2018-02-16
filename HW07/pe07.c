#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pe07.h"




#ifndef INT
bool IsInteger(char* str, int index)
{
  int nonint = 0;
  index = 0;
  for(int i = index; i < MAX_LENGTH; i++)
  {
    if(!isdigit(str[i]))
    {
      nonint ++;
    }
  }
  if(nonint != 0)
  {
    return false;    
  }
  else
  {
    return true;
  }
  	
}
#endif

#ifndef DOUBLE
bool IsDouble(char* str, int index, bool dot)
{
  int nondigit = 0;
  int dott = 0;
  int dot_idx = 0;
  index = 0;
  
  for(int i = index; i < MAX_LENGTH; i++)
  {
    if(!isdigit(str[i]))
    {
      if(strcmp(str[i], ".") == 0)
      {
        dot_idx = i;
        dot = true;        
        dott ++;
      }
      else
      {
        nondigit ++;
      }
    }
  }
  
  if((nondigit != 0) || (dott != 1) || (dot_idx == 0))
  {
    return true;
  }
  else
  {
    return false;    
  }

}
#endif

#ifndef VALID_ID
bool IsValidIdentifier(char* str, int index)
{
  
	
}
#endif
