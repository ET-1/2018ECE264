#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
#include "pe07.h"




#ifndef INT
bool IsInteger(char* str, int index)
{
  
  if(*str == '\0')//End of the string
  {
    return true;//If there is no non-integer numbers, return true
  }
  else//Not the end of the string
  {
    if(isdigit(*str))//If current character is a digit, do recursion
    {
      return IsInteger(str + 1, index + 1);//Go to check next character
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
  while(str[idx] != '\0')//Not the end of the string, go to next recursion
  {
    idx ++;
  }
  
  if((*str == '\0') && (dot == true))//End of the string and only one dot
  {
    return true;
  }
  else//Not the end of the string
  {
	  if(isdigit(*str))//If string is a digit
	  {
	    if(dot == false)//If no dot before
	    {
	      return IsDouble(str + 1, index + 1, false);//Go to next recursion with dot is false
	    }
	    else//If there is a dot before
	    {
	      return IsDouble(str + 1, index + 1, true);//Go to next recursion with dot is true	      
	    }
	  }	  
	  else//If string is not a digit
	  {
	    if(*str == '.')//If string is a dot
	    {
	      if((index != 0) && (dot != true) && (str[1] != '\0'))//If the dot is not at first and not at last and there is no dot before
	      {
	        return IsDouble(str + 1, index + 1, true);//Go to the next recursion with dot is true
	      }
	      else
	      {
	        return false;//Break the last rule, not a double
	      }
	    }
	    else
	    {
	      return false;//Not a digit, not a double
	    }
	  }
	}
}  


#endif

#ifndef VALIDID
bool IsValidIdentifier(char* str, int index)
{
  if(*str == '\0')//End of the string, it's a identifier
  {
    return true;
  }
  else//Not at the end of the string
  {
    if(isalpha(*str))//If the string is not a  alphabe
    {
      return IsValidIdentifier(str + 1, index + 1);//Go to the next recursion
    }
    
    
    else if(isdigit(*str))//If the string is not a digit
    {
      if(index == 0)//If the first element is digit, not identifier
      {
        return false;
      }
      else//Else go to the next recursion 
      {
        return IsValidIdentifier(str + 1, index + 1);
      }
    }
    
    
    else if(*str == '_')//If the string is "_"
    {
      return IsValidIdentifier(str + 1, index + 1);//Go to next recursion
    }
    
    
    else//If the string is not "_" or digit, not a identifier
    {
      return false;
    }
  }
}
#endif














