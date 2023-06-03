class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                s1 += tolower(ch);
            }
        }
        string s1_rev(s1.rbegin(), s1.rend());
        return s1 == s1_rev;
    }
};