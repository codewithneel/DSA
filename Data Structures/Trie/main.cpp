#include "trie_node.h"
#include <iostream>
#include "trie.h"

int main(){
    Trie trie;
    trie.add("abc");
    trie.add("abgl");
    trie.add("cdf");
    trie.add("abcd");
    trie.add("lmn");
    std::cout << "Contains word abgl: " << trie.containsWord("abgl") << std::endl;   
    std::cout << "Contains word abcd: " << trie.containsWord("abcd") << std::endl;
    std::cout << "Contains prefix ab: " << trie.containsPrefix("ab") << std::endl;
    trie.remove("abc");
    trie.remove("abgl");
    trie.remove("abcd");
    std::cout << "Contains word lmn: " << trie.containsWord("lmn") << std::endl;
    std::cout << "Contains word ab: " << trie.containsWord("ab") << std::endl;
    std::cout << "Contains word cdf: " << trie.containsWord("cdf") << std::endl;
    std::cout << "Contains word ghi: " << trie.containsWord("ghi") << std::endl;
    std::cout << "Contains word abc: " << trie.containsWord("abc") << std::endl;
    std::cout << "Contains word abgl: " << trie.containsWord("abgl") << std::endl;   
    std::cout << "Contains word abcd: " << trie.containsWord("abcd") << std::endl;
    std::cout << "Contains prefix ab: " << trie.containsPrefix("ab") << std::endl;
}