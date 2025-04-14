#ifndef _trie_node_h
#define _trie_node_h
#include <iostream>

//Each trie node in tree, except for the root node, implicitly represent a character
struct TrieNode{
    //make use of smart pointer here!
    TrieNode** children;
    bool isWord;

    TrieNode(){
        children = new TrieNode*[26]();
        bool isWord = false;
    }

    ~TrieNode(){
        delete[] children;
        // std::cout << "trie node deleted\n";
    }

    bool isLeaf(){
        for(int i = 0; i < 26; i++){
            if(children[i] != nullptr){
                return false;
            }
        }
        return true;
    }
};

#endif