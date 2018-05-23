#include<bits/stdc++.h>
using namespace std;
vector<unordered_map<int,int>> L,R;

void populate(vector<int> &arr){
	for(int i=0;i<arr.size();i++){
		L.push_back(unordered_map<int,int>());
		R.push_back(unordered_map<int,int>());
	}
	for (int i = 0; i < arr.size(); i++) {
		unordered_map<int, int> &currentMap = L[i];
		int j = i, distance = 0;
		do {
			if (currentMap.find(arr[j]) == currentMap.end())
				currentMap[arr[j]] = distance;
			distance++;

			j = (j - 1 + arr.size()) % arr.size();
		} while (j != i);
	}

	for (int i = 0; i < arr.size(); i++) {
		unordered_map<int, int> &currentMap = R[i];
		int j = i, distance = 0;
		do {
			if (currentMap.find(arr[j]) == currentMap.end())
				currentMap[arr[j]] = distance;
			distance++;

			j = (j + 1 + arr.size()) % arr.size();
		} while (j != i);
	}
}

int solve(vector<int>&arr,int y,int z,char d) {
	if (d == 'L') {
		if (L[y].find(z) != L[y].end())
			return L[y][z];
		else
			return -1;

	} else {
		if (R[y].find(z) != R[y].end())
			return R[y][z];
		else
			return -1;
	}
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	populate(arr);
	while(q--) {
		int y,z;
		char c;
		//scanf(" %d%d%c",&y,&z,&c);
		cin>>y>>z>>c;
		printf("%d\n",solve(arr,y,z,c));
	}
	return 0;
}
