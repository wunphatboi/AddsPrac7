#include "PrefixMatcher.h"
PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
};

void PrefixMatcher::insert(string address, int routerNumber) {
        TrieNode* cur = root;
        for (int i = 0; i < address.size(); i++) {
            int bit = address[i] - '0';
            if (cur->children[bit] == nullptr) {
                cur->children[bit] = new TrieNode();
            }
            cur = cur->children[bit];
        }
        cur->routerNumber = routerNumber;
};
    
int PrefixMatcher::selectRouter(string networkAddress) {
        TrieNode* cur = root;
        int lastRouter = -1;
        for (int i = 0; i < networkAddress.size(); i++) {
            int bit = networkAddress[i] - '0';
            if (cur->children[bit] != nullptr) {
                cur = cur->children[bit];
                if (cur->routerNumber != -1) {
                    lastRouter = cur->routerNumber;
                }
            } else {
                break;
            }
        }
        return lastRouter;
};
    