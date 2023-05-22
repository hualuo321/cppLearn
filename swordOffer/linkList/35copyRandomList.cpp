#include <iostream>
#include <vector>
#include <unordered_map>
#include "LinkList.h"
using namespace std;

/**
 *  题目：复制一个复杂链表，每个节点有 next 和 rnadom 指针
 *  输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 *  输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *  思路：
 *      1. 实现复杂复制，可采用哈希表法
 *      2. 先遍历一遍链表
 *      3. 采用哈希表，实现节点 val 的一对一复制
 *      4. 再遍历一遍链表
 *      5. 实现 next 和 random 的复制
*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return head;
        Node *cur = head;
        unordered_map<Node *, Node *> umap;     // 1. 实现复杂复制，可采用哈希表法
        while (cur != nullptr) {                // 2. 先遍历一遍链表
            umap[cur] = new Node(cur->val);     // 3. 采用哈希表，实现节点 val 的一对一复制
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {                // 4. 再遍历一遍链表
            umap[cur]->next = umap[cur->next];  // 5. 实现 next 和 random 的复制
            umap[cur]->random = umap[cur->random];
            cur = cur->next;
        }
        return umap[head];
    }
};

int main() {
    RandomList rlist;
    vector<int> nums = {1, 2, 3, 4,5};
    vector<int> randoms = {-1, 0, 4, 2, 0};
    for (int i = 0; i < nums.size(); i++) {
        rlist.Insert(i, nums[i]);
    }
    for (int i = 0; i < randoms.size(); i++) {
        rlist.RandomInsert(i, randoms[i]);
    }
    rlist.Display(rlist.head->next);

    Solution sol;
    Node *newHead = sol.copyRandomList(rlist.head->next);
    rlist.Display(newHead);
}