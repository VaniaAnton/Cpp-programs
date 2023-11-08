#include <iostream>
#include <string>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.empty())
            return "";

        int start = 0, maxLen = 1;
        int strLen = s.length();

        for (int i = 0; i < strLen;)
        {
            // Skip duplicates to find the center of a potential palindrome
            int left = i, right = i;
            while (right < strLen - 1 && s[right] == s[right + 1])
            {
                right++;
            }
            // Update the next center
            i = right + 1;
            // Expand around the center
            while (left > 0 && right < strLen - 1 && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
            // Update the longest palindrome if a longer one is found
            if (maxLen < right - left + 1)
            {
                start = left;
                maxLen = right - left + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};