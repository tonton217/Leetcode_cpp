#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    if (s.empty()) return "";
    string reversed_s(s);
    size_t begin = 0, end = reversed_s.length() - 1;
    cout << begin << " " << end << endl;
    while (true) {
      while((begin < reversed_s.length()) && !isVowels(reversed_s[begin]))
        begin++;
      while(end > 0 && !isVowels(reversed_s[end]))
        end--;
      if (begin >= end) break;
      swap(reversed_s[begin++], reversed_s[end--]);
    }
    return reversed_s;
  }

private:
  bool isVowels(char ch) {
    switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return true;
    default:
      return false;
    }
  }
};

int main() {
  Solution solution;
  cout << solution.reverseVowels("hello") << endl;
  cout << solution.reverseVowels("leetcode") << endl;
  cout << solution.reverseVowels("") << endl;
  cout << solution.reverseVowels(" ") << endl;
  cout << solution.reverseVowels("OE") << endl;
  cout << solution.reverseVowels(".,") << endl;
  return 0;
}
