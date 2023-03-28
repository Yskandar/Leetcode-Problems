class Solution {
public:
    bool isValid(string s) {
        
        
        std::unordered_map<char, int> dico = {{'[',']'}, {'{','}'}, {'(',')'}};
        std::stack<int> ans = {};
        
        
        for (int i = 0; i<s.size(); i++){
            
            if (ans.empty()){ans.push(s[i]);
                                    continue;}
            if (dico[ans.top()] == s[i]){ans.pop();}
            else{ans.push(s[i]);}
            
        }
        
        return ans.empty();
        
        
        
        
    }
};