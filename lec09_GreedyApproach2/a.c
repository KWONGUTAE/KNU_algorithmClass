#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000

typedef struct {
    int deadline;
    int profit;
} Job;

int main() {
    int N;
    int deadlines[MAX_N], profits[MAX_N];
    Job jobs[MAX_N];
    bool slot[MAX_N + 1] = { false };  // 1-based indexing
    Job selected[MAX_N];
    int selected_count = 0;
    int total_profit = 0;

    // 입력
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &deadlines[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &profits[i]);

    for (int i = 0; i < N; ++i) {
        jobs[i].deadline = deadlines[i];
        jobs[i].profit = profits[i];
    }

    // 스케줄링
    for (int i = 0; i < N; ++i) {
        int d = jobs[i].deadline;
        // 가능한 가장 늦은 슬롯을 찾음
        for (int j = d; j >= 1; --j) {
            if (!slot[j]) {
                slot[j] = true;
                selected[selected_count++] = jobs[i];
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    // 선택된 job들을 deadline 기준으로 정렬
    for (int i = 0; i < selected_count - 1; ++i) {
        for (int j = i + 1; j < selected_count; ++j) {
            if (selected[i].deadline > selected[j].deadline) {
                Job temp = selected[i];
                selected[i] = selected[j];
                selected[j] = temp;
            }
        }
    }

    // 출력
    printf("%d\n", total_profit);
    for (int i = 0; i < selected_count; ++i) {
        printf("%d", selected[i].profit);
        if (i != selected_count - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
