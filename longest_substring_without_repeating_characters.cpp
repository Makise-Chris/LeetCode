/*
 * Bài toán LeetCode: Longest Substring Without Repeating Characters (Chuỗi con dài nhất không có ký tự lặp lại)
 *
 * Mô tả bài toán:
 * Cho một chuỗi `s`, tìm độ dài của chuỗi con dài nhất không có ký tự lặp lại.
 *
 * Ví dụ:
 * - Input: s = "abcabcbb"
 * - Output: 3 (Đáp án là "abc")
 *
 * ---
 *
 * Hướng giải quyết phổ biến: Cửa sổ trượt (Sliding Window) với Hash Map
 *
 * Đây là phương pháp tối ưu và phổ biến nhất cho bài toán này.
 *
 * 1. Khởi tạo:
 *    - `maxLength`: Lưu trữ độ dài lớn nhất tìm được, khởi tạo bằng 0.
 *    - `start`: Chỉ số bắt đầu của cửa sổ hiện tại, khởi tạo bằng 0.
 *    - `charIndexMap`: Một hash map (hoặc một mảng kích thước 256 cho bộ ký tự ASCII) để lưu chỉ số xuất hiện cuối cùng của mỗi ký tự.
 *
 * 2. Vòng lặp cửa sổ trượt:
 *    - Chúng ta duyệt qua chuỗi bằng một con trỏ `end` từ 0 đến cuối chuỗi.
 *    - Với mỗi ký tự `s[end]`:
 *      - Kiểm tra xem ký tự đã có trong `charIndexMap` và chỉ số cuối cùng của nó có nằm trong cửa sổ hiện tại không (tức là `charIndexMap[s[end]] >= start`).
 *      - Nếu có, điều đó có nghĩa là chúng ta có một ký tự lặp lại. Chúng ta cần thu hẹp cửa sổ bằng cách di chuyển con trỏ `start` đến vị trí ngay sau lần xuất hiện cuối cùng của ký tự hiện tại (`charIndexMap[s[end]] + 1`).
 *      - Cập nhật chỉ số xuất hiện cuối cùng của ký tự `s[end]` trong `charIndexMap` thành chỉ số hiện tại `end`.
 *      - Tính độ dài của cửa sổ hiện tại (`end - start + 1`) và cập nhật `maxLength` nếu cửa sổ hiện tại lớn hơn.
 *
 * 3. Trả về kết quả:
 *    - Sau vòng lặp, `maxLength` sẽ giữ độ dài của chuỗi con dài nhất không có ký tự lặp lại.
 *
 * Phân tích độ phức tạp (Cửa sổ trượt):
 * - Độ phức tạp thời gian: O(N), trong đó N là độ dài của chuỗi. Chúng ta chỉ duyệt qua chuỗi một lần.
 * - Độ phức tạp không gian: O(min(N, M)), trong đó N là độ dài của chuỗi và M là kích thước của bộ ký tự. Trong trường hợp xấu nhất, chúng ta lưu trữ tất cả các ký tự duy nhất trong hash map. Đối với ASCII, độ phức tạp này là O(1) vì kích thước được cố định là 256.
 *
 * ---
 *
 * Ghi chú về giải pháp Quy hoạch động (DP) đã cài đặt:
 * Giải pháp được cung cấp sử dụng phương pháp quy hoạch động. Mặc dù sáng tạo, nó phức tạp và kém hiệu quả hơn kỹ thuật cửa sổ trượt. Trạng thái DP `dp[i]` dường như cố gắng ghi lại độ dài của chuỗi con dài nhất kết thúc tại chỉ số `i`. Logic này bao gồm việc tìm kiếm chỉ số lặp lại cuối cùng trong chuỗi con ứng cử viên trước đó, điều này có thể tốn nhiều tài nguyên tính toán. Phương pháp cửa sổ trượt tránh được các tìm kiếm lặp lại này bằng cách theo dõi vị trí ký tự một cách hiệu quả.
 */
#include <bits/stdc++.h>

using namespace std;

int lastRepeatedIndex(string s, char c)
{
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

int lengthOfLongestSubstring(string s)
{
    int length = s.length();
    if (length == 0)
    {
        return 0;
    }
    if (length == 1)
    {
        return 1;
    }
    int dp[100000];

    dp[0] = 1;
    if (s[1] == s[0])
    {
        dp[1] = 1;
    }
    else
    {
        dp[1] = 2;
    }

    for (int i = 2; i < length; i++)
    {
        string curCandidate = s.substr((i - 1) - dp[i - 1] + 1, dp[i - 1]);
        int lastIndex = lastRepeatedIndex(curCandidate, s[i]);
        dp[i] = dp[i - 1] - lastIndex;
    }

    int result = 0;
    for (int i = 0; i < length; i++)
    {
        cout << "dp[" << i << "] = " << dp[i] << endl;
        if (dp[i] > result)
            result = dp[i];
    }
    return result;
}

int main()
{
    string s = "dvdf";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}