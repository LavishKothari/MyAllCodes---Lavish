package dmatics;

public class List
{
 private Node start,last;
 private int count;

 public void append(int val)
 {
  Node nd=new Node(val);
  if(start==null)
   start=nd;
  else
   last.next=nd;
  last=nd;
  count++;
 }

 public void print()
 {
  Node ptr=start;
  while(ptr!=null)
  {
   System.out.println(ptr);
   ptr=ptr.next;
  }
 }

 public boolean isExist(int val)
 {
  Node ptr=start;
  while(ptr!=null && ptr.val!=val)
   ptr=ptr.next;

  if(ptr!=null)
   return true;
  return false;
 }

 public int getCount()
 {
  return count;
 }

 public boolean remove(int val)
 {
  Node prv=null,ptr=start;
  while(ptr!=null && ptr.val!=val)
  {
   prv=ptr;
   ptr=ptr.next;
  }

  if(ptr!=null)
  {
   if(ptr==start)
    start=start.next;
   else
   {
    prv.next=ptr.next;
    if(ptr==last)
     last=prv;
   }
   count--;
   return true;
  }
  return false;
 }

 public String toString()
 {
  String str="";
  Node ptr=start;
  while(ptr!=null)
  {
   str=str+ptr+"\n";
   ptr=ptr.next;
  }
  return str;
 }  

 class Node
 {
  private int val;
  Node next;

  Node(){}

  Node(int val)
  {
   this.val=val;
  }

  public String toString()
  {
   return String.valueOf(val);
  }
 }
}