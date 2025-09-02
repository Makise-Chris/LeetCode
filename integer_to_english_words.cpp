/*
 * Bài toán LeetCode: Integer to English Words (Chuyển số nguyên thành chữ tiếng Anh)
 *
 * Mô tả bài toán:
 * Chuyển một số nguyên không âm `num` thành dạng chữ tiếng Anh của nó.
 * Dữ liệu đầu vào được đảm bảo nhỏ hơn 2^31 - 1.
 *
 * Ví dụ:
 * - Input: num = 123
 * - Output: "One Hundred Twenty Three"
 * - Input: num = 12345
 * - Output: "Twelve Thousand Three Hundred Forty Five"
 *
 * ---
 *
 * Hướng giải quyết:
 * Ý tưởng cốt lõi là chia số thành các nhóm ba chữ số (0-999)
 * và chuyển đổi mỗi nhóm thành dạng chữ tiếng Anh. Sau đó, chúng ta nối thêm
 * các đơn vị tương ứng ("Thousand", "Million", "Billion") vào mỗi nhóm.
 *
 * 1. Hàm trợ giúp `hundredNumberToWord(int num)`:
 *    - Hàm này là nền tảng của giải pháp. Nó nhận một số từ 0 đến 999
 *      và chuyển đổi nó thành chữ.
 *    - Đầu tiên, nó trích xuất chữ số hàng trăm và, nếu khác không, nối thêm "Hundred".
 *    - Sau đó, nó xử lý số có hai chữ số còn lại (0-99).
 *      - Nếu chữ số hàng chục từ 2 trở lên (20-99), nó sẽ nối thêm "Twenty", "Thirty", v.v.,
 *        theo sau là chữ của chữ số hàng đơn vị nếu nó khác không.
 *      - Nếu chữ số hàng chục là 1 (10-19), nó xử lý các trường hợp đặc biệt "teen" ("Ten", "Eleven", "Twelve", v.v.).
 *      - Nếu chữ số hàng chục là 0, nó chỉ cần nối thêm chữ của chữ số hàng đơn vị.
 *
 * 2. Hàm chính `numberToWords(int num)`:
 *    - Xử lý trường hợp cơ bản khi `num` là 0, trả về "Zero".
 *    - Nó xử lý số đầu vào từ trái sang phải (từ đơn vị lớn nhất đến nhỏ nhất).
 *    - Nó trích xuất phần tỷ (`num / 1000000000`), phần triệu, phần nghìn,
 *      và phần trăm còn lại.
 *    - Đối với mỗi phần lớn hơn không, nó gọi `hundredNumberToWord` để lấy
 *      dạng chữ tiếng Anh của nhóm 3 chữ số đó.
 *    - Sau đó, nó nối thêm đơn vị đúng ("Billion ", "Million ", "Thousand ") vào chuỗi kết quả.
 *    - Cuối cùng, nó xử lý phần trăm cuối cùng.
 *
 * 3. Định dạng cuối cùng:
 *    - Quá trình này tự nhiên thêm một khoảng trắng ở cuối mỗi từ hoặc đơn vị. Bước cuối cùng
 *      là loại bỏ khoảng trắng thừa này trước khi trả về kết quả.
 *
 * Phân tích độ phức tạp:
 * - Độ phức tạp thời gian: O(1). Số đầu vào bị giới hạn bởi phạm vi của `int` (khoảng 2 * 10^9),
 *   có nghĩa là số chữ số tối đa là 10. Do đó, số bước xử lý là
 *   hằng số bất kể độ lớn của số đầu vào.
 * - Độ phức tạp không gian: O(1). Không gian được sử dụng để lưu trữ chuỗi kết quả cũng bị giới hạn bởi
 *   một hằng số, vì số lượng từ trong đầu ra là có hạn.
 */
#include <bits/stdc++.h>

using namespace std;

string digitToWord(int num)
{
    if (num == 1)
    {
        return "One ";
    }
    else if (num == 2)
    {
        return "Two ";
    }
    else if (num == 3)
    {
        return "Three ";
    }
    else if (num == 4)
    {
        return "Four ";
    }
    else if (num == 5)
    {
        return "Five ";
    }
    else if (num == 6)
    {
        return "Six ";
    }
    else if (num == 7)
    {
        return "Seven ";
    }
    else if (num == 8)
    {
        return "Eight ";
    }
    else if (num == 9)
    {
        return "Nine ";
    }
    return "Zero ";
}

string hundredNumberToWord(int num)
{
    int hundred = num / 1e2;
    int tyPart = num - hundred * 1e2;
    int ty = tyPart / 10;
    int digit = tyPart - ty * 10;

    string result = "";
    if (hundred > 0)
    {
        result += digitToWord(hundred) + "Hundred ";
    }
    if (ty > 1)
    {
        switch (ty)
        {
        case 2:
            result += "Twenty ";
            break;
        case 3:
            result += "Thirty ";
            break;
        case 4:
            result += "Forty ";
            break;
        case 5:
            result += "Fifty ";
            break;
        case 6:
            result += "Sixty ";
            break;
        case 7:
            result += "Seventy ";
            break;
        case 8:
            result += "Eighty ";
            break;
        case 9:
            result += "Ninety ";
            break;
        }
        if (digit > 0)
        {
            result += digitToWord(digit);
        }
    }
    else if (ty == 1)
    {
        switch (digit)
        {
        case 0:
            result += "Ten ";
            break;
        case 1:
            result += "Eleven ";
            break;
        case 2:
            result += "Twelve ";
            break;
        case 3:
            result += "Thirteen ";
            break;
        case 4:
            result += "Fourteen ";
            break;
        case 5:
            result += "Fifteen ";
            break;
        case 6:
            result += "Sixteen ";
            break;
        case 7:
            result += "Seventeen ";
            break;
        case 8:
            result += "Eighteen ";
            break;
        case 9:
            result += "Nineteen ";
            break;
        }
    }
    else if (digit > 0)
    {
        result += digitToWord(digit);
    }
    return result;
}

string numberToWords(int num)
{
    if (num == 0)
    {
        return "Zero";
    }

    int billion = num / 1e9;
    cout << "billion: " << billion << endl;
    int millionPart = num - billion * 1e9;
    int million = millionPart / 1e6;
    cout << "million: " << million << endl;
    int thousandPart = millionPart - million * 1e6;
    int thousand = thousandPart / 1e3;
    cout << "thousand: " << thousand << endl;
    int hundredPart = thousandPart - thousand * 1e3;
    string result = "";
    if (billion > 0)
    {
        result += hundredNumberToWord(billion) + "Billion ";
    }
    if (million > 0)
    {
        result += hundredNumberToWord(million) + "Million ";
    }
    if (thousand > 0)
    {
        result += hundredNumberToWord(thousand) + "Thousand ";
    }
    if (hundredPart > 0)
    {
        result += hundredNumberToWord(hundredPart);
    }
    return result.substr(0, result.size() - 1);
}

int main()
{
    int num = 1234567;
    string result = numberToWords(num);
    cout << "Number in words: " << result << endl;
}