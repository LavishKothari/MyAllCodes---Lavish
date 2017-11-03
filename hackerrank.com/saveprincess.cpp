#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid)
{
	//cout<<grid[0][0]<<endl<<grid[0][n-1]<<endl<<grid[n-1][0]<<endl<<grid[n-1][n-1];
	int mx,my,px,py;
	if(grid[0][0]=='p'){px=0;py=0;}
	else if(grid[0][n-1]=='p'){px=0;py=n-1;}
	else if(grid[n-1][0]=='p'){px=n-1;py=0;}
	else if(grid[n-1][n-1]=='p'){px=n-1;py=n-1;}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(grid[i][j]=='m'){mx=i;my=j;}
	//cout<<mx<<my<<px<<py;
	for(int i=my;i<py;i++)
		cout<<"RIGHT\n";
	for(int i=py;i<my;i++)
		cout<<"LEFT\n";
	for(int i=mx;i<px;i++)
		cout<<"DOWN\n";
	for(int i=px;i<mx;i++)
		cout<<"UP\n";
}
int main(void) {

	int m;
	vector <string> grid;

	cin >> m;

	for(int i=0; i<m; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m,grid);

	return 0;
}

