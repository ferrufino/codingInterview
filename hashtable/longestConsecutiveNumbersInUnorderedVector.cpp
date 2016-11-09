class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 1;
        while(!s.empty()){
            auto it = s.begin();
            int val = *it;
            s.erase(it);
            int prev = val-1;
            int next = val+1;
            int counter = 1;
            while( (it = s.find(prev)) != s.end()){
                prev--;
                counter++;
                s.erase(it);
            }
            
            while( (it = s.find(next)) != s.end()){
                next++;
                counter++;
                s.erase(it);
            }
            
            ans = max(counter, ans);
        }
        
        return ans;
        
    }
};
