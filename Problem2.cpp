// Time Complexity : O(mxn)
// Space Complexity : O(mxn)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :  No

// Your code here along with comments explaining your approach
// 1. We first process all zeroes since they will be a distance 0  from 0
// 2. Then we go level by level and keep updating the distances if mat[nr][nc]
// == -1
// 3. In the end we returned the matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int m = (int)mat.size();
    int n = (int)mat[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1) {
          mat[i][j] = -1;
        } else {
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      int size = q.size();
      auto front = q.front();
      q.pop();
      for (auto dir : dirs) {
        int nr = dir.first + front.first;
        int nc = dir.second + front.second;
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1) {
          q.push({nr, nc});
          mat[nr][nc] = mat[front.first][front.second] + 1;
        }
      }
    }

    return mat;
  }
};
