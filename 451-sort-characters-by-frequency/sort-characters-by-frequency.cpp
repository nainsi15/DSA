class Solution {
public:
    
    string frequencySort(string s) {
        //declare map
       unordered_map<char, int> mp;
       //declare a priority queue
       priority_queue<pair<int,char>> pq;
       string ans = "";

       for(auto ch : s){
        mp[ch]++;
       }
        //push in priority queue
       for(auto it : mp){
        pq.push({ it.second,it.first});
       }
        //traverse the heap and append char to the string 
        while(!pq.empty()){
            auto temp = pq.top();
            int freq  = temp.first;
            char ch = temp.second;
            ans += string(freq, ch);
            pq.pop();
        }
        return ans;
    } 
};