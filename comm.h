#pragma once


#include <map>

#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};




struct ListNode* create_listnode(int * num, int size) {

  struct ListNode* head = nullptr;
  struct ListNode* p = nullptr;
  struct ListNode* pre = nullptr;//(struct ListNode*)malloc(sizeof(struct ListNode));


  for (int i = 0; i < size; i++) {
    p = (struct ListNode*)malloc(sizeof(struct ListNode));

    if (head == nullptr) {
      head = p;
    }

    p->val = num[i];
    p->next = nullptr;

    if (pre)
      pre->next = p;
    pre = p;
  }


  return head;
}