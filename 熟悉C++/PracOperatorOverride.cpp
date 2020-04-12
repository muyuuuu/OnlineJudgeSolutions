/*** 
 * @Author         : lanling
 * @Date           : 2020-04-12 14:41:50
 * @LastEditTime   : 2020-04-12 14:42:19
 * @FilePath       : \熟悉C++\PracOperatorOverride.cpp
 * @Github         : https://github.com/muyuuuu
 * @Description    : 操作符重载练习
 * @佛祖保佑，永无BUG
 */

struct node 
{
    int value, cnt;
    bool operator < (const node &a) const 
    {
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};