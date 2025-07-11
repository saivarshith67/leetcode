class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> hashMapS, hashMapT; // Fix: key should be `char`

        for (char ch : s) {
            hashMapS[ch]++;
        }

        for (char ch : t) {
            hashMapT[ch]++;
        }

        return hashMapS == hashMapT;
    }
};
