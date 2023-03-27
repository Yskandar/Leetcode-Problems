class Solution {
public:

	int characterReplacement(std::string& s, int& k){
	
		int max_len = 0;
		int l = 0, r = 0;
		std::unordered_map<char, int> letter_dict = {};



		
		while (r < s.size()) {
            
            // std::cout << "r: "<< r<< " l: "<< l << std::endl;
			
			if (letter_dict.find(s[r]) == letter_dict.end()) {
				letter_dict[s[r]] = 1;
			}
			else { letter_dict[s[r]] += 1; }
            // std::cout << s[r] << ": " << letter_dict[s[r]] << std::endl;
            
            while (not is_valid(s.substr(l, r-l+1), letter_dict, k)) {

				if (letter_dict.find(s[l]) != letter_dict.end()) {
					letter_dict[s[l]] = std::max(0, letter_dict[s[l]] - 1);
				}

				l += 1;

			}

			max_len = std::max(max_len, r - l + 1);

			r += 1;


		}

		return max_len;
	
	
	
	}


	bool is_valid(std::string substring, std::unordered_map<char, int>& letter_dict, int& k) {
		
		if (substring.empty() || letter_dict.empty()) {
			return true;
		}
        
        
		int maximum = 0;
        int sum = 0;

		for (auto element : letter_dict) {
            sum += element.second;
            if (element.second > maximum) { maximum = element.second; }
            if (substring.size() - sum <= maximum){ return ((substring.size() - maximum) <= k);}
			
            
		}
        
        //std::cout << "max letter: " << maxi->first << ": " << maxi->second<< std::endl;
        //std::cout << "sub_size: " << substring.size() << std::endl;
        //std::cout << "valid: " << (int)((substring.size() - maximum) <= k) << std::endl;

		return ((substring.size() - maximum) <= k);

	}



};