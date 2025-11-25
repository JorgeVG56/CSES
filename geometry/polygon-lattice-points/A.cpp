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

  Polygon(int a = 0) : n(a), points(n) { }
  
  ll getDoubleArea(){
    ll area = 0;
    for(int i = 0; i < n; i++) area += points[i].cross(points[(i + 1) % n]);
    return abs(area);
  }

  double getArea(){
    return (double)getDoubleArea() / 2;
  }

  pair<ll, ll> getLatticePoints(){
    ll area = getDoubleArea();
    ll boundary = 0;
    for(int i = 0; i < n; i++) boundary += __gcd(abs(points[i].x - points[(i + 1) % n].x), abs(points[i].y - points[(i + 1) % n].y));
    ll inside = (area - boundary) / 2ll + 1ll;
    return {inside, boundary};
  }

  bool inDisk(Point p, Point p1, Point p2){ return (p - p1).dot(p - p2) <= 0; }
  bool onSegment(Point p, Point p1, Point p2){ return p1.cross(p2, p) == 0 && inDisk(p, p1, p2); }

  // -1/0/1 -> Outside/On Polygon/Inside
  int insidePolygon(Point p){
    int cnt = 0;
    for(int i = 0; i < n; i++){
      Point pA = points[i], pB = points[(i + 1) % n];
      if(onSegment(p, pA, pB)) return 0;
      if(pA.y <= p.y && p.y < pB.y && p.cross(pA, pB) > 0) cnt ^= 1;
      if(pB.y <= p.y && p.y < pA.y && p.cross(pB, pA) > 0) cnt ^= 1;
    }
    return cnt ? 1 : -1;
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

  pair<ll, ll> result = p.getLatticePoints();

  cout << result.first << ' ' << result.second << '\n';

  return 0;
}