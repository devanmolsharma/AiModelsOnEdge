#include "helpers.h"

struct TokenPair
{
    int index;
    int wordLength;
    char *word;
};

struct TokeniserConfig
{
    int length;
    TokenPair *tokens;
};

double tokeniseWord(TokeniserConfig config, char *word, int length);
void tokenise(TokeniserConfig config, char *word, int maxWords, Tensor *out);