class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;

        sort(nums.begin(), nums.end());

        int start = 0;
        int end = n - 1;

        while(start < n && nums[start] == sorted[start]){
            start++;
        }

        if(start == n){
            return 0;
        }

        while(end >= 0 && nums[end] == sorted[end]){
            end--;
        }
        int count = end - start + 1;

        return count; 
    }
};