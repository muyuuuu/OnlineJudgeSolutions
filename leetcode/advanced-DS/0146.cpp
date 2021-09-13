class DLinkNode {
public:
    int key;
    int val;
    DLinkNode* pre;
    DLinkNode* next;
    DLinkNode() : key{0}, val{0}, pre{nullptr}, next{nullptr} {};
    DLinkNode(int k, int v) : key{k}, val{v}, pre{nullptr}, next{nullptr} {};
};

class LRUCache {
private:
    unordered_map<int, DLinkNode*> m;
    int capacity;
    int size;
    DLinkNode* head;
    DLinkNode* tail;
public:
    LRUCache(int capacity) : capacity{capacity} {
        size = 0;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->pre = head;
    }
    
    // 插入节点
    void addHead(DLinkNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    // 删除某个节点,这里不能 free 掉
    // 因为 moveHead 还要用, 只有在 removeTail 时才能删除
    void removeNode (DLinkNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    // 某个缓存中的页面放到前面
    void moveHead(DLinkNode* node) {
        removeNode(node);
        addHead(node);
    }

    // 超出容量，删除尾部节点
    DLinkNode* removeTail() {
        DLinkNode* node = tail->pre;
        removeNode(node);
        return node;
    }

    // 获取节点
    int get(int key) {
        if (!m.count(key)) {
            return -1;
        }
        DLinkNode* node = m[key];
        moveHead(node);
        return node->val;
    }
    
    // 插入节点
    void put(int key, int value) {
        if (!m.count(key)) {
            DLinkNode* node = new DLinkNode(key, value);
            m[key] = node;
            // 添加
            addHead(node);
            size++;
            if (size > capacity) {
                DLinkNode* node = removeTail();
                // 链表需要存储 key 的原因
                m.erase(node->key);
                delete node;
                size--;
            }
        }
        else {
            DLinkNode* node = m[key];
            node->val = value;
            // 移动
            moveHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 执行用时： 360 ms , 在所有 C++ 提交中击败了 89.28% 的用户
// 内存消耗： 161.2 MB , 在所有 C++ 提交中击败了 38.97% 的用户
