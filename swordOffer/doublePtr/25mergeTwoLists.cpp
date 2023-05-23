#include <iostream>
#include <vector>
#include "LinkList.h"
using namespace std;

/**
 *  题目：合并两个有序链表
 *  输入：1->2->4, 1->3->4
 *  输出：1->1->2->3->4->4
 *  思路：
 *      1. 定义两个指针 P1 P2，分别指向链表 L1 L2
 *      2. 比较 P1 P2 的值，每次取出两者中较小的值，并移动对应链表
 *      3. 定义 res 链表存放合并排序后的链表
 *      4. res 始终接在 P1 P2 中最小值的后面，并时刻更新 res
 *      5. 当其中有一条链表遍历完时，把另一条链表直接接在 res 后面
*/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1, *p2 = l2;                            // 1. 定义两个指针 P1 P2，分别指向链表 L1 L2
        ListNode *newHead = new ListNode(-1), *res = newHead;   // 3. 定义 res 链表存放合并排序后的链表
        while (p1 != nullptr && p2 != nullptr) {                // 2. 比较 P1 P2 的值，每次取出两者中较小的值，并移动对应链表
            if (p1->val < p2->val) {
                res->next = p1;
                p1 = p1->next;
            } else {
                res->next = p2;                                 // 4. res 始终接在 P1 P2 中最小值的后面，并时刻更新 res
                p2 = p2->next;
            }
            res = res->next;
        }
        if (p1 != nullptr) {                                    // 5. 当其中有一条链表遍历完时，把另一条链表直接接在 res 后面
            res->next = p1;
        } else if (p2 != nullptr) {
            res->next = p2;
        }
        return newHead->next;
    }
};

int main() {
    LinkList link1, link2;
    vector<int> nums1 = {1, 2, 4}, nums2 = {1, 3, 4};
    for (int i = 0; i < nums1.size(); ++i) {
        link1.insertNode(i, nums1[i]);
    }
    for (int i = 0; i < nums2.size(); ++i) {
        link2.insertNode(i, nums2[i]);
    }
    link1.dispaly(link1.head->next);
    link2.dispaly(link2.head->next);
    Solution sol;
    cout << "-----" << endl;
    link1.dispaly(sol.mergeTwoLists(link1.head->next, link2.head->next));
}

// 1 2 4
// 1 2 3