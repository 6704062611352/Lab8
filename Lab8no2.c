#include <stdio.h>

#define Q 10
#define STD 8

int checkscore(char std[]);

char keys[Q] = {'D','B','D','C','C','D','A','E','A','D'};

int checkscore(char std[]) {
    int score = 0;
    for (int i = 0; i < Q; i++) {
        if (std[i] == keys[i]) score++;
    }
    return score;
}

int main() {
    char ans[STD][Q] = {
        {'A','B','A','C','C','D','E','E','A','D'}, // 7
        {'D','B','A','B','C','A','E','E','A','D'}, // 6
        {'E','D','D','A','C','B','E','E','A','D'}, // 5
        {'C','B','A','E','D','C','E','E','A','D'}, // 4
        {'A','B','D','C','C','D','E','E','A','D'}, // 8
        {'B','B','E','C','C','D','E','E','A','D'}, // 7
        {'B','B','A','C','C','D','E','E','A','D'}, // 7
        {'E','B','E','C','C','D','E','E','A','D'}  // 7
    };

    for (int i = 0; i < STD; i++) {
        printf("std %d => %d\n", i + 1, checkscore(ans[i]));
    }

    return 0;
}
