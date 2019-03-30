/*
	At the top of the food chain, we have the add function. Its purpose, mysteriously, is to add new data to the linked list, and to keep the nodes in numerical order.
*/
#include "include.h"

int add(struct node *ll, int number)
{	
	struct node *previous, *current;					//define a few pointers to aid in the editing process
	previous=ll;								//set the previous pointer to not-previous, at the beginning of the list along with our friend sentinel node
	current=previous->next;							//take one step backward, then take one step forward
	while(current!=NULL)
	{
		if(current->data>number)					//find the next largest number, then insert before it
		{
			struct node *temp=malloc(sizeof(struct node));		//generate a home for our new data
			temp->data=number;					//show the number around its new quarters
			temp->next=previous->next;				//make sure the list now points to the node just created
			previous->next=temp;
			return 1;
		}
		previous=current;						
		current=current->next;						//continue list traversal until a suitable location for number is found
	}
	struct node *temp=malloc(sizeof(struct node));				//the list was empty. generate a new node as described above, keep things in order, and end the list
	previous->next=temp;
	temp->next=NULL;
	temp->data=number;
}
