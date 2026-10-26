class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int count = 0;
        vector<int> freq(100, 0);

        for (auto& domino : d) {
            int a = domino[0];
            int b = domino[1];

            if (a > b) swap(a, b);

            int key = a * 10 + b;

            count += freq[key];
            freq[key]++;
        }

        return count;
    }
};