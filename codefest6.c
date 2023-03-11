#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int B, C, D;
        scanf("%d %d %d", &B, &C, &D);
        int intervals = (12-6)/B + 1;
        int A[intervals];
        for (int i = 0; i < intervals; i++) {
            scanf("%d", &A[i]);
        }
        int bench_count = 0, stool_count = 0;
        int renting_expense = 0;
        for (int i = 0; i < intervals; i++) {
            int required_benches, required_stools;
            if (A[i] % 2 == 0) {
                required_benches = A[i]/2;
                required_stools = 0;
            } else {
                required_benches = (A[i]+1)/2;
                required_stools = 1;
            }
            if (required_stools % 2 == 1 && stool_count == 0) {
                renting_expense += C;
                stool_count++;
            } else if (required_stools % 2 == 1 && stool_count == 1) {
                renting_expense += D + C;
                bench_count++;
                stool_count = 0;
            } else if (required_stools % 2 == 0 && stool_count == 1) {
                renting_expense += D;
                bench_count++;
                stool_count = 0;
            }
            bench_count += required_benches;
            stool_count += required_stools;
        }
        printf("Case #%d: %d %d\n", t, bench_count, renting_expense);
    }
    return 0;
}