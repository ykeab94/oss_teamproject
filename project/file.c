// file 관련 함수
#include "manager.h"
#include "file.h"
#include <stdio.h>
#include <string.h>

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
    printf("==> 로딩성공!!!\n");
    return count;
}

void saveResult(Student *s, int count) {
	FILE * fp;
	float total = 0;
	int sum = 0;
	char grade;
	float avg = 0;
	fp = fopen("oss_result.txt", "wt");
	fprintf(fp, "2020-01 오픈소스 소프트웨어 학생 성적\n");
	fprintf(fp, "No | Name |  mid  |  lab  |project| final |  sum  |  grade  | \n");
	for(int i = 0; i<count; i++) {
		if(s[i].mid == -1) continue;
		sum = s[i].mid+s[i].lab+s[i].project+s[i].finals;
		grade = gradeScore(sum);
		fprintf(fp, "%2d %10s %7d %7d %7d %7d %7d %7c\n", i+1, s[i].name, s[i].mid, s[i].lab, s[i].project, s[i].finals, sum, grade);
		total+= (float)sum;
		sum = 0;
	}
	avg = total / count;
	fprintf(fp, "이 분반의 성적 평균은 [%.2f]점입니다.\n", avg);
	fclose(fp);
	printf("==> 저장됨! \n");
}

