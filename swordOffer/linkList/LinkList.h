#ifndef LINKLIST_H
#define LINKLIST_H

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class LinkList {
public:    
    ListNode *head;
    LinkList() : head(new ListNode(-1)) {};     // [-1] [2]
    void Insert(int i, int val);
    void Delete(int i);
    void Dispaly(ListNode *head);
    int GetLength();
};

class Node {
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class RandomList {
public: 
    Node *head;
    RandomList() : head(new Node(-1)) {};
    void Insert(int i, int val);
    void RandomInsert(int i, int j);
    void Display(Node *head);
    int GetIdx(Node *node, Node *newHead);
};

#endif
