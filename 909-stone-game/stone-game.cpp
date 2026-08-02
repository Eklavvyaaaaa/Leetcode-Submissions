class Solution {
public:
    int dp[501][501];

    int solve(vector<int>& piles, int left, int right) {
        if (left == right)
            return piles[left];

        if (dp[left][right] != -1)
            return dp[left][right];

        int takeLeft = piles[left] - solve(piles, left + 1, right);
        int takeRight = piles[right] - solve(piles, left, right - 1);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, piles.size() - 1) > 0;
    }
};