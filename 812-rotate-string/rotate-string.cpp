class Solution {
public:
    bool rotateString(string s, string goal) {
			// Strings must be same length to be rotations of each other
			if(s.length() != goal.length()){
				return false;
			}
			string doubleS = s + s;  // Concatenate s with itself
			//Check if goal is a substring of s + s
			return doubleS.find(goal) != string::npos;
    }
};