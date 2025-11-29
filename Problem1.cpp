// Time Complexity : O(mxn)
// Space Complexity : O(mxn)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :  No

// Your code here along with comments explaining your approach
// 1. We perform a BFS traversal here and keep changing the color of the image
// for their neighbors
// 2. In the end we return the modified image
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int ogcolor = image[sr][sc];
    if (ogcolor == color)
      return image;
    int m = (int)image.size();
    int n = (int)image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
      auto front = q.front();
      q.pop();
      image[front.first][front.second] = color;
      for (auto dir : dirs) {
        int nr = dir.first + front.first;
        int nc = dir.second + front.second;
        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
            image[nr][nc] == ogcolor) {
          q.push({nr, nc});
        }
      }
    }
    return image;
  }
};
