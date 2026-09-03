class Solution {
public:
    int mini= INT_MAX;
    bool uniformArray(vector<int>& nums1) {
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%2==1){
                mini=min(mini, nums1[i]);
            }
        }
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%2==0 && nums1[i]<=mini && mini!=INT_MAX){
                return false;
            }
        }
        return true;    
    }

};