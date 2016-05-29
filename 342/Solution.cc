#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
  bool isPowerOfFour(int num) {
    if (num <= 0) return false;
    while (num > 1) {
      if (num % 4 != 0) return false;
      num /= 4;
    }
    return true;
  }
};

int main() {
  Solution solution;
  if (solution.isPowerOfFour(16)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
