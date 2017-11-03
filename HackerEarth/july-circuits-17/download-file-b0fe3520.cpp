#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

class Fraction
{
	public:
		ll n,d;
		Fraction(){n=0;d=1;}
		Fraction(int n,int d=1)
		{
			if(d==0)
			{
				n=0,d=1;	
			}
			else
			{
				//ll g=gcd(n,d);
				ll g=1;
				this->n=n/g;
				this->d=d/g;
			}
		}
		void reduce()
		{
			ll g=gcd(abs(n),abs(d));
			n/=g;
			d/=g;
			if(n<0 && d<0)
			{
				n*=-1;
				d*=-1;
			}
		}
		bool operator<(const Fraction&f)
		{
			return n*f.d<f.n*d;	
		}
		Fraction operator+(const Fraction&f)
		{
			Fraction fr(n*f.d+f.n*d,d*f.d);
			fr.reduce();
			return fr;
		}
		Fraction operator-(const Fraction&f)
		{
			Fraction fr(n*f.d-f.n*d,d*f.d);
			fr.reduce();
			return fr;
		}
		void reciprocate()
		{
			swap(n,d);
		}
		Fraction operator*(const Fraction&f)
		{
			Fraction fr(f.n*n,f.d*d);
			fr.reduce();
			return fr;
		}
		Fraction operator/(const Fraction&f)
		{
			Fraction fr(n*f.d,d*f.n);
			fr.reduce();
			return fr;
		}
		void print()
		{
			printf("%lld/%lld\n",n,d);
		}
};

void solve(int n,int size,vector<ll>&time,vector<ll>&speed)
{
	int dummy_size=size,ci=0;
	Fraction answer_time(0,1);
	while(dummy_size>0)
	{
		int done=0;
		if(ci<n-1)
		{
			done=(time[ci+1]-time[ci])*speed[ci];
			if(done>dummy_size)
				done=dummy_size;
			Fraction tempf(done,speed[ci]);
			answer_time=answer_time+tempf;
			ci++;
		}
		else
		{
			answer_time = answer_time+Fraction(dummy_size,speed[ci]);
			done=dummy_size;
		}
		dummy_size-=done;
	}
	//cout<<"before all removals the time taken for download is : ";
	//answer_time.print();

	Fraction final_answer=answer_time;
	for(int i=0;i<n-1;i++)
	{
		dummy_size=(time[i+1]-time[i])*speed[i];
		if(dummy_size > size)
			dummy_size=size;
		Fraction ft(dummy_size,speed[i]);
		answer_time = answer_time-ft;
		while(dummy_size>0)
		{
			int done=0;
			if(ci<n-1)
			{
				done=(time[ci+1]-time[ci])*speed[ci];
				if(done>dummy_size)
					done=dummy_size;
				Fraction tempf(done,speed[ci]);
				answer_time=answer_time+tempf;
				ci++;
			}
			else
			{
				answer_time = answer_time+Fraction(dummy_size,speed[ci]);
				done=dummy_size;
			}
			dummy_size-=done;
		}
		//cout<<"after removing slot "<<i<<" the new time is : ";
		//answer_time.print();
		if(answer_time<final_answer)
			final_answer = answer_time;
	}

	final_answer.print();
}
int main()
{
	int n,size;
	scanf("%d%d",&n,&size);
	vector<ll>time(n);
	vector<ll>speed(n);
	for(int i=0;i<n;i++)
		scanf("%lld%lld",&time[i],&speed[i]);
	solve(n,size,time,speed);
	return 0;
}
