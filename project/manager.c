// CRUD 함수+list menu 함수
#include "manager.h"
#include <stdio.h>
#include <string.h>

//학생 이름을 검색하여 그 학생의 점수를 읽는 함수
void searchName(Student *s, int count){
  int scount = 0;
  char search[20];
  printf("원하는 이름은? ");
  scanf("%s", search);

  printf("\n| Name | mid | lab |project| final | \n");
  printf("=================================\n");  
  for(int i = 0; i < count; i++){
    if(s[i].mid == -1) continue;
    if(strstr(s[i].name, search)){
      readScore(s[i], 0);
      scount++;
  }
}
if(scount == 0) printf("==> 검색결과 없음!!\n");
}

// 한 학생의 점수를 읽어오는 함수(listProd 함수에 포함될 예정)

int readScore(Student s, int isResult) {
    int sum = 0;
    char grade;
    if(isResult == 0) 
	printf("%10s %7d %7d %7d %7d", s.name, s.mid, s.lab, s.project, s.finals);
    else if(isResult == 1) {
	sum = s.mid+s.lab+s.project+s.finals;
	grade = gradeScore(sum);
	printf("%10s %7d %7d %7d %7d %7d %7c", s.name, s.mid, s.lab, s.project, s.finals, sum, grade);
    }
    printf("\n");
    return sum;
}

//학생성적의 등급을 매기는 함수
char gradeScore(int sum){
     char grade;
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
    else if(isResult == 1) printf("\nNo| Name |  mid  |  lab  |project| final |  sum  | grade |\n");
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
/*
void searchName(Student *s, int count) {

}
*/
void searchGrade(Student *s, int count) {
	int scount = 0;
	char sgrade;
	int sum;
	char grade;
	printf("원하는 성적 별 학생은?(A~F) : ");
	scanf("%c", &sgrade);
	
	printf("\nNo| Name | grade |\n");
	printf("=====================\n");
	for(int i=0; i< count; i++) {
	     if(s[i].mid == -1) continue;
	     sum = s[i].mid+s[i].lab+s[i].project+s[i].finals;
	     grade = gradeScore(sum);
	     printf("%2d %10s %5c\n", i+1, s[i].name, grade);
	//	printf("debug check!\n");
	     scount++;
//	printf("scount : %d\n",scount);
	}
	if(scount == 0) printf("=> 검색결과 없음!\n");
}

void sortList(Student *s, int count) {
	int num;
	listScore(s, count, 1);
	printf("==========================================\n");
	printf("어떤 항목으로 정렬하시겠습니까?\n");
	printf("(이름(1), 중간(2), lab(3), project(4), final(5), sum(6) : ");
	scanf("%d", &num);
	
	if(num == 1) {
		sortName(s, count, num);	
	}
	else if(1<num && num < 7) {
		sortNum(s, count, num);
	}
	printf("===========================================\n");
	printf("=> 정렬되었습니다!\n");
	listScore(s, count, 1);
	
}
// 버블 정렬을 이용한 내림차순 문자 정렬
void sortName(Student *s, int count, int num) {
	Student temp;
	printf(" => 이름별 정렬\n");
	for(int step = 0; step<count; step++) {
		for(int i =0; i< count-step; i++) {
			if(num == 1) {
				if(strcmp(s[i].name, s[i+1].name) > 0) { // < 에서 >으로 수정 
					temp = s[i];
					s[i] = s[i+1];
					s[i+1] = temp;
				}
			}
		}
	}	
}

void sortNum(Student *s, int count, int num) {
	Student temp;
	int sum1, sum2;
	if(num == 2) printf(" => 중간 성적별 정렬\n");
	else if(num==3) printf(" => lab 성적별 정렬\n");
	else if(num ==4) printf("=> project 성정별 정렬\n");
	else if(num ==5) printf("=> 기말 성적별 정렬\n");
	else if(num ==6) printf("=> 최종 성적별 정렬\n");
	for(int step = 0; step<count; step++) {
		for(int i =0; i<count-step; i++) {
			if(num == 2) {
				if(s[i].mid<s[i+1].mid) {
					temp = s[i];
					s[i] = s[i+1];
					s[i+1] = temp;
				}
			}
			else if(num == 3) {
                                if(s[i].lab<s[i+1].lab) {
                                        temp = s[i];
                                        s[i] = s[i+1];
                                        s[i+1] = temp;
                        	}
			}
			else if(num ==4) {
                                if(s[i].project<s[i+1].project) {
                                        temp = s[i];
                                        s[i] = s[i+1];
                                        s[i+1] = temp;
                        	}
			}
			else if(num ==5 ) {
                                if(s[i].finals<s[i+1].finals) {
                                        temp = s[i];
                                        s[i] = s[i+1];
                                        s[i+1] = temp;
                        	}
			}
                        else if(num ==6 ) {
				sum1 = s[i].mid+s[i].lab+s[i].project+s[i].finals;
				sum2 = s[i+1].mid+s[i+1].lab+s[i+1].project+s[i+1].finals;
                                if(sum1<sum2) {
                                        temp = s[i];
                                        s[i] = s[i+1];
                                        s[i+1] = temp;
                                }
                        }
	
		}
	}
}	
