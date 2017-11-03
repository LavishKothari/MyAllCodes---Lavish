#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
	int mx,my,px,py;
	if(grid[0][0]=='p'){px=0;py=0;}
	else if(grid[0][n-1]=='p'){px=0;py=n-1;}
	else if(grid[n-1][0]=='p'){px=n-1;py=0;}
	else if(grid[n-1][n-1]=='p'){px=n-1;py=n-1;}
	mx=r;my=c;
	if(my<py){ cout<<"RIGHT\n"; return; }
	if(py<my){ cout<<"LEFT\n"; return; }
	if(mx<px){ cout<<"DOWN\n"; return; }
	if(px<mx){ cout<<"UP\n"; return; }
}
int main(void) {

	int n, r, c;
	vector <string> grid;

	cin >> n;
	cin >> r;
	cin >> c;

	for(int i=0; i<n; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	nextMove(n, r, c, grid);
	return 0;
}

