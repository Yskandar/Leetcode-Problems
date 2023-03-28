class Solution {
public:
    bool isAnagram(string s, string t) {
     
        int N = s.size(), M = t.size();
        if (N != M){return false;}
        
        std::unordered_map<char, int> s_dict;
        std::unordered_map<char, int> t_dict;
        
        
        int counts[26] = {0};
        
        
        for (int i = 0; i<N; i++){
            counts[s[i] -'a'] += 1;
            counts[t[i] -'a'] -= 1;
        }
        
        for (int i = 0; i<N; i++){
            if (counts[s[i]-'a'] != 0){return false;}
            
        }
        
    return true;
        
    }
};