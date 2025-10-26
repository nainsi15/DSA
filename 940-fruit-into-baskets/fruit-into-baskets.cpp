class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen =0;
        int l = 0, r =0;

        unordered_map<int, int> map;

        while(r < fruits.size()){
          map[fruits[r]]++;
          
          if(map.size() > 2){
              map[fruits[l]]--;
              if(map[fruits[l]] == 0){
              map.erase(fruits[l]);
            }
            l++;
          }
            if(map.size() <= 2){
              maxLen = max(maxLen , r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};