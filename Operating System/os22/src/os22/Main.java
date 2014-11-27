package os22;

import java.awt.Color;
import java.awt.Graphics;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.swing.JFrame;

public class Main 
{
	static int sumCPUBurstTime;
	static int lengthOfEachBlock;
	static final int SCREEN_WIDTH=700,SCREEN_HEIGHT=280;
	static final int rectangleUpperPadding=50,rectangleHeight=100;
	static int numberOfProcesses;
	static int CPUBurstTime[];
	static BufferedReader br;
	static Main obj;
	static int timeQuantum;
	Main()
	{
		this.obj=this;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the number of processes : ");
		numberOfProcesses=Integer.parseInt(br.readLine());
		
		CPUBurstTime=new int[numberOfProcesses];
		
		System.out.print("Enter the time Quantum : ");
		timeQuantum=Integer.parseInt(br.readLine());
		
		
		for(int i=0;i<numberOfProcesses;i++)
		{
			System.out.println("________________________________________________");
			System.out.println("Enter the data for the process "+(i+1));
			System.out.println("________________________________________________");
			System.out.print("Enter the CPU Burst Time : ");
			CPUBurstTime[i]=Integer.parseInt(br.readLine());
			
			
		}
		drawGanttChart();

	}
	
	public static void drawGanttChart() throws NumberFormatException, IOException
	{
	    sumCPUBurstTime=0;


	    /* calculating the sum of all cpu burst time */
	    for(int i=0;i<numberOfProcesses;i++)
	    {
	        sumCPUBurstTime+=CPUBurstTime[i];
	    }

	    /* now the total width of the screen is to be divided into sumCPUBurstTime equal parts */
	    lengthOfEachBlock=SCREEN_WIDTH/sumCPUBurstTime;

	    drawGanttChartForPriorityScheduling();
	}
	public static void drawGanttChartForPriorityScheduling()
	{
		new FrameForRoundRobinScheduling(obj);
	}
}

class FrameForRoundRobinScheduling extends JFrame
{
	Main obj;
	int CPUBurstTime[];
	FrameForRoundRobinScheduling(Main obj)
	{
		super("Round Robin Scheduling");
		this.obj=obj;
		
		this.setVisible(true);
		this.setSize(obj.SCREEN_WIDTH+100, obj.SCREEN_HEIGHT);
		repaint();
	}
	@Override
	public void paint(Graphics g) 
	{
		super.paint(g);

		CPUBurstTime=obj.CPUBurstTime.clone();
		this.getContentPane().setBackground(Color.white);
		int currentTime=0;
		int leftStart=50;
	    int processNumber=0;
		int min,mini = 0;
		g=this.getContentPane().getGraphics();
		g.drawString(""+currentTime,leftStart,obj.rectangleUpperPadding+obj.rectangleHeight+20);
		int temptime=0;
		for(currentTime=0;currentTime<=obj.sumCPUBurstTime;currentTime++)
	    { 
	        temptime++;
	        
	        if(temptime>obj.timeQuantum || CPUBurstTime[processNumber]==0 || currentTime==obj.sumCPUBurstTime-1)
	        {
	        	System.out.println(currentTime);
	        	int blockLength=temptime-1<obj.timeQuantum?temptime-1:obj.timeQuantum;
	        	
	        	g=this.getContentPane().getGraphics();
		        g.drawRect(leftStart,obj.rectangleUpperPadding,obj.lengthOfEachBlock*blockLength,obj.rectangleHeight);
		        g.drawString("P"+(processNumber+1),leftStart+5,obj.rectangleUpperPadding+50);
		        leftStart+=obj.lengthOfEachBlock*blockLength;
		        
	        	g.drawString(""+(currentTime),leftStart,obj.rectangleUpperPadding+obj.rectangleHeight+20);
		        temptime=1;
		        int counter=0;
		        do
		        {
		        	counter++;
		        	if(counter==obj.numberOfProcesses+1)
		        		break;
		        	processNumber=(processNumber+1)%obj.numberOfProcesses;
		        	
		        }while(CPUBurstTime[processNumber]==0);
		       
		      
	        }
	        
	        CPUBurstTime[processNumber]--;
	    }
	}
}