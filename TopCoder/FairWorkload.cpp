#include <bits/stdc++.h>

#define MAX 15000

using namespace std;

bool isPossible(vector<int> &folders, int &workers, int &work){
	int counter = 1, aux = 0;
	for(const auto& f : folders){
		if(aux + f > work){
			aux = f;
			counter++;
		}else{
			aux += f;
		}
	}

	if(aux > work) return false;

	return counter <= workers;
}

int getMostWork(vector<int> &folders, int &workers){
	int left = 1, right = MAX, mid;
	while(left < right){
		mid = left + ((right - left) >> 1);
		if(isPossible(folders, workers, mid)) right = mid;
		else left = mid+1;
	}

	return left;
}

int main(){
	vector<int> folders = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };
	int workers = 6;
	cout << getMostWork(folders, workers) << endl;
	return 0;
}
