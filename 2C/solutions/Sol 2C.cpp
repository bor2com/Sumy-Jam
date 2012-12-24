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

#define DELIM " "

const int N = 1003;

char field[N][N], buf[N * 10], *ptr;

int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

queue<pii> qu;

pii trace[N][N];

int main() {
  int i, j, n, m, d, di, dj, xi = -1, xj;
  scanf("%d%d\n", &n, &m);
  assert(n > 0 && m > 0 && n <= 1000 && m <= 1000);
  FOR (i, n) {
    gets(buf);
    for (j = 0, ptr = strtok(buf, DELIM); ptr != NULL; ptr = strtok(NULL, DELIM), ++j) {
      assert(ptr[1] == '\0');
      assert(ptr[0] == '.' || ptr[0] == 'x' || ptr[0] == '#');
      field[i][j] = ptr[0];
      if (field[i][j] == 'x') {
        assert(xi < 0);
        xi = i;
        xj = j;
      }
    }
    assert(j == m);
  }
  C(trace, -1);
  trace[xi][xj] = pii(xi, xj);
  for (qu.push(pii(xi, xj)); qu.size(); qu.pop()) {
    i = qu.front().X;
    j = qu.front().Y;
    if (i == 0 && j == 0) {
      pii cur = qu.front();
      while (cur.X != xi || cur.Y != xj) {
        printf("(%d;%d) ", cur.Y, cur.X);
        cur = trace[cur.X][cur.Y];
      }
      printf("(%d;%d)\n", xj, xi);
      return 0;
    }
    FOR (d, 4) {
      di = i + dir[d][0];
      dj = j + dir[d][1];
      if (di >= 0 && dj >= 0 && di < n && dj < m && field[di][dj] != '#' && trace[di][dj].X < 0) {
        trace[di][dj] = qu.front();
        qu.push(pii(di, dj));
      }
    }
  }
  assert(false);
  return 0;
}