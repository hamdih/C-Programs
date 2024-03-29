#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TABLESIZE 100000
#define SEARCHSIZE 1000000

int h1(int k)
{
    return k % TABLESIZE;
}

int h2(int k)
{
    return 1;
}

int search(int htable[TABLESIZE], int key)
{
    int index;
    int inc;

    index = h1(key);  
    inc = h2(key); 

    while (1) 
    {
	if ( htable[index] == key )
	      return index;
        else if (htable[index] == -1 ) // search failure
	      return index;
        else
	      index = (index + inc) % TABLESIZE;
    }
}


int main()
{
    int A[TABLESIZE];
    int i, key, index;

// read the data
    for(i = 0; i < TABLESIZE/2; i++)
	scanf("%d",&A[i]);

// Now search for data repeatedly

    for(i = 0; i < SEARCHSIZE; i++)
    {
        key = random() % 500000;
        index = search(A,key);
        if( index != -1  )
        {
            assert(key = A[index]);
        }
    }
}
