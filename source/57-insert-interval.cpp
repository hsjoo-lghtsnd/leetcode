class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N = intervals.size();
        int idx_a=N;
        int idx_b=N;
        int a=newInterval[0];
        int b=newInterval[1];

        if ((N==0) || intervals[N-1][1] < a) {
            intervals.push_back(newInterval);
            return intervals;
        }

        for (int i=0; i<N; i++) {
            if (intervals[i][0] > a) {
                idx_a = i-1;
                break;
            }
        }
        for (int i=0; i<N; i++) {
            if (intervals[i][1] > b) {
                idx_b = i;
                break;
            }
        }

        for (auto i: intervals) {
            if ((i[0] <= a) && (i[1] >= b)) {
                return intervals;
            }
        }
        
        if (idx_a == N) {
            intervals[N-1][1] = b;
            return intervals;
        }
        else {
            if (idx_a == idx_b) {
                intervals[idx_b][1]=b;
                return intervals;
            }
        }


        vector<vector<int>> v;
        if (intervals[0][0] > b) {
            v.push_back(newInterval);
            for (auto it:intervals) {
                v.push_back(it);
            }
            return v;
        }

        if (idx_b == 0) {
            intervals[0][0] = a;
            return intervals;
        }

        for (int i=0; i<idx_a; i++) {
            v.push_back(intervals[i]);
        }
        if (idx_a != -1) {
            if (intervals[idx_a][1] < a) {
                v.push_back(intervals[idx_a]);
            }
            else {
                newInterval[0] = intervals[idx_a][0];
            }
        }
        // else: idx_a==-1: newInterval[0] = a
        if ((idx_b != N) && (intervals[idx_b][0]<=b)) {
            newInterval[1] = intervals[idx_b][1];
            idx_b++;
        }
        v.push_back(newInterval);
        if (intervals[N-1][1] < b) {
            return v;
        }
        for (int i=idx_b; i<N; i++) {
            v.push_back(intervals[i]);
        }

        return v;
    }
};
