- [链表](#链表)
  - [删除链表的节点，剑指 offer 18](#删除链表的节点剑指-offer-18)
  - [两个链表的第一个公共节点，剑指 offer 52](#两个链表的第一个公共节点剑指-offer-52)
  - [剑指 Offer 25. 合并两个排序的链表](#剑指-offer-25-合并两个排序的链表)
  - [剑指 Offer 24. 反转链表](#剑指-offer-24-反转链表)
  - [剑指 Offer 35. 复杂链表的复制](#剑指-offer-35-复杂链表的复制)

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

## 剑指 Offer 24. 反转链表

反转链表的标配模板。因为每次反转需要移动两个 next 的指针，因需要设置三个链表节点。然后通过这三个节点依次反转链表，如果是反转部分链表，那么条件就是 `while (curr != end)`。

```cpp
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = head;
    ListNode* curr = head;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
```

## 剑指 Offer 35. 复杂链表的复制

请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e1.png)

之前做过这个题，但又忘记了。刚开始尝试直接复制，发现没办法复制 random 节点。官方题解里面的回溯不容易理解，所以还是用传统遍历的方法了。

首先创建一个 map，key 是要复制的链表的节点，value 是新创建的节点，这里只记录数值，不记录指针关系。之后开始操作指针关系，由于 value 是新创建的节点，因此更改在指针关系时需要根据 map 中 key 的关系来操作 map 的 value。

```cpp
class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;
    Node* p = head;
    while (p != nullptr) {
      m[p] = new Node(p->val);
      p = p->next;
    }
    p = head;
    while (p != nullptr) {
      // 新节点的下一个节点仍然是新节点
      m[p]->next = m[p->next];
      m[p]->random = m[p->random];
      p = p->next;
    }
    return m[head];
  }
};
```