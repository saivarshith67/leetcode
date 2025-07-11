class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagramMap;

        for(const string &s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            anagramMap[sortedS].push_back(s);
        }

        vector<vector<string>> res;

        for(auto &pair : anagramMap) {
            res.push_back(pair.second);
        }

        return res;
    }
};