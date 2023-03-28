class Solution {
public:
    bool isAnagram(string s, string t) {
     
        int N = s.size(), M = t.size();
        if (N != M){return false;}
        
        std::unordered_map<char, int> s_dict;
        std::unordered_map<char, int> t_dict;
        
        
        for (int i = 0; i<N; i++){
            
            if (s_dict.find(s[i]) == s_dict.end()){
                s_dict[s[i]] = 1;
            }
            
            else{
                s_dict[s[i]] += 1;
            }
        
            if (t_dict.find(t[i]) == t_dict.end()){
                t_dict[t[i]] = 1;
            }
            else{
                t_dict[t[i]] += 1;
            }
            
            
        }
        
        for (int i = 0; i<N; i++){
            if (s_dict[s[i]] != t_dict[s[i]]){
                return false;
            }
            
        }
        
    return true;
        
    }
};