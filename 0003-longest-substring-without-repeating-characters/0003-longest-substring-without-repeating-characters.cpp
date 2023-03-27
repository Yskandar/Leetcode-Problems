class Solution {
public:

	int lengthOfLongestSubstring(std::string s) {
		
		std::queue<char> window = {};
		int max_len = 0;
		std::unordered_set<char> letter_set;

		for (int i = 0; i < s.size(); i++) {

			while (letter_set.find(s[i]) != letter_set.end()) {
				letter_set.erase(window.front());
                window.pop();
				
			}

			window.push(s[i]);
			letter_set.insert(s[i]);
			max_len = std::max(max_len, (int)window.size());


		}

		return max_len;


	}


};