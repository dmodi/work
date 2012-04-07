	# include<stdio.h>
	int main()
	{
		
		int prevRem = 0, num , rem ;
		int newNum = num;
		while(newNum !=0)
		{
			rem = newNum % 10 ;
			newNum = newNum / 10 ;
			prevRem = prevRem * 10 + rem ;
		}
			if(prevRem == num)
			{
			printf("palindrom\n");
			}
			else
			{
			printf("not a palindrom\n");
			}
	}
		
