#include "testlib.h"
#include <set>
#include <cstring>
using namespace std;

const int V = 100005, E = 100005;

int theLock[V], kick[V], dest[E], foll[E], order[V], esnap = 0;

void addEdge(int a, int b) {
  foll[esnap] = kick[a];
  dest[esnap] = b;
  kick[a] = esnap++;
}

set<int> available;

int main(int argc, char * argv[]) {
  setName("check topological order");
  registerTestlibCmd(argc, argv);
  
  string correct = ans.readLine(), user = ouf.readLine();
  if (correct != user) {
    quitf(_wa, "Answers don\'t match. Correct: %s, user: %s", correct.data(), __testlib_part(user).data());
  }
  if (correct == "NO") {
    quitf(_ok, "OK no solution");
  }
  
  int n, m, i, j, u;
  memset(theLock, 0, sizeof(theLock));
  memset(kick, -1, sizeof(kick));
  n = inf.readInt();
  for (i = 0; i < n; ++i) {
    for (theLock[i] = m = inf.readInt(); --m >= 0; addEdge(inf.readInt() - 1, i));
    if (theLock[i] == 0) {
      available.insert(i);
    }
  }
  for (i = 0; i < n; ++i) {
    u = ouf.readInt() - 1;
    if (u < 0 || u >= n) {
      quitf(_wa, "Invalid item number %d", u + 1);
    } else if (!available.count(u)) {
      quitf(_wa, "Item %d is unavailable or duplicated", u + 1);
    }
    available.erase(u);
    for (m = kick[u]; m >= 0; m = foll[m]) {
      j = dest[m];
      if (--theLock[j] == 0) {
        available.insert(j);
      }
    }
  }
  
  quitf(_ok, "OK %d items", n);
  return 0;
}
