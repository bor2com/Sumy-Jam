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

const int V = 100005, E = 100005;

int theLock[V], kick[V], dest[E], foll[E], order[V], esnap = 0;

void addEdge(int a, int b) {
  foll[esnap] = kick[a];
  dest[esnap] = b;
  kick[a] = esnap++;
}

set<int> available;

int main() {
  int n, m, i, j;
  C(theLock, 0);
  C(kick, -1);
  n = in();
  FOR (i, n) {
    for (theLock[i] = m = in(); --m >= 0; addEdge(in() - 1, i));
    if (theLock[i] == 0) {
      available.insert(i);
    }
  }
  FOR (i, n) {
    if (available.empty()) {
      puts("NO");
      return 0;
    }
    available.erase(order[i] = m = *available.begin());
    ADJ (j, m) {
      if (--theLock[dest[j]] == 0) {
        available.insert(dest[j]);
      }
    }
  }
  puts("YES");
  FOR (i, n) {
    printf("%d ", order[i] + 1);
  }
	return 0;
}
