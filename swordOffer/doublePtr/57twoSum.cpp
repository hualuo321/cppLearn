#include <iostream>
#include <vector>
using namespace std;

/**
 *  题目：输入一个数组，看里面有没两个数相加等于 target
 *  输入：nums = [2,7,11,15], target = 9
 *  输出：[2,7] 或者 [7,2]
 *  思路：
 *      1. 定义双指针 P1 P2，指向数组头和尾
 *      2. 如果 nums[P1] + nums[P2] > target，P2--
 *      3. 如果 nums[P1] + nums[P2] < target，P1--
 *      4. 如果 nums[P1] + nums[P2] = target，return nums[P1] nums[P2]
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int p1 = 0, p2 = nums.size() - 1;   // [0 - 4]
        while (p1 < p2) {
            if (nums[p1] + nums[p2] > target) {
                p2--;
            } else if (nums[p1] + nums[p2] < target) {
                p1++;
            } else {
                return {nums[p1], nums[p2]};
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution sol;
    vector<int> res = sol.twoSum(nums, target);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}