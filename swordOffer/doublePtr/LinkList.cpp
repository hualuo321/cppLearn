#include <iostream>
#include "LinkList.h"
using namespace std;

/* 在第 i 个位置插入值为 val 的节点 */
void LinkList::insertNode(int i, int val) {
    ListNode *node = new ListNode(val);
    ListNode *tmp = head;
    int idx = 0;
    while (idx < i) {
        tmp = tmp->next;
        idx++;
    }
    node->next = tmp->next;
    tmp->next = node;
}

/* 删除位置 i 处的节点 */
void LinkList::deleteNode(int i) {
    ListNode *tmp = head;
    int j = 0;
    while (j < i) {
        j++;
        tmp = tmp->next;

    }
    tmp->next = tmp->next->next;
}

/* 显示链表中的值 */
void LinkList::dispaly(ListNode *head) {
    ListNode *tmp = head;
    int idx = 0;
    while (tmp != nullptr) {
        cout << "idx:" << idx++ << " val:" << tmp->val << endl;
        tmp = tmp->next;
    }
    cout << endl;
}
//  T
//  1, 2, 3, 4
/* 获取链表当前的长度 */
int LinkList::getLength(ListNode *head) {
    ListNode *tmp = head;
    int count = 0;
    while (tmp != nullptr) {
        tmp = tmp->next;
        count++;
    }
    cout << "len is :" << count << endl;
    return count;
}
//      t
// h 1, 2, 3
ListNode *LinkList::getNode(int i) {
    ListNode *tmp = head->next;
    while (i--) tmp = tmp->next;
    return tmp;
}

/* 在第 i 个位置插入值为 val 的节点 */
void RandomList::Insert(int i, int val) {
    Node *node = new Node(val);
    Node *tmp = head;
    int idx = 0;
    while (idx < i) {
        tmp = tmp->next;
        idx++;
    }
    node->next = tmp->next;
    tmp->next = node;
}

void RandomList::RandomInsert(int i, int j) {
    Node *p1 = head, *p2 = head;
    while (i-- >= 0) p1 = p1->next;
    if (j == -1) {
        p1->random = nullptr;
    } else {
        while (j-- >= 0) p2 = p2->next;
        p1->random = p2;
    }
}

/* 显示链表中的值 */
void RandomList::Display(Node *newHead) {
    Node *tmp = newHead;
    int idx = 0;
    while (tmp != nullptr) {
        cout << "idx:" << idx++ << " val:" << tmp->val << " random idx:" << GetIdx(tmp->random, newHead) << endl;
        // cout << "idx:" << idx++ << " val:" << tmp->val <<  tmp->random << endl;
        tmp = tmp->next;
    }
}
//     t     n
// [h] 1, 2 ,3 , 4
int RandomList::GetIdx(Node *node, Node *newHead) {
    if (node == nullptr) return -1;
    Node *tmp = newHead;
    int count = 0;
    while (tmp != node) {
        count++;
        tmp = tmp->next;
    }
    return count;
}