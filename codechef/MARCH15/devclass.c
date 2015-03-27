#include<stdio.h>
#include<stdlib.h>
#include<string.h>
findFirstMisMatch(char str[],char startChar,char of,int from)
{
	int i;
	char otherChar;
	if(startChar=='B') otherChar='G'; else otherChar='B';
	for(i=from;str[i];i++)
	{
		if(i%2==0 && str[i]!=startChar && str[i]==of)
			return i;
		if(i%2==1 && str[i]!=otherChar && str[i]==of)
			return i;
	}
	return i;
}
long long int findAnswer2(char str[],int type)
{
	long long int countB,countG,answer,answer1,answer2,a,b,i;
	countB=countG=0;
	for(i=0;str[i];i++)
	{
		if(str[i]=='B')
			countB++;
		else countG++;
	}
	//////////////////////////////////////////////
	if(countB+1==countG)
	{
		answer=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'G','B',a);
			b=findFirstMisMatch(str,'G','G',b);
			if(str[a] && str[b])
				answer=answer+abs(a-b)*abs(a-b);
			else
				break;
		}
	}
	else if(countG+1==countB)
	{
		answer=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'B','B',a);
			b=findFirstMisMatch(str,'B','G',b);
			if(str[a] && str[b])
				answer=answer+abs(a-b)*abs(a-b);
			else
				break;
		}
	}
	else if(countB==countG)
	{
		answer1=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'G','B',a);
			b=findFirstMisMatch(str,'G','G',b);
			if(str[a] && str[b])
				answer1=answer1+abs(a-b)*abs(a-b);
			else
				break;
		}
		answer2=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'B','B',a);
			b=findFirstMisMatch(str,'B','G',b);
			if(str[a] && str[b])
				answer2=answer2+abs(a-b)*abs(a-b);
			else
				break;
		}
		answer=answer1<answer2?answer1:answer2;
	}
	else 
		answer=-1;
	return answer;
}
long long int findAnswer1(char str[],int type)
{
	long long int countB,countG,answer,answer1,answer2,a,b,i;
	countB=countG=0;
	for(i=0;str[i];i++)
	{
		if(str[i]=='B')
			countB++;
		else countG++;
	}
	//////////////////////////////////////////////
	if(countB+1==countG)
	{
		answer=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'G','B',a);
			b=findFirstMisMatch(str,'G','G',b);
			if(str[a] && str[b])
				answer=answer+abs(a-b);
			else
				break;
		}
	}
	else if(countG+1==countB)
	{
		answer=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'B','B',a);
			b=findFirstMisMatch(str,'B','G',b);
			if(str[a] && str[b])
				answer=answer+abs(a-b);
			else
				break;
		}
	}
	else if(countB==countG)
	{
		answer1=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'G','B',a);
			b=findFirstMisMatch(str,'G','G',b);
			if(str[a] && str[b])
				answer1=answer1+abs(a-b);
			else
				break;
		}
		answer2=a=b=0;
		for(;str[a] && str[b];a++,b++)
		{
			a=findFirstMisMatch(str,'B','B',a);
			b=findFirstMisMatch(str,'B','G',b);
			if(str[a] && str[b])
				answer2=answer2+abs(a-b);
			else
				break;
		}
		answer=answer1<answer2?answer1:answer2;
	}
	else 
		answer=-1;
	return answer;
}

long long int findAnswer0(char str[],int type)
{
	int match,index,tempAnswer1=0,tempAnswer2=0;
	int i,countB,countG,answer1,answer2,flag,counter;
	int n=strlen(str);
	countB=countG=0;
	for(i=0;str[i];i++)
	{
		if(str[i]=='B')
			countB++;
		else countG++;
	}
	flag=1; // starting with B
	counter=0;
	match=0;
	for(i=0;str[i];flag=(!flag),i++)
	{
		if(flag==1)
		{
			if(str[i]!='B')
			{
				if(match==0)
				{
					match=1;
					index=i;
				}
				else if(match==1)
				{
					tempAnswer1=tempAnswer1+i-index;
					match=0;
				}
				counter++;
			}
		}
		else if(flag==0)
		{
			if(str[i]!='G')
			{
				if(match==0)
				{
					match=1;
					index=i;
				}
				else if(match==1)
				{
					tempAnswer1=tempAnswer1+i-index;
					match=0;
				}
				counter++;
			}
		}
	}
	answer1=counter/2;
	flag=0; // starting with G
	counter=0;
	match=0;
	for(i=0;str[i];flag=(!flag),i++)
	{
		if(flag==1)
		{
			if(str[i]!='B')
			{
				if(match==0)
				{
					match=1;
					index=i;
				}
				else if(match==1)
				{
					tempAnswer2=tempAnswer2+i-index;
					match=0;
				}
				counter++;
			}
		}
		else if(flag==0)
		{
			if(str[i]!='G')
			{
				if(match==0)
				{
					match=1;
					index=i;
				}
				else if(match==1)
				{
					tempAnswer2=tempAnswer2+i-index;
					match=0;
				}
				counter++;
			}
		}
	}
	answer2=counter/2;
	
	if(countB+1==countG || countG+1==countB || countB==countG)
	{
		if(type==0)
		{
			if(countG==countB)
			{
				return answer1>answer2?answer2:answer1;
			}
			else if(countB>countG) // you need to start with B
			{
				return answer1;
			}
			else // you need to start with G
			{
				return answer2;
			}
		}
		else if(type==1)
		{
			if(countG==countB)
			{
				return tempAnswer1>tempAnswer2?tempAnswer2:tempAnswer1;
			}
			else if(countB>countG) // you need to start with B
			{
				return tempAnswer1;
			}
			else // you need to start with G
			{
				return tempAnswer2;
			}
		}
	}
	else return -1;
}
int main()
{
	char str[100001];
	int t,type;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&type,str);
		if(type==0)
			printf("%lld\n",findAnswer0(str,type));	
		else if(type==1 || type==2)
			printf("%lld\n",findAnswer1(str,type));
	}
	return 0;
}
