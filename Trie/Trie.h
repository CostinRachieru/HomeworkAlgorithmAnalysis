#ifndef __TRIE_H
#define __TRIE_H
 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

int ALPHABET_SIZE = 26;

class Trie
{
 private:
    int count;
    std::vector<Trie*> children;
    bool isEndOfWord;
  public:
    Trie() {
    }
        
    Trie(int capacity) 
        : count(0),
        children(capacity, NULL) { }
        
    ~Trie() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (children[i] != NULL) {
                delete children[i];
            }
        }
    }
 	void insert(std::string key) {
        if (key.empty()) {
            isEndOfWord = true;
            return;
        }
        int next = key[0] - 'a';
        if (children[next] == NULL) { 
            children[next] = new Trie(ALPHABET_SIZE);
            count++;
        }
        key.erase(key.begin());
        children[next]->insert(key);
    }
	
    bool search(std::string key) {
        if (key.empty()) {
            return isEndOfWord;
        }
        int next = key[0] - 'a';
        if (children[next] == NULL) {
            return false;
        }
        key.erase(key.begin());
        return children[next]->search(key);
    }
};
#endif

