- [送分题](#送分题)
  - [剑指 Offer 05. 替换空格](#剑指-offer-05-替换空格)
  - [剑指 Offer 06. 从尾到头打印链表](#剑指-offer-06-从尾到头打印链表)
  - [剑指 Offer 17. 打印从1到最大的n位数](#剑指-offer-17-打印从1到最大的n位数)

# 送分题

指特别简单，没啥必要分类到标签中的题目。

## 剑指 Offer 05. 替换空格

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

```cpp
class Solution {
public:
  string replaceSpace(string s) {
    string res{""};
    for (auto i : s) {
      if (i != ' ')
        res += i;
      else
        res += "%20";
    }
    return res;
  }
};
```

## 剑指 Offer 06. 从尾到头打印链表

```cpp
class Solution {
public:
  vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    if (head == nullptr)
      return {};
    while (head != nullptr) {
      res.push_back(head->val);
      head = head->next;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
```

## 剑指 Offer 17. 打印从1到最大的n位数

```cpp
class Solution {
public:
  vector<int> printNumbers(int n) {
    vector<int> res;
    for (int i = 1; i < pow(10, n); i++) {
      res.push_back(i);
    }
    return res;
  }
};
```