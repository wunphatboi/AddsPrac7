#ifndef TRIENODE_H
#define TRIENODE_H

class TrieNode {
    public:
    TrieNode* children[26];
    bool is_end_of_word;
    TrieNode();
};
#endif