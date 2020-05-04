//21500706_지성민
#include "product.h"
#include <stdio.h>
#include <string.h>

// 제품의 항목을 추가하는 함수
int addProd(Product *p) {
    printf("이름은? ");
    scanf("%s", p->item);
    printf("중량은? ");
    scanf("%d", &p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("표준가격은? ");
    scanf("%d", &p->st_price);
    printf("별점수는? ");
    scanf("%d", &p->star);
    return 1;
}

// 한 제품의 정보를 읽어오는 함수(listProd 함수에 포함될 예정)
void readProd(Product s) {
    printf("%10s %8d %6d %7d    ", s.item, s.weight, s.price, s.st_price);
    for(int i =1; i<=s.star; i++) {
        printf("*");
    }
    printf("\n");
}

// 원하는 제품 정보를 수정하는 함수
int updateProd(Product *s) {
    printf("이름은? ");
    scanf("%s", s->item);
    printf("중량은? ");
    scanf("%d", &s->weight);
    printf("가격은? ");
    scanf("%d", &s->price);
    printf("표준가격은? ");
    scanf("%d", &s->st_price);
    printf("별점수는? (1~5) ");
    scanf("%d", &s->star);
    printf("=> 수정됨!\n");
    return 1;
}

// 원하는 제품을 삭제하는 함수
int deleteProd(Product *s) {
    s->weight = -1;
    s->price = -1;
    s->st_price = -1;
    s->star = -1;
    printf("=> 삭제됨!\n");
    return 1;
}

// 제품 리스트를 읽어오는 함수
void listProd(Product *s, int count) {
    printf("\nNo       Name   weight price st_price    star \n");
    printf("=================================================\n");
    for(int i =0; i<count; i++) {
        if(s[i].weight == -1) continue;
        printf("%2d ", i+1);
        readProd(s[i]);
    }
    printf("\n");
}

// 제품 리스트를 텍스트 파일로 저장하는 함수
void saveData(Product *s, int count) {
    FILE *fp;
    fp = fopen("product.txt", "wt");
    for(int i =0; i< count; i++) {
        if(s[i].weight == -1) continue;
        fprintf(fp, "%s %d %d %d %d\n", s[i].item, s[i].weight, s[i].price, s[i].st_price, s[i].star);
    }
    fclose(fp);
    printf("==> 저장됨! \n");
}

// 텍스트 파일로 저장되어있는 제품 리스트를 불러오는 함수
int loadData(Product *s) {
    FILE *fp;
    fp = fopen("product.txt", "rt");
    if(fp == NULL) {
        printf("==> 파일이 없음\n");
        return 0;
    }
    int count = 0;
    // index를 위한 count 변수를 생성.
    for(;;count++){
        fscanf(fp, "%s %d %d %d %d", s[count].item, &s[count].weight, &s[count].price, &s[count].st_price, &s[count].star);
        if(feof(fp)) break;
    }
    fclose(fp);
    printf("==> 로딩성공!!!\n");
    return count;
}
