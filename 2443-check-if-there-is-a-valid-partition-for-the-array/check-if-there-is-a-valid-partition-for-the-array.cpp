class Solution {
public:
    bool solve(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if (i == n) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        bool ans = false;

        if (i + 1 < n && nums[i] == nums[i + 1]) {
            ans = ans || solve(i + 2, nums, dp);
        }

        if (i + 2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
            ans = ans || solve(i + 3, nums, dp);
        }

        if (i + 2 < n && nums[i + 1] == nums[i] + 1 &&
            nums[i + 2] == nums[i + 1] + 1) {
            ans = ans || solve(i + 3, nums, dp);
        }

        return dp[i] = ans;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(0, nums, dp);
    }
};