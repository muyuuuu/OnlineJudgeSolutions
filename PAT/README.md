# 乙级

对乙级题目进行了分类整理，仅代表我个人的分类，不是很严谨。如1087可以集合，也可以哈希；1079也有数字计算和进制转换，但核心问题是字符串处理；1094是判断素数，但也有求字符串字串的使用。

此外，乙级以字符串处理为简单题目，其中涉及：求子串、字符串查找、替换等多个考点，借助结构体实现多条件排序，通常难度较大，且需要借助`vector`等数据结构方能实现。建议按类型刷题。

- 15分：简单的编程应用，涉及数组、分支、循环、判断等
- 20分：比较复杂的编程应用，逻辑复杂，但不涉及数据结构
- 25分：涉及简单的数据结构的使用，如`vector, map`等，不涉及算法，但涉及一些算法库的使用，如`algorithm`里的`sort`函数，同样需要合理设计逻辑，如哈希等，不然很容易出错。

| 类型                   | 题目                                                                                                                                                                                                  |
| ---------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 数据精度与范围         | 1011，1034，                                                                                                                                                                                          |
| 进制转换               | 1022，1074                                                                                                                                                                                            |
| 数组应用               | 1008，1061，1066，1092                                                                                                                                                                                |
| 素数判断               | 1007，1013，1094                                                                                                                                                                                      |
| 哈希                   | 1004，1005，1032， 1038，1047，1064，1072，1083                                                                                                                                                       |
| 字符串处理             | 1002，1003，1006，1009，1014，1017，1018，1021，1023，1024，1027，1028，1029，1031，1033，1036，1039，1042，1043，1044，1048，1052，1056，1057，1067，1076，1078，1079，1081，1084，1086， 1091，1093 |
| 数学计算               | 1001，1010，1012，1016，1019，1020，1026，1030，1037，1046，1049，1051，1053，1054，1060，1062，1063，1070，1071，1077，1082，1088，1089                                                              |
| 借助结构体的多条件排序 | 1015，1041，1055，1058，1073，1080，1085，1095                                                                                                                                                        |
| map映射                | 1059，1065，1069，1090                                                                                                                                                                                |
| 集合                   | 1087                                                                                                                                                                                                  |
| 链表类                 | 1025，1075                                                                                                                                                                                            |
| 排序算法               | 1035，1045                                                                                                                                                                                            |
| 子串匹配               | 1040                                                                                                                                                                                                  |
| 螺旋矩阵               | 1050                                                                                                                                                                                                  |
| 递归查找               | 1068                                                                                                                                                                                                  |

## 不知为何出错的题目

- 1030 5分，看不懂题
- 1044 看不懂题在说什么，仿佛是为了考试而考试，没意思。
- 1088 18分，一个点没过
- 1033 19分，一个点没过
- 1073 14分，两个点没过，猜测算法设计的不好

## 记录

本人没学过C++，第一次接触，记录的东西可能有点low。1003，1030看不懂题，不知道他在说什么。1005题目的描述实在花了很长时间才看懂。对于这些题目没有做的兴趣。

