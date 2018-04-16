#include "tree.h"
#include "list_node.h"
#include "frequency.h"

#ifndef MAIN_FUNC

int main(int argc, char **argv)
{
  // Create CharFreq array
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
		// initialize all the frequencies inside freq array to be 0
		for(int idx = 0; idx < NUMLETTER; idx ++)
		{
			frequency[idx].data = '0';		
			frequency[idx].freq = 0;
		}

 	  // count frequency by calling CountFrequency function and passing the input filename
		filename = argv[1];
  	num_char = CountFrequency(filename, frequency);
  	
  //2a. if return value from the function is not success, return exit failure
  	if(num_char == 0)
  	{
  		printf("Wrong arguments\n");
  		return EXIT_FAILURE;
  	}
  
  	// sort frequencies by calling SortFrequency function
  	SortFrequency(frequency);
  	
  	// build linked list sorted linked list
  	ListNode * head = ListBuild(frequency);
  	
  	// Get two minimum frequencies and merge them and reduce one list node - call BuildHuffmanTree.
  	head = BuildHuffmanTree(head);
  	
  	// Print the final huffman tree in prefix by calling the print function - call the prefix print function
  	PrefixTreePrint(head->treeNodePtr, 1);
  
  	// Free all the memory allocated  
  	CleanTree(head->treeNodePtr);
  	CleanList(head);
  	
  }

  return EXIT_SUCCESS;
}
#endif
