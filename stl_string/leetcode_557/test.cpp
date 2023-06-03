class Solution {
public:
    string reverseWords(string s) {
        int mark = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + mark, s.begin() + i);
                mark = i + 1;
            }
        }
        reverse(s.begin() + mark, s.end());
        return s;
    }
};
