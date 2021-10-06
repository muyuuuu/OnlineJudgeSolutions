# 数据结构常用 API

每次刷题刷到一半发现 API 细节忘了，每次都要去查阅，这里整理常用的 API。

## Algorithm

| 用法 | 效果 | 作用于当前变量 |
|--|--|--|
| `std::reverse(bit, eit)` | 从 `bit` 到 `eit` 逆序容器，左闭右开 | 是 |
| `std::fill(bit, eit, val)` | 从 `bit` 到 `eit` 填充指定数值，左闭右开 | 是 |

## map 和 unordered\_map

`map` 位于头文件 `<map>`, `unordered_map` 位于头文件 `<unordered_map>`。`map` 会按照 `key` 升序排列。常用方法：

| 用法 | 效果 | 作用于当前变量 |
|--|--|--|
| `m.count(key)` | 返回 `key` 在哈希表中的数量，1 或 0 | 是 |
| `m.clear()` | 清空哈希表 | 是 |
| `m.erase(key)` | 删除哈希表中的 `key`  | 是 |
| `m.erase(bit, eit)` | 删除哈希表中 `bit` 到 `eit` 之间的元素，左闭右开 | 是 |
| `m1.swap(m2)` | 交换两个 `map` | 是 |
| `m.lower_bound(val)` | 返回第一个哈希表中 `key` 等于 `val` 的迭代器指针，否则返回 `m.end()` | 是 |
| `m.upper_bound(val)` | 返回第一个哈希表中 `key` 大于 `val` 的迭代器指针，否则返回 `m.end()` | 是 |

## vector

定义在头文件 `vector`，这个是比较常见的容器，类似于 python 的列表吧。

| 用法 | 效果 | 作用于当前变量 |
|--|--|--|
| `v1(n, v)` | 构造函数，`v1`中放入 `n` 个取值为 `v` 的元素 | 是 |
| `back()` | 返回最有一个元素 | 是 |
| `front()` | 返回第一个元素 | 是 |
| `assign(n, v)` | 从开始指针到结束指针分配元素，或分配 `n` 个取值为 `v` 的元素 | 是 |
| `insert(it, item)` | 在 `it` 位置之前插入 item，可以是单个元素，可以是迭代器| 是 |
| `emplace(it, item)` | 可以理解为 `insert` 的变种，`insert` 插入为创建好的对象，`emplace` 可以不用创建对象，直接插入 | 是 |
| `push_back()` | 尾部追加 | 是 |
| `emplace_back()` | 尾部追加，效果同 `emplace` | 是 |
| `pop_back()` | 尾部弹出 | 是 |

## set

定义在头文件 `set`，不包含重复元素；同样 `multiset` 也定义在头文件 `set`，但可以包含重复元素。两者都按 `key` 升序，都是集合的意思。

| 用法 | 效果 | 作用于当前变量 |
|--|--|--|
| `s.insert(item)` | 将元素插入集合  | 是 |
| `s1.merge(s2)` | 将 `s2` 与 `s1` 不同的元素放入 `s1`，且在 `s2` 中删除 | 是 |
| `s.count(key)` | 统计 `key` 出现的次数  | 是 |
| `s.erase(key)` | 删除集合中的 `key` | 是 |

`lower_bound()` 和 `upper_bound()` 的含义同 `map`。

## deque

包含在头文件 `deque` 中，双端队列，大部分 API 与 vector 相同，额外增加了头部的删除和插入操作，分别为 `push_front()` 和 `pop_front()`，以及相应的 `emplace` 版本。

## 数值

- `INT_MAX`，`INT_MIN` 来自头文件 `<climits>`
