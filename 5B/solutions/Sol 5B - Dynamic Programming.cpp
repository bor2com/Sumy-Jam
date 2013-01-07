#include <cstdio>
#include <cstring>
using namespace std;

typedef long long i64;

const int N = 502;

i64 maj[N][N], sum[N][N];

i64 getSum(int i1, int j1, int i2, int j2) {
  return sum[i2][j2] - sum[i2][j1] - sum[i1][j2] + sum[i1][j1];
}

int main() {
  int r, c, q, i, j, i2, j2;
  scanf("%d%d", &r, &c);
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      scanf("%lld", &maj[i][j]);
    }
  }
  memset(sum, 0, sizeof(sum));
  for (i = 1; i <= r; ++i) {
    for (j = 1; j <= c; ++j) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + maj[i - 1][j - 1];
    }
  }
  scanf("%d", &q);
  while (--q >= 0) {
    scanf("%d%d%d%d", &i, &j, &i2, &j2);
    printf("%lld\n", getSum(i - 1, j - 1, i2, j2));
  }
  return 0;
}
