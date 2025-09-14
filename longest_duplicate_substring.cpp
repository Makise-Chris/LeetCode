#include <bits/stdc++.h>

using namespace std;

string longestDupSubstring(string s)
{
    map<string, int> subStringToCountMap;
    for (int length = 1; length <= s.length(); length++)
    {
        for (int i = 0; i + length - 1 < s.length(); i++)
        {
            string subString = s.substr(i, length);
            subStringToCountMap[subString]++;
            if(subStringToCountMap[subString] > 1)
            {
                break;
            }
        }
    }

    string result = "";

    for (auto &p : subStringToCountMap)
    {
        cout << "subString: " << p.first << ", count: " << p.second << endl;
        if (p.second > 1 && p.first.length() > result.length())
        {
            result = p.first;
        }
    }
    return result;
}

int main()
{
    string s = "fmjyojhkkpubinlwpnzvpmglqsvspbfpkkpynumeshybzjadrgnkidjpcmfqtngosdikbhttrajxtmijncwmebbkopsryslivutfwfwcesivtfdhfiteckyuyfgovazckvzylutksnrpmxicbbnxzwdnxfvuixvtlmzetincjxlyoixyfnzrcfnjnozhyalzyncvkuyachyufrtjcpgjemnkfzzwxcbnydaxhjcgtcskjvhwnfdpvfyoqxjhltoqrvzxhtzvmqnyzxzjacaxpspybthhhqgtxitxcfjohwqkcsryhjdazmzupjxeyfqpyffmgyyobwnvvpiyblcidsntqvwiosqtoerkasdxhtuabaybyfpibiboyhinvirrncvjgujhvtedbpfxziwkdvocxhsehcbxnhedhxckqsjlluzkfrmqgceyztxgiwtaokensgumrrkdlmuknpusaiqwjketvxtedjaxrzoaxllofzjuhxsjwuwsbdopidlonofbbswouekysldblsxftlqmleevbemwivikonyieqdwijpslehpwoxjqjjjfpomjprlyxebksrwuqanvixwnpbulnmxmfkixxqpcscirlbznedmxilkgigducxfajeqtrcrrlztrvqrbwudiaeptxisqbleoeavzydlgkfcrmkcnkbtplrvsbvhureajf";
    string result = longestDupSubstring(s);
    cout << "longestDupSubstring: " << result << endl;
}