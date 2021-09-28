# 数据结构常用 API

每次刷题刷到一半发现 API 细节忘了，每次都要去查阅，这里整理常用的 API。

## Algorithm

| 用法 | 效果 | 作用于当前变量 |
|--|--|--|
| `std::reverse(bit, eit)` | 从 `bit` 到 `eit` 逆序容器，左闭右开 | 是 |
| `std::fill(bit, eit, val)` | 从 `bit` 到 `eit` 填充指定数值，左闭右开 | 是 |

## 数值

- `INT_MAX`，`INT_MIN` 来自头文件 `<climits>`
