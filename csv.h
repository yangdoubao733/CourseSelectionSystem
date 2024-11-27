//zhangyanhe
#ifndef CSV
#define CSV
#define MAX_VALUE 514 // 最大值
typedef struct course
{
    int course_id;
    char* course_name;
    char course_property;
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



struct course* readCourseInfo(); //返回一个数组，
int writeCourseInfo(struct course new_course); //输入一个数组，将课程写入文件course.csv
struct student readStudentInfo(); //返回一个数组包含所有学生
int writeStudentInfo(); //将学生信息写入文件student.csv

#endif