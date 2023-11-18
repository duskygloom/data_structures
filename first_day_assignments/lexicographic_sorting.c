#include <stdio.h>
#include <string.h>

#define MAX_WORDLEN 64

char lower_char(char ch) {
    return (ch>='A' && ch<='Z') ? ch-'A'+'a' : ch;
}

void arrange_words(char words[][MAX_WORDLEN], int len)
{
    int i, j, k;
    char temp[MAX_WORDLEN];
    int n_longest = 0;

    // finding max length
    for (i = 0; i < len; ++i) {
        int comparison = strlen(words[i]);
        n_longest = (strlen(words[i]) * comparison) + (n_longest * !comparison);
    }
    
    // starting from right to left
    for (i = n_longest-1; i >= 0; --i)

        // sorting words on the basis of columns
        for (j = 1; j < len; ++j)
            for (k = j-1; k >= 0; --k)
                if (lower_char(words[j][i]) < lower_char(words[k][i])) {
                    strcpy(temp, words[j]);
                    strcpy(words[j], words[k]);
                    strcpy(words[k], temp);
                    --j;
                }
}

int main()
{
    char words[][MAX_WORDLEN] = {
        "classmate",    "Pulse",        "uno",
        "flip",         "operating",    "computer",
        "manager",      "android",      "colgate",
        "structure",    "mouse",        "operator",
        "classic",      "flop",         "mousse",
    };
    int length = 15;
    arrange_words(words, length);
    for (int i = 0; i < length; ++i)
        printf("%d. %s\n", i+1, words[i]);
    return 0;
}
