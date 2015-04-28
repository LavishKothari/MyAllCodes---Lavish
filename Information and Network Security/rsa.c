/*
    Sample test case 1 :
        Choose p = 3 and q = 11
        Compute n = p * q = 3 * 11 = 33
        Compute φ(n) = (p - 1) * (q - 1) = 2 * 10 = 20
        Choose e such that 1 < e < φ(n) and e and n are coprime. Let e = 7
        Compute a value for d such that (d * e) % φ(n) = 1. One solution is d = 3 [(3 * 7) % 20 = 1]
        Public key is (e, n) => (7, 33)
        Private key is (d, n) => (3, 33)
        The encryption of m = 2 is c = 27 % 33 = 29
        The decryption of c = 29 is m = 293 % 33 = 2
        
    Sample test case 2 :
        Choose p = 61 and q = 53
        Compute n = p * q = 61 * 53 = 3233
        Compute φ(n) = (p - 1) * (q - 1) = 60 * 52 = 3120
        Choose e such that 1 < e < φ(n) and e and n are coprime. Let e = 17
        Compute a value for d such that (d * e) % φ(n) = 1. One solution is d = 2753 [(2753 * 17) % 20 = 1]
        Public key is (e, n) => (17, 3233)
        Private key is (d, n) => (2753, 3233)
        The encryption of m = 65 is c = 2790
        The decryption of c = 2790 is m = 65
*/
#include<stdio.h>
/*
    Exponentiation by squaring
        http://en.wikipedia.org/wiki/Exponentiation_by_squaring
*/
long long int power(long long int a,long long int b,long long int mod)
{
    long long int t;
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    t=power(a,b/2,mod);
    if(b%2==0)
        return (t*t)%mod;
    else
        return (((t*t)%mod)*a)%mod;
}

/*
    Euler's theorem may be used to compute modular inverse:
    According to Euler's theorem, if a is coprime to m, that is, gcd(a, m) = 1, then
        
        inverse of a = power(a,m-2) % m 
        
    but for Euler's m must be prime.
        and our mod will never be prime.
            because mod is phi(n) = (p-1)*(q-1) ... so this is never prime.
    so we cant apply Eulers Theorem to find multiplicative inverse of e
*/
/*
long long int modularMultiplicativeInverse_Euler(long long int e,long long int mod)
{
    return power(e,mod-2,mod);
}
*/
/*
long long int modularMultiplicativeInverse_ExtendedEuclideantheorem(long long int e,long long int mod)
{
    
}
*/
long long int modularMultiplicativeInverse_BruteForce(long long int e,long long int mod)
{
    long long int i;
    for(i=1;i<mod;i++)
        if((e*i)%mod==1)
            return i;
}
long long int encrypt(long long int m,long long int e,long long int n)
{
    return power(m,e,n);
}
long long int decrypt(long long int c,long long int d,long long int n)
{
    return power(c,d,n);
}
int main()
{
	long long int p,q,n,phin,d,e,m,c;
	// p and q should be prime numbers of similar bit length.
	printf("Enter the value of p and q (p and q should be primes of similar bit length) :\n");
	scanf("%lld%lld",&p,&q);
	n=p*q;
	phin=(p-1)*(q-1);

	printf("Enter an integer e such that 1 < e < %lld, and gcd(e,%lld)=1 : ",phin,phin);
	scanf("%lld",&e);

	printf("NOTE : %lld,%lld is your public key.\n",e,n);
	// e is called the public key exponent
	
	d=modularMultiplicativeInverse_BruteForce(e,phin);
	printf("NOTE : %lld,%lld is your private key.\n",d,n);
	// d is called the private key exponent
    
    printf("\nEnter the number to be encrypted : ");
    scanf("%lld",&m);
    c=encrypt(m,e,n); // sending the message to be encrypted and the public key.
    printf("the encrypted message is : %lld\n",c);
    
    printf("\nEnter the number to be decrypted : ");
    scanf("%lld",&c);
    m=decrypt(c,d,n); // sending the cipher message to be decrypted and the private key.
    printf("the decrypted message is : %lld\n",m);
	return 0;
}
