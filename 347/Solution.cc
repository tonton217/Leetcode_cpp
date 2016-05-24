#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequent;
    for(auto& num : nums)
      frequent[num]++;

    vector<pair<int, int>> kvList(frequent.begin(), frequent.end());
    sort(kvList.begin(), kvList.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
          return a.second > b.second;
         });
    vector<int> result(k);
    for (int i = 0; i < k; ++i)
      result[i] = kvList[i].first;
    return result;
  }
};

void print_vector(vector<int>& nums) {
  for (auto& num : nums)
    cout << num << " ";
  cout << endl;
}

int main() {
  Solution solution;
  vector<int> nums = { 1, 1, 1, 2, 2, 3 };
  int k = 2;
  auto result = solution.topKFrequent(nums, k);
  print_vector(result);
  return 0;
}
