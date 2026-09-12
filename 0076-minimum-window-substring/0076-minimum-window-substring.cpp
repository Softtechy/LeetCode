class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()){
            return "";
        }

        vector<int> need(128, 0);

        for(char c : t){
            need[c]++;
        }

        int left = 0;
        int required = t.size();

        int bestStart = 0;
        int bestLength = INT_MAX;

        for(int right = 0; right < s.size(); right++){

            if(need[s[right]] > 0){
                required--;
            }

            need[s[right]]--;

            while (required == 0){

                int windowLength = right - left + 1;

                if(windowLength < bestLength) {
                    bestLength = windowLength;
                    bestStart = left;
                }

                need[s[left]]++;

                if (need[s[left]] > 0){
                    required++;
                }

                left++;
            }
        }

        if(bestLength == INT_MAX){
            return "";
        }

        return s.substr(bestStart, bestLength);
        
    }
};
