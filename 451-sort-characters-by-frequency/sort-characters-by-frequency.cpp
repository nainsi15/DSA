class Solution {
public:
    static bool comp(pair<int,char> &p1, pair<int, char> &p2){
			if(p1.first > p2.first) return true;
			if(p1.first < p2.first) return false;
			return p1.second < p2.second;
		}
    string frequencySort(string s) {
        pair<int, char> freq[256];

			for(int i = 0 ; i < 256; i++){
				freq[i] = {0, (char)i};
			}
			for(int i = 0 ; i <s.length() ; i++){
				freq[(unsigned char)s[i]].first++;
			}
			sort(freq, freq + 256, comp);
			string ans ="";
			for(int i = 0 ; i < 256 ;i++){
				while(freq[i].first--){
					ans.push_back(freq[i].second);
				}
			}
			return ans;
    }
};