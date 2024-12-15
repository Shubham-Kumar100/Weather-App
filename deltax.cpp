#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Map to store Roman numerals and their corresponding values
unordered_map<char, int> roman_numerals = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

// Function to convert integer back to Roman numeral (for validation)
string intToRoman(int num)
{
    string result = "";
    pair<int, string> value_map[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    for (const auto &[value, numeral] : value_map)
    {
        while (num >= value)
        {
            result += numeral;
            num -= value;
        }
    }
    return result;
}

// Function to check if the given string is a valid Roman numeral and return its integer value
string isValidRoman(const string &roman)
{
    // Check if all characters are valid Roman numerals
    for (char c : roman)
    {
        if (roman_numerals.find(c) == roman_numerals.end())
        {
            return "Invalid";
        }
    }

    // Convert the Roman numeral to its integer equivalent
    int total_value = 0;
    int prev_value = 0;

    for (int i = roman.size() - 1; i >= 0; --i)
    {
        int value = roman_numerals[roman[i]];
        if (value >= prev_value)
        {
            total_value += value;
        }
        else
        {
            total_value -= value;
        }
        prev_value = value;
    }

    // Check if the reconstructed Roman numeral matches the original
    if (intToRoman(total_value) != roman)
    {
        return "Invalid";
    }

    return to_string(total_value);
}

// Main function to test the code
int main()
{
    string test_cases[] = {"XIV", "IIII", "MCMXCIV", "ABC", "MMXXIV"};

    for (const string &test : test_cases)
    {
        cout << test << ": " << isValidRoman(test) << endl;
    }

    return 0;
}
