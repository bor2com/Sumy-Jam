#include "testlib.h"
#include <set>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& a) {
  for (int i = 0; i < a.size(); ++i) {
    printf("%d ", a[i]);
  }
  putchar('\n');
}

bool test(vector<int>& answer, vector<int>& output) {
  rotate(answer.begin(), min_element(answer.begin(), answer.end()), answer.end());
  rotate(output.begin(), min_element(output.begin(), output.end()), output.end());
  return answer == output;
}

int main(int argc, char * argv[]) {
  setName("check convex hull");
  registerTestlibCmd(argc, argv);
  
  int i;
  vector<int> answer, output;
  while (!ans.seekEof()) {
    answer.push_back(ans.readInt());
  }
  for (i = 0; i < answer.size(); ++i) {
    output.push_back(ouf.readInt());
  }
  if (!test(answer, output)) {
    reverse(answer.begin(), answer.end());
    if (!test(answer, output)) {
      quitf(_wa, "Sequences don\'t match");
    }
  }
  quitf(_ok, "OK %d vertices", answer.size());
  return 0;
}
