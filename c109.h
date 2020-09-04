#pragma once

#include "comm.h"

//给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//////////////////////////////////////////////////////////////////////////
//思路

//第一步是确认根节点？
//为什么？因为，树的插入就是要确认根节点，

//问题：怎么确认根节点？
//就是找链表的中位数

//问题：怎么找顺序链表的中位数？
//中位数中还需要考虑的一点就是，len的奇偶

//********关键
//答：链表的中位数是采取，快慢指针的，当快指针右边移动两次之后，慢指针移动一次，这样快指针是慢指针速度的一半，因此
//可以采用这种方式获取有序链表的中位数



//封装好找中位数的接口之后，再像有序数组变为bst树一样，将其中序遍历，变为一个树
struct ListNode* getMedian(struct ListNode* left, struct ListNode* right) {
  struct ListNode* fast = left, *slow = left;




  while (fast && fast->next)  { //注意，这里应该是对right的判断
    fast = left->next;
    fast = fast->next;

    slow = slow->next;
  }
  
  return slow;
}

//采用递归，注意递归退出条件
struct TreeNode* buildTree(struct ListNode* left, struct ListNode* right) {
  if (left == right) {  //递归退出条件
    return NULL;
  }
  
  struct ListNode* mid = getMedian(left, right);
  struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
  root->val = mid->val;

  //注意，这里需要对root进行初始化

  root->left = buildTree(left, mid);
  root->right = buildTree(mid->next, right);

  return root;
}


struct TreeNode* sortedListToBST(struct ListNode* head) {
  return buildTree(head, NULL);
}