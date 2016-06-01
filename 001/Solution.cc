#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> cache;
    vector<int> result(2);
    for (size_t i = 0, len = nums.size(); i < len; ++i) {
      int num = nums[i];
      int temp = cache[target - num];
      if (temp != 0) {
        result[0] = temp - 1;
        result[1] = i;
        break;
      }
      cache[num] = i + 1;
    }
    return result;
  }
};

int main() {
  Solution solution;
  //vector<int> nums = { 2, 7, 11, 15 };
  vector<int> nums = { 3, 2, 4 };
  auto result = solution.twoSum(nums, 6);

  for (auto& num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
