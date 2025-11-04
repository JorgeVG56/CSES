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

struct Segment{
  Point p1, p2;

  bool inDisk(Point p){ return (p - p1).dot(p - p2) <= 0; }
  bool onSegment(Point p){ return p1.cross(p2, p) == 0 && inDisk(p); }

  int sign(ll num){ return num < 0 ? -1 : num > 0 ? 1 : 0; }

  bool properInter(Segment s, Point & p){
    ll a = s.p1.cross(s.p2, p1), b = s.p1.cross(s.p2, p2), 
        c = p1.cross(p2, s.p1), d = p1.cross(p2, s.p2);
    
    if(sign(a) * sign(b) < 0 && sign(c) * sign(d) < 0){ p = (p1 * b - p2 * a) / (b - a); return true; }

    return false;
  }

  vector<Point> segInter(Segment s){
    Point p;
    if(properInter(s, p)) return {p};
    set<Point> points;
    if(onSegment(s.p1)) points.insert(s.p1); 
    if(onSegment(s.p2)) points.insert(s.p2);
    if(s.onSegment(p1)) points.insert(p1); 
    if(s.onSegment(p2)) points.insert(p2);
    return {begin(points), end(points)};
  }

  friend istream &operator>>(istream &in, Segment &s) {
		in >> s.p1 >> s.p2;
		return in;
	}
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    Segment s1, s2; cin >> s1 >> s2;
    
    vector<Point> points = s1.segInter(s2);
    if(points.empty()) cout << "NO";
    else cout << "YES";

    cout << '\n';
  }

  return 0;
}