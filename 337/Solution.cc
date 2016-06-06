#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int rob(TreeNode * root) {
    auto robbed_money = rob_from_node(root);
    return max(robbed_money.first, robbed_money.second);
  }

private:
  pair<int, int> rob_from_node(TreeNode * node) {
    if (node == nullptr)
      return make_pair(0, 0);

    auto left = rob_from_node(node->left);
    auto right = rob_from_node(node->right);

    int first = left.second + right.second + node->val;
    int second = max(left.first, left.second) + max(right.first, right.second);

    return make_pair(first, second);
  }
};

TreeNode * make_test_tree() {
  TreeNode * root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  auto node = root->left;
  node->left = new TreeNode(1);
  node->right = new TreeNode(3);
  node = root->right;
  node->right = new TreeNode(1);
  return root;
}

void clear_tree(TreeNode * node) {
  if (node == nullptr) return;
  clear_tree(node->left);
  clear_tree(node->right);
  delete node;
}

int main() {
  Solution solution;
  auto root = make_test_tree();
  auto money = solution.rob(root);
  cout << money << endl;
  clear_tree(root);

  return 0;
}
