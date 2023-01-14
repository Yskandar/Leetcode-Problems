class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int l=0, r=0, res=0;
        while (r<n-1){
            int temp = r;
            
            for (int j = l; j <= temp; j++){r = max(r, j + nums[j]);}
            
            l = temp + 1;
            res += 1;
        }
        
        return res;   
        
    }
};