#include<stdio.h>
int main()
{
	int rem[26];
	int freq[26];
	char str[1001];
	int t,maxi,max,counter,i,j,n;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<26;i++)
			freq[i]=0;
		scanf("%s",str);
		for(i=0;str[i];i++)
			freq[str[i]-'a']++;
		for(i=0;i<26;i++)
		{
			counter=0;
			for(j=i+1;j<26;j++)
			{
				if(freq[j]>=freq[i])
					counter++;
			}
			rem[i]=counter;
		}
		for(i=0;i<26;i++)
		{
			max=0;
			for(j=i;j<n;j++)
			{
				if(rem[j]>max)
				{
					maxi=j;
					max=rem[j];
				}
			}
			i=maxi;
			printf("%c",(maxi+'a'));
		}
	}
	return 0;
}
