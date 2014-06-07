import java.sql.*;
class makeDatabase
{
	public static void main(String args[])
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			
			String str="jdbc:mysql://localhost:/3306";
			Connection cn=DriverManager.getConnection(str,"root","lavikothari");
			PreparedStatement pst=cn.prepareStatement("create database mbm");
			pst.executeUpdate();
			pst.close();
			cn.close();
			
			str="jdbc:mysql://localhost:/3306/mbm";
			cn=DriverManager.getConnection(str,"root","lavikothari");
			pst=cn.prepareStatement("create table stude(sid int not null, sname varchar(20),dob date, primary key(sid))");
			pst.executeUpdate();
			
			pst.close();
			cn.close();
			
			
			
			
			
		}
		catch(ClassNotFoundException e)
		{
			System.err.println("Driver not found!!! Aborting...");
		}
		catch(SQLException e)
		{
			System.err.println("SQL /Failed...");
		}
	}
}