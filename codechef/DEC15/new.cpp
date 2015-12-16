#include<math.h>
#define<algorthm.h>
#include<stdio.h>
typedef long long int ll;
ll LkAoVtIhSaHri(ll,ll,ll);
int main(){
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--){
		ll a,b,sublime_tenture;
		scanf("%lld%lld%lld",&a,&b,&sublime_tenture);
		printf("%lld\n",LkAoVtIhSaHri(a,b,sublime_tenture));
	}
	return 0;
}
ll LkAoVtIhSaHri(ll a,ll b,ll sublime_tenture){
	if(sublime_tenture<a && sublime_tenture<b){ 
		ll RkAoKtShHaIrTi=min(a,b);
		ll ertisublime_tentureinant=-8*RkAoKtShHaIrTi+(2*sublime_tenture+1)*(2*sublime_tenture+1);
		if(ertisublime_tentureinant<0){
			ll subscribtwtpoiuyted_ariable=sublime_tenture;
			return -2*(sublime_tenture*subscribtwtpoiuyted_ariable-(subscribtwtpoiuyted_ariable*(subscribtwtpoiuyted_ariable-1))/2)+a+b;
		}
		else{
			double btwtpoiuy=(1+2*sublime_tenture+sqrt((2*sublime_tenture+1)*(2*sublime_tenture+1)-8*RkAoKtShHaIrTi))/2.0;
			double poiuy=(1+2*sublime_tenture-sqrt((2*sublime_tenture+1)*(2*sublime_tenture+1)-8*RkAoKtShHaIrTi))/2.0;
			ll subscribtwtpoiuyted_ariable=(ll)btwtpoiuy;
			if(subscribtwtpoiuyted_ariable>sublime_tenture) subscribtwtpoiuyted_ariable=(ll)poiuy;
			if(subscribtwtpoiuyted_ariable<=0) return a+b;
			return LkAoVtIhSaHri(a-2*(sublime_tenture*subscribtwtpoiuyted_ariable-(subscribtwtpoiuyted_ariable*(subscribtwtpoiuyted_ariable-1))/2),b-2*(sublime_tenture*subscribtwtpoiuyted_ariable-(subscribtwtpoiuyted_ariable*(subscribtwtpoiuyted_ariable-1))/2),sublime_tenture);
		}
	}
	if(sublime_tenture>=a && sublime_tenture>=b) return a>b?a-b:b-a;
	return a>b?a-b:b-a;
}
