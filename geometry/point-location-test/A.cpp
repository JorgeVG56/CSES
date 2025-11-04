#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
	ll x, y;
	Point(ll a = 0, ll b = 0) : x(a), y(b) {}

  Point operator+(Point p){ return {x + p.x, y + p.y}; }
  Point operator-(Point p){ return {x - p.x, y - p.y}; }
  Point operator*(Point p){ return {x * p.x - y * p.y, x * p.y + y * p.x}; }

  Point operator*(ll d){ return {x * d, y * d}; };
  Point operator/(ll d){ return {x / d, y / d}; };

  bool operator<(Point p) const { return x < p.x || (x == p.x && y < p.y); }
  bool operator==(Point p) const{ return x == p.x && y == p.y; }

  ll dot(Point p){ return x * p.x + y * p.y; }
  ll cross(Point p){ return x * p.y - y * p.x; }
  ll cross(Point p1, Point p2){ return (p1 - *this).cross(p2 - *this); }

	friend istream &operator>>(istream &in, Point &p) {
		in >> p.x >> p.y;
		return in;
	}
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  
  for(int c = 0; c < t; c++){
    Point p1, p2, p3; cin >> p1 >> p2 >> p3;

    ll collinear = p3.cross(p1, p2);

    if(collinear > 0) cout << "LEFT";
    else if(collinear < 0) cout << "RIGHT";
    else cout << "TOUCH";

    cout << '\n';
  }

  return 0;
}