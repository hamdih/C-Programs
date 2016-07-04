#include <stdio.h>
#include <stdlib.h>

#define LOWEST 	1
#define HIGHEST 1000

int binarySearch(int A[], int key, int low, int high);

int main(void)
{
	unsigned int A[HIGHEST];	// the range of numbers
	unsigned int i = 0;				// loop variable
	unsigned int found = 0;	  // the array index where the value is found
	unsigned int number = 0;	// the random number for guessing
	// initialize the range of numbers
  for(i = 0; i < HIGHEST; i++)
    A[i] = i +1;
    srand((unsigned int)time(NULL));	// seed and get the random number
     number = random()%(HIGHEST-LOWEST+1)+LOWEST;		// ADD YOUR CODE HERE FOR RANDOM NUMBERS

	
        
	// find the number in the range using a binary search
	printf("Searching for %d\n", number);
	found = binarySearch(A, number, LOWEST-1, HIGHEST-1);
	printf("FOUND! %d at element #%d\n", A[found], found);

	return 0;
}

// function to find a number within a sub-range using binary search
int binarySearch(int A[], int key, int low, int high)
{   
        unsigned int mid;
        mid = (HIGHEST + LOWEST)/2;
        if (A[mid] = key)
            return key;
          else if (A[mid] < key)
               binarySearch(A,key,LOWEST,mid-1);
            else if (A[mid] > key)
               binarySearch(A,key,mid+1,HIGHEST);       
          
	// ADD YOUR CODE HERE FOR THE BINARY SEARCH

	
}
