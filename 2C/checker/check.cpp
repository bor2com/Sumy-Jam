#include "testlib.h"
#include <cstdio>
#include <vector>
using namespace std;

#define N 1000

char maj[N][N];

void readCoord(const string& s, int& a, int& b) {
  if (sscanf(s.data(), "(%d;%d)", &a, &b) != 2) {
    quitf(_wa, "Wrong output forma in line \"%s\"", __testlib_part(s).data());
  }
}

int main(int argc, char * argv[]) {
  setName("check the shortest path");
  registerTestlibCmd(argc, argv);
  
  int ci, cj, i, j, n, m, userLength = 0, correctLength = ans.readInt();
  n = inf.readInt();
  m = inf.readInt();
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      maj[i][j] = inf.readToken()[0];
    }
  }
  if (ouf.seekEof()) {
    quitf(_wa, "Empty answer");
  }
  readCoord(ouf.readToken(), j, i);
  if (i != 0 || j != 0) {
    quitf(_wa, "You should begin from cell (0;0), user started from (%d;%d)", j, i);
  }
  while (!ouf.seekEof()) {
    ci = i;
    cj = j;
    readCoord(ouf.readToken(), j, i);
    if (i < 0 || i >= n || j < 0 || j >= m) {
      quitf(_wa, "Step out of bounds into (%d;%d)", j, i);
    }
    if (!(abs(i - ci) == 0 && abs(j - cj) == 1 || abs(i - ci) == 1 && abs(j - cj) == 0)) {
      quitf(_wa, "The step should be done in an adjacent cell. Can\'t move from (%d;%d) to (%d;%d)", cj, ci, j, i);
    }
    if (maj[i][j] == '#') {
      quitf(_wa, "Can\'t go into occupied cell (%d;%d)", j, i);
    }
    if (++userLength > correctLength) {
      quitf(_wa, "The answer is not optimal. Expected %d steps but obtained %d steps", correctLength, userLength);
    }
  }
  if (maj[i][j] == 'x') {
    if (userLength == correctLength) {
      quitf(_ok, "OK %d steps", userLength);
    } else {
      quitf(_fail, "The user answer is better than judge's. Judge answer %d steps, user answer %d steps", correctLength, userLength);
    }
  } else {
    quitf(_wa, "The user solution doesn't reached the \'x\' cell and stopped in cell (%d;%d)", j, i);
  }
  return 0;
}
