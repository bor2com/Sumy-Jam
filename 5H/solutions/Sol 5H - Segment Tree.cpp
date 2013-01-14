#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long i64;

const int N = 100005;

bool head[N];

int tree[N * 8], maj[N * 2], tail[N];

int query(int qfrom, int qto, int from, int to, int v) {
  if (qfrom < qto) {
    if (qfrom == from && qto == to) {
      return tree[v];
    } else {
      int mid = (from + to) / 2;
      return query(qfrom, min(mid, qto), from, mid, v * 2)
        + query(max(qfrom, mid), qto, mid, to, v * 2 + 1);
    }
  }
  return 0;
}

void set(int q, int val, int from, int to, int v) {
  if (from + 1 == to) {
    tree[v] = val;
  } else {
    int mid = (from + to) / 2;
    if (q < mid) {
      set(q, val, from, mid, v * 2);
    } else {
      set(q, val, mid, to, v * 2 + 1);
    }
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
  }
}

int main() {
  i64 answer = 0;
  int n, i;
  memset(head, 0, sizeof(head));
  memset(tree, 0, sizeof(tree));
  scanf("%d", &n);
  for (i = 0; i < n * 2; ++i) {
    scanf("%d", maj + i);
    if (!head[maj[i]]) {
      head[maj[i]] = true;
      set(i, 1, 0, n * 2, 1);
    } else {
      tail[maj[i]] = i;
      set(i, -1, 0, n * 2, 1);
    }
  }
  for (i = 0; i < n * 2; ++i) {
    if (i != tail[maj[i]]) {
      answer += query(i + 1, tail[maj[i]], 0, n * 2, 1);
      set(i, 0, 0, n * 2, 1);
      set(tail[maj[i]], 0, 0, n * 2, 1);
    }
  }
  printf("%lld\n", answer);
  return 0;
}
