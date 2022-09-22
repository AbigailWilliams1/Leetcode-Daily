/*
827. 最大人工岛             难度：困难
给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
返回执行此操作后，grid 中最大的岛屿面积是多少？
岛屿 由一组上、下、左、右四个方向相连的 1 形成。

链接：https://leetcode.cn/problems/making-a-large-island/

执行用时：512 ms, 在所有 C++ 提交中击败了45.92% 的用户
内存消耗：140.5 MB, 在所有 C++ 提交中击败了56.96% 的用户
通过测试用例：75 / 75
*/
#include<temp.h>

class Solution {
private:
    const vvi action = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    void bfs(vvi& grid, int x, int y, int number){
        int n = grid.size();
        grid[x][y] = number;
        for(int i = 0; i < 4; i++){
            int newx = x + action[i][0], newy = y + action[i][1];
            if(newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy] == 1)
                dfs(grid, newx, newy, number);
        }
        return;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), number = 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    bfs(grid, i, j, number);
                    number++;
                }
            }
        }
        if(number == 2)return 1;
        vi area(number+1, 0);
        for(auto &i : grid){
            for(auto &j : i){
                area[j]++;
            }
        }

        int maxArea = min(n * n, *max_element(area.begin(), area.end())+1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    usi adj;
                    for(int k = 0; k < 4; k++){
                        int x = i + action[k][0], y = j + action[k][1];
                        if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1)
                            adj.insert(grid[x][y]);
                    }
                    if(adj.size() > 1){
                        int tmp = 1;
                        for(auto & t : adj)
                            tmp += area[t];
                        maxArea = max(maxArea, tmp);
                    }
                }
            }
        }

        return maxArea;
    }
};