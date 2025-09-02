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