class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int target = image[sr][sc];
        int x,y;
        
        vector<int> stx;
        vector<int> sty;
        
        if (target == color) {
            return image;
        }
        
        stx.push_back(sr);
        sty.push_back(sc);
        
        
        // iterative model
        while (stx.size() != 0) {
            x = stx.back();
            stx.pop_back();
            y = sty.back();
            sty.pop_back();
            
            image[x][y] = color;
            
            if (((x-1)>=0) && (image[x-1][y] == target)) {
                stx.push_back(x-1);
                sty.push_back(y);
            }
            if (((x+1) <m) && (image[x+1][y] == target)) {
                stx.push_back(x+1);
                sty.push_back(y);
            }
            if (((y-1)>=0) && (image[x][y-1] == target)) {
                stx.push_back(x);
                sty.push_back(y-1);
            }
            if (((y+1) <n) && (image[x][y+1] == target)) {
                stx.push_back(x);
                sty.push_back(y+1);
            }
        }
        
        return image;
    }
};

