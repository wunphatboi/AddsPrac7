#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include "TrieNode.h"
#include <vector>
#include <string>
using namespace std;
class Autocomplete {
    private:
    TrieNode* root;
    public:
    Autocomplete();
    vector<std::string> getSuggestions(std::string partialWord); 
    void insert(std::string word); 
    void getWordsFromNode(TrieNode* node, std::string prefix, vector<std::string>& suggestions);
};
#endif