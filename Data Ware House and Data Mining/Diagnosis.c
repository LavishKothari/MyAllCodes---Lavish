/*
Question 6.
THE TABLE GIVEN BELOW SHOWS THE HYPOTHETICAL TRAINING DATA FOR DISEASE DIAGNOSIS	N=NO, Y=YES

Patient id#	    Sore throat	    Fever	Swollen Glands	    congestion	    Headache	    Diagnosis
1	            Y	            Y	    Y	                Y	            Y	            Strep throat=1
2	           	N	            N	    N	                Y	            Y	            Allergy=2
3	            Y	            Y	    N	                Y	            N	            Cold=3
4	            Y	            N	    Y	                N	            N	            Strep throat=1
5	            N	            Y	    N	                Y               N	            Cold=3
6	            N	            N       N	                Y	            N	            Allergy=2
7		        N	            N       Y	                N	            N	            Strep throat=1
8		        Y	            N	    N	                Y	            Y	            Allergy=2
9	            N	            Y	    N	                Y	            Y	            Cold=3
10	            Y	            Y	    N	                N	            Y	            Cold=3

WRITE	A PROGRAM TO DISPLAY THE   DIAGNOSIS   WHEN USER ENTER THE SYMPTOMS OF A DISEASE BASED ON ABOVE GIVEN DATA.
*/

#include<stdio.h>
#include<string.h>
int findDiagnosis(char**data,char *response,int *diagnosisNumber)
{
    int i,j,maxMatch=0,current_i,counter;
    for(i=0;i<10;i++)
    {
        counter=0;
        for(j=0;j<5;j++)
        {
            if(data[i][j]==response[j])
                counter++;
        }
        if(counter>maxMatch)
        {
            maxMatch=counter;
            current_i=i;
        }
    }
    return diagnosisNumber[current_i];
}

int main()
{
    int d;
    char data[10][5]={{'Y','Y','Y','Y','Y'},
    {'N','N','N','Y','Y'},
    {'Y','Y','N','Y','N'},
    {'Y','N','Y','N','N'},
    {'N','Y','N','Y','N'},
    {'N','N','N','Y','N'},
    {'N','N','Y','N','N'},
    {'Y','N','N','Y','Y'},
    {'N','Y','N','Y','Y'},
    {'Y','Y','N','N','Y'}};

    char diagnosis[3][20];
    char response[5];
    int diagnosisNumber[]={0,1,2,0,2,1,0,1,2,2};
    int i,j,maxMatch=0,current_i,counter;



    strcpy(diagnosis[0],"Strep Throat");
    strcpy(diagnosis[1],"Allergy");
    strcpy(diagnosis[2],"Cold");

    printf("Sore throat ? ");
    scanf(" %c",&response[0]);

    printf("Fever ? ");
    scanf(" %c",&response[1]);

    printf("Swollen Glands ? ");
    scanf(" %c",&response[2]);

    printf("congestion ? ");
    scanf(" %c",&response[3]);

    printf("Headache ? ");
    scanf(" %c",&response[4]);

    for(i=0;i<10;i++)
    {
        counter=0;
        for(j=0;j<5;j++)
        {
            if(data[i][j]==response[j])
                counter++;
        }
        if(counter>maxMatch)
        {
            maxMatch=counter;
            current_i=i;
        }
    }
    d=diagnosisNumber[current_i];

    printf("\n DIAGNOSIS : %s",diagnosis[d]);
    return 0;
}
