#include "frequency.h"

// Counting the frequencies of the characters in the frequency table
#ifndef COUNT_FREQ
int CountFrequency(char * filename, CharFreq * freq)
{
  // as compared to HW13 please do not exclude newline character.
  // open the file
  int count = 0;
  FILE * fptr;
  fptr = fopen(filename, "r");
  if(fptr == NULL)
  {
  	return EXIT_FAILURE;
  }
  // get through each element of the file and get each character
	
  while (! feof(fptr))
  {
  	int onechar = fgetc(fptr);
  	if(onechar != EOF)
  	{
  		freq[onechar].data = (char) onechar;
  		freq[onechar].freq ++;
  		count ++;
  		
  	}
  }
  // read each character from the file
  fclose(fptr);
  return count;
  
  // put the value in the freq table except for the newline character i.e '\n'
}

#endif

static int compareFreq ( const void * p1 , const void * p2 )
{
	const CharFreq * ip1 = ( const CharFreq *) p1 ;
	const CharFreq * ip2 = ( const CharFreq *) p2 ;
	const int iv1 = ip1 -> freq ;
	const int iv2 = ip2 -> freq ;
	return ( iv1 - iv2 ) ;
}

#ifndef SORT_FREQ


// Sort function for sorting frequencies
void SortFrequency(CharFreq * freq)
{
	// sort the frequencies in the ascending order
	qsort(freq, NUMLETTER, sizeof(CharFreq), compareFreq);
	// if frequencies are same then the character with lower ascii value will be first
}
#endif

