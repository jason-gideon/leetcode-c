#pragma once




double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

  int mid1 = nums1Size / 2, mid2 = nums2Size / 2;
  int s1 = 0, s2 = 0;
  int e1 = nums1Size - 1;
  int e2 = nums2Size - 1;

  while (mid2 < mid1) {
    if (nums1[mid1] <= nums2[mid2]) {
      //在1 后半部，2前半部找

//            mid1 = (nums1[mid1] + nums1[e1]) /2;
            //mid2 = (nums2[s2] + nums2[mid2]) / 2;

      mid1 = (mid1 + e1) / 2;
      mid2 = (s2 + mid2) / 2;

      //nums1[]
    }
    else {
      mid1 = (s1 + mid1) / 2;
      mid2 = (mid2 + e2) / 2;
    }
  }


  return (nums1[mid1] + nums2[mid2]) / 2;;
}


void c004() {
  
  int a[] = {1, 3};

  int b[] = { 2 };

  findMedianSortedArrays(a, 2, b, 1);


  return;
}