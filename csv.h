//zhangyanhe
#ifndef CSV
#define CSV
#define MAX_VALUE 514 // 最大值
#define MAX_COURSE 50 // 最大课程数
typedef struct course
{
    int course_id;
    char* course_name;
    char* course_property;
    int course_credit;
    int course_totalHour;
    int course_classHour;
    int course_practiceHour;
    int course_term;
};
typedef struct student
{
    char* student_name;
    int student_id;
    int student_selectedCourseId[50];
};

//函数声明
void readCourseInfo(struct course course_info[]); //接受一个数组，将文件中的课程信息读入数组中
int writeCourseInfo(struct course new_course); // 输入课程信息并将其写入文件course.csv
void readStudentInfo(struct student student_info[]); //接受一个数组，将文件中的学生信息读入数组中
int writeStudentInfo(struct student new_student); // 输入学生信息并将其写入文件student.csv

#endif