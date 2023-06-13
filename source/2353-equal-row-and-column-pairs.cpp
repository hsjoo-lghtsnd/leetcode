class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<int> grid_transpose;
        int N = grid[0].size();
        int result = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                grid_transpose.push_back(grid[j][i]);
            }
            for (int j=0; j<N; j++) {
                if (grid[j]==grid_transpose) {
                    result++;
                }
            }
            grid_transpose.clear();
        }
        return result;
    }
};

