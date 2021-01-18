// Copyright 2021 Longa_Bonga

#include <iostream>
#include <string>
#include "postfix.h"


int main() {
    std::string s1("5.9 * 8 * (2 + 9) + (7 - 5 + 8 - 9 * (5 * 5) + 5)");
    std::string s2 = infix2prefix(s1);
    std::cout << s2;  // 2 6 3 * 4 2 - / +
    return 0;
}
