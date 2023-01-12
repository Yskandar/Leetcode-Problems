class Solution {
public:
    int rob(vector<int>& nums) {

        const int n = nums.size();

        int dp_1 = 0;
        int dp_2 = 0;
        int temp = 0;
        for (auto num:nums){
            temp = max(num + dp_2, dp_1);
            dp_2 = dp_1;
            dp_1 = temp;
            
        }
        
        return dp_1;

    }
};