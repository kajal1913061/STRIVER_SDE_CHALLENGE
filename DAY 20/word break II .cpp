/*
#include <unordered_set>
using namespace std;

void wordBreakHelper(string &s, int idx, unordered_set<string> &dictSet, int size,vector<vector<string>>& ans,vector<string>& Part)
{
    // Base Condition
    if (idx == size)
    {
        ans.push_back(Part);
        return;
    }
    string word = "";
    for (int j = idx; j < size; j++)
    {

        word.push_back(s[j]);
        if (dictSet.count(word) != 0)
        {
            Part.push_back(word);
            wordBreakHelper(s, j + 1, dictSet, size,ans,Part);
            Part.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> Part;
    unordered_set<string> dictSet;
    vector<vector<string>> ans;
    for (int i = 0; i < dictionary.size(); i++)
    {
        dictSet.insert(dictionary[i]);
    }
      wordBreakHelper(s, 0, dictSet, s.size(),ans,Part);
    vector<string> real_ans;
    for(int i=0;i<ans.size();i++){
        string temp="";
        for(int j=0;j<ans[i].size();j++){
            if(j==ans[i].size()){
                temp+=ans[i][j];
                continue;
            }
            temp+=ans[i][j]+" ";
        }
        real_ans.push_back(temp);
    }
    return real_ans;
}*/
    void words(string &s, int start, vector<string> &dictionary, vector<string> &ans, string &curr) {
    // We've reached end of string
    if(start >= s.size()) {
        ans.push_back(curr);
        return;
    }
    
    for(int i=start; i<s.size(); ++i) {
        string tmp = s.substr(start, i-start+1);
        
        // Check if this word is present in dictionary
        bool isPresent = false;
        for(string st : dictionary) {
            if(st.compare(tmp) == 0) {
                isPresent = true;
                break;
            }
        }
        
        // If this word is present in dictionary
        // then try the remaining string
        if(isPresent) {
            string x = curr;
            // Push this to current ans
            curr += tmp + " ";
            
            words(s, i+1, dictionary, ans, curr);
            
            // Backtracking
            curr = x;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string curr;
    
    words(s, 0, dictionary, ans, curr);
    
    return ans;
}
