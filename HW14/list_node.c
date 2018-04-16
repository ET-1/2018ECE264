#include "list_node.h"

// Create the list node from treenode as input
#ifndef LIST_CREATE
ListNode * ListNodeCreate(TreeNode * treenode)
{
	ListNode * ln = malloc(sizeof(ListNode));
	ln->next = NULL;
	ln->treeNodePtr = treenode;
  return ln;
}

#endif

#ifndef LIST_BUILD
ListNode * ListBuild(CharFreq * freqArray)
{
  // find the first index with non-zero frequency
  // if all are character have zero freq then return nothing
  int idx = 0;
  while(freqArray[idx].freq == 0)
  {
  	idx ++;
  }
  
  if(idx == NUMLETTER)
  {
  	return NULL;
  }
  
  ListNode * head = NULL;
  // build the linked list such that lower frequency comes first and then higher
  while(idx < NUMLETTER)
  {
  	TreeNode * tn = TreeNodeCreate(freqArray[idx].data, freqArray[idx].freq);
  	ListNode * ln = ListNodeCreate(tn);
  	head = ListInsert(head, ln);
  	idx ++;
  }
  return head;
}
#endif




#ifndef LIST_INSERT

ListNode * ListInsert(ListNode * head, ListNode * listNode){
  // insert such that lower frequency comes before the already inserted frequency
  // if the frequencies are same for the nodes, then inserted node should come after the compared node
  if(head == NULL)
  {
  	return listNode;
  }
  
  if(listNode == NULL)
  {
  	printf("ERROR ! ln is NULL\n");
  }
  
  if((listNode->next) != NULL)
  {
  	printf("ERROR ! ln -> next is not NULL\n");
  }
  
  int freq1 = (head->treeNodePtr)->freq;
  int freq2 = (listNode->treeNodePtr)->freq;
  
  if(freq1 > freq2)
  {
  	listNode->next = head;
  	return listNode;
  }
  
  head->next = ListInsert(head->next, listNode);
  return head;
}

#endif

#ifndef LIST_CLEANd

void CleanList(ListNode *head)
{
  // clean the ListNode
  ListNode * temp = NULL;
  if(head == NULL)
  {
  	return;
  }
  while(head != NULL)
  {
  	temp = head;
  	head = temp->next;
  	free(temp);
  }
}

#endif

#ifndef HUFFMAN_BUILD
// builds the huffman tree from the linked list
ListNode * BuildHuffmanTree(ListNode *head)
{
	if(head == NULL)
	{
		return 0;
	}
	
	while((head->next) != NULL)
	{
		ListNode * second = head->next;
		// second must not be NULL , otherwise , will not enter
		ListNode * third = second->next;
		// third may be NULL
		// get the tree nodes of the first two list nodes
		TreeNode * tn1 = head->treeNodePtr;
		TreeNode * tn2 = second->treeNodePtr;
		// remove the first two nodes
		free(head);
		free(second);
		head = third;
		TreeNode * mrg = TreeMerge(tn1, tn2);
		ListNode * ln = ListNodeCreate(mrg);
		head = ListInsert(head, ln);
	}
	
  return head;
}

#endif
