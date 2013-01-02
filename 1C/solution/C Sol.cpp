#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;

int cnt[N];

int main() {
    int n, m, i, s, f, a, b;
    scanf("%d%d%", &n, &m);
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b), --a, --b;
        ++cnt[a];
        ++cnt[b];
    }
    long long sum = 0;
    for (i = 0; i < n; ++i) {
        sum += (long long)(cnt[i]) * (long long)(n - cnt[i] - 1);
    }
    printf("%lld\n", (long long)(n) * (long long)(n - 1) * (long long)(n - 2) / 6 - sum / 2);
    return 0;
}
