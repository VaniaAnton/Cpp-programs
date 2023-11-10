#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
        {
            return true;
        }
        int result = 0;
        int temp = x;
        while (temp != 0)
        {
            int pop = temp % 10;
            temp /= 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return false;
            result = result * 10 + pop;
        }
        return result == x;
    }
};

int main()
{
    Solution s;
    cout << INT_MAX / 10 << endl;
    cout << INT_MIN / 10 << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(10) << endl;
    cout << s.isPalindrome(-101) << endl;
    cout << s.isPalindrome(0) << endl;
}