#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string answer;
        for (string row : rows)
            answer += row;
        return answer;
    }
};

int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}