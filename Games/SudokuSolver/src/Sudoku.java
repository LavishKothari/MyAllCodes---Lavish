public class Sudoku {
	//static int numberArray[][];
	public static boolean isValidSudoku(int numberArray[][])
	{
		int count=0;
		int flag[]=new int[9];
		for(int z=0;z<9;z++)
			flag[z]=0;

		// checking validity of each row
		for(int i=0;i<9;i++)
		{
			for(int z=0;z<9;z++)
				flag[z]=0;

			for(int j=0;j<9;j++)
			{	
				if(numberArray[i][j]!=0)
				{
					flag[numberArray[i][j]-1]++;
				}
			}

			for(int z=0;z<9;z++)
				if(flag[z]>1)
					return false;
		}

		// checking validity of each column
		for(int i=0;i<9;i++)
		{
			for(int z=0;z<9;z++)
				flag[z]=0;

			for(int j=0;j<9;j++)
			{
				if(numberArray[i][j]!=0)
				{
					flag[numberArray[i][j]-1]++;
				}
			}

			for(int z=0;z<9;z++)
				if(flag[z]>1)
					return false;
		}

		// checking validity of each 3*3 grid
		for(int x=0;x<3;x++)
		{
			for(int y=0;y<3;y++)
			{
				for(int z=0;z<9;z++)
					flag[z]=0;

				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						int indexX=3*x+i;
						int indexY=3*y+j;
						if(numberArray[indexX][indexY]!=0)
						{
							flag[numberArray[indexX][indexY]-1]++;
						}
					}
				}
				for(int z=0;z<9;z++)
					if(flag[z]>1)
						return false;
			}
		}

		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(numberArray[i][j]>0)
					count++;
			}
		}
		if(count<17)
			return false;

		return true;
	}

	public static int [][] solveSudoku(int [][] numberArray)
	{
		//Sudoku.numberArray=numberArray;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				numberArray[i][j]=findNumberToBeFilled(i,j,numberArray);
			}
		}

		for(int i=1;i<=9;i++)
		{
			numberArray=numberInABlock(i,numberArray);
		}

		return numberArray;
	}



	public static int findNumberToBeFilled(int x,int y,int [][]numberArray)
	{
		int indexX=0,indexY=0;
		if(numberArray[x][y]==0)
		{
			int flag[]=new int[9];
			for(int z=0;z<9;z++)
			{
				flag[z]=0;	
			}
			for(int i=0;i<9;i++)
			{
				if(numberArray[x][i]>0)
					flag[numberArray[x][i]-1]++;
			}

			for(int i=0;i<9;i++)
			{
				if(numberArray[i][y]>0)
					flag[numberArray[i][y]-1]++;
			}


			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					indexX=3*(x/3)+i;
					indexY=3*(y/3)+j;
					if(numberArray[indexX][indexY]>0)
					{
						flag[numberArray[indexX][indexY]-1]++;
					}
				}
			}

			int count=0;
			int pos=0;
			for(int i=0;i<9;i++)
			{

				if(flag[i]==0)
				{
					count++;
					pos=i;
				}

			}
			if(count==1)
			{
				return pos+1;
			}
			return 0;
		}
		else
		{
			return numberArray[x][y];
		}
	}

	public static boolean isSudokuFilled(int[][]numberArray)
	{
		//Sudoku.numberArray=numberArray;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(numberArray[i][j]==0)
					return false;
			}
		}
		return true;
	}

	private static int[][] numberInABlock(int n,int[][] numberArray) {
		// TODO Auto-generated method stub

		///////////////////////////////////////
		//Checking for a number across each row
		for(int i=0;i<9;i++)
		{
			int counter=0;
			int flag[]=new int[9];
			for(int z=0;z<9;z++)
			{
				flag[z]=0;
			}

			for(int j=0;j<9;j++)
			{
				if(numberArray[i][j]==n)
				{
					counter++;
					break;
				}
			}
			if(counter==0)
			{
				int currentX=0;
				int currentY=0;
				int count=0;
				for(int j=0;j<9;j++)
				{
					if(isPossible(n,i,j,numberArray))
					{
						count++;
						currentX=i;
						currentY=j;
					}

				}
				if(count==1)
				{
					numberArray[currentX][currentY]=n;
				}
			}

		}

		///////////////////////////////////////
		//Checking for a number across each column

		for(int i=0;i<9;i++)
		{
			int counter=0;
			int flag[]=new int[9];
			for(int z=0;z<9;z++)
			{
				flag[z]=0;
			}

			for(int j=0;j<9;j++)
			{
				if(numberArray[j][i]==n)
				{
					counter++;
					break;
				}
			}
			if(counter==0)
			{
				int currentX=0;
				int currentY=0;
				int count=0;
				for(int j=0;j<9;j++)
				{
					if(isPossible(n,j,i,numberArray))
					{
						count++;
						currentX=j;
						currentY=i;
					}

				}
				if(count==1)
				{
					numberArray[currentX][currentY]=n;
				}
			}

		}

		///////////////////////////////////////
		//Checking for a number across each grid

		for(int x=0;x<3;x++)
		{
			for(int y=0;y<3;y++)
			{
				int counter=0;
				int flag[]=new int[9];
				for(int z=0;z<9;z++)
					flag[z]=0;

				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						int indexX=3*x+i;
						int indexY=3*y+j;
						/************************************/
						if(numberArray[indexX][indexY]==n)
						{
							counter++;
							break;
						}
						/************************************/
					}
				}

				if(counter==0)
				{
					int currentX=0;
					int currentY=0;
					int count=0;
					for(int i=0;i<3;i++)
					{
						for(int j=0;j<3;j++)
						{
							int indexX=3*x+i;
							int indexY=3*y+j;

							if(isPossible(n,indexX,indexY,numberArray))
							{
								count++;
								currentX=indexX;
								currentY=indexY;
							}
						}

					}
					if(count==1)
					{
						numberArray[currentX][currentY]=n;
					}
				}


			}
		}

		//////////////////////////////////////////////////////////////
		return numberArray;
	}

	private static boolean isPossible(int n, int i, int j, int[][] numberArray) {
		// TODO Auto-generated method stub
		if(numberArray[i][j]!=0)
			return false;



		int flag[]=new int[9];
		for(int z=0;z<9;z++)
		{
			flag[z]=0;	
		}
		for(int i1=0;i1<9;i1++)
		{
			if(numberArray[i][i1]>0)
				flag[numberArray[i][i1]-1]++;
		}

		for(int i1=0;i1<9;i1++)
		{
			if(numberArray[i1][j]>0)
				flag[numberArray[i1][j]-1]++;
		}

		int indexX=0,indexY=0;

		for(int i1=0;i1<3;i1++)
		{
			for(int j1=0;j1<3;j1++)
			{
				indexX=3*(i/3)+i1;
				indexY=3*(j/3)+j1;
				if(numberArray[indexX][indexY]>0)
				{
					flag[numberArray[indexX][indexY]-1]++;
				}
			}
		}
		if(flag[n-1]==0)
			return true;
		else
			return false;
	}
}


