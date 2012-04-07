/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

   * File Name : testRepeated.c

   * Purpose :

   * Creation Date : Mon 22 Dec 2008 10:36:49 PM PST

   * Last Modified : Saturday 07 April 2012 08:11:27 PM IST

   * Created By : Dharmendra Modi  <dharmendra.modi.86@gmail.com> 

   * Description :
   _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HASHTABLE_SIZE	52

typedef struct hashTable {
	unsigned int count;
	unsigned short index;
} hash;

char findFirstNonRepeated(char * input, unsigned int length)
{
	unsigned short index = 0;
	hash lookup[MAX_HASHTABLE_SIZE];
	unsigned int i = 0;
	unsigned short min;
	int  returnIndex = 0;
	
	if (!input)
	{
		printf("ERROR : Invalid Params\n");
		return -2;
	}

	for (i = 0; i < MAX_HASHTABLE_SIZE; i++)
	{
		lookup[i].count = 0;
		lookup[i].index = MAX_HASHTABLE_SIZE;
	}

	for (i = 0; i < length; i++) 
	{
		char ch = input[i];
		unsigned int ind;

		if (ch >= 'A' && ch <= 'Z')
		{
			ind = ch - 'A';
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			ind = ch - 'a' + 26;
		}
		else
		{
			printf("Invalid input : contains %c\n", ch);
			return -2;
		}
		lookup[ind].count++;
		if (lookup[ind].count > 1)
		{
			lookup[ind].index = MAX_HASHTABLE_SIZE;
		}
		else
		{
			lookup[ind].index = index++;
		}
		printf("index is %d \n", index);
	}
	min = MAX_HASHTABLE_SIZE;
	for (i = 0; i < MAX_HASHTABLE_SIZE; i++)
	{
		if (lookup[i].index < min)
		{
			min = lookup[i].index;
			returnIndex = i; 
			printf(" return index %d and min %d \n", returnIndex, min);
		}
		printf(" index %d and count %d \n", lookup[i].index, lookup[i].count);
	}

	printf("returtIndex %d min is %u\n", returnIndex, min);
	if (min >= MAX_HASHTABLE_SIZE)
		return -1;
	if (returnIndex < 26)
		return ('A' + returnIndex);
	return ('a' + (returnIndex - 26));
}

int main(int argc, char * argv[])
{
	char * arr = "aaaaaaaa";
	char ch = findFirstNonRepeated(arr, 8);
	if (ch == -1)
		printf ("no non repeated element \n");
	else
		printf("first non repeated %c\n", ch);

	return 0;
}
