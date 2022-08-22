# include <iostream>
# include <string>
using namespace std;
#include <vector>
#include <stack>
#include <unordered_map>
int lengthOfLongestSubstring(string s) {
    int ptr1 = 0, ptr2 = 0;
    int curnum = 0, maxnum = 0;
    if (s.size() == 0) return maxnum;
    int i = 0;
    while (i < s.size())
    {
        unordered_map<char, int> mp;
        mp.insert(make_pair(s[i], i));
        int j = i + 1;
        while (j < s.size())
        {
            if (mp.find(s[j]) != mp.end()) {
                maxnum = max(maxnum, j - i);
                i = mp[s[j]] + 1;
                break;
            }
            else mp.insert(make_pair(s[j], j));
            j++;
        }
        if (j == s.size()) maxnum = max(maxnum, j - i);
    }
    return maxnum;
}
void main()
{
    lengthOfLongestSubstring("abcabcbb");
    return;
}