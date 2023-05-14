#include "Autocomplete.h"
Autocomplete::Autocomplete() {
        root = new TrieNode();
    };
void Autocomplete::insert(std::string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->is_end_of_word = true;
};

vector<string> Autocomplete::getSuggestions(std::string partialWord) {
        vector<string> suggestions;
        TrieNode* current = root;
        for (char c : partialWord) {
            int index = c - 'a';
            if (!current->children[index]) {
                return suggestions;
            }
            current = current->children[index];
        }
        getWordsFromNode(current, partialWord, suggestions);
        return suggestions;
};

void Autocomplete::getWordsFromNode(TrieNode* node, string prefix, vector<string>& suggestions) {
        if (node->is_end_of_word) {
            suggestions.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                getWordsFromNode(node->children[i], prefix + char(i + 'a'), suggestions);
            }
        }
};
