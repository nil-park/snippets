#include <bits/stdc++.h>

using namespace std;

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

/*
 * TODOS
 * integer pair의 comparator 만들기
 * merge sort MOCK 디자인
 * modulo 연산을 이용해 정수 최대값 초과하지 않게 잘라주는 wrapper 함수 구현
 */
