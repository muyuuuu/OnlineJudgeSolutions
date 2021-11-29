- [链表](#链表)
  - [删除链表的节点，剑指 offer 18](#删除链表的节点剑指-offer-18)
  - [两个链表的第一个公共节点，剑指 offer 52](#两个链表的第一个公共节点剑指-offer-52)
  - [剑指 Offer 25. 合并两个排序的链表](#剑指-offer-25-合并两个排序的链表)

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

## 剑指 Offer 25. 合并两个排序的链表

首先判断两个链表哪个节点的数值小，选择数值最小的即可，然后对应链表的指针向后移动。但是有两个注意事项：

1. 两个链表有指针为空后，另一个链表可能不为空，需要追加剩下的部分
2. 创建额外的指针时，需要开辟空间，创建实体或者 new 都可以，不然 `p->next` 会失效

```cpp
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p = new ListNode();
    ListNode* dummy = p;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      }
      else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    p->next = l1 == nullptr ? l2 : l1;
    return dummy->next;
  }
};
```