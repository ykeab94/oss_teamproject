#include "product.h"
#include <stdio.h>
#include "manager.h"
#include <string.h>
// 다중 데이터 처리 때 사용
// update와 delete 할 때, 번호을 물어보는 함수(updateProd, deleteProd, searchProd함수에서 사용)
int selectDataNo(Product *s, int count) {
    #ifdef DEBUG
	printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
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
