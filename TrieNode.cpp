#include "TrieNode.h"
TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++) {
            children[i] = 0;
        }
        is_end_of_word = false;
};