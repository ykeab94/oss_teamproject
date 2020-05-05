#include "product.h"
#include "manager.h"
#include <stdio.h>
#include <string.h>

int selectMenu() {
    int menu;
    while(1) {
    	printf("\n*** DB  중간 고사 성적 관리 ***\n");
    	printf("1. 성적 조회\n");
    	printf("2. 성적 기록\n");
    	printf("3. 기록 수정\n");
    	printf("4. 기록 삭제\n");
    	printf("5. 파일 저장\n");
    	printf("0. 종료\n");
    	printf("\n=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
	if(0<=menu && menu<9) return menu;
	else printf("Error: incorrect menu number.\n");
    }
}

int main() {
    Product plist[100];
    int curcount = 0;
    int count = 0, menu;
    count = loadData(plist);
    curcount = count;
    #ifdef DEBUG
	printf("--------DEBUG mode----------\n");
	printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
    #endif
    while(1) {
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1 || menu == 3 || menu == 4) {
            if(count == 0) {
                printf("데이터가 존재하지 않습니다.\n");
                continue;
            }
        }
        // Read
        if(menu == 1) {
            if(count > 0) listProd(plist, curcount);
            else printf("데이터가 없습니다.\n");
        }
        // create
        else if(menu == 2) {
            count += addProd(&plist[curcount++]);
        }
        // update
        else if(menu == 3) {
            int no = selectDataNo(plist, curcount);
            if(no == 0 || no == -1) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateProd(&plist[no-1]);
        }
        // delete
        else if(menu == 4) {
            int no = selectDataNo(plist, curcount);
            if(no == 0 || no == -1) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 : 1) ");
            scanf("%d", &deleteok);
            if(deleteok == 1) {
                if(deleteProd(&plist[no-1])) count--;
            }
            else printf("삭제되지 않았습니다.\n");
        }
        // Data save
        else if(menu == 5) {
            if(count == 0)
                printf("=> 데이터 없음!\n");
            else {
                saveData(plist, curcount);
            }
    }
}
    printf("종료됨!\n");
    return 0;
}
