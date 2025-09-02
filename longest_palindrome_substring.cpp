/*
 * Bài toán LeetCode: Longest Palindromic Substring (Chuỗi con đối xứng dài nhất)
 *
 * Mô tả bài toán:
 * Cho một chuỗi `s`, trả về chuỗi con đối xứng dài nhất trong `s`.
 *
 * Ví dụ:
 * - Input: s = "babad"
 * - Output: "bab" ("aba" cũng là một đáp án hợp lệ)
 * - Input: s = "cbbd"
 * - Output: "bb"
 *
 * ---
 *
 * Hướng giải quyết: Brute Force (Vét cạn)
 *
 * Giải pháp được cài đặt sử dụng phương pháp vét cạn để tìm chuỗi con đối xứng dài nhất.
 * Logic như sau:
 *
 * 1. Lặp qua tất cả các độ dài chuỗi con có thể:
 *    Vòng lặp bên ngoài bắt đầu với độ dài lớn nhất có thể (độ dài của toàn bộ chuỗi)
 *    và giảm dần xuống 1. Điều này đảm bảo rằng chuỗi đối xứng đầu tiên chúng ta tìm thấy sẽ là chuỗi dài nhất.
 *
 * 2. Lặp qua tất cả các điểm bắt đầu có thể:
 *    Với mỗi độ dài, vòng lặp bên trong lặp qua tất cả các chỉ số bắt đầu có thể cho một chuỗi con
 *    có độ dài đó.
 *
 * 3. Kiểm tra tính đối xứng (Palindrome):
 *    - Đối với mỗi chuỗi con được tạo ra, hàm trợ giúp `isPalindrome` được gọi.
 *    - `isPalindrome` kiểm tra xem một chuỗi có phải là đối xứng hay không bằng cách so sánh các ký tự từ đầu
 *      và cuối, di chuyển vào trung tâm.
 *
 * 4. Trả về kết quả khớp đầu tiên:
 *    - Bởi vì việc tìm kiếm bắt đầu với các chuỗi con dài nhất có thể, chuỗi đối xứng đầu tiên
 *      được tìm thấy được đảm bảo là một trong những chuỗi dài nhất. Hàm ngay lập tức trả về chuỗi con này.
 *
 * Phân tích độ phức tạp:
 * - Độ phức tạp thời gian: O(N^3), trong đó N là độ dài của chuỗi.
 *   - Hai vòng lặp lồng nhau cho độ dài và chỉ số bắt đầu dẫn đến O(N^2) lần lặp.
 *   - Bên trong các vòng lặp, `s.substr()` có thể mất tới O(N) thời gian, và việc kiểm tra `isPalindrome` cũng mất O(N) thời gian.
 *   - Điều này dẫn đến độ phức tạp tổng thể là O(N^2 * N) = O(N^3).
 * - Độ phức tạp không gian: O(N) để lưu trữ chuỗi con `sub`.
 *
 * ---
 *
 * Các giải pháp tối ưu hơn:
 *
 * 1. Quy hoạch động (Dynamic Programming):
 *    - Thời gian: O(N^2), Không gian: O(N^2)
 *    - Xây dựng một bảng 2D `dp[i][j]` lưu trữ xem chuỗi con `s[i..j]` có phải là đối xứng hay không.
 *    - `dp[i][j]` là true nếu `s[i] == s[j]` và `dp[i+1][j-1]` là true.
 *
 * 2. Mở rộng từ trung tâm (Expand Around Center):
 *    - Thời gian: O(N^2), Không gian: O(1)
 *    - Đây là một phương pháp rất phổ biến và hiệu quả. Lặp qua mọi ký tự của chuỗi,
 *      coi nó như một trung tâm tiềm năng của một chuỗi đối xứng.
 *    - Đối với mỗi trung tâm, mở rộng ra bên ngoài (một con trỏ sang trái, một con trỏ sang phải) miễn là
 *      các ký tự khớp nhau.
 *    - Bạn cần xử lý cả hai trường hợp chuỗi đối xứng có độ dài lẻ (trung tâm là một ký tự) và độ dài chẵn
 *      (trung tâm nằm giữa hai ký tự).
 */
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