// football_score.c
#include <stdio.h>

void print_combinations(int score) {
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        for (int td1 = 0; td1 * 7 + td2*8 <= score; td1++) {
            for (int td = 0; td*6 + td1*7 + td2*8 <= score; td++) {
                for (int fg = 0; fg*3 + td*6 + td1*7 + td2*8 <= score; fg++) {
                    for (int sa = 0; sa*2 + fg*3 + td*6 + td1*7 + td2*8 <= score; sa++) {
                        int total = sa*2 + fg*3 + td*6 + td1*7 + td2*8;
                        if (total == score) {
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety\n",
                                   td2, td1, td, fg, sa);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);
        if (score == 1) break;
        if (score < 2) {
            printf("Score must be at least 2.\n");
            continue;
        }
        printf("Possible combinations if a team's score is %d:\n", score);
        print_combinations(score);
    }
    return 0;
}
