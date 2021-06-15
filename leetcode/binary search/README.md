- 第 35 题，搜索插入位置。最朴素的二分法，如果元素在，返回索引，如果不在，返回应该插入位置的索引。注意循环条件与退出条件。
- 第 349 题，两个数组的交集。首先对两个数组进行排序，而后两个索引分别遍历数组。比较第一个数组与第二个数组的大小。如果相等，判断不重复后追加；无论是否相等，索引都要自增；如果小于，第一个数组的索引自增，如果大于，第二个数组的索引自增。
- 第 350 题，两个数组的交集 II。和 349 题类似，不过加了限制，一个元素可以出现多次，但出现次数应与元素在两个数组中出现次数的最小值一致。第一种方案，哈希，记录第一个数组中每个元素出现的次数，如果第二个数组中出现了，追加，次数--，当次数为 0 时，说明是出现次数的最小值。第二种方案，排序后双指针，不过不用判断这个元素是否出现过了。
- 第 374 题，猜数字大小。最简单的二分应用，注意如何使用题目提供的接口。
- 第 441 题，排列硬币。因本人追求的是常规思路，所以暴力破解了。其实二分也行，需要借助等差数列的求和公式。
- 第 392 题，判断子序列。可以将时间复杂度从 `NM` 降低到 `N+M`，只需一次遍历。如果匹配上了，子串自增，而无论如何，被查找的字符串一定自增，最后查看子串的索引是否等于长度即可。
- 剑指 offer 53-1 题，在排序数组中查找数字 I。两种方案，第一种方案是 lower_bound 和 upper_bound，包含在头文件 algorithm 中。第二种方案是二分，不过需要增加额外的判断条件。除了保留最原始的 mid 判断外，还要增加左侧边界的判断。在左侧是目标的条件下，如果右侧是目标，返回；如果中间是目标，右侧递减；如果都并不是，右侧等于 mid - 1。当然，也可以通过右侧是目标的条件进行判断。
- 剑指 offer 1005 题，稀疏数组搜索。本质是二分，不过需要增加额外的空字符串删除。如果中间是空，中间指针向右移动，**注意越界判断，**如果 mid >= right，说明 mid 到 right 都是空，r -= 1 直接下一循环；如果不是，进行常规的二分判断。
- 剑指 offer 53-2 题，0～n-1中缺失的数字。二分不仅能查找数字所在的位置，还能在该数字缺失的情况下，找到插入的位置。所以，简单的二分查找应该插入的位置即可。
- 面试题 17.08，马戏团人塔。我草率了，以为是简单的排序，结果发现是动态规划。留着，日后解决。
- 面试题 10.09，排序矩阵查找。不同的是，这是二维矩阵，矩阵的行、列都是升序的，所以，需要巧妙的二分。以矩阵的右上角或左下角为起点，因为这样能确定唯一的移动方向。且需要两个索引。以右上角为例，大了，水平左移；小了，竖直下移。
- 第 1818 题，绝对差值和。首先，先求出两个数组的绝对值之差。且，对第一个数组进行去重。而后，利用二分法，在第一个数组中查找和第二个数组最接近的元素，分别为前后两个位置。看看能降低多少，记录最大的降低数值。最后减去降低的数值，就是答案。我认为这道题不错。
- 第 454 题，四数相加 II。我以为是动态规划要跳过，结果发现可以分组。
- 第 875 题，爱吃香蕉的珂珂。变相二分法的应用，确定速度的最小值和最大值区间，然后开始二分搜索。对于每一个速度值，判断是否能吃完，如果能，更新最小值。
- 第 1482 题，制作 m 束花所需的最少天数。和 875 题类似，不过这里不能直接排序，需要保持原有顺序。所以需要遍历获取最小值和最大值，而后在区间内二分搜索判断。
- 第 1111 题，有效括号的嵌套深度。其实我没看太懂，大概意思是，根据括号的匹配程度，填入 0 和 1 。设置一个变量 a，如果是左括号，那么变量 a 自增，追加 a%2；如果是右括号，应该先和左括号匹配，追加 a%2，然后 a 自减。这样是为了对应 `((())))` 这样的情况。
- 第 1552 题，两球之间的磁力。因为球不管放到哪里，磁力都是一样的，所以对序列进行排序。磁力的最小值应该是相邻元素的最小值，不过可以直接设为 1，磁力的最大值是序列元素的末尾减去开头。在这个磁力区间内进行搜索。如果能放下 m 个球，说明成功，搜索右区间；如果放不下，搜索左区间。如果想放下这个球，现在第一个位置放一个，而后遍历，如果差大于磁力，说明放得下，记录当前位置。这道题有很多需要注意的细节。