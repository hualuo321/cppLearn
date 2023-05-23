#include <iostream>
#include "LinkList.h"
#include <vector>
using namespace std;

/**
 *  题目：找到两个链表的第一个公共节点
 *  输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 *  输出：Reference of the node with value = 8
 *  思路：
 *      1. 定义两个指针 P1 遍历 A->B，P2 遍历 B->A
 *      2. 一步一步走，如果相交必会相遇
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = (p1 != nullptr) ? p1->next : headA;
            p2 = (p2 != nullptr) ? p2->next : headB;
        }
        return p1;
    }
};

int main() {
    LinkList link1, link2;
    vector<int> nums1 = {4, 1, 8, 4, 5}, nums2 = {5, 0, 2};
    for (int i = 0; i < nums1.size(); i++) {
        link1.insertNode(i, nums1[i]);
    }
    for (int i = 0; i < 3; i++) {
        link2.insertNode(i, nums2[i]);
    }
    link1.dispaly(link1.head->next);
    link2.dispaly(link2.head->next);
    cout << link2.getNode(2)->val << endl;
    cout << link1.getNode(2)->val << endl;
    link2.getNode(2)->next = link1.getNode(2);
    link1.dispaly(link1.head->next);
    link2.dispaly(link2.head->next);
    Solution sol;
    cout << sol.getIntersectionNode(link1.head->next, link2.head->next)->val << endl;
    return 0;
}

// 4 1 8 4 5 | 5 0 1 8 4 5
// 5 0 1 8 4 5 | 4 1 8 4 5