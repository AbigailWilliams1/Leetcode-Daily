/*
365. 水壶问题               难度：中等
有两个水壶，容量分别为 jug1Capacity 和 jug2Capacity 升。水的供应是无限的。确定是否有可能使用这两个壶准确得到 targetCapacity 升。
如果可以得到 targetCapacity 升水，最后请用以上水壶中的一或两个来盛放取得的 targetCapacity 升水。
你可以：
    装满任意一个水壶
    清空任意一个水壶
    从一个水壶向另外一个水壶倒水，直到装满或者倒空

链接：https://leetcode.cn/problems/water-and-jug-problem/description


*/
#include "temp.h"

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity + jug2Capacity < targetCapacity) return false;
        if(jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity) return true;
        if(jug1Capacity == 0 || jug2Capacity == 0) return false;
        if(jug1Capacity > jug2Capacity) swap(jug1Capacity, jug2Capacity);
        if(targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0) return true;
        return false;
    }
};