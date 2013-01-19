#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005;

// storage

struct Event {

  bool special, open;
  int x, y1, y2;

  bool operator< (const Event& r) const {
    if (x != r.x) {
      return x < r.x;
    }
    // we should postpone special opening
    if (open && special) {
      return false;
    }
    if (r.open && r.special) {
      return true;
    }
    // and advance special closing
    if (!open && special) {
      return true;
    }
    if (!r.open && r.special) {
      return false;
    }
    // finally any opening should precede closing
    if (open) {
      return false;
    }
    if (r.open) {
      return true;
    }
    // else they are probably identical
    return false;
  }

} maj[N];

void read(int i, bool spec) {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  maj[i].x = x1;
  maj[i + 1].x = x2;
  maj[i].open = true;
  maj[i + 1].open = false;
  maj[i].y1 = maj[i + 1].y1 = y1 + 100000;
  maj[i].y2 = maj[i + 1].y2 = y2 + 100000;
  maj[i].special = maj[i + 1].special = spec;
}

// segment minimum tree

int tree[N * 4], augment[N * 4];

void alter(int qfrom, int qto, int val, int from, int to, int v) {
  if (qfrom < qto) {
    if (qfrom == from && qto == to) {
      augment[v] += val;
    } else {
      if (augment[v] != 0) {
        if (from + 1 == to) {
          tree[v] += augment[v];
        } else {
          augment[v * 2] += augment[v];
          augment[v * 2 + 1] += augment[v];
          augment[v] = 0;
        }
      }
      int mid = (from + to) / 2;
      alter(qfrom, min(mid, qto), val, from, mid, v * 2);
      alter(max(qfrom, mid), qto, val, mid, to, v * 2 + 1);
      tree[v] = min(tree[v * 2] + augment[v * 2], tree[v * 2 + 1] + augment[v * 2 + 1]);
    }
  }
}

bool solve() {
  int n, i;
  memset(tree, 0, sizeof(tree));
  memset(augment, 0, sizeof(augment));
  
  read(0, true);
  scanf("%d", &n), ++n;
  for (i = 1; i < n; ++i) {
    read(i * 2, false);
  }
  sort(maj, maj + n * 2);
  
  // sweepline
  for (i = 0; i < n * 2; ++i) {
    alter(maj[i].y1, maj[i].y2, maj[i].open != maj[i].special ? 1 : -1, 0, N, 1);
    if (tree[1] + augment[1] < 0) {
      return true;
    }
  }
  return false;
}

int main() {
  puts(solve() ? "YES" : "NO");
  return 0;
}
