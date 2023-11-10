#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int result = 0;
        int sign = 1;
        int i = 0;
        while (s[i] == ' ')
            i++;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            int pop = s[i] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            result = result * 10 + pop;
            i++;
        }
        return result * sign;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("   -42") << endl;
    cout << s.myAtoi("4193 with words") << endl;
    cout << s.myAtoi("words and 987") << endl;
    cout << s.myAtoi("-91283472332") << endl;
}