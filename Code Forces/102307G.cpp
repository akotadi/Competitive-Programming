#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int  n, k;
vector<int> father, noReq, height;

int recursive(int index){
	if(index == 0)
		return 0;

	if(height[index] == -1){
		height[index] = recursive(father[index]) + 1;
	}
	
	return height[index];
}

class Compare{
	public:
		bool operator() (PII a, PII b){
			if(a.second != b.second) return a.second > b.second;
			if(noReq[father[a.first]] != noReq[father[b.first]]) return noReq[father[a.first]] < noReq[father[b.first]];
			return father[a.first] < father[b.first];
		}
};


int main(){
	cin >> n >> k;
	father.resize(n+1);
	noReq.resize(n+1, 0);
	height.resize(n+1, -1);
	for(auto i{1}; i <= n; i++){
		int x;
		cin >> x;
		father[i] = x;
		noReq[x]++;
	}
	for(auto i{1}; i <= n; i++)
		recursive(i);
	priority_queue< pair<int, int>, vector< pair<int, int> >, Compare > pq;
	for(auto i{1}; i <= n; i++){
		if(noReq[i] == 0)
			pq.push({i, height[i]});
	}
	int result = 0;
	while(!pq.empty()){
		result++;
		vector<int> next;
		for(auto i{0}; i < k && !pq.empty(); i++){
			auto aux = pq.top();
			pq.pop();
			int vader = father[aux.first];
			if(vader){
				noReq[vader]--;
				if(noReq[vader] == 0)
					next.push_back(vader);
			}
		}
		for(const auto& x : next)
			pq.push({x, height[x]});
	}

	cout << result << endl;
	return 0;
}
