#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa12.h"




int main(int argc, char **argv)
{
	struct node * head = NULL;
	if(argc != 5)
	{
		return EXIT_FAILURE;
	}
	else
	{
		int length = atoi(argv[2]);
		int k = atoi(argv[3]);
		int p = atoi(argv[4]);
		
		if(strcmp(argv[1], "-J") == 0)
		{
			josp(&head, k, p, length);
		}
	}
	
	return EXIT_SUCCESS;
}
