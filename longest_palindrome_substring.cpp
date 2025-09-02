#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(string s) {

    if(s.length() < 2) {
        return true;
    }

    int maxIndex = s.length() / 2;
    for(int i = 0; i < maxIndex; i++){
        if(s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }

    return true;
}

string longestPalindrome(string s){
    for (int length = s.size(); length > 0; length--) {
            for (int start = 0; start <= s.size() - length; start++) {
                string sub = s.substr(start, length);
                if (isPalindrome(sub)) {
                    return sub;
                }
            }
        }

    return "";
}

int main(){
    string s = "vnjwvalrbypfcbqnmopltjnoifmzwgvpzqzsdtvawndpjtpmpjbjionjifqtvvocpeaftvhpdgjjfafunfndztdjkcxyihtsyppendfzzjeyxlbwpdygiqmdqcdbmgyjigrmfkswcwryaydjilqqxvcnyvviesuncslvzikawwqykqwdfibggezufqihcjkebapmgkvwixywgdextafxycnipjglsndkyjoqfyfljfkkvoieksmavdlmlhhnstesibffiopqvlyuidvrawndbzonwzbsjmpeqoglmdbinkovqpzfkxihzitdopnomseqhmrrkcsvrzziphwpuhjngeotwcrebcmbtirkgeavojtmpakcewmexhxacngknokxsvtqobdgckutpexswgwqzbosjpxauyflnylfcxsucsehqvakbpvfmkelmkspsqxnutwfwacpqqvovdqafeylobneojdsgqowcbxfsvuqusdbylcgcvgrofgvzubakjmlbffjhrafvnqttwuyhokzpmhlludpbowuxzrebxsdusalljfjgjkucwzpmndqncykvfnbrxcrcaxwisjpstejjqbpwegpxyrtyafxklgralnkwxkmjpuqfixzkonznmguyizlancpxdzcfkgiotyelegprbaytdhbutbuihkxnbtuqrtezaskfqsmrznfohhlqp";
    cout << "Longest palindrome: " << longestPalindrome(s) << endl;
}