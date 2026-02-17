#include <stdio.h>

#define Q 10
#define STD 8

int checkscore(char std[]);
int countCorrectQ1(char ans[][10], int nStd, char keys[]);

int findHardestQuestion(char ans[][10], int nStd, char keys[], int correctCount[]);
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
	printf("Correct Q1 = %d\n", countCorrectQ1(ans, 8, keys));
	int correctCount[10];
    int hardest = findHardestQuestion(ans, 8, keys, correctCount);

printf("Hardest question(s): ");
for (int q = 0; q < 10; q++) {
    if (correctCount[q] == correctCount[hardest]) {
        printf("%d ", q + 1); 
    }
}
printf("(correct %d people)\n", correctCount[hardest]);

    return 0;
}
int countCorrectQ1(char ans[][10], int nStd, char keys[]) {
    int count = 0;
    for (int i = 0; i < nStd; i++) {
        if (ans[i][0] == keys[0]) { // ??? 1 = index 0
        if (ans[i][0] == keys[0]) { 
            count++;
        }
    }
    return count;
}
int findHardestQuestion(char ans[][10], int nStd, char keys[], int correctCount[]) {
  
    for (int q = 0; q < 10; q++) correctCount[q] = 0;

    for (int i = 0; i < nStd; i++) {
        for (int q = 0; q < 10; q++) {
            if (ans[i][q] == keys[q]) correctCount[q]++;
        }
    }
    int min = correctCount[0];
    int hardest = 0;
    for (int q = 1; q < 10; q++) {
        if (correctCount[q] < min) {
            min = correctCount[q];
            hardest = q;
        }
    }
    return hardest; 
}
