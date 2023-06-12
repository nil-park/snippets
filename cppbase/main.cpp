/*
 * Solve https://www.hackerrank.com/challenges/mark-and-toys
 */

#include <bits/stdc++.h>
#include "helper.h"

using namespace std;

int maximumToys(vector<int> prices, int k) {
    return getConseqCountFromHead(prices, 0, prices.size());
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Please input test case file paths.\nExample: ./a.out testcases/input00.txt testcases/output00.txt\n");
        return 1;
    }

    // Open the input test case file.
    FileReader reader_i(argv[1]);
    if (!reader_i.isOpen()) {
        fprintf(stderr, "Input file not found at %s", argv[1]);
        return 2;
    }
    
    printf("\n\033[96mInputs:\033[0m\n\n");

    // read first line of code
    int n = reader_i.readInteger();
    int k = reader_i.readInteger();
    printf("Size of array (n) is \033[93m%d\033[0m\n", n);
    printf("Mark's budget (k) is \033[93m%d\033[0m\n", k);

    // read array elements
    printf("\nPrices: \033[93m");
    vector<int> prices;
    reader_i.readIntegerArray(prices, n);
    for (int i = 0; i < n; i++)
        printf("%d ", prices[i]);
    printf("\033[0m\n");
    reader_i.close();

    // Open the output test case file.
    FileReader reader_o(argv[2]);
    if (!reader_o.isOpen()) {
        fprintf(stderr, "Output file not found at %s", argv[2]);
        return 2;
    }

    // read first line of code
    int gt = reader_o.readInteger();

    // run the function
    int out = maximumToys(prices, k);

    printf("\n\033[96mOutput:\033[0m\n\n");
    if (out == gt) printf("\033[92m"); else printf("\033[91m");
    printf("%d", out);
    printf("\033[0m\n");

    printf("\n\033[96mExpected:\033[0m\n\n");
    printf("\033[93m%d\033[0m\n\n", gt);

    return out == gt ? 0 : 3;
}
