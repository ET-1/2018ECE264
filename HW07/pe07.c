#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
#include "pe07.h"




#ifndef INT
bool IsInteger(char* str, int index)
{
  
  if(*str == '\0')
  {
    return true;//If there is no non-integer numbers, return true
  }
  else
  {
    if(isdigit(*str))//If current character is a digit, do recursion
    {
      return IsInteger(++str, ++index);//Go to check next character
    }
    else
    {
      return false;//If there is any non-integer numbers, return false
    }
  }	
}
#endif

#ifndef DOUBLE
bool IsDouble(char* str, int index, bool dot)
{
  int idx = 0;
  while(str[idx] != '\0')
  {
    idx ++;
  }
  
  if((*str == '\0') && (dot == true))
  {
    return true;
  }
  else
  {
	  if(isdigit(*str))
	  {
	    if(dot == false)
	    {
	      return IsDouble(++str, ++index, false);
	    }
	    else
	    {
	      return IsDouble(++str, ++index, true);	      
	    }
	  }	  
	  else
	  {
	    if(*str == '.')
	    {
	      if((index != 0) && (dot != true) && (str[1] != '\0'))
	      {
	        return IsDouble(++str, ++index, true);
	      }
	      else
	      {
	        return false;
	      }
	    }
	    else
	    {
	      return false;
	    }
	  }
	}
}  


#endif

#ifndef VALID_ID
bool IsValidIdentifier(char* str, int index)
{
  if(*str == '\0')
  {
    return true;
  }
  else
  {
    if(isalpha(*str))
    {
      return IsValidIdentifier(++str, ++index);
    }
    
    
    else if(isdigit(*str))
    {
      if(index == 0)
      {
        return false;
      }
      else
      {
        return IsValidIdentifier(++str, ++index);
      }
    }
    
    
    else if(*str == '_')
    {
      return IsValidIdentifier(++str, ++index);
    }
    
    
    else
    {
      return false;
    }
  }
}
#endif














