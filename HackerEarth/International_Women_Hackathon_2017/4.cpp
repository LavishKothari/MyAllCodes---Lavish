/*#include<iostream>
  long n,k,a[1<<20],m,o;
  main(){
  std::cin>>n>>k;
  while(n--)
  std::cin>>m,o+=2*a[m%k]++;
  std::cout<<o;
  }
 */


// with gcc

long n,k,a[1<<20],m,o;
main(){
	scanf("%ld%ld",&n,&k);
	while(n--)
		scanf("%ld",&m),o+=2*a[m%k]++;

	printf("%ld",o);
}




long n,k,a[1<<20],m,o;main(){scanf("%u%u",&n,&k);while(n--)scanf("%u",&m),o+=2*a[m%k]++;printf("%u",o);}







/*
#include<iostream>long n,k,a[1<<20],m,o;main(){std::cin>>n>>k;while(n--)std::cin>>m,o+=2*a[m%k]++;std::cout<<o;}
 */
