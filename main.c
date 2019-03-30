/****************************************************************************************************
*
*	This program allows the user to generate and experiment with
*	linked lists. The program lets the user add new entries, delete entries
*	print out all entries, and search for a specific entry, all while
*	maintaining a linked list so that entries are arranged numerically.
*
*/

#include "include.h"

int number;							//this will always be the number the user most recently input
char numtemp[100]={0};
char command;							//add, delete, print, whatever the user specifies

int main(void)
{
	init();
	while(1)
	{
		printf(" > ");							//promptly engage prompt
		fgets(numtemp, 100, stdin);					//get input from the ever-cooperative user
		int parse=sscanf(numtemp, "%c%d", &command, &number);		//parse the input. you know, just in case.
		if(parse != 2 && command!='x' && command !='p')
		{
			command='a';						//pretend the input was 'a' to trigger the instruction message
		}
		if(command=='i')
		{
			(search(ll,number)) ? printf("NODE ALREADY IN LIST\n") : add(ll,number);	//report node's presence in the list and abort, or add a new node
		}
		if(command=='p')
		{
			print(ll);
		}
		if(command=='s')
		{
			int sar=search(ll, number);		//look for the number and report result
			(sar==1) ? printf("FOUND\n") : printf("NOT FOUND\n");
			
		}
		if(command=='d')				//delete command received
		{
			if(search(ll, number))			//make sure the target exists
			{
				del(ll, number);		//cause this number to suffer a lil' accident-like
				printf("SUCCESS\n");
			}
			else
			{
				printf("NODE NOT FOUND\n");
			}
		}
		if(command=='x')				//exit command received, time to clean up
		{
			struct node *temp;			
			temp=ll;				//set a temp node to store half of the counting stuff
			while(temp!=NULL)
			{
				temp=ll->next;			//start off with the sentinel node
				ll=ll->next;			//traverse the list
				free(temp);			//set them all free
			}
			return 0;
		}
		if(command!='i' && command!='p' && command!='s' && command!='d')						//the user entered something incorrect. let's educate them a bit.
		{
			printf("Command\t\tResult\ni number\tinserts number into the list\np \t\tprints the list's contents\ns number\tsearches for the given number\nd number\tdeletes the given number\nx\t\tquits the program\n");
		}
	}
}
