#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000
#define START 10
#define END 1000
#define STEP 1
void bubbleSort(int*arr,int n)
{
	int i,j,temp;
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void selectionSort(int*arr,int n)
{
	int i,j,temp,mini;
	for(i=0;i<n;i++)
	{
		mini=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[mini]>arr[j])
				mini=j;
		}
		temp=arr[i];
		arr[i]=arr[mini];
		arr[mini]=temp;
	}
}
void insertionSort(int*arr,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp<arr[j])
				arr[j+1]=arr[j];
			else break;
		}
		arr[j+1]=temp;
	}
}
void merge(int*arr,int a,int mid,int b)
{
	int counter1,counter2,counter3;
	int*newArray,i;
	newArray=(int*)malloc(sizeof(int)*(b-a+1));
	counter1=a;
	counter2=mid+1;
	counter3=0;
	while(counter1<=mid && counter2<=b)
		if(arr[counter1]>arr[counter2])
			newArray[counter3++]=arr[counter2++];
		else 
			newArray[counter3++]=arr[counter1++];
	while(counter1<=mid)
		newArray[counter3++]=arr[counter1++];
	while(counter2<=b)
		newArray[counter3++]=arr[counter2++];
	for(i=a;i<=b;i++)
		arr[i]=newArray[i-a];
	free(newArray);
}
void mergeSort(int *arr,int a,int b)
{
	int mid;
	if(a<b)
	{
		mid=(a+b)/2;
		mergeSort(arr,a,mid);
		mergeSort(arr,mid+1,b);
		merge(arr,a,mid,b);
	}
}
int partition(int *arr,int a,int b)
{
	int x,i,j,temp;
	x=arr[b];
	i=a-1;
	for(j=a;j<b;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[b];
	arr[b]=arr[i+1];
	arr[i+1]=temp;
	return i+1;
}
void quickSort(int *arr,int a,int b)
{
	int p;
	if(a<b)
	{
		p=partition(arr,a,b);
		quickSort(arr,a,p-1);
		quickSort(arr,p+1,b);
	}
}
void printArray(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int binarySearch(int *arr,int a,int b,int sval)
{
	int mid;
	while(a<=b)
	{
		mid=(a+b)/2;
		if(arr[mid]==sval)
			return mid;
		if(arr[mid]>sval)
			b=mid-1;
		else 
			a=mid+1;
	}
	return -1;
}
void generateTestCases(int n)
{
	FILE*f;
	int i;
	f=fopen("test.txt","w");
	if(f)
	{
		fprintf(f,"%d\n",n);
		srand(time(NULL));
		for(i=0;i<n;i++)
		{
			fprintf(f,"%d ",(int)random()%MAX);
		}
		fclose(f);
	}
	else printf("There was some error in opening the file\n");
}
void generateTestCases1(int n)
{
	FILE*f;
	int i;
	f=fopen("test.txt","w");
	if(f)
	{
		fprintf(f,"%d\n",n);
		srand(time(NULL));
		for(i=0;i<n;i++)
		{
			fprintf(f,"%d ",i);
		}
		fclose(f);
	}
	else printf("There was some error in opening the file\n");
}
int main1()
{
	int arr[]={2,5,8,9,10,15,132,365,4545};
	printf("this the result of binary search = %d\n",binarySearch(arr,0,sizeof(arr)/sizeof(arr[0])-1,365));
	return 0;
}
int main0()
{
	int arr[]={9,8,7,6,5,4,3,2,1,5};
	system("clear");
	
	quickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr,sizeof(arr)/sizeof(arr[0]));
	
	selectionSort(arr,sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr,sizeof(arr)/sizeof(arr[0]));
	
	bubbleSort(arr,sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr,sizeof(arr)/sizeof(arr[0]));
	
	insertionSort(arr,sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr,sizeof(arr)/sizeof(arr[0]));
	
	mergeSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
int main()
{
	clock_t start,end;
	int i,j,*arr,n,sval;
	FILE*inputFile,*outputFile;
	outputFile=fopen("result.txt","w");
	for(i=START;i<=END;i+=STEP)
	{
		printf("%d\n",i);
		generateTestCases(i); // for random numbers.
		//generateTestCases1(i); // for already sorted numbers.
		/**********************************/ // Bubble Sort
		inputFile=fopen("test.txt","r");
		fscanf(inputFile,"%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
			fscanf(inputFile,"%d",&arr[j]);
		fclose(inputFile);
		
		start=clock();
		bubbleSort(arr,n);
		end=clock();
		
		fprintf(outputFile,"%d %lf\n",n,(end-start)/(double)CLOCKS_PER_SEC);
		
		free(arr);
		/**********************************/
		/**********************************/ // Insertion Sort
		inputFile=fopen("test.txt","r");
		fscanf(inputFile,"%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
			fscanf(inputFile,"%d",&arr[j]);
		fclose(inputFile);
		
		start=clock();
		insertionSort(arr,n);
		end=clock();
		
		fprintf(outputFile,"%d %lf\n",n,(end-start)/(double)CLOCKS_PER_SEC);
		free(arr);
		/**********************************/
		/**********************************/ // Selection Sort
		inputFile=fopen("test.txt","r");
		fscanf(inputFile,"%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
			fscanf(inputFile,"%d",&arr[j]);
		fclose(inputFile);
		
		start=clock();
		selectionSort(arr,n);
		end=clock();
		
		fprintf(outputFile,"%d %lf\n",n,(end-start)/(double)CLOCKS_PER_SEC);
		free(arr);
		/**********************************/
		/**********************************/ // Quick Sort
		inputFile=fopen("test.txt","r");
		fscanf(inputFile,"%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
			fscanf(inputFile,"%d",&arr[j]);
		fclose(inputFile);
		
		start=clock();
		quickSort(arr,0,n-1);
		end=clock();
		
		fprintf(outputFile,"%d %lf\n",n,(end-start)/(double)CLOCKS_PER_SEC);
		free(arr);
		/**********************************/
		/**********************************/ // Merge Sort
		inputFile=fopen("test.txt","r");
		fscanf(inputFile,"%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
			fscanf(inputFile,"%d",&arr[j]);
		fclose(inputFile);
		
		sval=arr[n/2];
		
		start=clock();
		mergeSort(arr,0,n-1);
		end=clock();
		
		fprintf(outputFile,"%d %lf\n",n,(end-start)/(double)CLOCKS_PER_SEC);
		
		//////////////////////////////////////// /* Binary search on already sorted array */
		start=clock();
		binarySearch(arr,0,n-1,sval+i%2);
		end=clock();
		fprintf(outputFile,"%d %lf\n",n,(end-start)/(double)CLOCKS_PER_SEC);
		////////////////////////////////////////
		
		free(arr);
		/**********************************/
		
	}
	fclose(outputFile);
}
