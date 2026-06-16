class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> mp(26, 0);
       for(int i = 0 ; i < tasks.size(); i++){
        mp[tasks[i] - 'A']++;
       }
       int time = 0;
       //max heap
       priority_queue<int> pq;

       for(int i = 0 ; i < 26; i++){
        if(mp[i] > 0)
        pq.push(mp[i]);
       }

       while(!pq.empty()){
        vector<int> temp;
        for(int i = 1 ; i <= n+1; i++){
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] > 0){
                    pq.push(temp[i]);
                }
            }
            if(!pq.empty()){
                time += n+1 ;
            }
            else{
                time += temp.size();
            }
        }
       return time;
    }
};