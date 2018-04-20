#include "tree.h"

#ifndef USIGN_TO_BIN
// function to create binary values from the input char values
char * UnSig2Bin(unsigned char value) 
{
   // determine the number of bits needed ("sizeof" returns bytes)
	// create mask which you would use for the getting each bit value
	// for loop to mast values and creating char array of bits
  char * bin = NULL;
  bin = malloc(sizeof(char) * NUM_BITS);
  
  int base = 2;
  char digit[3] = "01";
  int remainder = 0;

  for(int idx = NUM_BITS; idx > 0; idx--)
	{
		remainder = value % base;
		value = value / base;
		bin[idx - 1] = digit[remainder];
	}
	
	
	return bin;
}

#endif

#ifndef WRITE_BINARY
//Write a byte to the file
int writeBit(FILE * fptr, unsigned char bit, unsigned char * whichbit, unsigned char * curbyte)
{
	if((*whichbit) == 0)
	{
		//reset
		*curbyte = 0;
	}
	
	//shift the bit to the correct location
	unsigned char temp = bit << (7 - (*whichbit));
	* curbyte |= temp;//store the data
	int value = 0;
	
	//Write current byte if there are 8 bits
	if((* whichbit) == 7)
	{
		int ret;
		ret = fwrite(curbyte, sizeof(unsigned char), 1, fptr);
		
		if(ret == 1)
		{
			value = 1;
		}
		else
		{
			value = -1;
		}
	}
	
	* whichbit = ((* whichbit) + 1) % 8;
	return value;
	
}

static void Tree_headerHelper(TreeNode * root, FILE *outptr, unsigned char * whichbit, unsigned char * curbyte)
{
	//End of tree
	if(root == NULL)
	{
		return;
	}
	
	TreeNode * lc = root->leftChild;
	TreeNode * rc = root->rightChild;
	
	
	//Root is a leaf node
	if((lc == NULL) && (rc == NULL))
	{

		int write_flag = writeBit(outptr, 1, whichbit, curbyte);
				
		//Get convert char from root->data
		char * convert =  UnSig2Bin(root->data); 
		
		//Write convert char to file
		for(int idx = 0; idx < NUM_BITS; idx ++)
		{
			write_flag = writeBit(outptr, (convert[idx] - 48), whichbit, curbyte);

	
		}
		

		
		//Free malloc of convert
		free(convert);
		return;
	}
	
	//Preorder traversal
	writeBit(outptr, 0, whichbit, curbyte);
	Tree_headerHelper(lc, outptr, whichbit, curbyte);
	Tree_headerHelper(rc, outptr, whichbit, curbyte);
			
}




// WriteInOrderBinary takes root and file * as input
// and creates binary representation of the tree as specified in the example
int WritePreOrderBinary(TreeNode * root, FILE *outptr)
{
	unsigned char whichbit = 0;
	unsigned char curbyte = 0;

	Tree_headerHelper(root, outptr, &whichbit, &curbyte);
	
	//Pad '0' to the end of bin
	writeBit(outptr, 0, &whichbit, &curbyte);
	//Insert zero if the current byte has unused bits
	while ( whichbit != 0)
	{
		writeBit(outptr, 0, &whichbit, &curbyte);
	}
	
	//Add newline at the end
	//unsigned char newline = '\n';
	//fwrite(&newline, sizeof(unsigned char), 1, outptr);
	
  return EXIT_SUCCESS;
}

int CreateBinaryFromTree(TreeNode * root, const char *outfile)
{
	int ret;
	FILE * outptr = fopen(outfile, "wb");
	
	if(outptr == NULL)
	{
		return EXIT_FAILURE;
	}
	ret = WritePreOrderBinary(root, outptr);
	
	if(ret != EXIT_SUCCESS)
	{
		printf("Fail to write preorder binary\n");
		return EXIT_FAILURE;
	}
	
	fclose(outptr);
  return ret;
}


#endif





#ifndef CLEAN_TREE

void CleanTree(TreeNode * root)
{
	if(root == NULL)
	{
		return;
	}
	CleanTree(root->leftChild);
	CleanTree(root->rightChild);
	free(root);
}
#endif





#ifndef BINARY_SEARCH_TREE

int IntCompare(const void * val1, const void * val2){
  return (*(unsigned char*)val1 - *(unsigned char*)val2);
}

TreeNode * CreateBinarySearchTree(long randomSeed, long numNodes){
  unsigned char * binArray = malloc(sizeof(unsigned char)*numNodes);
  if(binArray == NULL){
    printf("Memory allocation to array failed\n" );
    return NULL;
  }
  srand(randomSeed);
  // allocate values to array
  for(int index = 0; index < numNodes ; index++){
    binArray[index] = rand() % 256;
  }
  // sort the array
  qsort(binArray, numNodes, sizeof(unsigned char), IntCompare);

  // create bst from the sorted array
  TreeNode * root = CreateBST(binArray, 0, numNodes-1);
  free(binArray);
  return root;

}
// TreeNode *CreateBSTHelper()
TreeNode* CreateTreeNode(unsigned char value){
  TreeNode *newNode = malloc(sizeof(TreeNode));
  newNode->data = value;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  return newNode;
}

TreeNode *CreateBST(unsigned char *sortedArray, int start , int end){
  // int len = sizeof(sortedArray)/sizeof(int);
  if(start > end) return NULL;
  int mid = (start+end)/2;
  TreeNode *newNode = CreateTreeNode(sortedArray[mid]);
  newNode->leftChild = CreateBST(sortedArray, start, mid -1);
  newNode->rightChild = CreateBST(sortedArray, mid +1, end);
  return newNode;

}
#endif
