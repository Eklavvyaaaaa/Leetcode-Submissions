class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;

        for (int num : nums) {
            x ^= num;
        }

        unsigned int bit = x;
        bit = bit & -bit;

        int a = 0;
        int b = 0;

        for (int num : nums) {
            if (num & bit)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};