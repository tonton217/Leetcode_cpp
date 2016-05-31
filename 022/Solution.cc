#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    helper(n, n, "");
    return result;
  }

private:
  void helper(int m, int n, string parentheses) {
    if (m == 0 && n == 0) {
      result.push_back(parentheses);
      return;
    }
    if (m > 0)
      helper(m - 1, n, parentheses + '(');
    if (m < n)
      helper(m, n - 1, parentheses + ')');
  }

  vector<string> result;
};

int main() {
  Solution solution;
  auto result = solution.generateParenthesis(3);

  for (auto& str : result) {
    cout << str << endl;
  }
  return 0;
}
