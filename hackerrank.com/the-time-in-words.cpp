#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string word(int a)
{
	switch(a)
	{
		case 1:return "one";
		case 2:return "two";
		case 3:return "three";
		case 4:return "four";
		case 5:return "five";
		case 6:return "six";
		case 7:return "seven";
		case 8:return "eight";
		case 9:return "nine";
		case 10:return "ten";
		case 11:return "eleven";
		case 12:return "twelve";
		case 13:return "thirteen";
		case 14:return "fourteen";
		case 15:return "fifteen";
		case 16:return "sixteen";
		case 17:return "seventeen";
		case 18:return "eithteen";
		case 19:return "nineteen";
		case 20:return "twenty";
		case 21:return "twenty one";
		case 22:return "twenty tow";
		case 23:return "twenty three";
		case 24:return "twenty four";
		case 25:return "twenty five";
		case 26:return "twenty six";
		case 27:return "twenty seven";
		case 28:return "twenty eight";
		case 29:return "twenty nine";
		case 30:return "thirty";
	}

	return "hello";
}
int main()
{
	int h,m;
	scanf("%d%d",&h,&m);
	if(m==0)
		cout<<word(h)<<" o' clock\n";
	else if(m==30)
		cout<<"half past "<<word(h)<<endl;
	else if(m==45)
		cout<<"quarter to "<<word(h+1)<<endl;
	else if(m==15)
		cout<<"quarter past "<<word(h)<<endl;
	else if(m==1)
		cout<<word(m)<<" minutes past "<<word(h)<<endl;
	else if(m<30)
		cout<<word(m)<<" minutes past "<<word(h)<<endl;
	else if(m>30)
		cout<<word(60-m)<<" minutes to "<<word(h+1)<<endl;
	return 0;
}
