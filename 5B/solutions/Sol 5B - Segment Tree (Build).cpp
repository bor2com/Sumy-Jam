#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

const int N = 502;

int r, c;

i64 tree[N * 4][N * 4], maj[N][N];

i64 queryY(const int& yfrom, const int& yto, const int& from, const int& to, const int& vx, const int& vy) {
  if (yfrom < yto) {
    if (yfrom == from && yto == to) {
      return tree[vx][vy];
    } else {
      int mid = (from + to) / 2;
      return queryY(yfrom, min(mid, yto), from, mid, vx, vy * 2)
        + queryY(max(yfrom, mid), yto, mid, to, vx, vy * 2 + 1);
    }
  }
  return 0;
}

i64 queryX(const int& xfrom, const int& xto, const int& yfrom, const int& yto, const int& from, const int& to, const int& vx) {
  if (xfrom < xto) {
    if (xfrom == from && xto == to) {
      return queryY(yfrom, yto, 0, c, vx, 1);
    } else {
      int mid = (from + to) / 2;
      return queryX(xfrom, min(mid, xto), yfrom, yto, from, mid, vx * 2)
        + queryX(max(xfrom, mid), xto, yfrom, yto, mid, to, vx * 2 + 1);
    }
  }
  return 0;
}

void buildY(const int& xfrom, const int& xto, const int& yfrom, const int& yto, const int& vx, const int& vy) {
  if (yfrom + 1 == yto) {
    if (xfrom + 1 == xto) {
      tree[vx][vy] = maj[xfrom][yfrom]; // direct
    } else {
      tree[vx][vy] = tree[vx * 2][vy] + tree[vx * 2 + 1][vy]; // belt
    }
  } else {
    int ymid = (yfrom + yto) / 2;
    buildY(xfrom, xto, yfrom, ymid, vx, vy * 2);
    buildY(xfrom, xto, ymid, yto, vx, vy * 2 + 1);
    tree[vx][vy] = tree[vx][vy * 2] + tree[vx][vy * 2 + 1];
  }
}

void buildX(const int& from, const int& to, const int& vx) {
  if (from + 1 != to) {
    int mid = (from + to) / 2;
    buildX(from, mid, vx * 2);
    buildX(mid, to, vx * 2 + 1);
  }
  buildY(from, to, 0, c, vx, 1);
}

int main() {
  int q, i, j, i1, j1, i2, j2;
  scanf("%d%d", &r, &c);
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      scanf("%lld", &maj[i][j]);
    }
  }
  buildX(0, r, 1);
  scanf("%d", &q);
  while (--q >= 0) {
    scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
    printf("%lld\n", queryX(i1 - 1, i2, j1 - 1, j2, 0, r, 1));
  }
  return 0;
}
