#include "helper.h"

using namespace std;

void ltrim(string &str) {
    auto p = str.end();
    for (auto it = str.begin(); it < str.end(); it++) {
        if (!isspace(*it)) {
            p = it;
            break;
        }
    }
    if (p != str.begin()) {
        if (p == str.end()) {
            str.clear();
        }
        else {
            str.erase(str.begin(), p);
        }
    }
}

void rtrim(string &str) {
    auto p = str.rend();
    for (auto it = str.rbegin(); it < str.rend(); it++) {
        if (!isspace(*it)) {
            p = it;
            break;
        }
    }
    if (p != str.rbegin()) {
        if (p == str.rend()) {
            str.clear();
        }
        else {
            str.erase(p.base(), str.end());
        }
    }
}

void trim(string &str) {
    ltrim(str);
    rtrim(str);
}

FileReader::FileReader(const std::string& path) {
    fp = fopen(path.c_str(), "r");
}

FileReader::FileReader(const char *path) {
    fp = fopen(path, "r");
}

FileReader::~FileReader() {
    close();
}

bool FileReader::isOpen() {
    return fp != nullptr;
}

void FileReader::close() {
    if (fp != nullptr) {
        fclose(fp);
        fp = nullptr;
    }
}

std::string FileReader::readAllText() {
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    std::string s(fsize, 0);
    fread((void *)s.data(), 1, fsize, fp);
    return s;
}

std::string FileReader::readLine(int bufferSize) {
    unique_ptr<char> buf(new char[bufferSize]);
    fscanf(fp, "%s", buf.get());
    return std::string(buf.get());
}

void FileReader::readIntegerArray(std::vector<int>& dst, size_t n) {
    dst.resize(n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &dst[i]);
    }
}

int FileReader::readInteger() {
    int x;
    fscanf(fp, "%d", &x);
    return x;
}

// 배열의 특정 위치(s)로 부터 오른쪽으로 연속적인 값의 개수를 구한다.
int getConseqCountFromHead(vector<int>& data, int s, int e) {
    int cnt = 1;
    int x = data[s];
    for (int i = s + 1; i < e; i++) {
        if (data[i] == x)
            cnt++;
        else
            break;
    }
    return cnt;
}

// 배열의 특정 위치(e - 1)로 부터 왼쪽으로 연속적인 값의 개수를 구한다.
int getConseqCountFromTail(vector<int>& data, int s, int e) {
    int cnt = 1;
    int x = data[e - 1];
    for (int i = e - 2; i >= s; i--) {
        if (data[i] == x)
            cnt++;
        else
            break;
    }
    return cnt;
}
// 배열에서 가장 작은 값의 위치를 구한다.
int getMinValuePosition(vector<int>& data, int s, int e) {
    int p = s;
    for (int i = s + 1; i < e; i++) {
        if (data[i] < data[p]) {
            p = i;
        }
    }
    return p;
}
// 배열이 오름차순인지 확인한다. // 정수 인덱스를 쓰는 것 제외하고는 is_sorted 함수와 동일
bool isAscending(vector<int>& data, int s, int e) {
    int p = data[s];
    for (int i = s + 1; i < e; i++) {
        if (data[i] < p)
            return false;
        p = data[i];
    }
    return true;
}
// 배열이 내림차순인지 확인한다. // is_sorted가 descending comparator를 넣을 수 없게 돼있어서 구현
bool isDescending(vector<int>& data, int s, int e) {
    int p = data[s];
    for (int i = s + 1; i < e; i++) {
        if (data[i] > p)
            return false;
        p = data[i];
    }
    return true;
}

uint64_t factorial(uint64_t n) { // maximum n is 20
    if (n < 2) return 1;
    uint64_t sum = n;
    for (uint64_t x = n - 1; x >= 2; x--)
        sum *= x;
    return sum;
}

uint64_t permutation(uint64_t n, uint64_t r) {
    if (n <= r) return factorial(n);
    uint64_t sum = n;
    uint64_t bound = n - r;
    for (uint64_t x = n - 1; x > bound; x--)
        sum *= x;
    return sum;
}

int combination(int n, int r) {
    return 0;
}

template <typename T> vector<T> combination(const vector<T>& arr, size_t r) {
    // vector<bool> indices(arr.size(), false);
    // // fill_n(arr.begin(), size_t r, )
    // for(int i = 0; i < r; i++)
    //     temp[i] = true;
 
    // do {
    //     for (int i = 0; i < arr.size(); ++i) {
    //         if (temp[i])
    //             cout << arr[i] << ' ';
    //     }
    //     cout << endl;
    // } while (prev_permutation(temp.begin(), temp.end()));
    return vector<T>();
}

/*
 * TODOS
 * integer pair의 comparator 만들기
 * lambda function for sorting sort(arr.begin(), arr.end(), [](auto a, auto b){return a < b;})
 * merge sort MOCK 디자인
 * modulo 연산을 이용해 정수 최대값 초과하지 않게 잘라주는 wrapper 함수 구현
 */


