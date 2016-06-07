#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    for (auto& num : nums) {
      if (second < num)
        return true;
      else if (num < first)
        first = num;
      else
        second = num;
    }
    return false;
  }
};

int main() {
  Solution solution;
  //vector<int> nums = { 1, 2, 3, 4, 5 };
  vector<int> nums = { 5, 4, 3, 2, 1 };
  if (solution.increasingTriplet(nums))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
