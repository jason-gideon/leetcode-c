#pragma once
#include "comm.h"


/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/







/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



 
//个人：递归，每个相加
struct ListNode* re2(struct ListNode* l1, struct ListNode* l2, int add) {
  if (l1 == NULL && l2 == NULL) {
    return nullptr;
  }

  struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));

  int v1 = l1->val;
  int v2 = l2->val;

  int val = v1 + v2;
  if (val >= 10) {
    val -= 10;
    root->val = val;
    add++;
  }
  else  {
    root->val = val + add;
  }

  root->next = re2(l1->next, l2->next, add);

  return root;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  return re2(l1, l2, 0);
}



//官方

struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {

}




void c002() {

  int n1[] = { 2,4,3 };
  struct ListNode* l1 = create_listnode(n1, 3);

  int n2[] = { 5,6,4 };
  struct ListNode* l2 = create_listnode(n2, 3);

  struct ListNode* l3 =  addTwoNumbers(l1, l2);

  return;
}