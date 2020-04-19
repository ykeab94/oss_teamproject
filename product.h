// 21500706 지성민
typedef struct {
    // 제품명
    char item[20];
    // 중량(숫자)
    int weight;
    // 가격(숫자)
    int price;
    // 표준가격
    int st_price;
    // 별점수(1~5)
    int star;
} Product;

// 제품의 항목을 추가하는 함수
int addProd(Product *p);
// 한 제품의 정보를 읽어오는 함수(listProd 함수에 포함될 예정)
void readProd(Product s);
// 원하는 제품 정보를 수정하는 함수
int updateProd(Product *s);
// 원하는 제품을 삭제하는 함수
int deleteProd(Product *s);
// 제품 리스트를 읽어오는 함수
void listProd(Product *s, int count);
// 제품 리스트를 텍스트 파일로 저장하는 함수
void saveData(Product *s, int count);
// 텍스트 파일로 저장되어있는 제품 리스트를 불러오는 함수
int loadData(Product *s);
