# 链表

1. 第 92 题，反转链表 II。设置 `dummyhead`，按照[这个题解](https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/yi-ge-neng-ying-yong-suo-you-lian-biao-t-vjx6/)移动其中的指针，注意 `cur, prv` 的位置。
2. 第 206 题，反转链表。尝试去移动指针。
3. 第 21 题，合并两个有序链表。`while (l1 != nullptr || l2 != nullptr)` 换为 while (l1 != nullptr && l2 != nullptr)，可以减少判断，使代码更简单。

---

前面的题都是移动指针，但实际面试的题不一定需要自己去真的建立链表，回头整点其它题目。