// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string,int>>q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(q.empty() == false){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;
            
            // trying to replace each character of word one by one and then find in set
            for(int i = 0; i < word.size(); i++){

                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    // check is above modified word lies in wordList
                    if(st.find(word) != st.end()){
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
