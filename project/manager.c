// CRUD 함수+list menu 함수
#include "manager.h"
#include <stdio.h>
#include <string.h>

// 한 학생의 점수를 읽어오는 함수(listProd 함수에 포함될 예정)

int readScore(Student s, int isResult) {
    int sum = 0;
    char grade='?';
    if(isResult == 0) 
	printf("%10s %7d %7d %7d %7d", s.name, s.mid, s.lab, s.project, s.finals);
    else if(isResult == 1) {
	sum = s.mid+s.lab+s.project+s.finals;
	grade = gradeScore(sum,grade);
	printf("%10s %7d %7d %7d %7d %7d %7c", s.name, s.mid, s.lab, s.project, s.finals, sum, grade);
    }
    printf("\n");
    return sum;
}

//학 생성적의 등급을 매기는 함수
char gradeScore(int sum,char grade){
     if (90 <= sum && sum <= 100) grade='A';
     else if (80 <= sum && sum < 90) grade='B';
     else if (70 <= sum && sum < 80) grade='C';
     else if (60 <= sum && sum < 70) grade='D';
     else if (sum < 60) grade='F';
     return grade;
}  

//학생의  점수를  추가하는 함수
int addScore(Student *s) {
    printStd();
    printf("학생이름은? ");
    scanf("%s", s->name);
    printf("중간고사 점수는? ");
    scanf("%d", &s->mid);
    printf("lab과제 점수는? ");
    scanf("%d", &s->lab);
    printf("팀 프로젝트 점수는? ");
    scanf("%d", &s->project);
    printf("기말고사 점수는? ");
    scanf("%d", &s->finals);
    return 1;
}

// 원하는 학생 점수 정보를 수정하는 함수
int updateScore(Student *s) {
    printStd();
    printf("학생이름은? ");
    scanf("%s", s->name);
    printf("중간고사 점수는? ");
    scanf("%d", &s->mid);
    printf("lab과제 점수는? ");
    scanf("%d", &s->lab);
    printf("팀 프로젝트 점수는? ");
    scanf("%d", &s->project);
    printf("기말고사 점수는? ");
    scanf("%d", &s->finals);
    printf("=> 수정됨!\n");
    return 1;
}



// 원하는 제품을 삭제하는 함수
int deleteScore(Student *s) {
    s->mid = -1;
    printf("=> 삭제됨!\n");
    return 1;
}


// 제품 리스트를 읽어오는 함수
void listScore(Student *s, int count, int isResult) {
    printStd();
    float total = 0;
    if(isResult == 0) printf("\nNo| Name |  mid  |  lab  |project| final |  \n");
    else if(isResult == 1) printf("\nNo| Name |  mid  |  lab  |project| final |  sum  | \n");
    printf("===========================================\n");
    for(int i =0; i<count; i++) {
	if(s[i].mid == -1) continue;
	printf("%2d ", i+1);
       	total += readScore(s[i], isResult);
    }
    if(isResult == 1) {
	float avg = total / count;
	printf("이 분반의 평균 점수는 [%.2f]점입니다.\n", avg);
    }
    printf("\n");
}

// 다중 데이터 처리 때 사용
// update와 delete 할 때, 번호을 물어보는 함수(updateProd, deleteProd, searchProd함수에서 사용)
int selectDataNo(Student *s, int count) {
    #ifdef DEBUG
	printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
    #endif
    int no;
    listScore(s, count, 0);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);

    if(s[no-1].mid == -1) {
        printf("이미 삭제된 데이터입니다.\n");
        return -1;
    }

    return no;
}

void printStd() {
	printf("standard(100/100) : 중간(40/40), lab(20/20), project(10/10), final(30/30)\n");
}
