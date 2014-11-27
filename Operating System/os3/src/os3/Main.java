package os3;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Main 
{
	static Main obj;
	static int in=0,out=-1;
	static final int BUFFER_SIZE=10;
	static int buffer[];
	Main()
	{
		obj=this;
	}
	public static void main(String args[])
	{
		buffer=new int[BUFFER_SIZE];
		new Producer(obj);
		new Consumer(obj);
	}
}

class Producer implements Runnable
{
	Main obj;
	static int counter=0;
	Producer(Main obj)
	{
		this.obj=obj;
		Thread thread=new Thread(this);
		thread.start();
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true)
		{
			while((obj.in+1)%(obj.BUFFER_SIZE)==obj.out);
				
			counter++;
			obj.buffer[obj.in]=counter;
			System.out.println("Producer produced : "+obj.buffer[obj.in]);
			obj.in=(obj.in+1)%obj.BUFFER_SIZE;
			int bufferStatus;
			if(obj.out<obj.in)
			{
				bufferStatus=obj.in-obj.out;
			}
			else if(obj.out>obj.in)
			{
				bufferStatus=obj.BUFFER_SIZE-(obj.out-obj.in);
			}
			else
			{
				bufferStatus=0;
			}
			System.out.println("Buffer Status : "+bufferStatus);
			if(counter==1)
				obj.out++;
			/*
			 * setting a delay of 1 second.
			 */
			try 
			{
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}

class Consumer implements Runnable
{
	Main obj;
	Consumer(Main obj) 
	{
		// TODO Auto-generated constructor stub
		this.obj=obj;
		Thread thread=new Thread(this);
		thread.start();
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		new ConsumerFrame(obj);
	}
}

class ConsumerFrame extends JFrame implements ActionListener
{
	Main obj;
	ConsumerFrame(Main obj) {
		this.obj=obj;
		setSize(50,50);
		setLocation(100,100);
		setVisible(true);
		
		JButton consumerButton=new JButton("Consume");
		add(consumerButton);
		consumerButton.addActionListener(this);
	}

	@Override
	public void actionPerformed(ActionEvent ae) {
		// TODO Auto-generated method stub
		while(obj.in==obj.out);
		
		System.out.println("Consumer Consumed : "+obj.buffer[obj.out]);
		obj.out=(obj.out+1)%obj.BUFFER_SIZE;
		
		int bufferStatus;
		if(obj.out<obj.in)
		{
			bufferStatus=obj.in-obj.out;
		}
		else if(obj.out>obj.in)
		{
			bufferStatus=obj.BUFFER_SIZE-(obj.out-obj.in);
		}
		else
		{
			bufferStatus=0;
		}
		System.out.println("Buffer Status : "+bufferStatus);
	}
	
}