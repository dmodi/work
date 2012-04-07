# include<stdio.h>
int main()
{

	int prevRem = 0;
	int num; 
	int rem;
	int newNum;

	printf ("Enter the number :");
	scanf ("%d", &num);

	newNum = num;

	while (newNum != 0)
	{
		rem = newNum % 10 ;
		newNum = newNum / 10 ;
		prevRem = prevRem * 10 + rem ;
	}
	if (prevRem == num)
	{
		printf("%d is palindrom\n", num);
	}
	else
	{
		printf("%d is not a palindrom\n", num);
	}
	return 0;
}

