#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, char> roman;
        roman[1] = 'I';
        roman[5] = 'V';
        roman[10] = 'X';
        roman[50] = 'L';
        roman[100] = 'C';
        roman[500] = 'D';
        roman[1000] = 'M';

        string result = "";
        int i = 0;
        while (i < num)
        {
            if (i + 1 < num && roman[i] < roman[i + 1])
            {
                result += roman[i + 1] - roman[i];
                num -= roman[i + 1] - roman[i];
                i += 2;
            }
            else
            {
                result += roman[i];
                num -= roman[i];
                i++;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(3) << endl;
    cout << s.intToRoman(4) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(58) << endl;
    cout << s.intToRoman(1994) << endl;
    return 0;
}