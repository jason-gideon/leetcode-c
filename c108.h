#pragma once


#include "comm.h"

// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */




struct TreeNode* helper(int* nums, int numsSize, int begain, int end) {
  if (begain > end) {
    return NULL;
  }


  int mid = (begain + end) / 2;
  struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
  root->val = nums[mid];

  root->left = helper(nums, numsSize, begain, mid - 1);
  root->right = helper(nums, numsSize, mid +1, end);

  return root;
}


//就是对二叉搜索树进行插入操作
//因为输入是有序的，
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  return helper(nums, numsSize, 0, numsSize - 1);
}



void c108() {
  int a[] = { -10,-3,0,5,9};

  struct TreeNode* t = sortedArrayToBST(a, 5);
}