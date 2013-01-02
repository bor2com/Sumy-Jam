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

const int N = 502;

int dp[N][N], trace[N][N];

char one[N], two[N];

/* Trace:
 * 0 - up
 * 1 - left
 * 2 - diag
 */

int main() {
  int i, j, n, m;
  C(dp, 0);
  C(trace, 0);
  n = strlen(gets(one));
  m = strlen(gets(two));
  FORE (i, 1, n) {
    FORE (j, 1, m) {
      dp[i][j] = dp[i - 1][j];
      trace[i][j] = remax(dp[i][j], dp[i][j - 1]);
      if (one[i - 1] == two[j - 1] && remax(dp[i][j], dp[i - 1][j - 1] + 1)) {
        trace[i][j] = 2;
      }
    }
  }
  stack<char> rev;
  for (i = n, j = m; dp[i][j] != 0; ) {
    switch (trace[i][j]) {
    case 2 :
      rev.push(one[--i]);
    case 1 :
      --j;
      break;
    case 0 :
      --i;
      break;
    }
  }
  while (!rev.empty()) {
    putchar(rev.top());
    rev.pop();
  }
  putchar('\n');
  return 0;
}
