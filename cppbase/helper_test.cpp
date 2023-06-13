#include "helper.h"

using namespace std;

void test_ltrim() {
    string s("  hello world !   ");
    ltrim(s);
    assert(s == "hello world !   ");
}

void test_rtrim() {
    string s("  hello world !   ");
    rtrim(s);
    assert(s == "  hello world !");
}

void test_trim() {
    string s("  hello world !   ");
    trim(s);
    assert(s == "hello world !");
}

void test_factorial() {
    assert(120 == factorial(5));
}

void test_comparator() {
#if __cplusplus >= 202002L
    // C++20 (and later) code
    std::set<IntPair, decltype(compareIntPair)> a {{3, 3},{1, 5},{1, 8},{1, 3},{8, 4}};
#else
    std::set<IntPair, decltype(compareIntPair)> a(compareIntPair);
    a.insert({{3, 3},{1, 5},{1, 8},{1, 3},{8, 4}});
#endif
    std::vector<IntPair> b {{1, 3},{1, 5},{1, 8},{3, 3},{8, 4}};
    auto it_b = b.begin();
    for (auto it_a = a.begin(); it_a != a.end(); it_a++) {
        assert(it_a->first == it_b->first);
        assert(it_a->second == it_b->second);
        it_b++;
    }
#if __cplusplus >= 202002L
    // C++20 (and later) code
    std::priority_queue<IntPair, std::vector<IntPair>, decltype(compareIntPair)> c;
#else
    std::priority_queue<IntPair, std::vector<IntPair>, decltype(compareIntPair)> c(compareIntPair);
#endif
    c.emplace(3, 3); c.emplace(1, 5); c.emplace(1, 8); c.emplace(1, 3); c.emplace(8, 4);
    auto it_rb = b.rbegin();
    while (!c.empty()) {
        assert(c.top().first == it_rb->first);
        assert(c.top().second == it_rb->second);
        c.pop();
        it_rb++;
    }
}


int main() {
    test_ltrim();
    test_rtrim();
    test_trim();
    test_comparator();
    test_factorial();
}
