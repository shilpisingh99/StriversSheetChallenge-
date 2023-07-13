#include <bits/stdc++.h>
int atoi(string str) {
  int num = 0;
  for (auto i : str) {
    if (isdigit(i))
        num = (num * 10) + (i - '0');
  }

  return str[0] == '-' ? -num : num;
}