// CRUD 함수+list menu 함수
#include "manager.h"
#include <stdio.h>
#include <string.h>

// 한 학생의 점수를 읽어오는 함수(listProd 함수에 포함될 예정)

void readScore(Student s) {
    printf("%10s %7d %7d %7d %7d", s.name, s.mid, s.lab, s.project, s.finals);
    printf("\n");
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
void listScore(Student *s, int count) {
    printStd();
    printf("\nNo| Name |  mid  |  lab  |project| final |  \n");
    printf("===========================================\n");
    for(int i =0; i<count; i++) {
        if(s[i].mid == -1) continue;
        printf("%2d ", i+1);
        readScore(s[i]);
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
    listScore(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);

    if(s[no-1].mid == -1) {
        printf("이미 삭제된 데이터입니다.\n");
        return -1;
    }

    return no;
}

void printStd() {
	printf("standard : 중간(40/40), lab(20/20), project(10/10), final(30/30)\n");
}
