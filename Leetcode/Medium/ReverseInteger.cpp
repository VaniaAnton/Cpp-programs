#include <iostream>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
                return 0;
            result = result * 10 + pop;
        }
        return result;
    }
};

int main()
{
    cout << 123 % 10 << endl;
    cout << 123 / 10 << endl;
    Solution s;
    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(120) << endl;
    cout << s.reverse(0) << endl;
    cout << s.reverse(1534236469) << endl;
    return 0;
}