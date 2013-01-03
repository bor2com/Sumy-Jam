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

const int N = 20;

int dig[N];

i64 dp[N][2][N];

int main() {
  i64 num;
  int a, n, i, j, m, d;
  C(dp, 0);
  dp[0][0][0] = dp[0][1][0] = 1;
  scanf(I64, &num);
  for (n = 0; num != 0; ++n) {
    dig[n] = num % 10;
    num /= 10;
  }
  for (i = 1; i <= n; ++i) {
    for (j = 0; j < 10; ++j) {
      a = j == 4 || j == 7;
      FOR (d, N - 1) {
        dp[i][0][d + a] += dp[i - 1][0][d];
      }
    }
    for (j = 0; j <= dig[i - 1]; ++j) {
      a = j == 4 || j == 7;
      FOR (d, N - 1) {
        dp[i][1][d + a] += dp[i - 1][j == dig[i - 1]][d];
      }
    }
  }
  FOR (d, 18) {
    printf(I64 " ", dp[n][1][d]);
  }
  return 0;
}
