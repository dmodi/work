#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node * next;
	int val;
} node;

node * helpAddLinkedList(node *h1, node *h2, int carry)
{
	node * head = NULL;
	int val1,val2,val;
	val1 = (h1!=NULL)?h1->val:0;
	val2 = (h2!=NULL)?h2->val:0;
	val = val1+val2+carry;
	if(val==0)return NULL;
	carry = val/10;
	val = val%10;

	head = (node *)malloc(sizeof(node));
	head->val = val;
	head->next = helpAddLinkedList((h1!=NULL)?h1->next:NULL,(h2!=NULL)?h2->next:NULL,carry);
	return head;
}

node * reverseLinkedList(node *n)
{
	node * prev = NULL;
	node * temp = NULL;
	node * curr = n;

	while(curr != NULL)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

node * addLinkedList(node *h1, node *h2)
{
	node * h;
	h1 = reverseLinkedList(h1);
	h2 = reverseLinkedList(h2);
	h = helpAddLinkedList(h1,h2,0);
	h = reverseLinkedList(h);
	reverseLinkedList(h1);
	reverseLinkedList(h2);
	return h;
}

int main()
{

	return 0;
}
