class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }

        for (int d = 2; 1LL * d * d <= n; d++) {
            if (n % d == 0) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;

        for(int i = 2; i <= n /2; i++){
            int j = n - i;

            if(isPrime(i) && isPrime(j)){
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};