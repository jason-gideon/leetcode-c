#pragma once

//����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��


//�ο�������/10֮�󣬳��������������Ǹ�λ����
int reverse(int x) {
  //������Ҫջ����Ϊ��x/10������֮��

  int rev = 0;
  while (x != 0) {
    int pop = x % 10;
    x /= 10;

    //��Χ���
    //rev ���� < MAX_INT
    //rev > MIN_INT

    //pop��ջ����Ͳ�
    rev = rev * 10 + pop;
  }

  return rev;
}