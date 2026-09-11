class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        long long ans = 0;
        long long sum = 0;

        int i = 0;
        int n = nums.size();

        for(int j = 0; j < n; j++){
            f[nums[j]]++;
            sum = sum + nums[j];

            if(j - i + 1 > k){
                f[nums[i]]--;
                sum = sum - nums[i];

                if(f[nums[i]] == 0){
                    f.erase(nums[i]);
                }
                i++;
            }

            if(j - i + 1 && f.size() == k){
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};