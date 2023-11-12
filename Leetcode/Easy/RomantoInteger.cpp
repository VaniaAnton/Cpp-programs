#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int result = 0;
        int i = 0;
        while (i < s.length())
        {
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]])
            {
                result += roman[s[i + 1]] - roman[s[i]];
                i += 2;
            }
            else
            {
                result += roman[s[i]];
                i++;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("IX") << endl;
    cout << s.romanToInt("LVIII") << endl;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}