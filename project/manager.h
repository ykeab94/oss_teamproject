typedef struct{
    // 학생이름
    char name[20];
    // 중간고사
    int mid;
    // lab 과제
    int lab;
    // 팀 프로젝트
    int project;
    // 기말고사
    int finals;
} Student;

// CRUD 함수 선언 + list menu 함수 구성
// 한 제품의 정보를 읽어오는 함수(listProd 함수에 포함될 예정)
void readScore(Student s);

// 원하는 제품 정보를 수정하는 함수
int updateScore(Student *s);

// 원하는 제품을 삭제하는 함수
int deleteScore(Student *s);

// 제품 리스트를 읽어오는 함수
void listScore(Student *s, int count);

// update와 delete 할 때, 번호을 물어보는 함수(updateProd, deleteProd, searchProd함수에서 사용)
int selectDataNo(Student *s, int count);

