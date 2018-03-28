#include <stdio.h>
#include <stdlib.h>
#include "pe11.h"

#ifndef PRINT
void print(struct node** head)
{
	struct node * h = *(head);
	
  if(h == NULL)
  {
  	printf("\n");
  }
  
  else
  {
		while(h != NULL)
		{
	 		printf("%d", h->value);
	 	 	h = h->next;
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
}
#endif

#ifndef INSF
void insertFirst(struct node** head,struct node * n)
{
  
  if(n != NULL)
  {
    n->next = *(head);
		*(head) = n;
	}
}
#endif

#ifndef INSA
void insertAt(struct node** head,struct node * n,int index)
{
	struct node * h = *(head);
	struct node * orglast = NULL;
	int count = 0;
	
	if(n != NULL && h != NULL)
	{
		if(index == 0)
		{
		  insertFirst(head, n);
		}
		else if(index <= getLength(head) && index >= 0)
		{
			while(h != NULL && count != index)
			{
		  	orglast = h;
				h = h->next;
				count ++;		
			}
			if(count == index)
			{	
				orglast->next = n;
				n->next = h;
			}
		}		
		
	}
	else if(h == NULL)
	{
		if(index == 0)
		{
			insertFirst(head, n);
		}
	}
	
}
#endif

#ifndef INSL
void insertLast(struct node** head,struct node *n)
{
  struct node * h = *(head);
	if(n != NULL && h != NULL)
	{
	  while(h->next != NULL)
	  {
	  	h = h->next;
	  }
	  h->next = n;
	  n->next = NULL;
	}
	else if(h == NULL)
	{
		n->next = NULL;
		*(head) = n;
	}
	
}
#endif

#ifndef DELFM
void deleteFirstMatch(struct node**head,int value)
{
	struct node * h = *(head);
	struct node * orglast = NULL;
	
	if(h != NULL && h->value == value)
	{
		*(head) = h->next;
		free(h);
		return;
	}
		
	while(h != NULL && h->value != value)
	{
		orglast = h;
		h = h->next;

	}
	
	if(h != NULL)
	{
		orglast->next = h->next;
		free(h);
	}

	
}
#endif

#ifndef DelA
void deleteAt(struct node** head,int index)
{
	int count = 0;
	struct node * h = *(head);
	struct node * orglast = NULL;
	
	if(index == 0)
	{
		*(head) = h->next;
		free(h);
		return;
	}
	
	while(h != NULL && (count < index ))
	{
		orglast = h;
		h = h->next;
		count ++;
	}
		
	if(h != NULL)
	{
		orglast->next = h->next;
		free(h);
	}
		
}
#endif

#ifndef DELAM
void deleteAllMatches(struct node** head,int value)
{
	struct node * h = *(head);
	struct node * temp = NULL;
	
	while(h != NULL && h->value == value)
	{
		*(head) = h->next;		
		free(h);
		h = *(head);
		
	}		
		
	while(h != NULL)
	{
		temp = h;
		h = h->next;
						
		if(h != NULL && h->value == value)
		{
			temp->next = h->next;
			free(h);
			h = temp;
		}			
	}
}
#endif

#ifndef L
int getLength(struct node** head)
{
	struct node * h = *(head);
	if(h != NULL)
	{
		int count = 0;
		while(h != NULL)
		{
	  	count++;
	  	h = h->next;
		}
	
		return count;
	}
	
	else
	{
		return 0;
	}
}
#endif

#ifndef FREEMEM
void freeMemory(struct node** head)
{
	struct node * h = *(head);
  struct node * orglast;
  
 	while(h != NULL)
 	{    	
 		orglast = h;
   	h = h->next;    
  	free(orglast);
 	}

}
#endif
