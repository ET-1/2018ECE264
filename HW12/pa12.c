#include <stdio.h>
#include <stdlib.h>
#include "pa12.h"

#ifndef INIT
//head: the head of the singly linkedlist.
//length: the length of the singly linkedlist.
//This function will create and initialize the singly linkedlist with length=length, 
//The values of the nodes within the singly linkedlist will be the same as array indices.
//For example, if the singly linkedlist length is 4, the values of the nodes will be 0 1 2 3
void init(struct node **head,int length)
{
	struct node * h = *head;
	if(h == NULL)
	{
		for(int idx = 0; idx < length; idx++)//Initialize a linklist with length
		{
			struct node * n;
			h = *head;
			n = malloc(sizeof(nodeType));//Allocate memory for node n
			n->value = idx;//Set value for node n
			n->next = NULL;
			
			//If h is not empty, insrt node n to the last of h
			if(n != NULL && h != NULL)
			{
	  		while(h->next != NULL)
	  		{
	  			h = h->next;
	  		}
	  		
	  		h->next = n;
	  		n->next = NULL;
			}
			
			//If h is empty, insrt node n to the first
			else if(h == NULL)
			{
				n->next = NULL;
				*(head) = n;
			}
		}
	}
	

}
#endif

#ifndef PRINT
//head: the head of the singly linkedlist.
//This function will print the values of the nodes within the singly linkedlist.
//For example, if the values of the nodes within the singly linkedlist are 1 5 6 8 9 10, this function will print 1,5,6,8,9,10
//Note: there is no extra comma nor at the beginning nor at the end.
void print(struct node** head)
{
	struct node * h = *head;
	
	//while h is not the last node, print the value of node and go to the next node  
	while(h != NULL)
	{
	 	printf("%d", h->value);
	 	h = h->next;
	 	
	 	//If h is not the node before the last node, print "comma". 
	 	if(h != NULL)
	 	{
	 	 	printf(",");
	 	}
	 	else
	 	{
	 		printf("\n");
	 	}
	}
}
#endif

#ifndef JOSPI
//head: the head of the singly linkedlist.
//k : this variable will be used for counting if count = k, the element will be out.
//p : this variable will be used for printing if the number of remaining elements/nodes is divisible by p (call the print function).
//length: the length of the singly linkedlist.
//This function will solve the josephus problem using the singly linkedlist.
void josp(struct node ** head,int k,int p,int length)
{
	init(head, length);
	int remain = length;
	int count = 0;
	struct node * temp = NULL;
	struct node * h = *head;
		
	//If there are more than one node in the linklist, go to the loop	
	while(remain > 1)
	{
		count = 0;//Initialize the count 
		
		while(count < (k + 1))
		{
			//If h is the last node, go to the head of the linklist
			if(h == NULL)
			{
				h = *head;
			}
			
			//If count equals skip number.
			if(count == k)
			{
			
				//If the node is not the first node, connect the tail of last node and head of next node				
				if(temp->next != NULL)
				{
					temp->next = h->next;
					free(h);
					h = temp->next;
					remain --;
					count ++;
				}
				
				//If the node is the first node, remove the first node. Repoint to the head node 
				else
				{
					*head = h->next;
					free(h);
					h = *head;
					remain --;
					count ++;
				}
			}
			//If count not equal skip number, go to next node, count ++ 
			else
			{
				count ++;
				temp = h;
				h = h->next;
				
			}
		}
		
		//If remain number can be divided by p, print the linklist 
		if(remain % p == 0)
		{
			print(head);
		}
	}
	
	//Free the linklist
	h = *(head);
  struct node * orglast = NULL;
  
 	while(h != NULL)
 	{    	
 		orglast = h;
   	h = h->next;    
  	free(orglast);
 	}

	


}

#endif


#ifndef INITII
//head: the head of the doubly linkedlist.
//length: the length of the doubly linkedlist.
//This function will create and initialize the doubly linkedlist with length=length, 
//The values of the nodes within the doubly linkedlist will be the same as array indices.
//For example, if the doubly linkedlist length is 4, the values of the nodes will be 0 1 2 3
//NOTE: this is a doubly linkedlist you should assign the prev pointer for each node probably.
//NOTE: head->prev is NULL as well as tail->next.

void init2(struct dnode ** head,int length)
{
	


}
#endif


#ifndef PRINTII
//head: the head of the doubly linkedlist.
//This function will print the values of the nodes within the doubly linkedlist.
//For example, if the values of the nodes within the doubly linkedlist are 1 5 6 8 9 10, this function will print 1,5,6,8,9,10
//Note: there is no extra comma nor at the beginning nor at the end.
void print2(struct dnode ** head)
{
	


}

#endif


#ifndef JOSPII
//head: the head of the doubly linkedlist.
//k : this variable will be used for counting if count = k, the element will be out.
//q : this variable will be used for flipping the direction. If while counting, the value of the node is divisible by q,
//you will take the node out, flip the direction, and continue counting.
//length: the length of the doubly linkedlist.
//This function will solve the modified josephus problem using the doubly linkedlist.
//NOTE: you should call the print2() function after any delete operation.
void josp2(struct dnode **head, int k, int q,int length)
{
	

}

#endif




