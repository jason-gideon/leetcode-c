#pragma once

#include "comm.h"

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//查找方法
//1.顺序查找
//2.折半查找
//3.分块查找

int seqFind(int * nums, int numsSize, int target) {
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == target) {
      return i;
    }
  }

  return -1;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//方法1：暴力遍历 
//时间复杂度 On2 
//空间复杂度 O1
int* twoSum1(int* nums, int numsSize, int target, int* returnSize) {

  //>ta pass
  //=ta pass
  //<ta as base
  int * sum = 0;

  //可以利用查找算法，当i < tar时，j = ta -i, nums中找j
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < target) {
      int dst = target - nums[i];
      int j = seqFind(nums, numsSize, dst);

      if (j != -1) {
        //return pair
        if (!sum) {
          sum = (int*)malloc(2*sizeof(int));
          sum[0] = i;
          sum[1] = j;
          return sum;
        }
      }
    }
  }

  return sum;
}


//方法2：使用hash
//降低时间复杂度，但是提高了空间复杂度
//时间复杂度 On 
//空间复杂度 On

/*
为了对运行时间复杂度进行优化，我们需要一种更有效的方法来检查数组中是否存在目标元素。如果存在，我们需要找出它的索引。保持数组中的每个元素与其索引相互对应的最好方法是什么？哈希表。

通过以空间换取速度的方式，我们可以将查找时间从 O(n)O(n) 降低到 O(1)O(1)。哈希表正是为此目的而构建的，它支持以 近似 恒定的时间进行快速查找。我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 O(n)O(n)。但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 O(1)O(1)。

一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]target−nums[i]）是否存在于表中。注意，该目标元素不能是 nums[i]nums[i] 本身！

作者：LeetCode
链接：https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

//生成map
//遍历数组，将每个值插入
//遍历map，如果
int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {
  int * sum = 0;
  std::map<int, int> nm;
  for (int i = 0; i < numsSize; ++i) {
    nm[nums[i]] = i;
  }

  for (int i = 0; i < numsSize; ++i) {
    int dst = target - nums[i];
    if (nm.find(dst) != nm.end()) {
      sum = (int*)malloc(2 * sizeof(int));
      sum[0] = i;
      sum[1] = dst;
      return sum;
    }
  }
}


//方法三：一遍hash
/*
事实证明，我们可以一次完成。在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。

作者：LeetCode
链接：https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/






void c001() {
  int nums[] = { 2, 7, 11, 15 };
  int target = 9;

  int returnSize = 0;

  //获取多少字节
  int len = sizeof nums;


  int * p = twoSum1(nums, 4, target, &returnSize);

  int * p2 = twoSum2(nums, 4, target, &returnSize);

  return;
}