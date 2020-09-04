#pragma once


#include "comm.h"

// ��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
//�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��


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


//���ǶԶ������������в������
//��Ϊ����������ģ�
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  return helper(nums, numsSize, 0, numsSize - 1);
}



void c108() {
  int a[] = { -10,-3,0,5,9};

  struct TreeNode* t = sortedArrayToBST(a, 5);
}