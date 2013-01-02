#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;

const int N = 1e5 + 5;

vi graph[N];

int dist[N];

int main() {
    // freopen("out.txt", "w", stdout);
    int n, m, i, s, f, a, b;
    scanf("%d%d%d%d", &n, &m, &s, &f), --s, --f;
    for (i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b), --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> qu;
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    for (qu.push(s); qu.size(); qu.pop()) {
        a = qu.front();
        for (i = 0; i < graph[a].size(); ++i) {
            if (dist[graph[a][i]] < 0) {
                dist[graph[a][i]] = dist[a] + 1;
                qu.push(graph[a][i]);
            }
        }
    }
    printf("%d\n", dist[f]);
    return 0;
}
