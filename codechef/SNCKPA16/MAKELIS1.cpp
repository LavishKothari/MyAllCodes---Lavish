#include<stdio.h>
#include<vector>
#include<bitset>
#include<iostream>
#include<map>


#define MAX 100010
using namespace std;

typedef long long int ll;



class Number
{
	public:
	bool isPrime;
	int sum,number,first,last;
	map<int,int>factors;
	
	Number(bool isPrime,int sum,int number,int first)
	{
		this->isPrime=isPrime;
		this->sum=sum;
		this->number=number;
		this->first=first;
	}
	Number(){}
};
vector<Number>numbers(MAX+1);
void populateNumbers()
{
	/*
	isPrime.reset();
	isPrime.flip();
	isPrime[0].flip();
	isPrime[1].flip();
	*/
	numbers[1]=Number(false,1,1,0);
	
	for(int i=2;i<MAX;i++)
	{
		numbers[i]=Number(true,0,0,0);
	}
	
	for(int i=2;i<=MAX;i++)
		if(numbers[i].isPrime)
		{
			for(int j=i*2;j<=MAX;j+=i)
			{
				if(numbers[j].first==0)
					numbers[j].first=i;
				numbers[j].last=i;
				numbers[j].isPrime=false;
				numbers[j].sum+=i;
				numbers[j].factors[i]=0;
			}
		}
	for(int i=2;i<=MAX;i++)
	{
		if(numbers[i].isPrime)
		{
			numbers[i].number=1;
			numbers[i].sum=i;
			numbers[i].first=i;
			numbers[i].last=i;
			numbers[i].factors[i]=1;
		}
		else 
		{
			int ci=i;
			for(map<int,int>::iterator it=numbers[i].factors.begin();it!=numbers[i].factors.end();it++)
			{
				int f=it->first;
				int count=0;
				while(ci!=1 && ci%f==0)
				{
					ci/=f;
					count++;
				}
				numbers[i].sum+=(count-1)*f;
				it->second=count;
				numbers[i].number+=count;
			}
		}
	}
}
void printNumbers()
{
	for(int i=2;i<100000;i++)
	{
		printf("\n*************\n%d : \n",i);
		cout<<"isPrime : "<<numbers[i].isPrime<<endl;
		cout<<"sum : "<<numbers[i].sum<<endl;
		cout<<"first : "<<numbers[i].first<<endl;
		cout<<"last : "<<numbers[i].last<<endl;
		cout<<"number : "<<numbers[i].number<<endl;
		cout<<"the factors are: \n";	 
		for(map<int,int>::iterator it=numbers[i].factors.begin();it!=numbers[i].factors.end();it++)
		{
			printf("%d %d\n",it->first,it->second);
		}
		
	}
	printf("**********************printing over**********************\n\n");
}
void printRev(int start,int end)
{
	int i;
	for(i=end;i>=start;i--)
		printf("%d ",i);
}
void printSpecial(int k,int initial)
{
	Number n=numbers[k];
	int start,end=initial;
	for(map<int,int>::iterator it=n.factors.begin();it!=n.factors.end();it++)
	{
		int current=it->first;
		int current_count=it->second;
		//printf("****************%d %d\n",current,current_count);
		for(int k=0;k<current_count;k++)
		{
			start=end+1;
			end+=current;
			printRev(start,end);
		}
	}
}
void printRev1(int start,int end)
{
	int i;
	for(i=end;i>=start;i--)
	{
		
		printf("%d ",i);
	}
}

void printSpecial1(int*arr,int k,int initial)
{
	Number n=numbers[k];
	int start,end=initial;
	for(map<int,int>::iterator it=n.factors.begin();it!=n.factors.end();it++)
	{
		int current=it->first;
		int current_count=it->second;
		//printf("****************%d %d\n",current,current_count);
		for(int k=0;k<current_count;k++)
		{
			start=end+1;
			end+=current;
			printRev(arr,start,end);
		}
	}
}
int getBit(int k)
{
	int counter=1;
	while(k)
	{
		k/=2;
		if(k==0)
			return counter-1;
		counter++;
	}
}

void goBinary(int k)
{
	int arr[100],index=100;
	int count=1;
	len=getBit(k);
	
	while(k)
	{
		int toadd=len-getBit(k);
		printSpecial1(arr,1<<getBit(k),counter);
		counter+=2*k;
		while(toadd--)
		{
			printf("%d ",counter);
			counter++;
		}
	}
}
void printAnswer(int k)
{
	int flag,c3=0,c4=0;
	//printf("################################################################%d\n",k);
	if(k==1)
	{
		printf("1\n1\n");
		return;
	}
	Number n=numbers[k];
	if(n.sum<=100)
	{
		/*
		printf("%d\n",n.sum);
		printSpecial(k,0);
		printf("\n");
		*/
	}
	else 
	{
		flag=0;
		for(int i=1;i<k;i++)
		{
			int one=i,two=k-i;
			if(one>two)
				break;
			if(numbers[one].number==numbers[two].number && numbers[one].sum+numbers[two].sum<=100)
			{	
				flag=1;
				/*
				printf("%d\n",numbers[one].sum+numbers[two].sum);
				printSpecial(two,numbers[one].sum);
				printSpecial(one,0);
				printf("\n");
				*/
				return;
			}
		}
		if(flag==0)
		{
			printf("Going for three numbers : %d\n",k);
			for(int i=2;i<100;i++)
			{
				//printf("%d\n",i);
				for(int j=i+1;j<100;j++)
				{
					int l=k-(i+j);
					//printf("i=%d j=%d k=%d\n",i,j,l);
					if(l>=101 || l<0)
						continue;
					if(numbers[i].number==numbers[j].number && numbers[i].number==numbers[l].number && numbers[i].sum+numbers[j].sum+numbers[l].sum<=100)
					{
						return;
					}
				}
			}
			//goBinary(k);
			printf("not returning\n");
			/*
			if(flag==0)
			{
				//printf("there is something terribly wrong with %d\n",k);
				//printf("Going for 4\n");
				for(int a=2;a<100;a++)
				{
					//printf("%d\n",i);
					for(int b=a+1;b<100;b++)
					{
						for(int c=b+1;c<100;c++)
						{
							int d=k-(a+b+c);
							if(d>=101 || d<0)
								continue;
							if(numbers[a].number==numbers[b].number && numbers[a].number==numbers[c].number && numbers[a].number==numbers[d].number && numbers[a].sum+numbers[b].sum+numbers[c].sum+numbers[d].sum<=100)
							{
								return;
							}
						}
						//printf("i=%d j=%d k=%d\n",i,j,l);
						
					}
				}
				//if(flag==0) printf("this is wrong..!!!! %d \n",k);
			}
			*/
		}
		
	}
	//if(flag==0)printf("c3=%d\nc4=%d\n",c3,c4);
}

int main()
{
	printf("%d\n",getBit(16));
	/*

	ll t,k,i;
	populateNumbers();
	//printNumbers();
	//printf("populating finished\n");
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&k);
		printAnswer(k);
	}
	
	for(i=2;i<100001;i++)
	{
		//printf("%lld ",i);
		printAnswer(i);
	}
	*/
	return 0;
}
