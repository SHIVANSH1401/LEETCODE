/*We first count how many times each character appears using a hash map. Then, we sort the characters based on their frequencies in descending order and add each character to the answer as many times as it appears.*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s)/*for (int i = 0; i < s.size(); i++) {
                         char ch = s[i];
                         freq[ch]++;
                          }*/
            freq[ch]++;

        vector<pair<char, int>> arr(freq.begin(), freq.end());

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;//Sort the characters based on their frequencies, placing the character with the higher frequency first.
        });

        string ans = "";

        for (auto &it : arr)//Go through every element of arr one by one.
        /*for (int i = 0; i < arr.size(); i++) {
    auto &it = arr[i];
}*/
         {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};