1. `scanf` 代替 `cin` 可在某种程度上避免超时。
2. 快速排序前后，主元位置不变，否则常规思路会超时。乙级 1045。
3. `stof`, `stoi` 完成字符串转数字。乙级 1054。
4. `isdigital` 传入的变量是`char`类型。
5. `if` `if` `else` 和 `if` `else if` `else` 对代码的执行结果影响不一样。
6. [二维数组的定义](https://blog.csdn.net/FX677588/article/details/52708813)：传入常量不能传入参数。乙级1066。
7. 输出`3`位数，高位补0：`printf("%03d ", arr[i][j]);`。
8. 哈希时要考虑空间大小，`int a[99999][99999]` 太大了，可以考虑使用 Map。乙级1090。
9. `map`键对应的值不止一个时，值可以考虑用 `vector` 载入。
10. 数字转字符串：`to_string()`，字符串逆序(algorithm)：`reverse(s.begin(), s.end());`，乙级1086。
11. 虽然链表可以考虑顺序结构和链式结构实现，但巧妙的软换会比两者都好。乙级1075。
12. `map`配合`hash`能有效提升程序的效率。乙级1065。
13. 在不知数据量多少的情况下，读取所有输入 `while(cin >> temp)`。乙级1009。
14. 尽量避免批量的命名数组，重复的操作很容易超时，同一种思维也能换一种写法。乙级1015。
15. 虽然我不知道我的哪里错了，但学习到了`abs(j - i) * 1.0 / x != abs(j - i) / x`。乙级1088。
16. `cin`时注意输入的与声明的数据类型是否有差异。乙级1053。
17. 乙级1085，差 `20ms` 超时。`if else`写法比三元运算符写法耗时。

```cpp
int cmp(node1 a, node1 b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
    {
        if (a.num != b.num)
            return a.num < b.num;
        else
            return a.id < b.id;
    }
}
```

不如`return a.score != b.score ? a.score > b.score : a.num != b.num ? a.num < b.num : a.id < b.id;`

19. 尽量不要操作一次删除一次，很容易超时，尽量以下标移动去解决问题。乙级1055。

# 甲级

之前刷了60多道，暂时先整理后刷的，不然一次性整理150道有点费劲。

| 题目类型               | 题目                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| ---------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 素数                   | 1015                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 数据精度               | 1058，1065，1081                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| 数组应用               | 1046，1042，1029(选择中位数)，1117，1067，1113，1128(N皇后判断)，1125，1082(极度繁琐，我抄的)，1002，1008，1009(与1002类似)，1011，1019，1041，1045，1046，1048，1054，1085，1109，1148                                                                                                                                                                                                                                                                                                            |
| 字符串处理             | 1035(`vector`应用)，1073，1069(字符串转数字)，1077(最大公共后缀子串)，1140，1136，1108，1120，1001，1005，1006，1023，1024，1027，1031，1035，1042，1061，1069，1073，1084，1092，1093(子串匹配)，1100，1108，1112，1116，1120，1132                                                                                                                                                                                                                                                               |
| 数学计算               | 1096，1104，1113，1117                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| `map`应用              | 1041(可哈希)，1144(不可哈希)，1124，1112，1121，1149，1022，1071                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| 哈希算法               | 1041(可`map`)，1121，1145(正宗哈希)，1050，1078(正宗哈希)                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 数据精度               | 1088，1136(写字符串加法)                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| `vector`应用           | 1048                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 借助结构体的多条件排序 | 1025，1012，1028，1047，1055，1062，1075，1083，1070，1036，1141，1137，1153，1070                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 排序算法               | 1089(插入与归并)，1101(快速排序)                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| 栈的应用               | 1051                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 树状数组               | 1057(无序数据的中位数)                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| `set`应用              | 1129(操作符重载)，1063                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| 动态规划               | 1040(最长对称子串)，1044，1045，1007(子序列和最大)                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 队列应用               | 1017                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 链表处理               | 1028，1032，1133，1052，1074，1097                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 树的应用               | 1004(层次遍历二叉树，输出叶子节点)，1102(层次、右根左遍历，反转二叉树)，1043(查找树、镜像查找树、先序、后序)，1064(完全查找树)，1099(按指定结构建立二叉查找树)，1110(判断完全二叉树，第六个测试点测评机器有问题)，1123(AVL树的层序遍历与判断是否是完全二叉树)，1066(寻找AVL树的根)，1130(中缀表达式)，1020(前序后序转层序)，1053(遍历树，求权重相等的路径)，1076(宽度优先遍历)，1079(深优遍历叶子节点)，1090(叶子节点数量)，1094(树中最长路径)，1106(树中最长路径与叶子数量)，1115(建立二叉查找树) |
| 图的应用               | 1154(相邻顶点颜色是否相同)，1146(有向图的拓扑序列)，1122(哈密顿图的判断)，1134(无向图的顶点覆盖)，1142(极大团问题)，1126(欧拉回路)，1013(连通分量计数)，1021(计数图内最长路径，连通子图计数)                                                                                                                                                                                                                                                                                                       |
| 最短路径               | 1030(借助遍历)，1003(最短路径数量与点权求和)，                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| 进制转换               | 1010                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 三维遍历               | 1091(dfs算法遍历三维数据)                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 旋转矩阵               | 1105                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 并查集                 | 1107，1114，1118                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |


## 记录

1. `vector<int> a(10, 1)`的含义为声明一个长度为10的不定长数组且全部初始化为 1 。
2. 当借助结构体的多条件排序需要比较的条件比较多时，可以考虑结构体中放数组。甲级1012。
3. 求两个递增序列的中位数，直接`sort`会超时，且有更好的算法，提前计算中位数的位置即可。甲级1029。
4. 运算的括号可能会加长运算时间而超时，也可考虑更换`cin`为`scanf`，`cout`为`printf`。甲级1055。
5. 在使用`map`时，查找无效表示为0，所以在设立映射时的初始值应该为1而不是0。甲级1137。
6. 简易判断完全二叉树的方法。甲级`1110-1.cpp`。

## 待解决

1067 的交换0排序算法

1044 的动态规划算法

1045 为何顺序计数不对

AVL树相关

1057 树形数组

1049 中 1 的计数