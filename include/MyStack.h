// Copyright 2021 Longa_Bonga

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template <typename T>
class MyStack {
 // private:




 public:
  int top;
  T *stackPtr;
  int size;
  explicit MyStack(int s = 10) {
      size = s > 0 ? s: 10;
      stackPtr = new T[size];
      top = -1;
  }

  ~MyStack() {
      delete [] stackPtr;
  }

  bool isFull() const {
      if (top == size - 1)
        return true;
      return false;
  }

  bool isEmpty() const {
      if (top == -1)
        return true;
      return false;
  }

  T get() const {
      if (top == - 1)
        return 0;
      return stackPtr[top];
  }

  bool push(const T value) {
      if (top == size - 1)
          return false;

      top++;
      stackPtr[top] = value;

      return true;
  }

  T pop() {
      if (top == - 1)
          return 0;
      T ans = stackPtr[top];
      stackPtr[top] = 0;
      top--;
      return ans;
  }
};

#endif  // INCLUDE_MYSTACK_H_
