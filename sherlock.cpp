#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool checkPermutation(string s1, string s2)
{
    unordered_map<char, int> exist;
    for(int i=0; i<s2.size();i++)
    {
        if(exist.count(s2[i]) > 0)
        {
            exist[s2[i]]++;
        }
        else
        {
            exist[s2[i]] = 1;
        }
    }

    for(int i=0; i<s1.size();i++)
    {
        if(exist[s1[i]] == 0)
        {
            return false;
        }
        else
        {
            exist[s1[i]]--;
        }
    }

    return true;

}

int main()
{
    int t;
    cin >> t;
    vector<string> output;
    while(t > 0)
    {
        string s1, s2;
        cin >> s1 >> s2;

        bool ans = checkPermutation(s1, s2);
        if(ans)
        {
            output.push_back("YES");
        }
        else{
            output.push_back("NO");
        }

        t--;
    }

    for(int i=0; i<output.size();i++)
    {
        cout << output[i] << endl;
    }
}
