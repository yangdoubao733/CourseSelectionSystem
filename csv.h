//zhangyanhe
#ifndef CSV
#define CSV
#define MAX_VALUE 514 // ���ֵ
#define MAX_COURSE 50 // ���γ���
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

//��������
void readCourseInfo(struct course course_info[]); //����һ�����飬���ļ��еĿγ���Ϣ����������
int writeCourseInfo(struct course new_course); // ����γ���Ϣ������д���ļ�course.csv
void readStudentInfo(struct student student_info[]); //����һ�����飬���ļ��е�ѧ����Ϣ����������
int writeStudentInfo(struct student new_student); // ����ѧ����Ϣ������д���ļ�student.csv

#endif