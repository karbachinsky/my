#include <iostream>
#include <cassert>
#include <unordered_map>

bool IsAnagram(const std::string & a, const std::string & b) {
    std::unordered_map<char, int> counter;

    if (a.size() != b.size())
        return false;

    const size_t len = a.size();
    for (size_t i = 0; i < len; ++i) {
        counter[a[i]]++; 
        counter[b[i]]--; 
    }

    auto it = counter.cbegin();
    for (;it != counter.cend(); ++it) {
        if (0 != it->second)
            return false;
    }

    return true;

}

int main() {
    assert(IsAnagram("aa", "aa"));
    assert(IsAnagram("aab", "baa"));
    assert(IsAnagram("aca", "aca"));
    assert(IsAnagram("qwerty", "yertwq"));
    assert(IsAnagram("qwwwerty", "wyertwqw"));
    assert(IsAnagram("", ""));
    
    assert(!IsAnagram("qwerty", "qqerty"));
    assert(!IsAnagram("aacc", "aacb"));

    return 0;
}


