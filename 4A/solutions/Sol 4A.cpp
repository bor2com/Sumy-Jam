#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long long w, h, a, n, left = -1, right;
	scanf("%lld%lld%lld", &w, &h, &n);
	right = max(w * n, h * n);
	while (left + 1 != right) {
		a = (left + right) / 2;
		((a / w) * (a / h) >= n ? right : left) = a;
	}
	printf("%lld\n", right);
	return 0;
}
