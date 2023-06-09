/*
 * Adopt codebase from https://www.hackerrank.com/challenges/mark-and-toys
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

int maximumToys(vector<int> prices, int k) {
    return 0;
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
    int n, k;
    fscanf(fp, "%d %d", &n, &k);
    printf("Size of array (n) is \033[93m%d\033[0m\n", n);
    printf("Mark's budget (k) is \033[93m%d\033[0m\n", k);

    // read array elements
    printf("\nPrices: \033[93m");
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &prices[i]);
        printf("%d ", prices[i]);
    }
    printf("\033[0m\n");

    /* Read all the line of codes.
    char *line = NULL;
    size_t len = 0;
    ssize_t readBytes;
    while ((readBytes = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", readBytes);
        printf("%s\n", line);
    }
    if (line)
        free(line);
    */

    fclose(fp);

    // Open the output test case file.
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Output file not found at %s", argv[1]);
        return 2;
    }

    // read first line of code
    int gt;
    fscanf(fp, "%d", &gt);
    fclose(fp);

    // run the function
    int out = maximumToys(prices, k);

    printf("\n\033[96mOutput:\033[0m\n\n");
    if (out == gt) printf("\033[92m"); else printf("\033[91m");
    printf("%d", out);
    printf("\033[0m\n");

    printf("\n\033[96mExpected:\033[0m\n\n");
    printf("\033[93m%d\033[0m\n\n", gt);

    return 0;
}
