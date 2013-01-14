#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

const int N = 150005;

int tree[N * 4], price[N], growth[N];

int query(int qfrom, int qto, int from, int to, int v) {
  if (qfrom < qto) {
    if (qfrom == from && qto == to) {
      return tree[v];
    } else {
      int mid = (from + to) / 2;
      return max(query(qfrom, min(mid, qto), from, mid, v * 2),
        query(max(qfrom, mid), qto, mid, to, v * 2 + 1));
    }
  }
  return 0;
}

void build(int from, int to, int v) {
  if (from + 1 == to) {
    tree[v] = price[from];
  } else {
    int mid = (from + to) / 2;
    build(from, mid, v * 2);
    build(mid, to, v * 2 + 1);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
  }
}

int main() {
  int n, d, i, answer = 0;
  scanf("%d%d", &n, &d);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", growth + i, price + i);
  }
  build(0, n, 1);
  for (i = 0; i < n; ++i) {
    answer += growth[i] * query(i, min(i + d, n), 0, n, 1);
  }
  printf("%lld\n", answer);
  return 0;
}
