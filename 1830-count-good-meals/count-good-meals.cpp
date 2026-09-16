class Solution {
public:
    int countPairs(vector<int>& d) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long count = 0;

        for (int x : d) {
            for (int power = 1; power <= (1 << 21); power *= 2) {
                int required = power - x;

                if (freq.count(required)) {
                    count += freq[required];
                }
            }

            freq[x]++;
        }

        return count % MOD;
    }
};