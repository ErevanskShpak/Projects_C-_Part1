#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

class Solution {
    int target;
    int ans;
    vector<int> nums;
    set<multiset<int>> gen;
    multiset<int> cur;

    void dfs(int sum) {
        if (sum>= target) {
            if (sum == target && gen.count(cur) == 0) {
                gen.insert(cur);
                ans++;
            }
            return;
        }

        for (auto el : nums) {
            cur.insert(el);
            dfs(sum + el);
            cur.erase(cur.find(el));
        }
    }
public:
    int findTargetSumWays(vector<int> nums, int target) {
        ans = 0;
        this->target = target;
        this->nums = nums;
        dfs(0);
        return ans;
    }
};

int main() {
    Solution s;

    cout << s.findTargetSumWays({ 5, 2, 3 }, 10);
}
