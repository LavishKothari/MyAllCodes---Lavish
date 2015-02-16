#include<stdio.h>
int c[1000001]={0},h[1000001]={0},e[1000001]={0},f[1000001]={0};

int ch[1000001][1000001];
int ce[1000001][1000001];
int cf[1000001][1000001];
int hc[1000001][1000001];
int he[1000001][1000001];
int hf[1000001][1000001];
int ec[1000001][1000001];
int eh[1000001][1000001];
int ef[1000001][1000001];
int fc[1000001][1000001];
int fh[1000001][1000001];
int fe[1000001][1000001];

void function(char a,char b,int c[],int h[],int e[],int f[])
{
    int l,r,finalAnswer,i,countb,answer;
    if(b=='c') { if(l!=0) answer=c[r]-c[l-1]; else answer=c[r]; }
    else if(b=='h') { if(l!=0) answer=h[r]-h[l-1]; else answer=h[r]; }
	else if(b=='e') { if(l!=0) answer=e[r]-e[l-1]; else answer=e[r]; }
    else if(b=='f') { if(l!=0) answer=f[r]-f[l-1]; else answer=f[r]; }
    if(a=='c' && b=='h')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                ch[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='c' && b=='e')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                ce[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='c' && b=='f')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                cf[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='h' && b=='c')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                hc[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='h' && b=='e')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                he[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='h' && b=='f')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                hf[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='e' && b=='c')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                ec[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='e' && b=='h')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                eh[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='e' && b=='f')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                ef[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='f' && b=='c')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                fc[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='f' && b=='h')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                fh[l][r]=finalAnswer;
            }   
        }
    }
    
    if(a=='f' && b=='e')
    {  
        for(l=0;str[l];l++)
        {
            for(r=l;str[r];r++)
            {
                finalAnswer=0;
		        for(i=l;i<=r;)
		        {
			        if(str[i]==b)
			        {
				        countb++;
				        answer--;
				        ++i;
			        }
			        else if(str[i]==a)
			        {
				        finalAnswer+=answer;
				        i++;
				        while(str[i] && i<=r && str[i]!=a)
				        {
					        if(str[i]==b)
						        answer--;
					        i++;
				        }
			        }
			        else i++;
		        }
                fe[l][r]=finalAnswer;
            }   
        }
    } 
}
int main()
{
	char str[1000001],a,b;
	int i,l,r,q,countb,answer,finalAnswer;
	scanf(" %s %d",str,&q);
	for(i=0;str[i];i++)
	{
		if(i==0)
		{
			if(str[i]=='c') c[0]++;
			else if(str[i]=='h') h[0]++;
			else if(str[i]=='e') e[0]++;
			else if(str[i]=='f') f[0]++;
		}
		else
		{
			if(str[i]=='c') { c[i]=c[i-1]+1; h[i]=h[i-1]; e[i]=e[i-1]; f[i]=f[i-1]; }
			else if(str[i]=='h') { c[i]=c[i-1]; h[i]=h[i-1]+1; e[i]=e[i-1]; f[i]=f[i-1]; }
			else if(str[i]=='e') { c[i]=c[i-1]; h[i]=h[i-1]; e[i]=e[i-1]+1; f[i]=f[i-1]; }
			else if(str[i]=='f') { c[i]=c[i-1]; h[i]=h[i-1]; e[i]=e[i-1]; f[i]=f[i-1]+1; }
		}
	}
	while(q--)
	{
		scanf(" %c %c %d %d",&a,&b,&l,&r);
		l--;r--;
		if(a=='c' && b=='h')
		    printf("%d\n",ch[l][r]);
		if(a=='c' && b=='e')
		    printf("%d\n",ce[l][r]);
		if(a=='c' && b=='f')
		    printf("%d\n",cf[l][r]);
		
		if(a=='h' && b=='c')
		    printf("%d\n",hc[l][r]);
		if(a=='h' && b=='e')
		    printf("%d\n",he[l][r]);
		if(a=='h' && b=='f')
		    printf("%d\n",hf[l][r]);
		    
		if(a=='e' && b=='c')
		    printf("%d\n",ec[l][r]);
		if(a=='e' && b=='h')
		    printf("%d\n",eh[l][r]);
		if(a=='e' && b=='f')
		    printf("%d\n",ef[l][r]);
		
		if(a=='f' && b=='c')
		    printf("%d\n",fc[l][r]);
		if(a=='f' && b=='h')
		    printf("%d\n",fh[l][r]);
		if(a=='f' && b=='e')
		    printf("%d\n",fe[l][r]);
		
	}
	return 0;
}
