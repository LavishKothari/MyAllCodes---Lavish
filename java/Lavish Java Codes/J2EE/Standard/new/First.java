/*
	this program illustrates type4
	creating a connection with the database and then 
	executing an SQL query
	printing the corresponding result
	
	here the sql query is regarding retrieving the data from the database.
*/

import java.sql.*;

class First
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
			
			Statement st=cn.createStatement();
			ResultSet rs=st.executeQuery("select * from studs");
			
			while(rs.next())
			{
				String name=rs.getString("NAME");
				int age=rs.getInt("AGE");
				String add=rs.getString("ADDRESS");
				
				System.out.printf("%-10s%-3d%-10s\n",name,age,add);
			}
			st.close();
			cn.close();
		}
		catch(SQLException e)
		{
			System.out.println(e);
		}	
	}
}