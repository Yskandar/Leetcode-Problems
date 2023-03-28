class Solution {
public:

	bool isPalindrome(std::string s) {


		int l = 0, r = s.size() - 1;


		while (l < r) {

			if (not std::iswalnum(s[l])) { 
				l += 1;
                continue;}

			if (not std::iswalnum(s[r])) {
				r -= 1;
                continue;
			}

			if (std::tolower(s[l]) != std::tolower(s[r])) {
				return false;
			}
			l += 1;
			r -= 1;


		}

		return true;


	}



};