/*
	The init function simply generates a linked list consisting solely of a sentinel node pointing to NULL and containing an arbitrary placeholder number as data. A pointer to this list is sent out for other functions to work with.
*/
#include "include.h"

struct node *init()
{
	ll=malloc(sizeof(struct node));		//demand memory space for the linked list
	ll->next=NULL;				//at this point, the sentinel node is alone
	ll->data=1024;				//input a number, definitely chosen at random, to hold down the data place
	return(ll);				//send the linked list out to play
}
