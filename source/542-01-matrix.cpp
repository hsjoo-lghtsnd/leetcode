class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        int temp;
        
        /*
        // naive approach: Time limit exceed
        vector<vector<int>> v(M, vector<int>(N, 10000));
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (!mat[i][j]) {
                    for (int k=0; k<M; k++) {
                        for (int l=0; l<N; l++) {
                            if (v[k][l] > abs(k-i)+abs(l-j)) {
                                v[k][l] = abs(k-i)+abs(l-j);
                            }
                        }
                    }
                }
            }
        }
        */

        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (mat[i][j]) { // mat[i][j] != 0
                    if (i) { // i != 0
                        if (j) { // j != 0
                            // temp = mat[i-1][j]>mat[i][j-1] ? mat[i][j-1]+1 : mat[i-1][j]+1;
                            // mat[i][j] = temp>mat[i][j] ? mat[i][j] : temp;
                            mat[i][j] = mat[i-1][j]>mat[i][j-1] ? mat[i][j-1]+1 : mat[i-1][j]+1;
                        }
                        else {
                            // mat[i][j] = mat[i-1][j]+1>mat[i][j] ? mat[i][j] : mat[i-1][j]+1;
                            mat[i][j] = mat[i-1][j]+1;
                        }
                    }
                    else {
                        if (j) {
                            // mat[i][j] = mat[i][j-1]+1>mat[i][j] ? mat[i][j] : mat[i][j-1]+1;
                            mat[i][j] = mat[i][j-1]+1;
                        }
                        else {
                            mat[i][j] = 10000;
                        }
                    }
                }
            }
        }

        for (int i=M-1; i>=0; i--) {
            for (int j=N-1; j>=0; j--) {
                if (mat[i][j]) {
                    if (i!=M-1) {
                        if (j!=N-1) {
                            temp = mat[i+1][j]>mat[i][j+1] ? mat[i][j+1]+1 : mat[i+1][j]+1;
                            mat[i][j] = temp>mat[i][j] ? mat[i][j] : temp;
                        }
                        else {
                            mat[i][j] = mat[i+1][j]+1>mat[i][j] ? mat[i][j] : mat[i+1][j]+1;
                        }
                    }
                    else {
                        if (j!=N-1) {
                            mat[i][j] = mat[i][j+1]+1>mat[i][j] ? mat[i][j] : mat[i][j+1]+1;
                        }
                    }
                }
            }
        }
        return mat;
    }
};
