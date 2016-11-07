class Solution {
public:
    /*
     
        */
    void bactrack(int position, string digits, string combination, vector<string> letters, vector<string> &ans){
        
        if(position == digits.size()){
            ans.push_back(combination);
            return;
        }
        
        for(int i = 0; i<letters[digits[position]-'2'].size(); i++){
            
            combination[position] = letters[digits[position]-'2'][i];
            bactrack(position+1, digits, combination, letters, ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return vector<string>();
        vector<string> letters = {"abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string combination(digits.size(), 0);
        vector<string> ans;
        
        bactrack(0, digits, combination, letters, ans);
        
        return ans;
    }
};
