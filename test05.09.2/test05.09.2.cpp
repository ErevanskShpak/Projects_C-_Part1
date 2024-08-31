#include <iostream>
#include <list>
#include<functional>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool isBe = 0;
        list<TreeNode*> list1, list2;
        function<void(TreeNode*, list<TreeNode*>, int p)> rec1 = [&rec1, &isBe](TreeNode* cur, list<TreeNode*> list1, int p) {
            if (!cur || isBe) {
                return;
            }

            list1.push_back(cur);
            if (cur->val == p) {
                isBe = 1;
                return;
            }
            rec1(cur->left, list1, p);
            rec1(cur->right, list1, p);

            if (!isBe) {
                list1.pop_back();
            }
        };

        rec1(root, list1, p->val);
        isBe = 0;
        rec1(root, list2, q->val);
        TreeNode* first, * second;
        while (true) {
            first = list1.front();
            list1.pop_front();
            second = list2.front();
            list2.pop_front();
            if (list1.front() != list2.front()) {
                return first;
            }
        }

    }
};

int main()
{
    Solution s;

}