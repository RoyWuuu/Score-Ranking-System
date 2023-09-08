#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENTS 40

void generate_scores(int chinese[], int english[]);
void calculate_weighted_scores(const int chinese[], const int english[], double weighted_scores[]);
void bubble_find(const double weighted_scores[], int top_scores[], int bottom_scores[]);

int main() {
    int chinese[NUM_STUDENTS], english[NUM_STUDENTS];
    double weighted_scores[NUM_STUDENTS];
    int top_scores[3], bottom_scores[3];

    srand(time(NULL));

    generate_scores(chinese, english);
    calculate_weighted_scores(chinese, english, weighted_scores);
    bubble_find(weighted_scores, top_scores, bottom_scores);

    printf("學生編號\t國文成績\t英文成績\t總分\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%d\t\t%d\t\t%d\t\t%.2lf\n", i + 1, chinese[i], english[i], weighted_scores[i]);
    }

    printf("\n前三名學生的總分：\n");
    for (int i = 0; i < 3; i++) {
        printf("第%d名學生編號：%d\t總分：%.2lf\n", i + 1, top_scores[i] + 1, weighted_scores[top_scores[i]]);
    }

    printf("\n後三名學生的總分：\n");
    for (int i = 0; i < 3; i++) {
        printf("第%d名學生編號：%d\t總分：%.2lf\n", i + 1, bottom_scores[i] + 1, weighted_scores[bottom_scores[i]]);
    }


    return 0;
}

void generate_scores(int chinese[], int english[]) //隨機生成國文、英文分數
{
    for (int i = 0; i < NUM_STUDENTS; i++) {
        chinese[i] = rand() % 101;
        english[i] = rand() % 101;
    }
}

void calculate_weighted_scores(const int chinese[], const int english[], double weighted_scores[])//加權分數
{
    for (int i = 0; i < NUM_STUDENTS; i++) {
        weighted_scores[i] = 0.3 * chinese[i] + 0.7 * english[i];
    }
}

void bubble_find(const double weighted_scores[], int top_scores[], int bottom_scores[])//泡沫排序法
{
    int sorted_indices[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++) {
        sorted_indices[i] = i;
    }

    for (int i = 0; i < NUM_STUDENTS - 1; i++) {
        for (int j = 0; j < NUM_STUDENTS - 1 - i; j++) {
            if (weighted_scores[sorted_indices[j]] < weighted_scores[sorted_indices[j + 1]]) {
                int temp = sorted_indices[j];
                sorted_indices[j] = sorted_indices[j + 1];
                sorted_indices[j + 1] = temp;
            }
        }
    }

    // 前三名
    for (int i = 0; i < 3; i++) {
        top_scores[i] = sorted_indices[i];
    }

    // 倒數三名
    for (int i = 0; i < 3; i++) {
        bottom_scores[i] = sorted_indices[NUM_STUDENTS - 1 - i];
    }
}
