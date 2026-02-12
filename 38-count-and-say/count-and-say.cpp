class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        // Recursive call
        string prev = countAndSay(n-1);
        int len = prev.length();
        
        // To store the answer
        string ans = ""; 
        
        // To count the frequency of identicals
        int count = 1;  
        
        // Traverse the string 
        for(int i=1; i < len; i++) {
            // If identicals are found, increment the counter
            if(prev[i] == prev[i-1]) count++;
            
            // Otherwise
            else {
                ans.push_back('0' + count); // Add frequency
                ans.push_back(prev[i-1]); // Add the digit 
                count = 1; // Reset counter to 1
            }
        }
        
        // Adding the frequency for the last digit and the last digit
        ans.push_back('0' + count);
        ans.push_back(prev[len-1]); 
        
        return ans; // Return the result
    } 
};