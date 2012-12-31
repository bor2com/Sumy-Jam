#include <cstdio>

const int N = 1e5 + 5;

int cnt[N];

int main() {
    int n, m, i, a, b;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        ++cnt[--a];
        ++cnt[--b];
    }
    for (i = 0; i < n; ++i) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}
