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

// typedef long long i64;
typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<i64, i64> pii64;
typedef vector<pii> vpii;
typedef complex<double> cd;

template<typename T>inline bool remin(T&c,const T&n){if(n<c){c=n;return 1;}return 0;}
template<typename T>inline bool remin2(T&c,const T&n){if(c<0||n<c){c=n;return 1;}return 0;}
template<typename T>inline bool remax(T&c,const T&n){if(c<n){c=n;return 1;}return 0;}
template<typename T>inline void addmod(T&c,const T&n,const T&m){c = (c + n) % m;}

int _in;int in(){scanf("%d",&_in);return _in;}
pii operator+(const pii&a,const pii&b){return pii(a.X+b.X,a.Y+b.Y);}

// stuff cutline

typedef complex<i64> ci;
#define x real()
#define y imag()

i64 dot(ci a, ci b) {
	return a.x * b.x + a.y * b.y;
}

i64 cross(ci a, ci b) {
	return a.x * b.y - a.y * b.x;
}

bool layOn(ci p, ci a, ci b) {
	return cross(a - p, b - p) == 0 && dot(a - p, b - p) <= 0;
}

bool intersect(ci a, ci b, ci c, ci d) {
	return cross(b - a, d - a) * cross(b - a, c - a) < 0
		&& cross(d - c, b - c) * cross(d - c, a - c) < 0
		|| layOn(a, c, d) || layOn(b, c, d)
		|| layOn(c, a, b) || layOn(d, a, b);
}

int main() {
	int ax, ay, bx, by, cx, cy, dx, dy;
	scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
	puts(intersect(ci(ax, ay), ci(bx, by), ci(cx, cy), ci(dx, dy)) ? "YES" : "NO");
	return 0;
}
