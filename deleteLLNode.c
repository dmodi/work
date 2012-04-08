/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

   * File Name : deleteLLNode.c

   * Purpose :

   * Creation Date : Mon 22 Dec 2008 10:36:49 PM PST

   * Last Modified : Sunday 08 April 2012 04:18:55 PM IST

   * Created By : Dharmendra Modi  <dharmendra.modi.86@gmail.com> 

   * Description :
   _._._._._._._._._._._._._._._._._._._._._.*/

node * deleteLLNode (node * head, int val)
{
	node * prev;
	prev = NULL;
	node * returnNode  = NULL;
	while (head != NULL)
	{
		if (head->val == val)
		{
			returnNode = head;
			if (prevNode != NULL)
			{
				prevNode->next = head->next;
			}
			else
			{
				head = head->next;
			}
			break;
		}
		else
		{
			prevNode = head;
			head = head->next;
		}
	}
	return returnNode;
}
