#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (map.find(s[i]) != map.end())
            {
                start = max(start, map[s[i]] + 1);
            }
            map[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;
    cout << s.lengthOfLongestSubstring(" ") << endl;
    cout << s.lengthOfLongestSubstring("au") << endl;
    return 0;
}