typedef struct {
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
}Student;

// CRUD 함수 선언 + list menu 함수 구성
// 한 제품의 정보를 읽어오는 함수(listScore 함수에 포함될 예정)
int readScore(Student s, int isResult);

// 학생의 정보를 추가하는 함수
int addScore(Student *s);

// 원하는 학생의 점수를 수정하는 함수
int updateScore(Student *s);

// 원하는 학생의 정보를 삭제하는 함수
int deleteScore(Student *s);

// 학생별 OSS 점수 리스트를 읽어오는 함수
void listScore(Student *s, int count, int isResult);

// update와 delete 할 때, 번호을 물어보는 함수(updateScore, deleteScore, searchScore함수에서 사용)
int selectDataNo(Student *s, int count);

void printStd();

//학생성적의 등급을 매기는 함수
char gradeScore();

void searchName(Student *s, int count);

void searchGrade(Student *s, int count);

