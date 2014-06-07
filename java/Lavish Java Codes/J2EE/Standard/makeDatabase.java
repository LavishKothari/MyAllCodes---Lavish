import java.sql.*;

class MakeDatabase
{
 public static void main(String arg[])
 {
  
  try
  {
   Class.forName("com.mysql.jdbc.Driver");
   Connection cn=DriverManager.getConnection("jdbc:mysql://localhost:3307","root","depan");
   Statement st=cn.createStatement();
   st.executeUpdate("create database mbm");
   st.close();
   cn.close();   

   cn=DriverManager.getConnection("jdbc:mysql://localhost:3307/mbm","root","depan");
   st=cn.createStatement();
   st.executeUpdate("create table studs(sid int not null,sname varchar(20),dob date,primary key(sid))");
   st.close();
   cn.close();
 
  }
  catch(ClassNotFoundException e) 
  {
   System.err.println("Driver not found");
  }
  catch(SQLException e)
  {
   System.err.println("SQL Failed..");
  }
 }
}