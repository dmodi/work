/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

   * File Name : chekNumeric.c

   * Purpose :

   * Creation Date : Mon 22 Dec 2008 10:36:49 PM PST

   * Last Modified : Saturday 07 April 2012 10:48:01 AM IST

   * Created By : Dharmendra Modi  <dharmendra.modi.86@gmail.com> 

   * Description :
   _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>

int isNumeric (char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		printf ("returning %i \n", ch - '0');
		return ch - '0';
	}
	return -1;
}

int isNumber (char * str)
{
	int num = 0;

	if (!str)
	{
	printf ("Invalid argument \n");
	return -1;
	}

	while (*str)
	{
	int ret = isNumeric (*str);
	if (ret == -1)
	{
		printf ("Not a number \n");
		return -1;
	}
	num = num * 10 + ret;
	str++;
	}
	return num;
}

int main(int argc, char *argv[])
{
	char ch;
	
	if (argc != 2)
	{
		printf ("Enter proper arguments \n");
		return -1;
	}
	//ch = argv[1][0];
	//printf (" %c is %sa Numeric Char \n", ch, isNumeric(ch) == -1 ? "not ": "");  
	
	printf ("%s is integer with val %d\n", argv[1], isNumber (argv[1])); 
	return 0;

}
