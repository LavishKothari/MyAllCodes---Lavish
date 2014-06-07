import static java.lang.System.*;
import java.sql.*;

class RMeta
{
 public static void main(String arg[])
 {
  try
  {
   Class.forName("com.mysql.jdbc.Driver");
 
   Connection cn=DriverManager.getConnection("jdbc:mysql://localhost:3307/banking","root","depan");
   Statement st=cn.createStatement();   
   ResultSet rs=st.executeQuery("select transid,dot,status from trans");           

   ResultSetMetaData rm=rs.getMetaData();

   out.println("\n\t");

   for(int i=1;i<=rm.getColumnCount();i++)
    out.printf("\n%-12s   %-12s",rm.getColumnName(i),rm.getColumnTypeName(i));    


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