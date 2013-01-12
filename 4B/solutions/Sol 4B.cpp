#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> maj;
int n, pos, m, k, i;

int main () {
    scanf ("%d%d", &n, &k);
    maj.resize (n);
    for(pos = 0; pos < n; ++pos) {
        scanf ("%d", &maj[pos]);
    }
    while (--k >= 0) {
        scanf ("%d", &i);
        puts(binary_search (maj.begin(), maj.end(), i)?"YES":"NO");
    }
    return 0;
}
