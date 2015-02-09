/*
 * Data structures used for Banker's Algorithm
 */
/*
 * Let the number of Processes be n and number of different resources be m.
 * Then...
 * 
 * available:	A vector of length m indicates the number of available resources
				of each type. If available[j] = k, there are k instances of resource type Rj are
				available.
 */
/*
 * max: 		An n x m matrix defines the maximum demand of each process. If
				max[i,j] = k, then process Pi may request at most k instances of resource type
				Ri.
 */

/*
 * allocation: 	An n x m matrix defines the number of resources of each type
				currently allocated to each process. If allocation[i,j] = k, then process Pi is
				currently allocated k instances of resource type Rj.
 */

/*
 * need: 		An n x m matrix indicates the remaining resource need of each
				process. If need[i,j] = k, then process Pi may need k more instances of
				resource type Ri to complete its task. Note that need[i,j] = max[i,j] -
				allocafion[i,j].
 */
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main 
{
	static String safetySequence=new String("");
	static int n,m,available[],max[][],allocation[][],need[][],request[],resources[];
	
	public static void main(String args[]) throws NumberFormatException, IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter the number of Processes : ");
		n=Integer.parseInt(br.readLine());
		
		System.out.print("Enter the number of Resources : ");
		m=Integer.parseInt(br.readLine());
		
		/*
		 * defining the data structures used in Banker's Algorithm
		 */
		available=new int[m];
		max=new int[n][m];
		allocation=new int[n][m];
		need=new int[n][m];
		request=new int[m];
		resources=new int[m];
		

		/*
		 * taking the input for the maximum of resources.
		 */
		System.out.println("Enter the number maximum number of instances available for each resource ");
		for(int i=0;i<m;i++)
		{
			System.out.print("Enter the maximum number of instances of resource "+(i+1)+" : ");
			resources[i]=Integer.parseInt(br.readLine());
		}
			
		/*
		 * taking the input for the maximum of resources needed by all the jobs.
		 */
		System.out.println("Enter the data for the max array : ");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				System.out.print("Enter the maximum instances needed by the process number : "+(i+1)+" of resource number "+(j+1)+" :");
				max[i][j]=Integer.parseInt(br.readLine());
			}
		}
		/*
		 * taking the input for filling the allocation of resources needed by all the job
		 */
		System.out.println("Enter the data for the allocation array : ");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				System.out.print("Enter the allocated instances to the process number : "+(i+1)+" of resource number "+(j+1)+" :");
				allocation[i][j]=Integer.parseInt(br.readLine());
			}
		}
		
		calculateAvailableArray();
		calculateNeedArray();
		
		/*
		 * taking the input for the request array
		 * that will be needed by a particular process 
		 */
		
		System.out.print("Enter the process number for which you will be entering the request array : ");
		int processNumber=Integer.parseInt(br.readLine())-1;
		
		System.out.println("Enter the data for request array for process "+(processNumber+1)+" : ");
		for(int i=0;i<m;i++)
		{
			System.out.print("Enter the number of instances requested for resource "+(i+1)+" : ");
			request[i]=Integer.parseInt(br.readLine());
		}
		
		/*
		 * Actual Banker's Algorithm starts here
		 */
		
		/*
		 * Banker's algorithm is divided into two sub-algorithms : 
		 * 	1. Resource Allocation Algorithm
		 * 	2. Safety Algorithm
		 */
		
		/*
		 * Resource Allocation Algorithm starts here : 
		 */
		
		/*
		 * step 1. The request of this particular process should be less than the need of this process.
		 */
		boolean isAllocationPossible=true;
		for(int i=0;i<m;i++)
		{
			if(request[i]>need[processNumber][i])
			{
				isAllocationPossible=false;
				break;
			}
		}
		/*
		 * step 2. The request of this particular process should be less than the available instances of this process.
		 */
		
		for(int i=0;i<m;i++)
		{
			if(request[i]>available[i])
			{
				isAllocationPossible=false;
				break;
			}
		}
		if(isAllocationPossible)
		{
			/*
			 * if allocation is possible then go to step 3.
			 * step 3 is as follows :
			 */
			
			/*
			 * making a clone of available, allocation and need
			 * so than we can roll back if the requested instances of resources leaves the system in deadlocked state.
			 */
			
			int availableClone[]=available.clone();
			int allocationClone[][]=allocation.clone();
			int needClone[][]=need.clone();
			
			/*
			 * making the system to pretend as if the request has been granted...
			 */
			for(int i=0;i<m;i++)
			{
				available[i]=available[i]-request[i];
			}
			for(int i=0;i<m;i++)
			{
				allocation[processNumber][i]+=request[i];
			}
			for(int i=0;i<m;i++)
			{
				need[processNumber][i]-=request[i];
			}
			
			if(!isSystemInSafeState())
			{
				System.out.println("The requested instances of the resources not allocated successfully as they don't leave the system in a safe state.");
				available=availableClone;
				allocation=allocationClone;
				need=needClone;
			}
			else
			{
				System.out.println("The requested instances of the resources are allocated successfully.");
				System.out.println("\nThe Safety Sequence is : \n"+safetySequence);
				System.out.println("The new state of the system is :");
				for(int i=0;i<n;i++)
				{
					System.out.print("P"+(i+1)+" -> ");
					for(int j=0;j<m;j++)
					{
						System.out.print(allocation[i][j]+" ");
					}
					System.out.println();
				}
			}
		}
		else
		{
			System.out.println("The Requested instances of the resources can't be allocated.");
		}
	}	
	
	public static boolean isSystemInSafeState()
	{
		/*
		 * this method contains the implementation of the safety algorithm
		 */
		int work[]=available.clone();
		boolean finish[]=new boolean[n];
		
		for(int i=0;i<finish.length;i++)
		{
			finish[i]=false;
		}
		/*
		 * step 2 starts here
		 */
		while(true)
		{
			int i;
			for(i=0;i<n;i++)
			{
				int counter=0;
				for(int j=0;j<m;j++)
				{
					if(need[i][j]<=work[j])
					{
						counter++;
					}
				}
				if(counter==m && !finish[i])
				{
					break;
				}
			}
			
			if(i==n)
			{
				int count=0;
				for(int j=0;j<n;j++)
				{
					if(finish[j])
						count++;
				}
				if(count==n)
					return true;
				else
					return false;
			}
			
			/*
				step - 3
			*/
			finish[i]=true;
			safetySequence+=("P"+(i+1)+"  ");
			
			for(int j=0;j<m;j++)
			{
				work[j]+=allocation[i][j];
			}
		}	
	}
	public static void calculateNeedArray()
	{
		/*
		 * calculating the data of need array : 
		 */
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				need[i][j]=max[i][j]-allocation[i][j];
			}
		}
		
	}
	public static void calculateAvailableArray()
	{
		/*
		 * calculating the data of the available array : 
		 */
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				available[i]+=allocation[j][i];
			}
		}
		for(int i=0;i<m;i++)
		{
			available[i]=resources[i]-available[i];
		}
	}
}