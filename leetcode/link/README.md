# 链表

1. 第 92 题，反转链表 II。设置 `dummyhead`，按照[这个题解](https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/yi-ge-neng-ying-yong-suo-you-lian-biao-t-vjx6/)移动其中的指针，注意 `cur, prv` 的位置。
2. 第 206 题，反转链表。尝试去移动指针。
3. 第 21 题，合并两个有序链表。`while (l1 != nullptr || l2 != nullptr)` 换为 while (l1 != nullptr && l2 != nullptr)，可以减少判断，使代码更简单。
4. 剑指 offer 06 题，从尾到头打印链表。用一个 vector 存储数据，最后逆序 vector。
5. 剑指 offer 18 题，删除链表的节点。设置 dummy 节点，主要是判断下最后一个节点是不是要删除的值。其它都是移动指针。
6. 剑指 offer 22 题，链表中倒数第k个节点。双指针，第一个指针移动到第 k 个节点，而后两个指针一起移动，第一个指针为空后，返回第二个指针。
7. 剑指 offer 24 题，反转链表。注意输入数据为空的情况，如果使用 `dummy`，防止自己指向自己。
8. 剑指 offer 35 题，复杂链表的复制。使用哈希，较为简单。复制原链表的内容后，更新新链表的指向。

---

前面的题都是移动指针，但实际面试的题不一定需要自己去真的建立链表，回头整点其它题目。