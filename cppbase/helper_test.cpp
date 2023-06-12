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

int main() {
    test_ltrim();
    test_rtrim();
    test_trim();
}
