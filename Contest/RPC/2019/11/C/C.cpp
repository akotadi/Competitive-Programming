#include <bits/stdc++.h>

#define SIZE 1005
#define MAXN 1000000005
#define rep(i,n) for(int i = 0; i < n; i++)
#define fi first
#define se second

using namespace std;

int r, c, k, maxH;
int a[SIZE][SIZE];
bool b[SIZE][SIZE];

int movX[] = {-1, 0, 1, 0}, movY[] = {0, -1, 0,  1};

struct Point{
	int x, y;
	Point(int X, int Y): x(X), y(Y) {}
};

bool isValid(int x, int y){
	if(x < 0 || x == r)
		return false;
	if(y < 0 || y == c)
		return false;
	return !b[x][y];
}

void clearQueue(queue<Point*> &q){
	while(!q.empty()) q.pop();
}

bool isPossible(int height){
	memset(b, false, sizeof(b));
	queue<Point*> bfs, next;
	int counter = 0;
	rep(i, c){
		auto p = new Point(0, i); 
		if(a[0][i] < height)
			next.push(p);
		else
			bfs.push(p);
		b[0][i] = true;
	}
	while(!bfs.empty() || !next.empty()){
		if(bfs.empty()){
			bfs = next;
			clearQueue(next);
			counter++;
			if(counter > k) return false;
		}
		auto p = bfs.front();
		bfs.pop();
		if(p->x == r-1)
			return true;
		rep(i, 4){
			if(!isValid(p->x + movX[i], p->y + movY[i])) continue;
			auto aux = new Point(p->x + movX[i], p->y + movY[i]);
			b[aux->x][aux->y] = true;
			if(a[aux->x][aux->y] < height)
				next.push(aux);
			else
				bfs.push(aux);
		}
		delete p;
	}

	return false;
}

int main(){
	maxH = -1;
	cin >> r >> c >> k;
	rep(i,r)
		rep(j,c){
			cin >> a[i][j];
			maxH = max(maxH, a[i][j]);
		}
	
	if(k == r-1) {
		cout << maxH << endl;
		return 0;
	}
	int left = 0, right = maxH+1, mid;
	while(left+1 < right){
		mid = left + ((right - left) >> 1);
		if(isPossible(mid)) left = mid;
		else right = mid;
	}

	cout << left << endl;

	return 0;
}
