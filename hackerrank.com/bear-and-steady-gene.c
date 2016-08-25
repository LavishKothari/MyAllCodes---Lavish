#include<stdio.h>
#define MAX 500010

int findAnswer0(char*str,int n)
{
	int i,j,end,start,count_a,count_c,count_t,count_g;
	count_a=count_c=count_t=count_g=0;
	i=0;j=n-1;
	for(i=0;str[i];i++){
		if(str[i]=='A') count_a++;
		if(str[i]=='C') count_c++;
		if(str[i]=='T') count_t++;
		if(str[i]=='G') count_g++;
		if(count_a>n/4 || count_c>n/4 || count_t>n/4 || count_g>n/4)
			break;
	}
	return n-i;
}
int findAnswer1(char*str,int n)
{
	int i,j,end,start,count_a,count_c,count_t,count_g;
	count_a=count_c=count_t=count_g=0;
	i=0;j=n-1;
	while(i<j){
		if(str[i]=='A') count_a++;
		if(str[i]=='C') count_c++;
		if(str[i]=='T') count_t++;
		if(str[i]=='G') count_g++;
		if(count_a>n/4 || count_c>n/4 || count_t>n/4 || count_g>n/4)
			break;
		i++;
		
		if(str[j]=='A') count_a++;
		if(str[j]=='C') count_c++;
		if(str[j]=='T') count_t++;
		if(str[j]=='G') count_g++;
		if(count_a>n/4 || count_c>n/4 || count_t>n/4 || count_g>n/4)
			break;
		j--;
	}
	if(i<j)
		return j-i+1;
	return 0;
}
int findAnswer2(char*str,int n)
{
	int i,j,end,start,count_a,count_c,count_t,count_g;
	count_a=count_c=count_t=count_g=0;
	i=0;j=n-1;
	for(i=n-1;i>=0;i--){
		if(str[i]=='A') count_a++;
		if(str[i]=='C') count_c++;
		if(str[i]=='T') count_t++;
		if(str[i]=='G') count_g++;
		if(count_a>n/4 || count_c>n/4 || count_t>n/4 || count_g>n/4)
			break;
	}
	return i+1;
}
int min(int a,int b,int c)
{
	return a<b?(a<c?a:c):(b<c?b:c);
}
int main()
{
	int n;
	char str[MAX];
	scanf("%d",&n);
	scanf("%s",str);
	//printf("%d %d %d\n",findAnswer0(str,n),findAnswer1(str,n),findAnswer2(str,n));
	printf("%d\n",min(findAnswer0(str,n),findAnswer1(str,n),findAnswer2(str,n)));
	return 0;
}
