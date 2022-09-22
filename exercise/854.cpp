/*
854. 相似度为 K 的字符串                难度：困难
对于某些非负整数 k ，如果交换 s1 中两个字母的位置恰好 k 次，能够使结果字符串等于 s2 ，则认为字符串 s1 和 s2 的 相似度为 k 。
给你两个字母异位词 s1 和 s2 ，返回 s1 和 s2 的相似度 k 的最小值。

链接：https://leetcode.cn/problems/k-similar-strings/

执行用时：160 ms, 在所有 C++ 提交中击败了35.45% 的用户
内存消耗：44.9 MB, 在所有 C++ 提交中击败了23.88% 的用户
通过测试用例：62 / 62
*/
#include"temp.h"

class Solution {
private:
    unordered_map<string, int> umsi;
public:
    int kSimilarity(string& s1, string& s2, int i) {
        int t = umsi[s1], tmp = 21;
        if(t)return t-1;

        while(i < s1.size() && s1[i] == s2[i])i++;
        if(i == s1.size()){
            umsi[s1] = 1;
            return 0;
        }

        for(int j = i+1; j < s1.size();j++){
            if(s1[j] == s2[i]){
                swap(s1[j], s1[i]);
                //pr(s1);
                tmp = min(tmp, kSimilarity(s1, s2, i+1));
                swap(s1[j], s1[i]);
            }
        }
        umsi[s1] = tmp + 2;
        return 1 + tmp;
    }


    int kSimilarity(string& s1, string& s2) {
        return kSimilarity(s1, s2, 0);
    }
};