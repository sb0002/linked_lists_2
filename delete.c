/*
	The delete function's insidious task is not merely to delete a node, but to make sure no evidence of it remains. It does this by forcing the pointers to circumvent the doomed node, and then frees the memory associated with the node, leaving nothing.
*/
#include "include.h"

int del(struct node *ll, int number)
{	
	struct node *current, *previous;			//declare some pointers to help keep track of things
	previous=ll, current=ll->next;
	while(current!=NULL)
	{
		if(current->data==number)
		{
			previous->next=current->next;		//make the link bypass the node we want gone
			free(current);				//free the memory holding the deleted value
			return 1;
		}
		previous=current;
		current=current->next;				//haven't found it yet, keep looking
	}
}
