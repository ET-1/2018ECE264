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
  int lc_start = Dvar->lower_case_start - 'a';
  int lc_end = Dvar->lower_case_end - 'a';
  int uc_start = Dvar->upper_case_start - 'A';
  int uc_end = Dvar->upper_case_end - 'A';
  int dg_start = Dvar->digit_start - '0';
  int dg_end = Dvar->digit_end - '0';
  int num_lc = lc_end - lc_start + 1;
  int num_uc = uc_end - uc_start + 1;
  int num_dg = dg_end - dg_start + 1;
  int num_char = num_lc + num_uc + num_dg + 1;
  int num_id = num_lc + num_uc + 1;
   
  
    //If the index equals the required length, print out the strings and return 
    
    if(index == len)
    {   
      for(int i = 0; i < len; i++)
      {
        printf("%c", string[i]);
      }
      printf("\n"); 
      return;
    }
    
    //If the index is less than the required length, do recursion to select character ranging from start to end
    else
    {       
      if(index == 0)//If index is 0, do not choose digit
      {
        for(sel = 0; sel < num_id; sel++)
        {
          if(sel < num_lc)//Choose the lowercase character
          {
            string[index] = sel + 'a' + lc_start;
            createVID(string, Dvar, index + 1, len);
          }
          else if(sel < (num_lc + num_uc))//Choose the uppercase character
          {
            string[index] = sel + 'A' - num_lc + uc_start;
            createVID(string, Dvar, index + 1, len);            
          }
          else//Choose the underscore
          {
            string[index] = '_';
            createVID(string, Dvar, index + 1, len);            
          }
        }
      }
      
      else//If index is not 0, choose all possible character
      {
        for(sel = 0; sel < num_char; sel++)
        {
          if(sel < num_lc)//Choose the lowercase character
          {
            string[index] = sel + 'a' + lc_start;
            createVID(string, Dvar, index + 1, len);
          }
          else if(sel < (num_lc + num_uc))//Choose the uppercase character
          {
            string[index] = sel + 'A' - num_lc + uc_start;
            createVID(string, Dvar, index + 1, len);            
          }
          else if(sel < (num_lc + num_uc + num_dg))//Choose the digit
          {
            string[index] = sel + '0' - num_lc - num_uc + dg_start;
            createVID(string, Dvar, index + 1, len);          
          }
          else//Choose the underscore
          {
            string[index] = '_';
            createVID(string, Dvar, index + 1, len);            
          }
        }
      }
    }    
    
    
	
}


#endif








