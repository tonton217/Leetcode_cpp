#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
  string reverseString(string s) {
    string reverse_s(s);
    int start = 0, end = s.length() - 1;
    while (start < end) {
      swap(reverse_s[start++], reverse_s[end--]);
    }
    return reverse_s;
  }

private:
  void swap(char& ch1, char& ch2) {
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
  }
};

int main() {
  Solution solution;
  cout << solution.reverseString("hello") << endl;
  return 0;
}
