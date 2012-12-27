#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <ctime>
#include <stack>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <list>
#include <iostream>
using namespace std;

#define C(_a, _v) memset(_a,_v,sizeof(_a))
#define ALL(_obj) (_obj).begin(),(_obj).end()
#define FORB(_i,_a,_b) for((_i)=(_a);(_i)<(_b);++(_i))
#define FORE(_i,_a,_b) for((_i)=(_a);(_i)<=(_b);++(_i))
#define FOR(_i,_n) FORB(_i,0,_n)
#define FORS(_i,_obj) FOR(_i,(_obj).size())
#define ADJ(_i,_v) for((_i)=kick[_v];(_i)>=0;(_i)=foll[_i])
#define X first
#define Y second
#define I64 "%lld"
#define pb push_back
#define ppb pop_back
#define mp make_pair

typedef long long i64;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<i64, i64> pii64;
typedef vector<pii> vpii;

template<typename T>inline bool remin(T&c,const T&n){if(n<c){c=n;return 1;}return 0;}
template<typename T>inline bool remin2(T&c,const T&n){if(c<0||n<c){c=n;return 1;}return 0;}
template<typename T>inline bool remax(T&c,const T&n){if(c<n){c=n;return 1;}return 0;}
template<typename T>inline void addmod(T&c,const T&n,const T&m){c = (c + n) % m;}

int _in;int in(){scanf("%d",&_in);return _in;}

// stuff cutline

const double eps = 1e-6;

typedef complex<double> pt;

#define x real()
#define y imag()

bool zero(double a) {
  return fabs(a) < eps;
}

double dot(pt a, pt b) {
  return a.x * b.x + a.y * b.y;
}

double sqr(double a) {
  return a * a;
}

pt read() {
  int a, b;
  scanf("%d%d", &a, &b);
  return pt(a, b);
}

double det(double a11, double a12, double a21, double a22) {
  return a11 * a22 - a12 * a21;
}

pt Kramer(double a11, double a12, double b1, double a21, double a22, double b2) {
  double d = det(a11, a12, a21, a22), d1 = det(b1, a12, b2, a22), d2 = det(a11, b1, a21, b2);
  return pt(d1 / d, d2 / d);
}

int main() {
  pt m, s, a, b, ab, p, ap, pm, ref, am, normAB, target;
  m = read();
  s = read();
  a = read();
  b = read();

  // Obtaining the reflection point
  if (zero(dot(m - a, a - b))) {
    swap(a, b);
  }
  ab = b - a;
  am = m - a;
  ap = ab * dot(am, ab) / sqr(abs(ab));
  p = a + ap;
  pm = m - p;
  ref = p - pm;

  // Getting the point on the mirror
  target = Kramer(
#define X1 a.x
#define Y1 a.y
#define X2 b.x
#define Y2 b.y
    Y1 - Y2, X2 - X1, -(X2 * (Y2 - Y1) + Y2 * (X1 - X2)),
#undef X1
#undef X2
#undef Y1
#undef Y2
#define X1 s.x
#define Y1 s.y
#define X2 ref.x
#define Y2 ref.y
    Y1 - Y2, X2 - X1, -(X2 * (Y2 - Y1) + Y2 * (X1 - X2)));

  printf("%lf %lf\n", target.x, target.y);
  return 0;
}
