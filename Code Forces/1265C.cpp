#include <bits/stdc++.h>

using namespace std;

void print_result(int g, int s, int b){
	cout << g << " " << s << " " << b << endl;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &it : a) cin >> it;
	
	int g = 0, s = 0, b = 0;
	if(n != 1){
		int left = 0, right = (n >> 1);
		right--;
		while(right >= 0 && a[right] == a[right+1]) right--;
		if(right < 0 || right - left < 2){
			print_result(0,0,0);
			return;
		}
		g++;
		while(left < right && a[left] == a[left+1]) left++, g++;
		left++;
		if(right - left < 1){
			print_result(0,s,b);
			return;
		}
		while(s <= g){
			s++;
			while(left <= right && a[left] == a[left+1]) left++, s++;
			left++;
			if(right - left < 0){
				print_result(0,0,b);
				return;
			}
		}
		b = right - left + 1;
		if(b <= g)
			print_result(0,0,0);
		else
			print_result(g,s,right-left+1);
	}
	else{
		print_result(g,s,b);
	}
	
}

int main(){
	int t; 
	cin >> t;
	while(t--) solve();
	return 0;
}
