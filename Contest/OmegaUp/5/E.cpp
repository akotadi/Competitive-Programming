#include <bits/stdc++.h>

using namespace std;

typedef __int128_t Long;

ostream&
operator<<(ostream& dest, __int128_t value)
{
	ostream::sentry s(dest);
	if(s){
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = end(buffer);
		do{
			--d;
			*d = "012345679"[tmp%10];
			tmp /= 10;
		}while(tmp != 0);
		if(value < 0){
			--d;
			*d = '-';
		}
		int len = end(buffer)-d;
		if(dest.rdbuf()->sputn(d,len) != len){
			dest.setstate(ios_base::badbit);
		}
	}
	return dest;
}

__int128_t max(__int128_t &a, __int128_t &b){
	return (a > b ? a : b);
}

struct cont{
	string name;
	Long pad, spac, w, h, area;
	bool isContainer, isVertical;
	vector<cont*> a;

	cont(string S, bool F): name(S), pad(0), spac(0), isContainer(true), isVertical(F), area(-1), w(0), h(0){}
	cont(string S, Long W, Long H): name(S), pad(0), spac(0), isContainer(false), area(W*H), w(W), h(H){}
};

void calcArea(cont *c){
	Long w = c->w, h = c->h;
#ifdef DEBUG
	cout << c->name << " " << w << ":" << h << " -> ";
#endif
	for(auto &con : c->a){
		if(con->area == -1ll)
			calcArea(con);
#ifdef DEBUG
		cout << "add(" << con->w << "," << con->h << ")" << con->isVertical << " ";
#endif
		if(c->isVertical){
			h += con->h;
			w = max(w, con->w);
		}
		else{
			w += con->w;
			h = max(h, con->h);
		}
	}
	
#ifdef DEBUG
	cout << w << ":" << h << " -> ";
#endif
	if(c->isContainer && !(c->a.empty())){
		w += (c->pad) << ((Long)1ll);
		h += (c->pad) << ((Long)1ll);
		if(c->isVertical)
			h += (c->spac)*((c->a.size())-(Long)1ll);
		else
			w += (c->spac)*((c->a.size())-(Long)1ll);
	}
#ifdef DEBUG
	cout << w << ":" << h << endl;
#endif
	c->h = h;
	c->w = w;
	c->area = w*h;
}

int main(){
	int n;
	cin >> n;cin.ignore();

	string s;
	map<string, cont*> check;
	for(int i{0}; i < n; i++){
		getline(cin,s);
		if(s.find(".") != string::npos){
			stringstream ss(s);
			string n1, f, n2;
			getline(ss, n1, '.');
			getline(ss, f, '(');
			getline(ss, n2, ')');
			if(f == "add")
				check[n1]->a.push_back(check[n2]);
			else if(f == "setPadding")
				check[n1]->pad = stoll(n2);
			else
				check[n1]->spac = stoll(n2);
		}else{
			stringstream ss(s);
			string type, aux, name, w, h;
			getline(ss, type, ' ');
			getline(ss, aux, ' ');
			if(aux.find("(") != string::npos){
				stringstream ss1(aux);
				getline(ss1, name, '(');
				getline(ss1, w, ',');
				getline(ss1, h, ')');
				check[name] = new cont(name, stoll(w), stoll(h));
			}else{
				name = aux;
				if(type.find("Vertical") != string::npos)
					check[name] = new cont(name, true);
				else
					check[name] = new cont(name, false);
			}
		}
	}


	for(auto &p : check){
		if(p.second->area == -1){
			calcArea(p.second);
		}
	}

	for(auto &p : check){
		cout << p.first << " " << p.second->w << " " << p.second->h << endl;
	}
}
