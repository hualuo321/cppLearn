#include <iostream>
#include <vector>
#include "LinkList.h"
using namespace std;

/**
 *  题目：删除链表中的某个值为 val 的节点
 *  输入: head = [4,5,1,9], val = 5
 *  输出: [4,1,9]
 *  思路：
 *      1. 排除只有一个节点的情况
 *      2. 定义两个指针，同向同步移动
 *      3. 第一个指针指向目标前一个位置，第二个指针指向目标位置
 *      4. 依次改变 p2 p1 指向，进行节点删除
*/

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head->val == val) return head->next;
        ListNode *p1 = head, *p2 = head->next;  // 1. 定义两个指针，同向同步移动
        while (p2 != nullptr) {
            if (p2->val == val) break;          // 2. 第一个指针指向目标前一个位置，第二个指针指向目标位置
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2 != nullptr) {
            p2 = p2->next;
            p1->next = p2;
        }
        return head;
    }
};

int main() {
    LinkList link;
    vector<int> nums = {4, 5, 1, 9};
    for (int i = 0; i < nums.size(); i++) {
        link.Insert(i, nums[i]);
    }
    link.Dispaly(link.head->next);
    cout << "len is: " << link.GetLength(link.head->next) << endl;
    Solution sol;
    ListNode *newHead = sol.deleteNode(link.head->next, 5);
    link.Dispaly(newHead);
    cout << "len is: " << link.GetLength(newHead) << endl;
}