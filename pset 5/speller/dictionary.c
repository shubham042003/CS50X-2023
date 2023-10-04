#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;

// Hash table
node *table[N];

// Declare count Variable

unsigned int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int code = hash(word);
    // printf("check input word\n%s\n", word);

    for (node *tmp = table[code]; tmp != NULL; tmp = tmp->next)
    {
        //printf(" my readout\n%s\n%s\n readout done\n", word, tmp->word);

        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Tried to improve this hash function, but something goes wrong!

    return 26 * (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

// Open dictionary file

    FILE *file;
    file = fopen(dictionary, "r");
    printf("the return value of fopen is: %p\n", fopen(dictionary, "r"));
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

// Read strings one by one into variable buffer

    while (fscanf(file, "%s", buffer) != EOF)//printf("%s\n", buffer);

//create a new node for this word
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            free(n);
            fclose(file);
            return false;
        }

//copy word into new node and initialise pointer to NULL

        //printf("%s\n", buffer);
        strcpy(n->word, buffer);
        n->next = NULL;

// Hash the word in the buffer

        int code = hash(buffer);
        //printf("%i\n", code);

// connect the new node to first in the list, then insert it at the front

        n->next = table[code];
        table[code] = n;
        count++;


    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // declare two variables - cursor and tmp
    node *tmp = NULL;
    node *cursor = NULL;

    // go to each part of the hash table
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        tmp = table[i];

        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

    }

    return true;
}