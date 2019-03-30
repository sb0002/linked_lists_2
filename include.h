#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *ll;

struct node* init();
int add(struct node *, int number);
void print(struct node *);
int del(struct node *, int number);
int search(struct node *, int number);
