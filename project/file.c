// file 관련 함수
#include "manager.h"
#include <stdio.h>
#include <string.h>
#include "file.h"

// 제품 리스트를 텍스트 파일로 저장하는 함수
void saveData(Student *s, int count) {
    FILE *fp;
    fp = fopen("oss_score.txt", "wt");
    for(int i =0; i< count; i++) {
        if(s[i].mid == -1) continue;
        fprintf(fp, "%s %d %d %d %d\n", s[i].name, s[i].mid, s[i].lab, s[i].project, s[i].finals);
    }
    fclose(fp);
    printf("==> 저장됨! \n");
}

int loadData(Student *s) {
    FILE *fp;
    fp = fopen("oss_score.txt", "rt");
    if(fp == NULL) {
        printf("==> 파일이 없음\n");
        return 0;
    }
    int count = 0;
    // index를 위한 count 변수를 생성.
    for(;;count++){
        fscanf(fp, "%s %d %d %d %d", s[count].name, &s[count].mid, &s[count].lab, &s[count].project, &s[count].finals);
        if(feof(fp)) break;
    }
    fclose(fp);
    printf("==> 로딩성공!!!\n")
;
}


