#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5;

int GCD(int a, int b) {
  return a == 0 ? b : GCD(b % a, a);
}

pii dir[N];

int main() {
  int x1, y1, x2, y2, i, n, j, counter = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    dir[i] = pii(x2 - x1, y2 - y1);
    j = GCD(dir[i].first, dir[i].second);
    dir[i].first /= j;
    dir[i].second /= j;
    if (dir[i].first < 0 || dir[i].first == 0 && dir[i].second < 0) {
      dir[i].first *= -1;
      dir[i].second *= -1;
    }
  }
  sort(dir, dir + n);
  for (i = 0; i < n; i = j) {
    for (j = i + 1; j < n && dir[i] == dir[j]; ++j);
    ++counter;
  }
  printf("%d\n", counter);
  return 0;
}
