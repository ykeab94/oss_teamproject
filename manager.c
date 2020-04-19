// 21500706 지성민
#include "product.h"
#include <stdio.h>
#include "manager.h"
#include <string.h>

// 다중 데이터 처리 때 사용
// update와 delete 할 때, 번호을 물어보는 함수(updateProd, deleteProd, searchProd함수에서 사용)
int selectDataNo(Product *s, int count) {
    #ifdef DEBUG
        print("debug[manager.c]: %s %s %s %d\n",__DATE__, __TIME__, __FILE__, __LINE__);
    #endif
    int no;
    listProd(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);

    if(s[no-1].weight == -1 && s[no-1].price == -1 && s[no-1].st_price == -1 && s[no-1].star == -1) {
        printf("이미 삭제된 데이터입니다.\n");
        return -1;
    }

    return no;
}
// 이름으로 제품을 검색할 수 있는 함수
void searchName(Product *s, int count) {
    int scount = 0;
    char search[20];
    printf("원하는 이름은? ");
    scanf("%s", search);

    printf("\n      Name   weight price st_price    star \n");
    printf("=================================================\n");
    for(int i =0; i < count; i++) {
        if(s[i].weight == -1) continue;
        if(strstr(s[i].item, search)) {
            readProd(s[i]);
            scount++;
        }
    }
    if(scount == 0) printf("==> 검색결과 없음!!!\n");
}
// 가격으로 제품을 검색할 수 있는 함수
// 플러스마이너스 오차 500원
void searchPrice(Product *s, int count) {
    int scount = 0;
    int search = 0;
    printf("원하시는 가격대는? ");
    scanf("%d", &search);

    printf("\n      Name   weight price st_price    star \n");
    printf("=================================================\n");
    for(int i =0; i < count; i++) {
        if(s[i].weight == -1) continue;
        if(search-500 <= s[i].price && s[i].price <= search+500) {
            readProd(s[i]);
            scount++;
        }
    }
    if(scount == 0) printf("==> 검색결과 없음!!!\n");
}
