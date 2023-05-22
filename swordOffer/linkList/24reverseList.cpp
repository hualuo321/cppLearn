#include <iostream>
#include <vector>
#include "LinkList.h"
using namespace std;

/**
 *  题目：反转一个链表
 *  输入：1->2->3->4->5->NULL 
 *  输出：5->4->3->2->1->NULL
 *  思路：
 *      1. 定义 3 个指针，分别指向 A, B, C 三个节点
 *      2. 先让头节点置空，作为反转后链表的尾
 *      3. 依次循环，直到第二个指针为空
 *      4. 让 B->A，再让指针分别指向 B, C, D 三个节点
 *      5. 三指针依次往后挪
 * 
*/
          
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *p1 = head, *p2 = p1->next, *tmp;      // 1. 定义 3 个指针，分别指向 A, B, C 三个节点
        p1->next = nullptr;                             // 2. 先让头节点置空，作为反转后链表的尾
        while (p2 != nullptr) {                         // 3. 依次循环，直到第二个指针为空
            tmp = p2->next;                             // 4. 让 B->A，再让指针分别指向 B, C, D 三个节点
            p2->next = p1;
            p1 = p2;                                    // 5. 三指针依次往后挪
            p2 = tmp;                             
        }
        return p1;
    }
};

int main() {
    LinkList link;
    vector<int> nums = {1, 2, 3, 4, 5};
    for (int i = 0; i < nums.size(); i++) {
        link.Insert(i, nums[i]);
    }
    link.Dispaly(link.head->next);
    cout << "----------------" << endl;
    Solution sol;
    ListNode * newHead = sol.reverseList(link.head->next);
    link.Dispaly(newHead);
}