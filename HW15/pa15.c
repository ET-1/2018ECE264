#include "pa15.h"

#ifndef MAIN_FUNC


//Main function:










int main(int argc, char **argv)
{
	//1. if the arguments != 4 then print "Wrong arguments\n" and return EXIT_FAILURE
	if(argc != 4)
	{
		printf("Wrong arguments\n");
		return EXIT_FAILURE;
	}
	
	//2. 1st input is long value using random seed needed for the generating the binary search tree
	char * checkSeed = NULL;
	long randomSeed = strtol(argv[2], &checkSeed, 10);
	
	//3. 2nd input is long values - which is number of nodes for the binary search tree
	char * checkNodes = NULL;
	long numNodes = strtol(argv[3], &checkNodes, 10);
	
	//4. If the random seed or number of nodes input is wrong - Print "Wrong inputs\n" and return EXIT_FAILURE
	errno = 0;
	fail1 = (checkSeed == argv[2]);
	fail2 = (checkNodes == argv[3]);
	fail3 = ((randomSeed == LONG_MAX || randomSeed == LONG_MIN) && errno == ERANGE);
	fail4 = ((numNodes == LONG_MAX || numNodes == LONG_MIN) && errno == ERANGE);
	
	if(fail1 || fail2 || fail3 || fail4 || numNodes < 0)
	{
		printf("Wrong inputs\n");
		return EXIT_FAILURE;
	}
	
	
	//5. Call CreateBinarySearchTree function to get the tree
	TreeNode * tree = CreateBinarySearchTree(randomSeed, numNodes);
	
	//6. If tree is not generated and you get NULL from it, then print "Binary Create Failed \n" and return EXIT_FAILURE
	if(tree == NULL)
	{
		printf("Binary Create Failed \n");
		return EXIT_FAILURE;
	}
	
	
	//7. 3rd input is output filename, in which output needs to be printed
	char * filename = argv[4];
	
	
	//8. if file read fails, free memory and return EXIT_FAILURE
	FILE * fptr = fopen(filename, "w");
	if(fptr == NULL)
	{
		CleanTree(tree);
		return EXIT_FAILURE;
	}
	
	fclose(fptr);
	
 	return EXIT_SUCCESS;

}
#endif
