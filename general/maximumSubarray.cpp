class Solution {
public:
    int maxNum(int a, int b){
        
        return (a<b?b:a);
    }
    
    int maxSubArray(vector<int>& nums) {
        
        int max = nums[0];
        int acum = nums[0];
        
        for(int i = 1; i<nums.size(); i++){
            
            acum = maxNum(acum + nums[i], nums[i]);
            
            if(max<acum){
                max = acum;
            }
            
        }
        
        return max;
        
    }
};
