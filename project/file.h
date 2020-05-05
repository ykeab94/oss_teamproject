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
    int final;
} Student;

// oss 점수 list를 파일로 저장하는 함수
void saveData(Student *s, int count);
// oss 점수 파일을 list로 불러오는 함수
int loadData(Student *s);
