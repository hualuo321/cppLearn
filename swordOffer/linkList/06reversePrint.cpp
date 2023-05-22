#include <iostream>
#include <vector>
#include "LinkList.h"
using namespace std;

/**
 *  题目：获取链表中的数反转的结果
 *  输入：head = [1,3,2]
 *  输出：[2,3,1]
 *  思路：
 *      1. 依次遍历每一个节点
 *      2. 将节点中的数按头插法放入 vector
*/

class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        vector<int> res;                // 结果
        ListNode *tmp = head;           // 临时
        while (tmp != nullptr) {                    // 1. 依次遍历每一个节点
            res.insert(res.begin(), tmp->val);      // 2. 将节点中的数按头插法放入 vector
            tmp = tmp->next;
        }
        return res;
    }

    void printVec(vector<int> vec) {
        for (int i = 0; i < vec.size(); i++) {
            cout << "idx:" << i << " val:" << vec[i] << endl;
        }
    }
};

int main() {
    LinkList link;
    vector<int> nums = {1, 2, 3, 4, 5};
    for (int i = 0; i < nums.size(); i++) {
        link.Insert(0, nums[i]);
    }
    link.Dispaly(link.head->next);
    cout << "len is  " << link.GetLength() << endl;
    link.Delete(2);
    link.Delete(0);
    link.Dispaly(link.head->next);
    cout << "len is  " << link.GetLength() << endl;
    Solution sol;
    vector<int> res = sol.reversePrint(link.head->next);
    sol.printVec(res);
    return 0;
}