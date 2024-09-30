#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int count;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    while (*word) {
        int index = *word - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        current->count++;
        word++;
    }
}

int calculateScore(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    int score = 0;
    while (*word) {
        int index = *word - 'a';
        if (current->children[index] == NULL) {
            return score;
        }
        current = current->children[index];
        score += current->count;
        word++;
    }
    return score;
}

int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    struct TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) {
        insert(root, words[i]);
    }
    int* result = (int*)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        result[i] = calculateScore(root, words[i]);
    }
    *returnSize = wordsSize;
    return result;
}