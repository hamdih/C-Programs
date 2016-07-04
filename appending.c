//Hamdi Hmimy
// Dr Keathly
// 3/4/2015
// This program make 2 lists of 1's and 2's and the shorter list will be added to the bottom of the greater list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char   *name;
  float  balance;
  struct account *next;
};

int main()
{
  struct account *temp = NULL;
  int listID;
  float  balance;
  char   name[20];
  struct account *list1head = NULL;
  struct account *list1tail = NULL;
  struct account *list2head = NULL;
  struct account *list2tail = NULL;
  struct account *walk = NULL;

  while(scanf("%d%s%f", &listID, name, &balance) != EOF) {
		if(listID == 1) {
			if(list1head == NULL) {

			list1head = (struct account*)malloc(sizeof(struct account));	// ENTER CODE HERE
			list1head->next = NULL;
			list1tail =list1head;
			list1tail->name = (char*)malloc(sizeof(char) * strlen(name)+1);	// create a list of 1 of all accounts with 1 infront
			strcpy(list1tail->name,name);
			list1tail->balance = balance;
			    
	}
			else {
			list1tail->next = (struct account*)malloc(sizeof(struct account));	// ENTER CODE HERE
			list1tail = list1tail->next;
			list1tail->next = NULL;
			list1tail->name = (char*)malloc(sizeof(char) * strlen(name)+1);		//create the tail of list of 1's
			strcpy(list1tail->name,name);
			list1tail->balance = balance;
				}
		}
		else { // listID == 2
      if(list2head == NULL) {

			list2head = (struct account*)malloc(sizeof(struct account));	// ENTER CODE HERE
			list2head->next = NULL;							// Create list 2 of all accounts with 2 infront
			list2tail =list2head;
      			list2tail->name = (char*)malloc(sizeof(char) * strlen(name)+1);
			strcpy(list2tail->name,name);
			list2tail->balance = balance;
				}
      else {
			list2tail->next = (struct account*)malloc(sizeof(struct account));	// ENTER CODE HERE
			list2tail = list2tail->next;
			list2tail->next = NULL;						// create the end tail of list of 2's
			list2tail->name = (char*)malloc(sizeof(char) * strlen(name)+1);
			strcpy(list2tail->name,name);
			list2tail->balance = balance;
				// ENTER CODE HERE

      }
		}
  }
		
	// ENTER CODE HERE TO ATTACH THE SHORTER LIST TO THE LONGER LIST
        int i = 0;
	int x = 0;
	// print list1	
        walk = list1head;
        while(walk != NULL) {			// while loop to count nodes in list1
     		i++;
		walk = walk->next;
	}	
	
	walk = list2head; 			// while loop to count nodes in list 2
        while(walk != NULL) {
    		x++;
	walk = walk->next;
        }
	printf("%d %d",i,x);	
	if( i > x)				// if loop to find out which list is larger
         {
	 list1tail->next = list2head;		// the next tail for list 1 becomes list2head
	 }	
         walk = list1head; 
	while(walk != NULL) {			// print the list
    	printf("%20s %8.2f\n", walk->name, walk->balance);
    	walk = walk->next;
  	}
	//print list2
	printf("----------------\n");
	
	walk = list2head;
	while(walk != NULL) {
    	printf("%20s %8.2f\n", walk->name, walk->balance);
    	walk = walk->next;
  	}


  return;
}
