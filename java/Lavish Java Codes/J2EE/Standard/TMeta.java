import static java.lang.System.*;
import java.sql.*;

class TMeta
{
 public static void main(String arg[])
 {
  try
  {
   Class.forName("com.mysql.jdbc.Driver");
 
   Connection cn=DriverManager.getConnection("jdbc:mysql://localhost:3307/banking","root","depan");
   
   DatabaseMetaData dm=cn.getMetaData();
   
   ResultSet rs=dm.getColumns(null,null,"cust",null);           

   out.println("\n\t");

   while(rs.next())
    out.printf("\n%-12s   %-12s   %-12s",rs.getString(4),rs.getString(5),rs.getString(6));    


  }
  catch(ClassNotFoundException e)
  {
   err.println("Driver Not Found...");
  }
  catch(SQLException e)
  {
   err.println(e.getMessage());
  }
 }
}