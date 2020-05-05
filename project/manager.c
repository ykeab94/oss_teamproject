// CRUD 함수+list menu 함수
#include "file.h"
#include <stdio.h>
#include "manager.h"
#include <string.h>
// 한 제품의 정보를 읽어오는 함수(listProd 함수에 포함될 예정)
void readScore(Student s) {
}

// 원하는 제품 정보를 수정하는 함수
int updateScore(Student *s) {
}

// 원하는 제품을 삭제하는 함수
int deleteScore(Student *s) {
}

// 제품 리스트를 읽어오는 함수
void listScore(Student *s, int count) {
    printf("\nNo       Name   mid    lab     project     final  \n");
    printf("=================================================\n");
    for(int i =0; i<count; i++) {
        if(s[i].weight == -1) continue;
        printf("%2d ", i+1);
        readProd(s[i]);
    }
    printf("\n");
}

