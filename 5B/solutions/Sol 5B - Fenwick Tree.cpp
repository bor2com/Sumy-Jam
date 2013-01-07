#include <cstdio>
#include <cstring>
using namespace std;

typedef long long i64;

const int N = 502;

int r, c;

i64 fen[N][N];

void ascend(int i, int j, i64 inc) {
  for (int sj = j; i < r; i |= i + 1) {
    for (j = sj; j < c; j |= j + 1) {
      fen[i][j] += inc;
    }
  }
}

i64 descend(int i, int j) {
  i64 result = 0;
  for (int sj = j; --i >= 0; i &= i + 1) {
    for (j = sj; --j >= 0; j &= j + 1) {
      result += fen[i][j];
    }
  }
  return result;
}

i64 getSum(int i1, int j1, int i2, int j2) {
  return descend(i2, j2) - descend(i2, j1) - descend(i1, j2) + descend(i1, j1);
}

int main() {
  int q, i, j, i2, j2, a;
  memset(fen, 0, sizeof(fen));
  scanf("%d%d", &r, &c);
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      scanf("%d", &a);
      ascend(i, j, a);
    }
  }
  scanf("%d", &q);
  while (--q >= 0) {
    scanf("%d%d%d%d", &i, &j, &i2, &j2);
    printf("%lld\n", getSum(i - 1, j - 1, i2, j2));
  }
  return 0;
}
