#include <stdio.h>
#include <stdlib.h>
#include "pa08.h"

#ifndef CDOUBLE
void createDouble(char * string,DoubleVar* var,int index,bool dot,int len)
{
  int sel = 0;
  int start = var->digit_start;
  int end = var->digit_end;
   
    //If the index equals the required length, print out the strings and return 
    
    if(index == len)
    {   
      if(dot == true)//Only print out strings with dot
      { 
        for(int i = 0; i < len; i++)
        {
          printf("%c", string[i]);
        }
        printf("\n");
      }
      return;
    }
    
    //If the index is less than the required length, do recursion to select character ranging from start digit to end digit
    else
    { 
      for(int pos = 1; pos <= (len -2); pos++)//Insert the dot for strings without dot
      {
        if((index == pos) && (dot != true))
        {
          string[index] = '.';
          createDouble(string, var, index + 1, true, len);
        }
      }
      
      if(dot == true)//If dot flag is on
      {
        for(sel = start; sel <= end; sel++)//Insert the digit for strings in each recursion
        {
          string[index] = sel + '0';
          createDouble(string, var, index + 1, true, len);
        }
      }
      
      else//If dot flag is off
      {
        for(sel = start; sel <= end; sel++)//Insert the digit for strings in each recursion
        {
          string[index] = sel + '0';
          createDouble(string, var, index + 1, false, len);
        }
      }
    }
}
      

  

#endif

#ifndef CVID
void createVID(char * string,VIDVar * Dvar,int index,int len)
{
  int sel = 0;
  int lc_start = Dvar->lower_case_start;
  int lc_end = Dvar->lower_case_end;
  int uc_start = Dvar->upper_case_start;
  int uc_end = Dvar->upper_case_end;
  int start = var->digit_start;
  int end = var->digit_end;  
  
    //If the index equals the required length, print out the strings and return 
    
    if(index == len)
    {   
      if(dot == true)//Only print out strings with dot
      { 
        for(int i = 0; i < len; i++)
        {
          printf("%c", string[i]);
        }
        printf("\n");
      }
      return;
    }
    
    //If the index is less than the required length, do recursion to select character ranging from start digit to end digit
    else
    {       
      if(index == 0)//If dot flag is on
      {
        for(sel = start; sel <= end; sel++)//Insert the digit for strings in each recursion
        {
          if()
          string[index] = sel + '0';
          createDouble(string, var, index + 1, true, len);
        }
      }
      
      else//If dot flag is off
      {
        for(sel = start; sel <= end; sel++)//Insert the digit for strings in each recursion
        {
          string[index] = sel + '0';
          createDouble(string, var, index + 1, false, len);
        }
      }
    }    
    
    
	
}
#endif








