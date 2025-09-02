// Solution by Nam Nguyen
#include <bits/stdc++.h>

using namespace std;

int toNumber(char c)
{
    if (c == '\0')
        return 0;
    return c - '0';
}

vector<int> toRevisions(string version)
{
    vector<int> revisions;
    int length = version.length();
    int curRevision = 0;
    for (int i = 0; i < length; i++)
    {
        if (version[i] == '.')
        {
            revisions.push_back(curRevision);
            curRevision = 0;
        }
        else
        {
            curRevision = curRevision * 10 + toNumber(version[i]);
        }
    }
    revisions.push_back(curRevision);
    return revisions;
}

void printRevisions(vector<int> revisions)
{
    for (int i = 0; i < revisions.size(); i++)
    {
        cout << revisions[i] << " ";
    }
    cout << endl;
}

int compareVersion(string version1, string version2)
{
    vector<int> revisions1 = toRevisions(version1);
    vector<int> revisions2 = toRevisions(version2);
    printRevisions(revisions1);
    printRevisions(revisions2);
    int length1 = revisions1.size();
    int length2 = revisions2.size();
    int length = max(length1, length2);
    for (int i = 0; i < length; i++)
    {
        int rev1 = (i < length1) ? revisions1[i] : 0;
        int rev2 = (i < length2) ? revisions2[i] : 0;
        cout << "Comparing " << rev1 << " and " << rev2 << endl;
        if (rev1 < rev2)
            return -1;
        if (rev1 > rev2)
            return 1;
    }
    return 0;
}

int main()
{
    string version1 = "1.0";
    string version2 = "1.0.0.0";
    cout << compareVersion(version1, version2) << endl;
    return 0;
}