- [链表](#链表)
  - [删除链表的节点，剑指 offer 18](#删除链表的节点剑指-offer-18)
  - [两个链表的第一个公共节点，剑指 offer 52](#两个链表的第一个公共节点剑指-offer-52)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

# 链表

## 删除链表的节点，剑指 offer 18

经典的链表删除节点的操作，脑部一下数据结构的老师是怎么教的，要被删除的节点记为 `p`，上一个节点记为 `p1`，下一个节点记为 `p2`，只需要让 `p1` 指向 `p2` 即可。因此，我们可以知道遍历时需要通过 `p1` 来进行删除，因此需要额外设置一个其他节点指向这个链表。如果 `p1` 的下一个节点是目标节点，那么进行删除就可以了。因为在这个过程中头节点没有变化，所以最后返回头节点即可。

但是，如果删除的是头节点，那么这个方法是不起作用的，此时只返回头节点的后面一个节点就好了。

```cpp
class Solution {
public:
  ListNode* deleteNode(ListNode* head, int val) {
    if (head->val == val)
      return head->next;
    ListNode* p1 = new ListNode();
    p1->next = head;
    while (p1->next->val != val) {
      p1 = p1->next;
    }
    p1->next = p1->next->next;
    return head;
  }
};
```

## 两个链表的第一个公共节点，剑指 offer 52

![](52-1.png)

这道题的思路很经典，假设在公共节点之前，`A` 链表有 $m$ 个节点，`B` 链表有 $n$ 个节点，公共节点之后有 $x$ 个节点。如果 `p1` 指向 `A`，`p2` 指向 `B`，那么两个指针都移动 $m + n + x$ 次，就会指向共同节点。

所以，指针遍历链表 `A`，而 `p2` 指针遍历链表 `B`，当 `p1` 走到末尾时，指向 `B` 的开头，`p2` 同样这么处理，当两者相等时，就是公共节点。此外还有注意事项：如果两个链表不相交，那么返回 `nullptr` 即可。至于不相交也很好判断，两个指针移动 $m + n + x$ 次后都是空指针，表示没有相交点。

```cpp
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headB == nullptr || headA == nullptr)
      return nullptr;
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while (headA != headB) {
      headA = headA->next;
      if (headA == nullptr) {
        headA = p2;
        p2 = nullptr;
      }
      headB = headB->next;
      if (headB == nullptr) {
        headB = p1;
        p1 = nullptr;
      }
    }
    return headB;
  }
};
```
