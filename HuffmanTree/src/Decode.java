import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;


public class Decode 
{
	String logFile,encodedFile;
	
	Decode(String logFile,String encodedFile)throws IOException
	{
		this.logFile=logFile;
		this.encodedFile=encodedFile;
		decode();
	}
	
	int isPresent(String searchString,String codedStrings[])
	{
		for(int i=0;i<codedStrings.length;i++)
		{
			if(searchString.equals(codedStrings[i]))
				return i;
		}
		return -1;
	}
	
	public void decode()throws IOException
	{
		File log=new File(logFile);
		File encoded=new File(encodedFile);
		File decoded=new File(encoded.getParent()+encoded.getName().substring(0,encodedFile.indexOf('.'))+"Decoded.txt");
		
		FileOutputStream fosDecoded=new FileOutputStream(decoded);
		FileInputStream fisLog=new FileInputStream(log);
		FileInputStream fisEncoded=new FileInputStream(encoded);
		
		String codedStrings[]=new String[256];
		for(int i=0;i<256;i++)
			codedStrings[i]=new String("");
		int remainingBitLength=0;
		int ch;
		int maxLength=0;
		/*
		    reading the logfile to store the huffman code of each character 
		*/
		while((ch=fisLog.read())!=-1)
		{
			if(fisLog.read()==-1) // extracing the : from the file
			{
				// ch is the remaining bit length
				remainingBitLength=ch-'0';
				break;
			}
			String temp=new String("");
			int a;
			while((a=fisLog.read())!='\n')
				temp+=(char)a;
			codedStrings[ch]=temp;
			if(codedStrings[ch].length()>maxLength)
				maxLength=codedStrings[ch].length();
		}

		int arr[]=new int[8];
		int a;
		int j=0;
		String searchString=new String("");
		
		RandomAccessFile randFile=new RandomAccessFile(encoded,"r");
		long randFileLength=randFile.length();
		long counter=0;
		while((ch=fisEncoded.read())!=-1)
		{
			counter++;
			int num=ch;
			for(int i=7;i>=0;i--)
			{
				int r=num%2;
				num/=2;
				arr[i]=r;
			}
			j=0;
			if((randFile.length())==counter)
			{
				j=8-remainingBitLength;
			}
			// when reading the last character start j with 8-remainingBitLength
			while(j<8)
			{
				searchString+=arr[j];
				a=isPresent(searchString,codedStrings);
				if(a!=-1)
				{
					char writecharacter=(char)a;
					//write the character writecharacter in the file.
					searchString=new String("");
					fosDecoded.write(writecharacter);
				}
				j++;
			}
		}	
		fosDecoded.close();
		fisEncoded.close();
		fisLog.close();
	}	
}
