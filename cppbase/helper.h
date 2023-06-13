#ifndef HELPER_H_
#define HELPER_H_

#include <bits/stdc++.h>

class FileReader {
    private:
        FILE* fp = nullptr;
    public:
        FileReader(const std::string& path);
        FileReader(const char *path);
        ~FileReader();
        bool isOpen(); // 파일이 열렸는지 여부
        void close(); // 파일을 미리 닫음
        std::string readAllText(); // 전체 파일 읽기
        std::string readLine(int bufferSize); // 한 줄 읽기
        void readIntegerArray(std::vector<int>& dst, size_t n); // 길이가 정해진 정수 배열을 읽는다.
        int readInteger(); // 정수 하나를 읽어온다.
};

// 문자열의 왼쪽 공백을 제거
void ltrim(std::string &s);
// 문자열의 오른쪽 공백을 제거
void rtrim(std::string &s);
// 문자열의 공백을 제거
void trim(std::string &s);
// 배열의 특정 위치(s)로 부터 오른쪽으로 연속적인 값의 개수를 구한다.
int getConseqCountFromHead(std::vector<int>& data, int s, int e);
// 배열의 특정 위치(e - 1)로 부터 왼쪽으로 연속적인 값의 개수를 구한다.
int getConseqCountFromTail(std::vector<int>& data, int s, int e);
// 배열에서 가장 작은 값의 위치를 구한다.
int getMinValuePosition(std::vector<int>& data, int s, int e);
// 배열이 오름차순인지 확인한다.
bool isAscending(std::vector<int>& data, int s, int e);
// 배열이 내림차순인지 확인한다.
bool isDescending(std::vector<int>& data, int s, int e);
// 정수 pair에서 비교 함수를 정의한다.
typedef std::pair<int, int> IntPair;
auto compareIntPair = [](IntPair const& x, IntPair const& y) -> bool {
    if (x.first < y.first)
        return true;
    else if (x.first == y.first)
        return x.second < y.second;
    else
        return false;
};
uint64_t factorial(uint64_t n);
uint64_t permutation(uint64_t n, uint64_t r);
// 컴비네이션을 구한다.
int combination(int n, int r); // only count
template <typename T> std::vector<T> combination(const std::vector<T>& arr, int n, int r);

#endif
