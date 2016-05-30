#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> numbers(num + 1);
    numbers[0] = 0;
    for (int i = 1; i <= num; ++i) {
      numbers[i] = numbers[i/2] + (i % 2);
    }
    return numbers;
  }
};

void print_vector(const vector<int>& nums) {
  for (auto& num : nums) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  Solution solution;
  auto result = solution.countBits(5);
  print_vector(result);

  return 0;
}
