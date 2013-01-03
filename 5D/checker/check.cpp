#include "testlib.h"
#include <string>
using namespace std;

const int N = 500;

bool contains(const string& sub, const string& str) {
  int i, j;
  for (i = j = 0; i < str.size() && j < sub.size(); ++i) {
    if (str[i] == sub[j]) {
      ++j;
    }
  }
  return j == sub.size();
}

int main(int argc, char * argv[]) {
  setName("check longest common subsequence");
  registerTestlibCmd(argc, argv);
  
  int correct = ans.readInt(), i, j;
  
  string user = ouf.readLine();
  
  if (user.size() < correct) {
    quitf(_wa, "the user answer is not optimal, expected %d obtained %d characters", correct, user.size());
  }
  
  string inputOne = inf.readLine();
  string inputTwo = inf.readLine();
  
  if (inputOne.size() > N) {
    quitf(_fail, "first input string\'s length %d is exceeding the limit %d", inputOne.size(), N);
  }
  if (inputTwo.size() > N) {
    quitf(_fail, "second input string\'s length %d is exceeding the limit %d", inputTwo.size(), N);
  }
  
  
  if (!contains(user, inputOne)) {
    quitf(_wa, "the string \'%s\' is not a subsequence of input string \'%s\'", __testlib_part(user).data(), __testlib_part(inputOne).data());
  }  
  if (!contains(user, inputTwo)) {
    quitf(_wa, "the string \'%s\' is not a subsequence of input string \'%s\'", __testlib_part(user).data(), __testlib_part(inputTwo).data());
  }  
  
  if (correct < user.size()) {
    quitf(_fail, "user has better answer, expected %d obtained %d characters", correct, user.size());
  }
  
  quitf(_ok, "OK %d characters", correct);
  return 0;
}
