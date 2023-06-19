class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentMAX = 0;
        int currentAlti = 0;
        int N = gain.size();

        for (int i=0; i<N; i++) {
            currentAlti += gain[i];
            if (currentAlti > currentMAX) {
                currentMAX = currentAlti;
            }
        }
        return currentMAX;
    }
};
