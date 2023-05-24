#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  题目：将数组中的奇数放在前面，偶数放在后面
 *  输入：nums = [1,2,3,4]
 *  输出：[1,3,2,4]
 *  思路：
 *      1. 定义双指针，一个指向头，一个指向尾
 *      2. 依次移动，分别找到偶数和奇数时暂停
 *      3. 交换两位置不对的元素
*/

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        if (nums.size() <= 1) return nums;
        int i = 0, j = nums.size() - 1;             // 1. 定义双指针，一个指向头，一个指向尾
        while (i < j) {
            while (i < j && nums[i] % 2 == 1) i++;  // 2. 依次移动，分别找到偶数和奇数时暂停
            while (i < j && nums[j] % 2 == 0) j--;
            swap(nums[i], nums[j]);                 // 3. 交换两位置不对的元素
        }
        return nums;
    }

    void printVec(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    sol.printVec(nums);
    sol.exchange(nums);
    sol.printVec(nums);
    return 0;
}

// N = 4    0   2  (4+1)/2
// N = 5    0   3  (5+1)/2
// 1  3  4  2
// p1 = 0 p2 = 2  n = 4
// 1  3  #  2  4

// 1     2
// 1  2  3  4