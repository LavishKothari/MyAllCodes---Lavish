package csub;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			int n=Integer.parseInt(br.readLine());
			String str=br.readLine();
			char cArray[]=str.toCharArray();
			int counter=0;
			for(int j=0;j<str.length();j++)
			{
				if(cArray[j]=='1')
					counter++;
			}
			long answer=((long)counter*(counter+1))/2;
			System.out.println(answer);
		}
	}

}
