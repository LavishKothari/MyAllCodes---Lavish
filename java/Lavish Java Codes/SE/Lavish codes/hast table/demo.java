import java.util.*;
class Main
{
	public static void main(String[]args)
	{
		Hashtable<String,Long> ht=new Hashtable<String,Long>();
		
		ht.put("Lavish",new Long(9460510404L));
		ht.put("Kothari",new Long(9456152364L));
		ht.put("Home",new Long(2942641500L));
		ht.put("Rakshit",new Long(5263415263L));
		
		System.out.println("your Hash Table                         : "+ht);
		System.out.println("Size                                    : "+ht.size());
		ht.clear();
		System.out.println("your Hash Table                         : "+ht);
		System.out.println("Size                                    : "+ht.size());
		
		/*****************************************/
		ht.put("Lavish",new Long(9460510404L));
		ht.put("Kothari",new Long(9456152364L));
		ht.put("Home",new Long(2942641500L));
		ht.put("Rakshit",new Long(5263415263L));
		
		System.out.println("ht.contains(new Long(9460510404L))      : "+ht.contains(new Long(9460510404L)));
		System.out.println("ht.containsKey(\"Home\")                  : "+ht.containsKey("Home"));
		System.out.println("ht.containsValue(new Long(9460510404L)) : "+ht.containsValue(new Long(9460510404L)));
		System.out.println("ht.get(\"Lavish\")                        : "+ht.get("Lavish"));

	}
}
		