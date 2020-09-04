#pragma once

//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。


//参考：整数/10之后，除到最后的余数就是高位数据
int reverse(int x) {
  //可能需要栈，因为，x/10到余数之后，

  int rev = 0;
  while (x != 0) {
    int pop = x % 10;
    x /= 10;

    //范围检查
    //rev 必须 < MAX_INT
    //rev > MIN_INT

    //pop是栈的最低层
    rev = rev * 10 + pop;
  }

  return rev;
}