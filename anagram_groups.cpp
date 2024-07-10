class Solution {
public:

    string get_key(string iter)
    {
        vector<int> count(26, 0); // if i dont provide anything, it will be initialized with 0
        
        for (auto c: iter){
            count[c-'a']++;
        }

        string key;
        for (int num : count) {
            key.append(to_string(num) + '#');
        } 
        cout<<key<<endl;
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> values;

        for (auto iter: strs){
            
            string key = get_key(iter);

            mp[key].push_back(iter);
        }

        for (auto x = mp.begin(); x!= mp.end(); x++)
            values.push_back(x->second);

        return values;

    }
};
