class Solution {
public:

	bool isPalindrome(std::string s) {

		std::string s_new;

		for (int i = 0; i < s.size(); i++) {

			if (std::iswalnum(s[i])) { s_new += std::tolower(s[i]); }



		}


		for (int i = 0; i < std::ceil(s_new.size() / 2); i++) {

			if (s_new[i] != s_new[s_new.size() - 1 - i]) { return false; }


		}
		return true;

	}



};