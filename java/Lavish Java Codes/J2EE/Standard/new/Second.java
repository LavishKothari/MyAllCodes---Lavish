/*
	this program illustrates type4
	creating a connection with the database and then 
	executing an SQL query
	printing the corresponding result
	
	here the sql query is regarding filling 
	in the values asked by the user 
	as a new row in the database;
*/
import java.io.*;
import java.sql.*;

class Second
{
	public static void main(String args[])
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
		}
		catch(ClassNotFoundException e)
		{
			System.err.println("you have an exception dear : " + e);
		}
		
		try
		{
			
			Connection cn;
			cn=DriverManager.getConnection("jdbc:mysql://localhost:3306/college","root","lavikothari");
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			
			System.out.print("enter the name : ");
			String name=br.readLine();
			
			System.out.print("enter the age : ");
			String age=br.readLine();
			
			System.out.print("enter the address : ");
			String address=br.readLine();
			
			PreparedStatement pst=cn.prepareStatement("insert into studs value(?,?,?)");
			pst.setString(1,name);
			pst.setInt(2,Integer.parseInt(age));
			pst.setString(3,address);
						
			pst.executeUpdate();
			
			pst.close();
			cn.close();
		}
		catch(SQLException e)
		{
			System.out.println(e);
		}	
		catch(IOException e){}
	}
}

