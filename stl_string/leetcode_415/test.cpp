#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        int next = 0;   //½øÎ»
        string strRet;

        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;

            int ret = val1 + val2 + next;
            /*
            if(ret > 9)
            {
                ret -= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }
            */
            next = ret / 10;
            ret = ret % 10;
            //strRet.insert(0, 1, '0' + ret);
            strRet += ('0' + ret);
            --end1;
            --end2;
        }
        if (next == 1)
        {
            //strRet.insert(0, 1, '1');
            strRet += '1';
        }

        reverse(strRet.begin(), strRet.end());

        return strRet;
    }
};