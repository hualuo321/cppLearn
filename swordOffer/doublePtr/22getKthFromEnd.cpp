#include <iostream>
#include <vector>
#include "LinkList.h"
using namespace std;

/**
 *  题目：给定一个链表，从 1 开始计数，取出链表倒数第 k 个节点
 *  输入：1->2->3->4->5, 和 k = 2.
 *  输出：4->5.
 *  思路：
 *      1. 定义两个指针 p1 p2 指向 head
 *      2. 先让 p2 走 k 步，再 p1 p2 一起走，直到 p2 为 null
 *      3. 此时 p1 所指即为结果
*/

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *p1 = head, *p2 = head;
        while (k--) {
            p2 = p2->next;
        }
        while (p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main() {
    LinkList link;
    vector<int> nums = {1, 2, 3, 4, 5};
    for (int i = 0; i < nums.size(); i++) {
        link.insertNode(i, nums[i]);
    }
    link.dispaly(link.head->next);
    link.getLength(link.head->next);
    Solution sol;
    ListNode * newHead = sol.getKthFromEnd(link.head->next, 2);
    link.dispaly(newHead);
    link.getLength(newHead);
}

//       1     2
// A, B, C, D, null