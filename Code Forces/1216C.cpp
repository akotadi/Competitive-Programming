#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x, y;
	Point(int X, int Y): x(X), y(Y) {}
};

struct Rectangle{
	Point p1, p2;
	Rectangle(Point P1, Point P2): p1(P1.x, P1.y), p2(P2.x, P2.y) {}
};

int main(){
	bool flag = true;
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Rectangle w(Point(x1,y1), Point(x2, y2));
	cin >> x1 >> y1 >> x2 >> y2;
	Rectangle b1(Point(x1,y1), Point(x2, y2));

	if(b1.p1.x <= w.p1.x){
		if(b1.p1.y <= w.p1.y){
			if(b1.p2.y >= w.p2.y){
				if(b1.p2.x >= w.p2.x){
					flag = false;
				}else{
					w.p1.x = max(w.p1.x, b1.p2.x);
				}
			}else if(b1.p2.x >= w.p2.x){
				w.p1.y = max(w.p1.y, b1.p2.y);
			}
		}else if(b1.p2.y >= w.p2.y){
			if(b1.p2.x >= w.p2.x){
				w.p2.y = min(w.p2.y, b1.p1.y);
			}
		}
	}else if(b1.p2.x >= w.p2.x && b1.p2.y >= w.p2.y){
		w.p2.x = min(w.p2.x, b1.p1.x);
	}

	cin >> x1 >> y1 >> x2 >> y2;
	Rectangle b2(Point(x1,y1), Point(x2, y2));

	if(b2.p1.x <= w.p1.x && b2.p1.y <= w.p1.y && b2.p2.x >= w.p2.x && b2.p2.y >= w.p2.y)
		flag = false;

	cout << ((flag)?("YES"):("NO")) << endl;

	return 0;
}
