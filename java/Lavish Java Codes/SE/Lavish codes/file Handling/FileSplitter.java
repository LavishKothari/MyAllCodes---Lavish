import java.io.*;

class FileSplitter
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter the name of file to be splitted with absolute path : ");
			File f0=new File(br.readLine());
			// f0 contains the file to be splitted
			
			System.out.println("Enter the number of bytes in which file will be splitted : ");
			int n=Integer.parseInt(br.readLine());
			// n contains the size of new files created after splitting
			int numberOfFiles;
			if(f0.length()%n==0)
				numberOfFiles=(int)f0.length()/n;
			else
				numberOfFiles=(int)f0.length()/n+1;
				
			File f[]=new File[numberOfFiles];
			for(int i=0;i<f.length;i++)
			{
				f[i]=new File(f0.getParent()+"//f"+(i+1));
				f[i].createNewFile();
			}
			
			FileOutputStream fos=new FileOutputStream(f[0]);
			FileInputStream fis=new FileInputStream(f0);
			
			int counter=0,fileCounter=0;
			int ch;
			
			while((ch=fis.read())!=-1)
			{
				if(counter%n==0)
				{
					fos=new FileOutputStream(f[fileCounter]);
					fileCounter++;
				}
				fos.write(ch);
				counter++;
			}
			fis.close();
			/* you should close the fis fileInputStream in order to delete the file.*/
			System.out.println("Original File Deleted : "+f0.delete());
			fos.close();
			System.out.println("\nfile splitting done successfully...");
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}
}