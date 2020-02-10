# 介绍

大概是发现github是个好东西后有了新鲜感？于是准备陆续的把一些代码放上来。当然回到正题，会记录日常的OJ，如果是一类的算法题目，也会归结到`algorithm`里面。

每天一道`OJ`，防止老年痴呆。

# PAT

## 乙级

第一阶段任务，慢慢刷吧。以C++为主，偶尔蹦出来几个python也不是不可能。
- 15分：简单的编程应用，涉及数组、分支、循环、判断等
- 20分：比较复杂的编程应用，逻辑复杂，但不涉及数据结构
- 25分：涉及简单的数据结构的使用，如`vector, map`等，不涉及算法

# 记录

本人没学过C++，第一次接触，记录的东西可能有点low。

1. `scanf` 代替 `cin` 可在某种程度上避免超时。
2. 快速排序前后，主元位置不变，否则常规思路会超时。乙级 1045。
3. `stof`, `stoi` 完成字符串转数字。乙级 1054。
4. `isdigital` 传入的变量是`char`类型。
5. `if` `if` `else` 和 `if` `else if` `else` 对代码的执行结果影响不一样。
6. [二维数组的定义](https://blog.csdn.net/FX677588/article/details/52708813)：传入常量不能传入参数。乙级1066。
7. 输出`3`位数，高位补0：`printf("%03d ", arr[i][j]);`。
8. 哈希时要考虑空间大小，`int a[99999][99999]` 太大了，可以考虑使用 Map。乙级1090。
9. `map`键对应的值不止一个时，值可以考虑用 `vector` 载入。
10. 数字转字符串：`to_string()`，字符串逆序(algorithm)：`reverse(s.begin(), s.end());`，乙级1086。
11. 虽然链表可以考虑顺序结构和链式结构实现，但巧妙的软换会比两者都好。乙级1075。

# 参考

大量参考了柳神的代码：https://github.com/liuchuo/PAT