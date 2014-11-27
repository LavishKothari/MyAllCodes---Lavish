#include<iostream>
#include<fstream>
#include<conio.h>
#include<dos.h>
using namespace std;

void printSnake(int length,int startx,int starty,int endx,int endy,int turnx,int turny)
{
    while(startx!=endx)
    {
        gotoxy(startx,starty);
        cout<<"*";
        startx++;
    }
}

int main()
{
    char str[100];
    int endx,endy;
    ofstream out;
    cout<<"Enter the Player Name : ";
    cin>>str;
    out.open("a.txt",ios::out);
    out<<"Your Name is : "<<str<<endl;
    clrscr();

    startx=endx=0;
    while(1)
    {
        printSnake(5,startx,10,endx,10,1,1);
        delay(100);
        startx++;
        endx++;
    }

    return 0;
}
