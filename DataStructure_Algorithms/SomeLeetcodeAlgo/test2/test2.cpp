#include <iostream>
#include <string>
#include <vector>
using namespace std;
int xiangcha(string s, string t)
{
    vector<int> redindex,whiteindex;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            if (s[i] == 'W') whiteindex.push_back(i);
            else redindex.push_back(i);
        }
    }
    int res = 0;
    for (int i = 0; i < redindex.size(); i++)
    {
        res += abs(redindex[i] - whiteindex[i]);
    }
    return res;
}
int main()
{
    string test = "WRRRWRRWR";
    int rednum = 0;
    for (int i = 0; i < test.size(); i++)
    {
        if (test[i] == 'R') rednum++;
    }
    string t = "";
    for (int i = 0; i < test.size(); i++)
    {
        t.push_back('W');
    }
    int ans = INT_MAX;
    for (int i = 0; i <= test.size() - rednum; i++)
    {
        for (int j = i; j < i + rednum; j++)
        {
            t[j] = 'R';
        }
        ans = min(ans, xiangcha(test, t));
        for (int j = i; j < i + rednum; j++)
        {
            t[j] = 'W';
        }
    }
    cout << ans;
    std::cout << "Hello World!\n";
}

