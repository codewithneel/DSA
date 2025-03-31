#include "trie_node.h"
#include "trie.h"
#include <string>
#include <iostream>

Trie::Trie(){
    root = new TrieNode();
}

Trie::~Trie(){
    deleteTrie(root);
}

//bottom up deletion
void Trie::deleteTrie(TrieNode* node){
    if(node != nullptr){
        for(int i = 0; i < 26; i++){
            deleteTrie(node->children[i]);
        }
        delete node;
    }
}

void Trie::add(std::string word){
    //validate string: no empty string, white spaces, capital letters, numbers, symbols
    addHelper(word, root, 0);

}

void Trie::addHelper(std::string word, TrieNode* node, int i){
    //base case
    if(i == word.size()){
        //node points to the trie node that represents the last letter of the word
        node->isWord = true;
    } else {
        //find child in array that represents char
        char character = word[i];
        int index = character - 'a'; //(int)lower case character - 97 
        //if child node (char) does not exist, create new child node and have array point to it
        if(node->children[index] == nullptr){
            TrieNode* newNode = new TrieNode();
            node->children[index] = newNode;
            // std::cout << "new trie node created: " << character << std::endl;
        }
        addHelper(word, node->children[index], ++i);
    }
}

bool Trie::containsWord(std::string word) const{
    return containsWordHelper(word, root, 0);
}

bool Trie::containsWordHelper(std::string word, TrieNode* node, int i) const{
    //base case failure: trie node respresenting index i-1 in word does not exist
    if(node == nullptr){
        return false;
    } else if(i == word.size()){
        //base case success: the string (word) exists in the tree as a prefix or word
        return node->isWord;
    } else {
        //process current char
        char character = word[i];
        int index = character - 'a';
        return containsWordHelper(word, node->children[index], ++i);
    }    
}

void Trie::remove(std::string word){
    removeHelper(word, root, 0);
}

bool Trie::removeHelper(std::string word, TrieNode*& node, int i){
    //base case failure: word does not exist in trie
    if(node == nullptr){
        return false;
    } else if(i == word.size()) {
        //base case success (half and half)
        if(node->isWord){
            if(node->isLeaf()){
                //node has no children, it is ok to delete
                delete node;
                node = nullptr;
                return true;
            } else {
                //node (last letter) is apart of another word, do not delete
                node->isWord = false;
                return false;
            }
        } else {
            //str word is a prefix
            return false;
        }
    } else { //i < word.size()
        char character = word[i];
        int index = character - 'a';
        if(removeHelper(word, node->children[index], ++i)){
            //backtracking step: if func returns true, delete node if it has no children
            if(node != root && node->isLeaf() && node->isWord == false){ 
                //do not delete root
                //if node is not a leaf node, the letter is apart of another word
                delete node;
                node = nullptr;
                return true;
                
            }
        }
        return false;
    }
}

bool Trie::containsPrefix(std::string prefix) const{
    return containsPrefixHelper(prefix, root, 0);
}

bool Trie::containsPrefixHelper(std::string prefix, TrieNode* node, int i) const{
    //base case failure
    if(node == nullptr){
        return false;
    } else if(i == prefix.size()){
        //base case success
        return true;
    } else {
        //general case
        char character = prefix[i];
        int index = character - 'a';
        return containsPrefixHelper(prefix, node->children[index], ++i);
    }
}