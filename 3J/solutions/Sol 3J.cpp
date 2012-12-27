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

typedef complex<int> pt;

#define x real()
#define y imag()

int cross(pt a, pt b) {
  return a.x * b.y - a.y * b.x;
}

int dot(pt a, pt b) {
  return a.x * b.x + a.y * b.y;
}

bool onLine(pt p, pt a, pt b) {
  return cross(p - a, b - a) == 0;
}

bool onSegment(pt p, pt a, pt b) {
  return onLine(p, a, b) && dot(a - p, b - p) <= 0;
}

const int N = 502;

pt dots[N];

bool cmp(pt a, pt b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main() {
  int n, first, i, a, b, j = -1, csign, cr;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    dots[i] = pt(a, b);
  }
  first = i = min_element(dots, dots + n, cmp) - dots;
  while (true) {
    FOR (a, n) {
      if (a != i && a != j) {
        csign = 0;
        FOR (b, n) {
          if (b != i && b != a) {
            cr = cross(dots[a] - dots[i], dots[b] - dots[i]);
            if (cr == 0 && !onSegment(dots[b], dots[i], dots[a])) {
              break;
            }
            if (cr * csign < 0) {
              break;
            }
            if (csign == 0) {
              csign = cr;
            }
          }
        }
        if (b == n) {
          j = i;
          i = a;
          printf("%d ", i + 1);
          if (i == first) {
            return 0;
          }
          break;
        }
      }
    }
  }
  return 0;
}
