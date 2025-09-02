/*
 * Bài toán LeetCode: Compare Version Numbers (So sánh số phiên bản)
 *
 * Mô tả bài toán:
 * Cho hai chuỗi số phiên bản, version1 và version2, hãy so sánh chúng.
 * Số phiên bản bao gồm một hoặc nhiều bản sửa đổi (revision) được nối với nhau bằng dấu chấm '.'.
 * Mỗi bản sửa đổi bao gồm một hoặc nhiều chữ số và có thể có số 0 ở đầu.
 * Ví dụ, 2.5.33 và 0.1 là các số phiên bản hợp lệ.
 * Để so sánh các số phiên bản, hãy so sánh các bản sửa đổi của chúng theo thứ tự từ trái sang phải.
 * Các bản sửa đổi được so sánh bằng giá trị số nguyên của chúng, bỏ qua mọi số 0 ở đầu.
 * Nếu một số phiên bản không chỉ định một bản sửa đổi tại một chỉ mục nào đó, hãy coi bản sửa đổi đó là 0.
 * Ví dụ, phiên bản 1.0 nhỏ hơn phiên bản 1.1 vì bản sửa đổi đầu tiên của chúng giống nhau,
 * nhưng bản sửa đổi thứ hai 0 nhỏ hơn 1.
 *
 * Giá trị trả về:
 * - -1 nếu version1 < version2
 * - 1 nếu version1 > version2
 * - 0 nếu version1 == version2
 *
 * Hướng giải quyết:
 * 1. Phân tích chuỗi phiên bản:
 *    Hàm `toRevisions` tách mỗi chuỗi phiên bản theo dấu chấm '.'.
 *    Nó chuyển đổi mỗi chuỗi con của bản sửa đổi thành một số nguyên và lưu chúng vào một vector.
 *    Ví dụ, "1.10.0" trở thành vector {1, 10, 0}.
 *
 * 2. So sánh các bản sửa đổi:
 *    Hàm `compareVersion` nhận hai vector chứa các bản sửa đổi.
 *    Nó lặp từ bản sửa đổi đầu tiên đến bản sửa đổi cuối cùng của chuỗi phiên bản dài hơn.
 *    Với mỗi chỉ mục `i`, nó lấy ra các số sửa đổi `rev1` từ vector thứ nhất và `rev2` từ vector thứ hai.
 *    Nếu một chỉ mục nằm ngoài giới hạn của một trong hai vector, bản sửa đổi của nó được coi là 0. Điều này xử lý các trường hợp chuỗi phiên bản có số lượng bản sửa đổi khác nhau (ví dụ: "1.0" so với "1.0.0").
 *    Sau đó, nó so sánh `rev1` và `rev2`.
 *    - Nếu `rev1` nhỏ hơn `rev2`, `version1` nhỏ hơn, trả về -1.
 *    - Nếu `rev1` lớn hơn `rev2`, `version1` lớn hơn, trả về 1.
 *    - Nếu chúng bằng nhau, tiếp tục với bản sửa đổi tiếp theo.
 *
 * 3. Xử lý trường hợp bằng nhau:
 *    Nếu vòng lặp kết thúc mà không trả về giá trị nào, điều đó có nghĩa là tất cả các bản sửa đổi tương ứng đều bằng nhau.
 *    Trong trường hợp này, các phiên bản bằng nhau, và chúng ta trả về 0.
 *
 * Phân tích độ phức tạp:
 * - Độ phức tạp thời gian: O(N + M), trong đó N là độ dài của version1 và M là độ dài của version2.
 *   - Việc phân tích chuỗi mất O(N + M).
 *   - Vòng lặp so sánh chạy max(L1, L2) lần, trong đó L1 và L2 là số lượng bản sửa đổi.
 * - Độ phức tạp không gian: O(N + M) để lưu trữ các vector bản sửa đổi.
 */
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