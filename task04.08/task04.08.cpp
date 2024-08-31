
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n - 1;) {
            if (nums[i] == val) {
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                n--;
            }
            else {
                i++;
            }
        }
        if (nums[n - 1] == val) {
            n--;
        }

        return n;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 1,2,3,4,3 };
    cout<< s.removeElement(arr, 3);

    return 0;
}
