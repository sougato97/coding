// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t){
            return true;
        }
        return false;
    }
};


// using map 
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        
        if (s.size()!=t.size()){
            return false;
        }

        for (auto i: s){
            // element exists 
            if (mp.find(i) != mp.end()){
                mp[i]++;
            }
            // doesnt exit
            else
            {
                mp[i] = 1;
            }
        }

        for (auto i: t){
            // element present
            if (mp.find(i) != mp.end()){
                mp[i]--;
                
            }
            // unequal occurance
            // if(mp[i] < 0){
            //     return false;
            // }
            // new char
            else{
                return false;
            }
            for (auto j: mp)
            {
                cout<< j.first <<" - "<< j.second<<" ";
            }
            cout<<endl;
        }
        for (auto j: mp)
        {
            if (j.second != 0){
                return false;
            }
        }        
        return true;
        }
};


// using map (optimized)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        
        if (s.size()!=t.size()){
            return false;
        }

        for (auto i: s){
            // element exists 
            if (mp.find(i) != mp.end()){
                mp[i]++;
            }
            // doesnt exit
            else
            {
                mp[i] = 1;
            }
        }

        for (auto i: t){
            // element present
            if (mp.find(i) != mp.end()){
                mp[i]--;
            }
            // new char
            else{
                return false;
            }

            // unequal occurance
            if(mp[i] < 0){
                return false;
            }

        }     
        return true;
    }
};

racecar
creracc