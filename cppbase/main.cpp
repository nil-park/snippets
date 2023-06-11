/*
 * This program solves https://leetcode.com/problems/count-of-integers
 */

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

class Solution {
private:
    // int recursionDepth = 0;
public:
    // all digits can be zero to nine
    int count(int digits, int min_sum, int max_sum, int d) {
        // if (d > recursionDepth)
        //     recursionDepth = d;
        if (max_sum < 0)
            return 0; // no remaining number to sum.
        if (max_sum == 0)
            return 1; // 0000 if digits == 4 for example.
        if (digits == 1) { // terminator of the recursion
            int s = max(min_sum, 0);
            int e = min(max_sum, 9);
            return e - s + 1;
        }
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += count(digits - 1, min_sum - i, max_sum - i, d + 1);
            if (sum >= MOD) {
                cerr << "NB - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
                sum %= MOD;
            }
        }
        return sum;
    }

    int countLB(int digits, int min_sum, int max_sum, vector<int>& n1, int d) {
        // if (d > recursionDepth)
        //     recursionDepth = d;
        if (max_sum < 0)
            return 0; // no remaining numbers to sum
        int s = n1[digits - 1];
        int e = min(max_sum, 9);
        // cerr << digits << " " << s << " " << e << " " << min_sum << " " << max_sum << endl;
        if (digits == 1) {
            s = max(s, min_sum);
            return e - s + 1;
        }
        int sum = countLB(digits - 1, min_sum - s, max_sum - s, n1, d + 1);
        if (sum >= MOD) {
            cerr << "LB1 - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
            sum %= MOD;
        }
        for (int i = s + 1; i < 10; i++) {
            sum += count(digits - 1, min_sum - i, max_sum - i, d + 1);
            if (sum >= MOD) {
                cerr << "LB2 - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
                sum %= MOD;
            }
        }
        return sum;
    }

    int countUB(int digits, int min_sum, int max_sum, vector<int>& n2, int d) {
        // if (d > recursionDepth)
        //     recursionDepth = d;
        if (max_sum < 0)
            return 0; // no remaining numbers to sum
        int s = 0;
        int e = min(max_sum, n2[digits - 1]);
        // cerr << digits << " " << s << " " << e << " " << min_sum << " " << max_sum << endl;
        if (digits == 1) {
            return e - s + 1;
        }
        int sum = 0;
        for (int i = 0; i < e; i++) {
            sum += count(digits - 1, min_sum - i, max_sum - i, d + 1);
            if (sum >= MOD) {
                cerr << "UB1 - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
                sum %= MOD;
            }
        }
        sum += countUB(digits - 1, min_sum - e, max_sum - e, n2, d + 1);
        if (sum >= MOD) {
            cerr << "UB2 - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
            sum %= MOD;
        }
        return sum;
    }

    // upper and lower bound
    int count(int digits, int min_sum, int max_sum, vector<int>& n1, vector<int>& n2, int d) {
        // if (d > recursionDepth)
        //     recursionDepth = d;
        if (max_sum < 0)
            return 0; // no remaining numbers to sum
        int s = n1[digits - 1]; // lower bound of the most significant digit.
        int e = min(max_sum, n2[digits - 1]); // upper bound of the most significant digit.
        // cerr << digits << " " << s << " " << e << " " << min_sum << " " << max_sum << endl;
        if (digits == 1) { // terminator of the recursion
            s = max(s, min_sum);
            return e - s + 1;
        }
        if (s == e) { // you don't need to take care of the most significant digit.
            return count(digits - 1, min_sum - s, max_sum - s, d + 1);
        }
        int sum = countLB(digits - 1, min_sum - s, max_sum - s, n1, d + 1);
        if (sum >= MOD) {
            cerr << "BB1 - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
            sum %= MOD;
        }
        for (int i = s + 1; i < e; i++) {
            sum += count(digits - 1, min_sum - i, max_sum - i, d + 1);
            if (sum >= MOD) {
                cerr << "BB2 - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
                sum %= MOD;
            }
        }
        sum += countUB(digits - 1, min_sum - e, max_sum - e, n2, d + 1);
        if (sum >= MOD) {
            cerr << "BB3 - BIG NUMBER!! " << sum << " " << sum % MOD << endl;
            sum %= MOD;
        }
        return sum;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        int digits = max(num1.size(), num2.size());
        vector<int> n1(digits, 0);
        vector<int> n2(digits, 0);
        int i = 0;
        for (auto it = num1.rbegin(); it != num1.rend(); it++)
            n1[i++] = *it - '0';
        i = 0;
        for (auto it = num2.rbegin(); it != num2.rend(); it++)
            n2[i++] = *it - '0';
        // for (int i = 0; i < n1.size(); i++)
        //     cerr << n1[i] << " ";
        // cerr << endl;
        // for (int i = 0; i < n2.size(); i++)
        //     cerr << n2[i] << " ";
        // cerr << endl;
        int sum = count(digits, min_sum, max_sum, n1, n2, 1);
        // cerr << "Recursion depth: " << recursionDepth << endl;
        return sum;
    }
};

void removeDoubleQuote(string &str) {
    str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Please input test case file paths.\nExample: ./a.out testcases/input00.txt testcases/output00.txt\n");
        return 1;
    }

    // Open the input test case file.
    FILE * fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Input file not found at %s", argv[1]);
        return 2;
    }
    
    printf("\n\033[96mInputs:\033[0m\n\n");

    // read first line of code
    char buf[100];
    int min_sum, max_sum;
    fscanf(fp, "%s", buf);
    string num1(buf); removeDoubleQuote(num1);
    fscanf(fp, "%s", buf);
    string num2(buf); removeDoubleQuote(num2);
    num2.erase(std::remove(num2.begin(), num2.end(), '"'), num2.end());
    fscanf(fp, "%d", &min_sum);
    fscanf(fp, "%d", &max_sum);
    printf("Num1 and Num2 are \033[93m%s, %s\033[0m\n", num1.c_str(), num2.c_str());
    printf("MinSum and MaxSum are \033[93m%d, %d\033[0m\n", min_sum, max_sum);

    fclose(fp);

    // Open the output test case file.
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        fprintf(stderr, "Output file not found at %s", argv[1]);
        return 2;
    }

    // read first line of code
    int gt;
    fscanf(fp, "%d", &gt);
    fclose(fp);

    // run the function
    Solution sol;
    int out = sol.count(num1, num2, min_sum, max_sum);

    printf("\n\033[96mOutput:\033[0m\n\n");
    if (out == gt) printf("\033[92m"); else printf("\033[91m");
    printf("%d", out);
    printf("\033[0m\n");

    printf("\n\033[96mExpected:\033[0m\n\n");
    printf("\033[93m%d\033[0m\n\n", gt);

    return out == gt ? 0 : 3;
}
