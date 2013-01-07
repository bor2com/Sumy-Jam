#include <cstdio>
#include <cstring>
using namespace std;

typedef long long i64;

const int N = 502;

i64 maj[N][N];

int main() {
  i64 sum;
  int r, c, q, i, j, i1, j1, i2, j2;
  scanf("%d%d", &r, &c);
  for (i = 1; i <= r; ++i) {
    for (j = 1; j <= c; ++j) {
      scanf("%lld", &maj[i][j]);
    }
  }
  scanf("%d", &q);
  while (--q >= 0) {
    scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
    for (sum = 0, i = i1; i <= i2; ++i) {
      for (j = j1; j <= j2; ++j) {
        sum += maj[i][j];
      }
    }
    printf("%lld\n", sum);
  }
  return 0;
}
