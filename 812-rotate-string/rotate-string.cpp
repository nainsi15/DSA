class Solution {
public:
    bool rotateString(string s, string goal) {
			if(s.length() != goal.length()){
				return false;
			}
			for(int i = 0  ;i  < s.length(); i++){
				string right = s.substr(i);
				string left = s.substr(0, i);
				if(right + left == goal) return true;
			}
			return false;
    }
};