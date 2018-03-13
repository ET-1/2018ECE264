#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pe10.h"




#ifndef PRINT
// This function will print the boolean array with length=len in the following format.
// It will print out the index if its corresponding value in the array is true, Otherwise it will print X instead.
// If the array is of length 4, and it has values of true(index=0),false(index=1),true(index=2),false(index=3)
// the output looks like this: 0,X,2,X
// ::::::::IMPORTANT NOTES:::::::
// 1- There should be no extra comma at the end nor at the beginning, "Violating this format will get you zero".
// 2- Make sure that there is a new line at the end of the output (i.e printf("\n")). 
void print(bool * arr,int len)
{
  //Print out the array based on TRUE or FALSE. If it is TRUE, print its index. Otherwise, print 'X' instead.
  for(int i = 0; i < len; i ++)
  {
		if(arr[i] == true)
		{
		  printf("%d", i);
		}
		else
		{
		  printf("X");
		}
		
		if(i < len - 1)
		{
		  printf(",");
		}
  }
	
	
	
}
#endif


#ifndef JOSEPHUS
// arr: a boolean array which you should initialized to 1's in the main.c.
// len: the length of the array
// k:   the numbers of elements you should skip
// p:   if the number of remaining elements in the array after each step is divisible by p, then you need to print the array.
// Your function should stop when it has only one element left.
void josephus(bool * arr, int len, int k,int p)
{
  int remain = len;
  int idx = 0;
  int count = 0;
  
  while(remain != 1)//If there are remaining number in the array
  {
    count = 0;//Reset the count for true number
    
    while(count < (k + 1) )//If true number count is smaller than skip number
    {
      if(  idx % len  == 0 && idx >= len )//Back to head of array if the index is out of range of array
      {
        idx = 0;
      }
      
      
      if(count == k )//If true number count equals skip number, set that number to false
      {
        while(arr[idx] != true)//If that number is already false, go to next true number 
        {
          idx ++;
          
          if(  idx % len  == 0 && idx >= len )
      		{
        		idx = 0;
      		}
        }
        
        arr[idx] = false;
        remain --;
        idx ++;
        count ++;
      }

      else if(arr[idx] == true && count != k)
      {
        idx ++;
        count ++;
      }
      
      else if(arr[idx] == false && count != k)
      {
        idx ++;
      }      


    }

		  	
  	if((remain % p) == 0)//Print out the array based on the divided number
  	{
  	  print(arr, len);
  	  printf("\n");
  	}
  }
	 

}
#endif
