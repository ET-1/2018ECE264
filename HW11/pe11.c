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
		}
	}
}
#endif

#ifndef INSF
void insertFirst(struct node** head,struct node * n)
{
  struct node * h = *(head);
  
  if(n != NULL)
  {
    n->next = h;
	}
	h = n;
}
#endif

#ifndef INSA
void insertAt(struct node** head,struct node * n,int index)
{
	int count = 0;
	struct node * h = *(head);
	struct node * orgnext;
	
	if(n != NULL)
	{
		while(count != index)
		{
		  if(h != NULL)
		  {
				h = h->next;
				count ++;
			}
		}
		
		if(h->next == NULL)
		{
			h->next = n;
		}
		else
		{
		  orgnext = h->next;
		  h->next = n;
		  n->next = orgnext;
		}
	}
	
}
#endif

#ifndef INSL
void insertLast(struct node** head,struct node *n)
{
	struct node * h = *(head);
	if(n != NULL)
	{
	  while(h != NULL)
	  {
	  	h = h->next;
	  }
	  h->next = n;
	  n->next = NULL;
	}
	
}
#endif

#ifndef DELFM
void deleteFirstMatch(struct node**head,int value)
{
	struct node * h = *(head);
	struct node * orglast;
	struct node * orgnext;
	
	if(h != NULL)
	{
  	while((h->value) != value)
  	{
  	  if(h != NULL)
  	  {
  	    orglast = h;
  			h = h->next;
  			orgnext = h->next;
  		}
  	}
  	orglast->next = orgnext;
  	free(h);
  }
	
}
#endif

#ifndef DelA
void deleteAt(struct node** head,int index)
{
	int count = 0;
	struct node * h = *(head);
	struct node * orglast;
	struct node * orgnext;
	
	if(h != NULL)
	{
		while(count != index)
		{
			if(h != NULL)
			{
				orglast = h;
				h = h->next;
				orgnext = h->next;
				count ++;
			}
		}
		
		orglast->next = orgnext;
		free(h);
		
	}
	
}
#endif

#ifndef DELAM
void deleteAllMatches(struct node** head,int value)
{
	struct node * h = *(head);
	struct node * orglast;
	struct node * orgnext;
	
	while(h != NULL)
	{
		orglast = h;
		h = h->next;
		orgnext = h->next;
		if(h->value == value)
		{
		  orglast->next = orgnext;
		  free(h);
		}
	}

}
#endif

#ifndef L
int getLength(struct node** head)
{
	struct node * h = *(head);
	int count = 0;
	while(h != NULL)
	{
	  count++;
	  h = h->next;
	}
	
	return count;
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
