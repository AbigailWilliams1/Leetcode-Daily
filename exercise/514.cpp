/*
514. 自由之路               难度：困难
电子游戏“辐射4”中，任务 “通向自由” 要求玩家到达名为 “Freedom Trail Ring” 的金属表盘，并使用表盘拼写特定关键词才能开门。
给定一个字符串 ring ，表示刻在外环上的编码；给定另一个字符串 key ，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。
最初，ring 的第一个字符与 12:00 方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。
旋转 ring 拼出 key 字符 key[i] 的阶段中：
您可以将 ring 顺时针或逆时针旋转 一个位置 ，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。

链接：https://leetcode.cn/problems/freedom-trail/description/
*/
#include "temp.h"

class Solution {
    const int _max = 1 << 16;
public:
    int findRotateSteps(string ring, string key) {
        int len_r = ring.length(), len_k = key.length();
        int dp[100][100] = {0};
        for(int j = 0; j < len_r; j++)
            dp[0][j] = ring[j] == key[0] ? min(j, len_r - j) : _max;
        for(int i = 1; i < len_k; i++){
            for(int j = 0; j < len_r; j++){
                dp[i][j] = _max;
                if(key[i] != ring[j])continue;
                for(int k = 0; k < len_r; k++){
                    int distance = abs(k - j);
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + min(distance, len_r - distance));
                }
            }
        }
        // for(int i = 0; i < len_k; i++){
        //     for(int j = 0; j < len_r; j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return *min_element(dp[len_k - 1], dp[len_k - 1] + len_r) + len_k;
    }
};