// the string should be palindrome, and it sholud contain at least n/2 distince characters.
bool ok(string s , int n)   
{
	set < char > mset;
	for(int i = 0; i < n; ++i)    {
		mset.insert(s[i]);
	}
	bool rekt = 1;
	for(int i = 0; i < n; ++i)    {
		rekt &= s[i] == s[n - i - 1];
	}
	if(mset.size() >= ( (n >> 1) + (n & 1) )   && rekt)    {
		return 1;
	}
	return 0;
} 

