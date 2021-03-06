#include<stdio.h>
int containsQuestionMark(char *arr)  // if question mark is present returns the index of question mark other wise returns -1
{
	int i;
	for(i=0;i<16;i++)
		if(arr[i]=='?')
			return i;
	return -1;
}
void printArray(char *arr)
{
	int i;
	for(i=0;i<16;i++)
		printf("%c",arr[i]);
	printf(" ");
}
int isValid(char*arr)
{
	int i,sum=0;
	for(i=15;i>=0;i--)
	{
		if(i%2==1)
		{
			sum+=arr[i]-'0';
		}
		else
		{
			if(arr[i]>='5' && arr[i]<='9')
				sum+=(arr[i]-'0')*2-9;
			else
				sum+=(arr[i]-'0')*2;
		}
	}
	if(sum%10==0)
		return 1;
	return 0;
}

int main()
{
	int t,i,c;
	char arr[16],temp;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<16;i++)
			scanf(" %c",&arr[i]);
		c=containsQuestionMark(arr);
		if(c!=-1)
		{
			if(c==0)
			{
				for(i=1;i<=9;i++)
				{
					arr[c]=i+'0';
					if(isValid(arr))
					{
						printArray(arr);
						break;
					}
				}				
			}
			else
			{
				for(i=0;i<=9;i++)
				{
					arr[c]=i+'0';
					if(isValid(arr))
					{
						printArray(arr);
						break;
					}
				}
			}
		}
		else
		{
			// means you need to swap and check.
			for(i=0;i<15;i++)
			{
				// swapping the ith and (i+1)th element 
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				if(isValid(arr))
				{
					printArray(arr);
					break;
				}	
				else
				{
					temp=arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=temp;
				}
			}
		}
		printf("\n");
	}
}

/*
3942682966937054 1217040151414995 2146133934667114 2553514623369425
3942682966937054 1217040151414995 2146133934667114 2553514623369425
*/
