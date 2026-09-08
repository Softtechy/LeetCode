class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // s1 cannot fit inside s2
        if (s1.size() > s2.size())
            return false;

        // Frequency of characters in s1
        vector<int> need(26, 0);

        // Frequency of characters in current window
        vector<int> window(26, 0);

        // Build frequency array for s1
        for (char c : s1) {
            need[c - 'a']++;
        }

        int k = s1.size();

        // Sliding window over s2
        for (int i = 0; i < s2.size(); i++) {

            // Add current character
            window[s2[i] - 'a']++;

            // If window becomes larger than k,
            // remove the leftmost character
            if (i >= k) {
                window[s2[i - k] - 'a']--;
            }

            // Same frequency = permutation found
            if (window == need) {
                return true;
            }
        }

        return false;
    }
};