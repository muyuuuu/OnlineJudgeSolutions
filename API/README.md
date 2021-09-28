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


## 数值

- `INT_MAX`，`INT_MIN` 来自头文件 `<climits>`
