package spellCodechefNov14;

import java.io.BufferedReader; 
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static String dict1[];
	public static int BinarySearch(String sval)
    {
		int first=0;
		int last=dict1.length-1;
        int mid;
        while(first<=last)
        {           
        	mid=(first+last)/2;
        	if(sval.compareTo(dict1[mid])==0)
	           	return mid;
	       	else if(sval.compareTo(dict1[mid])>0)
	           	first=mid+1;
	           else if(sval.compareTo(dict1[mid])<=0)
	           	last=mid-1;
	       }
	       return -1;
    }
	
	static boolean isPermutation(String s1,String s2)
	{
		int flag1[]=new int[26];
		int flag2[]=new int[26];
		for(int i=0;i<26;i++)
			flag1[i]=flag2[i]=0;
		if(s1.length()!=s2.length())
			return false;
		for(int i=0;i<s1.length();i++)
		{
			flag1[s1.charAt(i)-'a']++;
			flag2[s2.charAt(i)-'a']++;
		}
		for(int i=0;i<26;i++)
			if(flag1[i]!=flag2[i])
				return false;
		return true;
	}
	public static int calculateError(String s1,String s2)
	{
		if(s1.length()!=s2.length())
			return 2;
		int error=0;
		for(int i=0;i<s2.length();i++)
			if(s1.charAt(i)!=s2.charAt(i))
				error++;
		return error;
	}
	public static String findCompatibleWord(String str)
	{
		if(str.length()!=1)
		{
			// case 1 swapping of two letters
		
			for(int i=0;i<dict1.length;i++)
			{
				if(isPermutation(str,dict1[i]))
				{
					int error=calculateError(str, dict1[i]);
					if(error==2)
						return dict1[i];
				}
			}
		}
		// case 2 skip a letter
		// you need to insert a letter
		for(int i=0;i<=str.length();i++)
		{
			for(char j='a';j<='z';j++)
			{
				int index;
				if(i==0)
					index=BinarySearch(j+str);
				else if(i==str.length())
					index=BinarySearch(str+j);
				else
					index=BinarySearch((str.substring(0, i)+j)+str.substring(i,str.length()));
				if(index!=-1)
					return dict1[index];
			}
		}
		
		// case 3 to insert an irrelevant letter
		// you need to delete a letter from the word and then search in dict1ionary.
		if(str.length()!=1)
		{
			for(int i=0;i<str.length();i++)
			{
				int index;
				if(i==0)
					index=BinarySearch(str.substring(1, str.length()));
				else if(i==str.length())
					index=BinarySearch(str.substring(0, str.length()-1));
				else
					index=BinarySearch(str.substring(0, i)+str.substring(i+1,str.length()));
				if(index!=-1)
					return dict1[index];
			}
		}
		// case 4 mistype a letter.
		for(int i=0;i<dict1.length;i++)
		{
			int error=0;
			error=calculateError(dict1[i],str);
			if(error==1)
				return dict1[i];
		}
		return new String("");
	}
	public static void main(String[] args) throws Exception
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int d=Integer.parseInt(br.readLine());
			dict1=new String[d];
			for(int i=0;i<d;i++)
				dict1[i]=new String(br.readLine());
			StringTokenizer stz=new StringTokenizer(br.readLine());
			
			int counter=stz.countTokens();
			for(int i=0;i<counter;i++)
			{
				String punctuation="";
				int flag=0;
				String str=stz.nextToken();
				if((str.charAt(0)>='A' && str.charAt(0)<='Z') || str.length()==2)
				{
					System.out.print(str+" ");
					continue;
				}
				if(str.length()>1 && (str.charAt(str.length()-1)=='.' || str.charAt(str.length()-1)==',' || str.charAt(str.length()-1)=='?' || str.charAt(str.length()-1)=='!' || str.charAt(str.length()-2)=='\''))
				{
					flag=1;
					int index=0,actualIndex=0;
					index=str.indexOf(".");
					if(index!=-1)
					{
						actualIndex=index;
						punctuation=str.substring(index,str.length())+"";
					}
					index=str.indexOf(",");
					if(index!=-1)
					{
						actualIndex=index;
						punctuation=str.substring(index,str.length())+"";
					}
					index=str.indexOf("?");
					if(index!=-1)
					{
						actualIndex=index;
						punctuation=str.substring(index,str.length())+"";
					}
					index=str.indexOf("!");
					if(index!=-1)
					{
						actualIndex=index;
						punctuation=str.substring(index,str.length())+"";
					}
					index=str.indexOf("'");
					if(index!=-1)
					{
						actualIndex=index;
						punctuation=str.substring(index,str.length())+"";
					}
					str=str.substring(0,actualIndex);					
				}
				String strcpy=new String(str);
				if(BinarySearch(str)==-1)
					str=findCompatibleWord(str);
				if(str.equals(""))
					str=strcpy;
				if(flag==0)
					System.out.print(str+" ");
				else 
					System.out.print(str+punctuation+" ");
			}
		}
		catch(Exception e)
		{
			
		}
		
	}
}
