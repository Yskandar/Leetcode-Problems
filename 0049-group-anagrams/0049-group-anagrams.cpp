class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {

        std::hash<std::string> hasher;
        std::unordered_map<size_t, std::vector<std::string>> dico = {};


        for (int i = 0; i < strs.size(); i++) {

            std::string s_sorted = strs[i];
            std::sort(s_sorted.begin(), s_sorted.end());
            
            dico[hasher(s_sorted)].push_back(strs[i]);


        }

        std::vector<std::vector<std::string>> ans;
        for (auto element : dico) {

            ans.push_back(element.second);
        }

        return ans;
        
    }
};