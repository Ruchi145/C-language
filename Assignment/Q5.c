#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF_LEN 200
#define HASH_TABLE_SIZE 101 


typedef struct WordCountNode {
    char word[MAX_BUF_LEN];
    int count;
    struct WordCountNode *next;
} WordCountNode;


typedef struct {
    WordCountNode *table[HASH_TABLE_SIZE];
} WordCountHashTable;


unsigned int hash(const char *str) {
    unsigned int hashval = 0;
    while (*str) {
        hashval = tolower(*str++) + (hashval << 5) - hashval;
    }
    return hashval % HASH_TABLE_SIZE;
}

void insertWord(WordCountHashTable *hashTable, const char *word) {
    unsigned int index = hash(word);
    WordCountNode *node = hashTable->table[index];


    while (node != NULL) {
        if (strcasecmp(node->word, word) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }


    node = (WordCountNode *)malloc(sizeof(WordCountNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    strncpy(node->word, word, MAX_BUF_LEN);
    node->count = 1;
    node->next = hashTable->table[index];
    hashTable->table[index] = node;
}

void displayWordCounts(const WordCountHashTable *hashTable) {
    printf("Word Counts:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordCountNode *node = hashTable->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

int main() {
    char buf[MAX_BUF_LEN];
    WordCountHashTable hashTable;

    
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable.table[i] = NULL;
    }

    printf("Enter a string (max %d characters):\n", MAX_BUF_LEN - 1);
    fgets(buf, MAX_BUF_LEN, stdin);

    char *token = strtok(buf, " \t\n");
    while (token != NULL) {
        insertWord(&hashTable, token);
        token = strtok(NULL, " \t\n");
    }


    displayWordCounts(&hashTable);

    return 0;
}