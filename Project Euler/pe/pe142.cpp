#include<stdio.h>
#include<math.h>
typedef long long int ll;
bool isPerfectSquare(ll n)
{
	ll sq=(ll)sqrt(n);
	if(sq*sq==n)
		return true;
	return false;
}
int main()
{
	ll x,y,z; // x>y>z
	for(ll i=1;;i++)
	{
		printf("i = %lld\n",i);
		ll sq1=i*i;
		for(ll j=1;;j++)
		{
			ll sq2=j*j;
			if((sq1+sq2)%2==0)
			{
				x=(sq1+sq2)/2;
				y=sq1-x;
				if(y<=0)
					break;
				if(x>y && y>0)
				{
					for(ll k=1;;k++)
					{
						ll sq3=k*k;
						z=sq3-x;
						if(z>0)
						{
							if(x>z && y>z)
							{
								if(isPerfectSquare(x-z) && isPerfectSquare(y-z) && isPerfectSquare(y+z))
								{
									printf("x,y,z = %lld %lld %lld\n",x,y,z);
									printf("the answer is : %lld\n",(x+y+z));
									return 0;
								}
							}
							else break;
						}
					}
				}
			}
		}
	}
	return 0;
}
