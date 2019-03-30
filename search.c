/*
	Don't tell anyone else, but the search function's job is to look things. A user-defined number, specifically. It does this by traversing the linked list, following those pointer thingies, until it finds the number it wants or the end of the list, at which point it gives up.
*/
#include "include.h"

int search(struct node *ll,int number)
{
	struct node *temp=ll->next;			//set up a temporary list-exploring pointer
	while(temp!=NULL)
	{
		if(temp->data==number) return 1;	//found 'im out back, sheriff
		temp=temp->next;			//on to the next node
	}
	return 0;					//dead end
}
