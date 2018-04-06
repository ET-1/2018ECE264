#include "frequency.h"

// Step 1. - Create/ Define data structre in frequency.h such that it can hold character of 256 bytes
// Step 2. - Complete function in frequency.c file
// Step 3. - Complete main function
// Step 4. - Test all the test cases 


int main(int argc, char **argv)
{
  //0. Create array of CharFreq
  CharFreq frequency[NUMLETTER];
  char * filename = NULL;
  int num_char = 0;
	
	if(argc != 2)
	{
		printf("Wrong arguments\n");
		return EXIT_FAILURE;
	}
	else
	{
  //1. initialize all the frequencies inside freq array to be 0
		//frequency = malloc(sizeof(CharFreq)*NUMLETTER);
		
		for(int idx = 0; idx < NUMLETTER; idx ++)
		{
			frequency[idx].data = '0';		
			frequency[idx].freq = 0;
		}

  //2. Count Frequency from the the input file
		filename = argv[1];
  	num_char = CountFrequency(filename, frequency);
  	
  //2a. if return value from the function is not success, return exit failure
  	if(num_char == 0)
  	{
  		return EXIT_FAILURE;
  	}
  
  //3. Sort frequencies that you get
  	SortFrequency(frequency);
  
  //4. Print the frequencies on terminal
  	PrintFreq(frequency);
  	
  }
  //free(frequency);
  return EXIT_SUCCESS;
}
