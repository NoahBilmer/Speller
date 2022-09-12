// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of memory addresses possible in the hash table
const unsigned int N = 100000;

long int word_count = 0;

// Hash table
node *table[N];

// File pointer
FILE *fp;

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    int length = strlen(word);
    char *current_word = malloc(sizeof(char) * 45);
    for (int i = 0; i < length; i++)
    {
        current_word[i] = tolower(word[i]);
    }

    int index = hash(current_word);

    if (table[index] == NULL)
    {
        return false;
    }

    for (node *trav = table[index]; trav != NULL; trav = trav->next)
    {

        int result = strcasecmp(trav->word, current_word);
        if (result == 0)
        {
            free(current_word);
            return true;
        }
        else
        {
            if (trav == NULL)
            {
                free(current_word);
                return false;
            }
        }
    }

    free(current_word);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    unsigned long hash = 0;
    int c;

    while ((c = *word++) != 0)
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash % N;
    // djb2 - Hash Function made by Daniel J. bernstein,
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for (int i = 0; i <= N; i++)
    {
        table[i] = NULL;
    }
    // Point to dictionary
    fp = fopen(dictionary, "r");
    // Check if we are pointing to NULL
    if (fp == NULL)
    {
        return false;
    }
    char current_word[LENGTH];

    // read every word
    while (fscanf(fp, "%s", current_word) != EOF)
    {
        // Get our hash index
        int index = hash(current_word);
        // Create our node for the current word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // n->word = "a" (on first iteration)
        // n->next = NULL (on first iteration)
        // Copy the current word we are reading to the node's word field
        strcpy(n->word, current_word);
        n->next = NULL;
        // Check if there is anything at our hashed index.
        if (table[index] == NULL)
        {
            // Table is an array of node pointers, point to n.
            table[index] = n;

            word_count += 1;
        }
        else
        {
            // point to what table is pointing at, the first element in the linked list
            n->next = table[index];
            table[index] = n;
            word_count += 1;
        }
    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *trav = NULL;
    for (int i = 0; i <= N; i++)
    {
        trav = NULL;
        if (table[i] == NULL)
        {
            continue;
        }
        trav = table[i];

        node *tmp = trav;

        while (trav != NULL)
        {
            free(tmp);
            trav = trav->next;
            tmp = trav;
        }
    }
    free(fp);
    return true;
}
