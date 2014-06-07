// user defined exception example

class InvalidAmountException extends Exception
{
	InvalidAmountException()
	{
		super();		
	}
	InvalidAmountException(String str)
	{	
		super(str);
	}
}

class Amount 
{
	int dollar,cent;
	public void setAmount(int dollar,int cent) throws InvalidAmountException
	{
		if(dollar>=0 && cent>=0)
		{
			this.dollar=dollar;
			this.cent=cent;
		}
		else
		{
			throw new InvalidAmountException("the amount you entered is an invalid amount!!!");
		}
	}
}

class Main
{
	public static void main(String args[])
	{
		try
		{
	
			Amount a=new Amount();
			a.setAmount(-50,30);
		}
		catch(InvalidAmountException e)
		{
			System.out.println("your Exception : "+e.getMessage());
		}
		System.out.println("program successful");

	}
}