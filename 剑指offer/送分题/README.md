- [送分题](#送分题)
  - [剑指 Offer 05. 替换空格](#剑指-offer-05-替换空格)
  - [剑指 Offer 06. 从尾到头打印链表](#剑指-offer-06-从尾到头打印链表)
  - [剑指 Offer 17. 打印从1到最大的n位数](#剑指-offer-17-打印从1到最大的n位数)
  - [剑指 Offer 39. 数组中出现次数超过一半的数字](#剑指-offer-39-数组中出现次数超过一半的数字)
  - [剑指 Offer 50. 第一个只出现一次的字符](#剑指-offer-50-第一个只出现一次的字符)
  - [剑指 Offer 57. 和为s的两个数字](#剑指-offer-57-和为s的两个数字)
  - [剑指 Offer 56 - II. 数组中数字出现的次数 II](#剑指-offer-56---ii-数组中数字出现的次数-ii)
  - [剑指 Offer 58 - I. 翻转单词顺序](#剑指-offer-58---i-翻转单词顺序)
  - [剑指 Offer 64. 求1+2+…+n](#剑指-offer-64-求12n)

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

## 剑指 Offer 39. 数组中出现次数超过一半的数字

```cpp
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m1;
    int n = nums.size() / 2;
    for (auto i : nums) {
      m1[i]++;
      if (m1[i] > n)
        return i;
    }
    return 0;
  }
};
```

## 剑指 Offer 50. 第一个只出现一次的字符

```cpp
class Solution {
public:
  // using PCI = pair<char, int>;
  char firstUniqChar(string s) {
    int arr[26] = {0};
    for (auto i : s) {
      arr[i - 'a'] += 1;
    }
    for (auto i : s) {
      if (arr[i - 'a'] == 1)
        return i;
    }
    return ' ';
  }
};
```

## 剑指 Offer 57. 和为s的两个数字

```cpp
class Solution {
public:
  unordered_map<int, int> m1;
  vector<int> twoSum(vector<int>& nums, int target) {
    for (auto i : nums) {
      if (m1[i] == 1) {
        return {target - i, i};
      }
      m1[target - i] = 1;
    } 
    return {0, 0};
  }
};
```

## 剑指 Offer 56 - II. 数组中数字出现的次数 II

```cpp
class Solution {
public:
  unordered_map<int, int> m1;
  int singleNumber(vector<int>& nums) {
    int tmp = 0;
    for (auto i : nums)
      m1[i] ++;
    for (auto i : nums)
      if (m1[i] == 1)
        return i;
    return -1;
  }
};
```

## 剑指 Offer 58 - I. 翻转单词顺序

不得不说 stringstream 真的好用。

```cpp
class Solution {
public:
  string reverseWords(string s) {
    stringstream ss(s);
    string tmp;
    vector<string> res;
    while (ss >> tmp) {
      res.push_back(tmp);
    }
    reverse(res.begin(), res.end());
    string a{""};
    for (int i = 0; i < res.size(); i++) {
      if (i == 0)
        a += res[i];
      else {
        a += " ";
        a += res[i];
      }
    }
    return a;
  }
};
```

## 剑指 Offer 64. 求1+2+…+n

等差序列求和。

```cpp
class Solution {
public:
  int sumNums(int n) {
    return (1 + n) * n / 2;
  }
};
```