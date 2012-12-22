#include <cstdio>

typedef long long i64;

const int N = 3;

struct pt {
  int x, y;
} pts[N];

pt operator- (pt a, pt b) {
  pt vec;
  vec.x = b.x - a.x;
  vec.y = b.y - a.y;
  return vec;
}

i64 cross(pt a, pt b) {
  return i64(a.x) * i64(b.y) - i64(a.y) * i64(b.x);
}

int main() {
  int i;
  for (i = 0; i < N; ++i) {
    scanf("%d%d", &pts[i].x, &pts[i].y);
  }
  i64 css = cross(pts[1] - pts[0], pts[2] - pts[0]);
  printf("%lld.%lld\n", css / 2, (css % 2) * 5);
  return 0;
}
