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

struct Polygon{
  int n;
  vector<Point> points;
  ll area;

  Polygon(int a = 0) : n(a), points(n), area(0) { }

  void calcArea(){
    for(int i = 0; i < n; i++) area += points[i].cross(points[(i + 1) % n]);
    area = abs(area);
  }

  friend istream &operator>>(istream &in, Polygon & p){
    for(int i = 0; i < p.n; i++) in >> p.points[i];
    return in;
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  Polygon p(n); cin >> p;
  
  p.calcArea();

  cout << p.area << '\n';

  return 0;
}