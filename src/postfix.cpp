// Copyright 2020 Longa_Bonga
#include "MyStack.h"

bool isSymbol(char symbol) {
  return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int force(char symbol) {
  if (symbol == '*' || symbol == '/')
    return 2;
  if (symbol == '+' || symbol == '-')
    return 1;
  else
    return 0;
}

std::string infix2prefix(std::string str) {
  MyStack<char> stack(350);
  std::string queue = "";

  for (int i = 0; i < str.length(); i++) {
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ' ')
      queue.push_back(str[i]);

    else if (isSymbol(str[i]))  // if str[i] + - * /
    {

      if (stack.isEmpty() || stack.get() == '(')
        stack.push(str[i]);

      else if (force(str[i]) > force(stack.get()))
        stack.push(str[i]);

      else if (force(str[i]) <= force(stack.get())) {
        while(!stack.isEmpty() && (force(str[i]) <= force(stack.get())) && stack.get() != '(')
          queue.push_back(stack.pop());
        stack.push(str[i]);
      }
    }

    else if (str[i] == '(')
      stack.push(str[i]);

    else if (str[i] == ')') {
      while(!stack.isEmpty() && stack.get() != '(')
        queue.push_back(stack.pop());
      stack.pop();
    }

  }
  while (!stack.isEmpty()) {
    queue.push_back(stack.pop());
  }
  std::string ans = "";
  ans.push_back(queue[0]);
  for (int i = 1; i < queue.length(); i++)
  {
    if (ans.back() != ' ' && isSymbol(queue[i]))
      ans.push_back(' ');
    ans.push_back(queue[i]);
  }
  return ans;
}
