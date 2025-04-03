#ifndef _trie_h
#define _trie_h

#include "trie_node.h"
#include <string>

class Trie{
public:
    Trie();
    ~Trie();

    /*Insert word into trie. Time complexity: O(l), l represents the length of the word*/
    void add(std::string word);

    /*Remove word from trie. Time complexity: O(l) */
    void remove(std::string word);

    /*Return true if word exists in trie; otherwise, false. Time complexity: O(l)*/
    bool containsWord(std::string word) const;

    /*Return true if prefix exists in trie; otherwise, false. Time complexity: O(l)*/
    bool containsPrefix(std::string prefix) const;

private:
    TrieNode* root;
    void addHelper(std::string word, TrieNode* node, int i);
    bool containsWordHelper(std::string word, TrieNode* node, int i) const;
    bool removeHelper(std::string word, TrieNode*& node, int i);
    bool containsPrefixHelper(std::string prefix, TrieNode* node, int i) const;
    void deleteTrie(TrieNode* node);
};  


#endif