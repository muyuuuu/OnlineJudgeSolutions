# 链表

1. 第 92 题，反转链表 II。有的时候不用真的反转，创建数组存储数据，然后反转数组对应位置的内容。而后开始遍历数据，如果不在反转范围内，使用旧数组，如果在反转范围内，使用反转后的数组，而后访问数组的数据创建新的节点即可。
2. 第 206 题，反转链表。尝试去移动指针。
3. 第 21 题，合并两个有序链表。`while (l1 != nullptr || l2 != nullptr)` 换为 while (l1 != nullptr && l2 != nullptr)，可以减少判断，使代码更简单。
4. 剑指 offer 06 题，从尾到头打印链表。用一个 vector 存储数据，最后逆序 vector。
5. 剑指 offer 18 题，删除链表的节点。设置 dummy 节点，主要是判断下最后一个节点是不是要删除的值。其它都是移动指针。
6. 剑指 offer 22 题，链表中倒数第k个节点。双指针，第一个指针移动到第 k 个节点，而后两个指针一起移动，第一个指针为空后，返回第二个指针。
7. 剑指 offer 24 题，反转链表。注意输入数据为空的情况，如果使用 `dummy`，防止自己指向自己。
8. 剑指 offer 35 题，复杂链表的复制。使用哈希，较为简单。复制原链表的内容后，更新新链表的指向。
9. 剑指 offer 52 题，两个链表的第一个公共节点。第一种解法，哈希，记录链表每个节点的地址，如果映射有相同的，返回；第二种解法，双指针，第一个链表走到头就指向第二个链表，第二个链表走到头就指向第一个链表，再次相遇，就是公共节点。
10. 面试题 02.01，移除重复节点。双指针+哈希，哈希保存数值是否出现，如果没有出现，继续往后移动，并给 `pre->next` 赋值；如果出现了，`pre` 指针的 `next` 为空，`p` 指针继续向后移动。
11. 面试题 02.02，返回倒数第 k 个节点。同剑指 offer 22 题，双指针。
12. 面试题 02.03，删除中间节点。题目描述就离谱，没想到是直接忽略下一个节点，直接修改当前节点的数值和指针。
13. 面试题 02.04，分割链表。第一种方案，设置两个额外的存储空间，一个存储大的，一个存储小的，最后重构链表；第二种方案，双指针，一个指针指向小的，一个指针指向大的，最后合并指针。
14. 面试题 02.05，双指针。第一个指针往后走，产生进位；第二个指针指向第一个指针前面的位置。最后对进位进行判断，如果进位是0，删除。返回结果。
15. 面试题 02.06，回文链表。开创两个额外的向量，存储链表内容，通过两个数组判断是否满足回文。
16. 面试题 02.07，链表相交。注意判断条件，双指针不为空的判断条件是或，不是与。
17. 面试题 02.08，环路检测。可以使用哈希，也别忘了也可以使用集合。
18. 第 19 题，删除链表的倒数第 N 个结点。双指针，先画图，注意指针的指向，考虑好极端情况。如果快指针为空，说明要删除的就是第一个节点。
19. 第 148 题，排序链表。使用额外的数组对元素排序，而后创建新的链表。

---

前面的题都是移动指针，但实际面试的题不一定需要自己去真的建立链表，回头整点其它题目。

### 第 0025 题，反转链表

首先是反转链表的代码：

```cpp
ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode* pre = nullptr;
    ListNode* cur = a;
    ListNode* next = a;
    while (cur != b) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
 }
```

- 建议背过这个代码。而后就是递归调用这个反转函数，确定要被反转的 `k` 组链表的 `a` 和 `b`。
- 如果长度不够，那么不用反转。
- 反转结束后，返回头节点，且尾节点指向下一个链表的头节点。

### 第 234 题，回文链表

判断回文链表，其实不用真的判断，把链表存入数组，而后对数组逆序，判断两个数组元素是否相等即可。

### 第 141 题，链表环判断

使用快慢指针，如果两者相遇，说明有环。指针移动时只判断快指针即可，如果没有环，快指针走完，说明慢指针没走完，可以退出，如果有环，快指针会掉入环中，判断即可。快指针一次走两步，所以判断条件也是：判断快、快.next 是否为空。

### 第 142 题，链表环起点判断

- 首先是环起点的判断，由于快指针比慢指针快了两倍。两者重逢时，快指针多走了 k 步，假设环的起点是 m，那么一个指针从重逢点出发，一个指针从点头出发，都走 k - m 步，那么相聚的点就是起点。
- 判断有环的关键要素：如果 fast 指针或 fast 指针的下一个节点为空，那么就不存在环。

### 第 876 题，链表的中点

同样是双指针，快指针比慢指针快两倍，快指针走完，慢指针就是中点。
