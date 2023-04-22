class Solution {
#define N s.length()-1
private:
    string s_;
    std::vector<std::vector<int>> map_;
/*
    int helper(string s, int center_cursor) {
        int cursor_f = center_cursor;
        int cursor_b = center_cursor+1;
        int temp_answer, temp_answer2;
        int answer = s.length();

        while((cursor_f>=0) && (cursor_b<=N)) {
            if (s[cursor_f] == s[cursor_b]) {
                cursor_f--;
                cursor_b++;
            }
            else {
                if ((cursor_f==0) || (cursor_b==N)) {
                    temp_answer = 1;
                    break;
                }
                temp_answer = 1+helper(s.substr(0,cursor_f-1) + s.substr(cursor_b,N), cursor_f-1);
                temp_answer2 = 1+helper(s.substr(0,cursor_f) + s.substr(cursor_b+1,N), cursor_f);

                if (temp_answer > temp_answer2) {
                    answer = temp_answer2;
                    break;
                }
                else {
                    answer = temp_answer;
                    break;
                }
            }
        }
        return answer;
    }
*/
    int helper(int idx_f, int idx_b) {
        if (map_[idx_f][idx_b] != -1) {
            return map_[idx_f][idx_b];
        }
        int answer = 0;
        int temp1, temp2;
        if (idx_f >= idx_b) {
            return 0;
        }
        while (idx_f < idx_b) {
            if (s_[idx_f] == s_[idx_b]) {
                idx_f++;
                idx_b--;
            }
            else {
                answer++;
                temp1 = helper(idx_f+1, idx_b);
                temp2 = helper(idx_f, idx_b-1);
                if (temp1>temp2) {
                    answer+=temp2;
                }
                else {
                    answer+=temp1;
                }
                break;
            }
        }
        map_[idx_f][idx_b] = answer;
        return answer;
    }
public:
    Solution() {
        map_ = vector<vector<int>>(500, vector<int>(500,-1));
    }
    int minInsertions(string s) {
/*
        int temp_answer;
        int center_cursor;

        for (center_cursor = 0; center_cursor<N; center_cursor++) {
            temp_answer = helper(s, center_cursor);
            if (temp_answer < answer) {
                answer = temp_answer;
            }
            temp_answer = helper(s.substr(0,center_cursor)+s.substr(center_cursor+1,N),center_cursor);
            if (temp_answer < answer) {
                answer = temp_answer;
            }
        }
*/

        /*
        while (idx_f < idx_b) {
            if (s[idx_f] == s[idx_b]) {
                idx_f++;
                idx_b--;
            }
            else {
                answer++;
                idx_f++;
            }
        }
        */

        s_ = s;
        // return answer;
        return helper(0, N);
    }
};
