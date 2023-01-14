class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        const int n = nums.size();
        if (n==1){return true;}
        if (nums[0] == 0){return false;}
        
        
        int goal = n - 1;
        int i = n - 2;
        
        while (i>=0){
        
        if (i + nums[i] >= goal){goal = i;}
        i-=1;
        }
        
        return goal == 0;
        
    }
};