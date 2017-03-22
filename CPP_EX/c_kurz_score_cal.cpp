#include <iostream>

using namespace std;

int main(void) {
    int scores[5][4] = {0};
    for(int std=0; std<5; std++) {
        scanf("%d %d %d %d", &scores[std][0], &scores[std][1], &scores[std][2], &scores[std][3]);
    }

    string name[5] = {"张大明", "李小红", "王志强", "汪晓成", "李 丹"};
    int total_score[5] = {0};

    for (int i=0; i<5; i++) {
        for(int j=0; j<4; j++) {
            total_score[i] += scores[i][j];
        }
    }

    float std_ave_point[5] = {0};
    for (int s=0; s<5; s++) {
        std_ave_point[s] = total_score[s] / 4;
    }

    float sub_ave_point[4] = {0};
    int total[5] = {0};
    for (int p=0; p<4; p++) {
        for(int a=0; a<5; a++) {
            total[p] += scores[p][a];
            sub_ave_point[p] = total[p] / 5;
        }
    }

    cout << "个人总分";
    for(int i=0; i<5; i++) {
        cout << total_score[i] << " " << endl;
    }

    cout << "个人平均分";
    for (int s=0; s<5; s++) {
        cout << std_ave_point[s] << " " << endl;
    }

    cout <<"科目平均分";
    for (int p=0; p<4; p++) {
        cout << sub_ave_point[p] <<" " << endl;
    }
    return 0;
}
