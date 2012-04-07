#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	int val;
};

typedef struct node node;

node * deleteLinkedList(node *head, int K)
{
	node *rethead = NULL;
	node *prevhead = NULL;

	while(head != NULL)
	{
		if(head->val == K)
		{
			if(prevhead != NULL)
				prevhead->next = head->next;
		}
		else prevhead = head;
		head = head->next;
		if(rethead == NULL) rethead = prevhead;
	}
	return rethead;
}

void printLinkedList(node *n)
{
	while(n != NULL)
	{
		printf("%d ->",n->val);
		n=n->next;
	}
	printf("\n");
}

node * returnLinkedList(int A[], int n)
{
	node* head=NULL;
	node* prev=NULL;
	node *curr=NULL;
	int i;

	for(i=0;i<n;i++)
	{
		curr = (node *)malloc(sizeof(node));
		curr->val = A[i]; curr->next = NULL;
		if(prev!=NULL)prev->next=curr;
		prev = curr;
		if(head==NULL) head = curr;
	}
	return head;
}

void deleteListElement (node * list, int element)
{
	node * nd;
	nd = deleteLinkedList(list, element);
	printLinkedList(nd);
}

node * recursiveReverseList (node * list)
{
	node * temp;

	if (!list || !list->next)
		return list;

	temp = list;
	list = recursiveReverseList (list->next);
	temp->next->next = temp;
	temp->next = NULL;
	return list;
}

node * iterativeReverseList (node * list)
{
	node * returnHead = NULL;
	node * temp;
	node * cur = list;
	while (cur)
	{
		temp = cur->next;
		cur->next = returnHead;
		returnHead = cur;
		cur = temp;
	}
	return returnHead;
}

void testReverseList(node * list)
{
	node * temp;
	printf("original list \n");
	printLinkedList(list);
	temp = recursiveReverseList (list);
	printf("After recursive reverse list is \n");
	printLinkedList (temp);

	temp = iterativeReverseList (temp);
	printf("After iterative reverse list is \n");
	printLinkedList (temp);
}
int main()
{
	node* nd = NULL;
	node * rList;

	int A[] = {3,6,4,9,6,2}; int n = 6; int K = 6;
	//int A[] = {3,3,3,3,3,3}; int n = 6; int K = 3;
	//int A[] = {3,4}; int n = 2; int K = 3;
	nd = returnLinkedList(A,n);
	printLinkedList(nd);
	testReverseList (nd);

	return 0;
}
