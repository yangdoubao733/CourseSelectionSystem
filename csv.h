//zhangyanhe
#ifndef CSV
#define CSV
#define MAX_VALUE 514 // ���ֵ
#define MAX_COURSE 50 // ���γ���
typedef struct course
{
    int course_id; //id
    char* course_name; //�γ���
    char* course_property; //�γ�����
    int course_credit; //ѧ��
    int course_totalHour; //��ѧʱ
    int course_classHour; //�ڿ�ʱ��
    int course_practiceHour; //ʵ��ʱ��
    int course_term; //����ѧ��
};
typedef struct student
{
    char* student_name; //ѧ������
    int student_id; //ѧ��id
    int student_selectedCourseId[50]; //��ѡ�γ�
};

//��������
int readCourseInfo(struct course course_info[]); //����һ�����飬���ļ��еĿγ���Ϣ����������
int writeCourseInfo(struct course new_course); // ����γ���Ϣ������д���ļ�course.csv
int readStudentInfo(struct student student_info[]); //����һ�����飬���ļ��е�ѧ����Ϣ����������
int writeStudentInfo(struct student new_student); // ����ѧ����Ϣ������д���ļ�student.csv

#endif