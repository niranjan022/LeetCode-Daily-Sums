class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int n = words.size();
        vector<int> prefixSum(n, 0);
        for (int i = 0; i < n; i++) {
            if (!words[i].empty() && isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefixSum[i] = 1;
            }
            if (i > 0) {
                prefixSum[i] += prefixSum[i - 1];
            }
        }
        vector<int> result(q.size());
        for (int i = 0; i < q.size(); i++) {
            int l = q[i][0], r = q[i][1];
            result[i] = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
        }
        return result;
    }
};
