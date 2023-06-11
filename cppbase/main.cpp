/*
 * This program solves https://leetcode.com/problems/count-of-integers
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'maximumToys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER k
 */

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        return 11;
    }
};

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
    string num1(buf);
    fscanf(fp, "%s", buf);
    string num2(buf);
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

    return 0;
}
