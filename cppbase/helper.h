#ifndef HELPER_H_
#define HELPER_H_

#include <bits/stdc++.h>

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

#endif
