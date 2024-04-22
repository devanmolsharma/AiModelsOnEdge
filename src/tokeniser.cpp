#include "tokeniser.h"

double tokeniseWord(TokeniserConfig config, char *word, int length)
{
    double out = -1;

    for (int i = 0; i < config.length; i++)
    {
        TokenPair pair = config.tokens[i];
        if (pair.wordLength == length)
        {
            int isEqual = true;
            for (int i = 0; i < length; i++)
            {
                if (word[i] != pair.word[i])
                {
                    isEqual = false;
                }
            }

            if (isEqual)
            {
                out = pair.index;
            }
        }
    }

    return out;
}

void tokenise(TokeniserConfig config, char *word, int maxWords, Tensor *out)
{
    int i = 0;
    int j = 0;
    int wordIndex = 0;
    double tokenised[maxWords];
    char currentWord[10];
    free(out->data);

    while (1)
    {
        char character = word[j];
        currentWord[i] = character;
        if ((character == ' ') || (character == '\0'))
        {
            currentWord[i] = '\0';
            tokenised[wordIndex] = tokeniseWord(config, currentWord, i + 1);
            tokenised[wordIndex + 1] = -2;
            wordIndex++;
            i = 0;
            j++;
            if (character == '\0')
            {
                break;
            }
            continue;
        }

        i++;
        j++;
    }

    double *arr = (double *)malloc(wordIndex * sizeof(double));
    for (int i = 0; i < wordIndex; i++)
    {
        arr[i] = tokenised[i];
    }

    out->size = wordIndex;
    out->data = arr;
}
