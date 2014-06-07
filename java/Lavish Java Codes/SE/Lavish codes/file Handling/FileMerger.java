import java.io.*;

class FileMerger
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			
			System.out.println("Enter the parent directory of files to be merged (with absolute path) : ");
			File f=new File(br.readLine());
			File f0[]=f.listFiles();
			
			
			System.out.println("enter the name of the merged file that is to be created : ");
			File f1=new File(f.getAbsolutePath()+"//"+br.readLine());
			f1.createNewFile();
			
			FileOutputStream fos=new FileOutputStream(f1);
			FileInputStream fis=new FileInputStream(f0[0]);
			int ch;
			for(int i=0;i<f0.length;i++)
			{
				fis=new FileInputStream(f0[i]);
				while((ch=fis.read())!=-1)
				{
					fos.write(ch);
				}
			}
		}
		catch(Exception e){}
	}
}
			