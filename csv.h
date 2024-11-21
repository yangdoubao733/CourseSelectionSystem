#ifndef CSV
#define CSV

struct course
{
    int id;
    char name;
    char property;
    int credit;
    int classHour;
    int practiceHour;
    int term;
};
struct student
{
    char name;
    int id;
    int selectedCourseId;
};



struct course readCourseInfo(); //返回一个数组，包含所有课程
int writeCourseInfo(); //输入一个数组，将课程写入文件course.csv
struct student readStudentInfo(); //返回一个数组包含所有学生
int writeStudentInfo(); //将学生信息写入文件student.csv

#endif