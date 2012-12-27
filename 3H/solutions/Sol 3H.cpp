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

typedef pair<i64, i64> pt;

void read(pt& a) {
  scanf(I64 I64, &a.X, &a.Y);
}

void balance(pt& a, pt& b) {
  if (a.X > b.X) {
    swap(a.X, b.X);
  }
  if (a.Y > b.Y) {
    swap(a.Y, b.Y);
  }
}

int main() {
  i64 spanX, spanY;
  pt a, b, c, d, comLow, comHigh;
  read(a);
  read(b);
  read(c);
  read(d);
  balance(a, b);
  balance(c, d);
  comLow.X = max(a.X, c.X);
  comLow.Y = max(a.Y, c.Y);
  comHigh.X = min(b.X, d.X);
  comHigh.Y = min(b.Y, d.Y);
  spanX = comHigh.X - comLow.X;
  spanY = comHigh.Y - comLow.Y;
  printf(I64 "\n", spanX <= 0 || spanY <= 0 ? 0 : spanX * spanY);
  return 0;
}
