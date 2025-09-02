/*
 * Bài toán LeetCode: Longest Palindromic Substring (Chuỗi con đối xứng dài nhất - Quy hoạch động)
 *
 * Mô tả bài toán:
 * Cho một chuỗi `s`, trả về chuỗi con đối xứng dài nhất trong `s`.
 *
 * ---
 *
 * Hướng giải quyết: Quy hoạch động (Dynamic Programming)
 *
 * Ý tưởng cốt lõi là xây dựng một bảng boolean 2D `dp[i][j]`, trong đó `dp[i][j]` là true
 * nếu chuỗi con từ chỉ số `i` đến `j` (bao gồm cả hai) là một chuỗi đối xứng, và false nếu ngược lại.
 *
 * 1. Định nghĩa trạng thái DP:
 *    - `dp[i][j]`: Một giá trị boolean cho biết `s.substr(i, j-i+1)` có phải là chuỗi đối xứng hay không.
 *
 * 2. Công thức truy hồi DP:
 *    - Một chuỗi con `s[i..j]` là một chuỗi đối xứng nếu:
 *      a) Các ký tự ở hai đầu giống nhau (`s[i] == s[j]`).
 *      b) Chuỗi con bên trong `s[i+1..j-1]` cũng là một chuỗi đối xứng (`dp[i+1][j-1] == true`).
 *
 * 3. Các trường hợp cơ sở:
 *    - Tất cả các chuỗi con có độ dài 1 đều là chuỗi đối xứng (`dp[i][i] = true`).
 *    - Đối với các chuỗi con có độ dài 2, `dp[i][i+1]` là true nếu `s[i] == s[i+1]`.
 *
 * 4. Điền vào bảng DP:
 *    - Chúng ta có thể điền vào bảng bằng cách lặp qua các độ dài chuỗi con, từ 1 đến
 *      độ dài của chuỗi `n`.
 *    - Với mỗi độ dài `len`, chúng ta lặp qua tất cả các chỉ số bắt đầu có thể `i`. Chỉ số
 *      kết thúc `j` sau đó là `i + len - 1`.
 *    - Chúng ta áp dụng công thức truy hồi để điền vào `dp[i][j]`.
 *
 * 5. Tìm chuỗi đối xứng dài nhất:
 *    - Trong khi điền vào bảng, chúng ta theo dõi chỉ số bắt đầu và độ dài lớn nhất
 *      của chuỗi đối xứng tìm thấy cho đến nay.
 *    - Bất cứ khi nào chúng ta đặt `dp[i][j]` thành true, chúng ta kiểm tra xem độ dài hiện tại (`j - i + 1`)
 *      có lớn hơn độ dài tối đa đã thấy không. Nếu có, chúng ta cập nhật độ dài tối đa và
 *      lưu trữ chỉ số bắt đầu `i`.
 *
 * 6. Trả về kết quả:
 *    - Sau khi bảng được điền đầy, chúng ta có thể xây dựng chuỗi con đối xứng dài nhất
 *      bằng cách sử dụng chỉ số bắt đầu và độ dài tối đa đã lưu.
 *
 * Phân tích độ phức tạp:
 * - Độ phức tạp thời gian: O(N^2), trong đó N là độ dài của chuỗi. Chúng ta cần điền vào
 *   bảng DP N x N, mất O(N^2) thời gian.
 * - Độ phức tạp không gian: O(N^2) để lưu trữ bảng DP.
 *
 * ---
 *
 * Ghi chú về giải pháp đã cài đặt:
 * Giải pháp được cung cấp sử dụng đúng bảng DP. Nó khởi tạo bảng với các trường hợp cơ sở
 * (độ dài 1, 2, 3) và sau đó sử dụng một tập hợp vòng lặp thứ hai để điền vào phần còn lại của bảng dựa trên
 * công thức truy hồi `dp[i][j] = dp[i+1][j-1]`. Mặc dù cách này hoạt động, phương pháp tiêu chuẩn
 * lặp theo độ dài chuỗi con thường dẫn đến một cách cài đặt sạch sẽ và ngắn gọn hơn.
 */
#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s)
{
    int size = s.length();

    if (size < 2)
    {
        return s;
    }

    if (size == 2)
    {
        if (s[0] == s[1])
        {
            return s;
        }
        return s.substr(0, 1);
    }

    int dp[1000][1000];
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (j == i + 1 && s[i] == s[j])
            {
                dp[i][j] = 1;
            }
            else if (j == i + 2 && s[i] == s[j])
            {
                dp[i][j] = 1;
            }
            else if (s[i] != s[j])
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = -1;
            }
        }
    }

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - j; i++)
        {
            if (dp[i][i + j] > -1)
            {
                continue;
            }
            dp[i][i + j] = dp[i + 1][i + j - 1];
        }
    }

    int maxLength = 0;
    string result;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (dp[i][j] == 1 && j - i + 1 > maxLength)
            {
                maxLength = j - i + 1;
                result = s.substr(i, maxLength);
            }
        }
    }
    return result;
}

int main()
{
    string s = "xaabacxcabaaxcabaax";
    string result = longestPalindrome(s);
    cout << "Longest palindrome: " << result << endl;
}