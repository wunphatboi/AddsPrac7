#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include "TrieNode.h"
#include <vector>
#include <string>
using namespace std;

class PrefixMatcher {
    private:
    TrieNode* root;
    public:
    PrefixMatcher();
    void insert(string address, int routerNumber);
    int selectRouter(string networkAddress);
};
#endif