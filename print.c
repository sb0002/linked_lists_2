/*
	The marvelous print function outputs to the screen whatever is in the linked list. It looks at a node, prints out whatever the data section contains, and then follows the pointer to the next node, until the end of the list is reached.
*/
#include "include.h"

void print(struct node *ll)
{
	struct node *temp;				//one of life's great mysteries is why the temp pointer isn't declared globally
	temp=ll->next;					//start just after the sentinel node
	while(temp!=NULL)
	{
		printf("%i ", temp->data);		//the mail must go through
		temp=temp->next;			//we done with that one. move along.
	}
	printf("\n");
}
