//zhangyanhe
#ifndef CSV
#define CSV
#define MAX_VALUE 514 // 最大值
#define MAX_COURSE 50 // 最大课程数
typedef struct course
{
    int course_id; //id
    char* course_name; //课程名
    char* course_property; //课程性质
    int course_credit; //学分
    int course_totalHour; //总学时
    int course_classHour; //授课时长
    int course_practiceHour; //实验时长
    int course_term; //开课学期
};
typedef struct student
{
    char* student_name; //学生名字
    int student_id; //学生id
    int student_selectedCourseId[50]; //已选课程
};

//函数声明
int readCourseInfo(struct course course_info[]); //接受一个数组，将文件中的课程信息读入数组中
int writeCourseInfo(struct course new_course); // 输入课程信息并将其写入文件course.csv
int readStudentInfo(struct student student_info[]); //接受一个数组，将文件中的学生信息读入数组中
int writeStudentInfo(struct student new_student); // 输入学生信息并将其写入文件student.csv

#endif