#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char word[5][16];
    int maxlen = 0, len[5] = {0};

    for (int i = 0; i < 5; i++) {
        scanf("%s", word[i]);
        int wordlen = strlen(word[i]);
        len[i] = wordlen;
        if (wordlen > maxlen) {
            maxlen = wordlen;
        }
    }

    for (int i = 0; i < maxlen; i++) {
        for (int j = 0; j < 5; j++) {
            if ((word[j][i] >= '0' && word[j][i] <= '9') || (word[j][i] >= 'A' && word[j][i] <= 'z')) {
                if (len[j] > i) {
                    printf("%c", word[j][i]);
                } else
                    continue;
            }
        }
    }

    return 0;
}