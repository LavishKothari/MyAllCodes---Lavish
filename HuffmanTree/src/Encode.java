import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Encode 
{
	String fileName;// the file to be encoded.
	public Encode(String fileName)throws IOException
	{
		this.fileName=fileName;
		encode();
	}

	public char makeCharacter(String str)
	{
		char ch=0;
		for(int i=str.length()-1,j=0;i>=0;i--,j++)
			ch+=(char)((str.charAt(i)-'0')*(int)Math.pow(2, j));
		//System.out.println((int)ch);
		return ch;
	}

	public void encode()throws IOException
	{
		int noOfCharacters=0; // distinct number of characters in the file
		HuffmanTree ht=new HuffmanTree();
		char charArrayNew[];
		long frequencyArrayNew[];
		long frequencyArray[]=new long[256];
		int ch;
		File f=new File(fileName);
		FileInputStream fis=new FileInputStream(f);
		while((ch=fis.read())!=-1)
		{
			frequencyArray[ch]++;
			if(frequencyArray[ch]==1)
				noOfCharacters++;
		}
		fis.close();
		charArrayNew=new char[noOfCharacters];
		frequencyArrayNew=new long[noOfCharacters];

		int j=0;

		for(int i=0;i<256;i++)
		{
			if(frequencyArray[i]>0)
			{
				frequencyArrayNew[j]=frequencyArray[i];
				charArrayNew[j]=(char)i;
				j++;
			}
		}

		ht.makeHuffmanTree(charArrayNew,frequencyArrayNew);

		ht.makeCodes();
		File logFile=new File(f.getParent()+f.getName().substring(0, f.getName().indexOf('.'))+"logfile.txt");
		logFile.createNewFile();
		FileOutputStream fosLog=new FileOutputStream(logFile);

		//writing Huffman code for all characters in a Log file.
		for(int i=0;i<256;i++)
		{
			if(!ht.codeString[i].equals(""))
			{
				fosLog.write((char)i);
				fosLog.write(':');

				for(int j1=0;j1<ht.codeString[i].length();j1++)
					fosLog.write(ht.codeString[i].charAt(j1));
				fosLog.write('\n');
			}
		}

		/*
		   for(int i=0;i<ht.codeString.length;i++)
		   if(!ht.codeString[i].equals(""))
		   System.out.println((char)i+ht.codeString[i]);
		 */

		//Encoding of the given file.

		File foutput=new File(f.getParent()+f.getName().substring(0, f.getName().indexOf('.'))+"encodedFile.txt");
		foutput.createNewFile();
		FileOutputStream fos=new FileOutputStream(foutput);

		fis=new FileInputStream(f);

		String tempString=new String("");
outer:while(true)
	  {
		  while(tempString.length()<=8)
		  {
			  ch=fis.read();
			  if(ch==-1)
			  {
				  // write the character corresponding to the tempString in file
				  char writeCharacter=makeCharacter(tempString);
				  fos.write(writeCharacter);
				  fosLog.write((char)(tempString.length()+'0'));
				  break outer;
			  }
			  tempString+=ht.codeString[ch];
		  }
		  String writeString=new String(tempString.substring(0,8));
		  // write the character corresponding to the writeString in file
		  char writeCharacter=makeCharacter(writeString);
		  fos.write(writeCharacter);
		  tempString=new String(tempString.substring(8, tempString.length()));
	  }
	}
}
