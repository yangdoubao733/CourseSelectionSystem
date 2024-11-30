//zhangyanhe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "menu.h"

int writeCourseInfo(struct course new_course) // ����γ���Ϣ������д���ļ�course.csv
{
    FILE *file;
    //struct course new_course; �����ṹ��ʵ��

    // ��CSV�ļ���"a"��ʾ��׷��ģʽ��
    file = fopen("course.csv", "a");
    if (file == NULL) {
        perror("�޷����ļ�");
        return 1;
    }
    fprintf(file, "%d,%s,%s,%d,%d,%d,%d,%d\n", 
        new_course.course_id, 
        new_course.course_name, 
        new_course.course_property, 
        new_course.course_credit, 
        new_course.course_totalHour, 
        new_course.course_classHour, 
        new_course.course_practiceHour, 
        new_course.course_term);
    // �ر��ļ�
    fclose(file);
    
    return 0;
}

void readCourseInfo(struct course course_info[])//����һ�����飬���ļ��еĿγ���Ϣ����������
{
    FILE *file;
    int i = 0;

    // ��CSV�ļ���"r"��ʾ��ֻ��ģʽ��
    file = fopen("course.csv", "r");
    if (file == NULL) {
        perror("�޷����ļ�");
        exit(0);
    }

    // ��ȡ�ļ����ݣ�������洢���ṹ��ָ��������
    while (1) {
        char line[MAX_VALUE];
        if (fgets(line, sizeof(line), file) == NULL) {
            break;
        }
        char *token;
        token = strtok(line, ",");
        //ȡ�γ̵�idֵ
        int course_id = atoi(token);
        token = strtok(NULL, ",");
        //ȡ�γ̵�����
        char course_name[100];
        strcpy(course_name, token);
        //ȡ�γ̵�����
        token = strtok(NULL, ",");
        char course_property[100];
        //ȡ�γ̵�ѧ��
        strcpy(course_property, token);
        token = strtok(NULL, ",");
        //ȡ�γ̵���ѧʱ
        int course_credit = atoi(token);
        token = strtok(NULL, ",");
        //ȡ�γ̵���ѧʱ
        int course_totalHour = atoi(token);
        token = strtok(NULL, ",");
        //ȡ�γ̵��Ͽ�ѧʱ
        int course_classHour = atoi(token);
        token = strtok(NULL, ",");
        //ȡ�γ̵�ʵ��ѧʱ
        int course_practiceHour = atoi(token);
        token = strtok(NULL, ",");
        //ȡ�γ̵�ѧ��
        int course_term = atoi(token);
        //course_info = (struct course*)realloc(course_info, (i+1)*sizeof(struct course));
        course_info[i].course_id = course_id;
        course_info[i].course_name = course_name;
        course_info[i].course_property = course_property;
        course_info[i].course_credit = course_credit;
        course_info[i].course_totalHour = course_totalHour;
        course_info[i].course_classHour = course_classHour;
        course_info[i].course_practiceHour = course_practiceHour;
        course_info[i].course_term = course_term;
        i++;

    }
    //��β�ͣ������������,����-1��ʾ��������ˡ�
    course_info[i].course_classHour= -1;
    course_info[i].course_practiceHour= -1;
    course_info[i].course_term= -1;
    course_info[i].course_totalHour= -1;
    course_info[i].course_credit= -1;
    course_info[i].course_property= NULL;
    course_info[i].course_name= NULL;
    course_info[i].course_id= -1;
    // �ر��ļ�
    fclose(file);
    
}

void readStudentInfo(struct student student_info[]) //����һ�����飬���ļ��е�ѧ����Ϣ����������
    
{
    FILE *file;
    
    
    // ��CSV�ļ���"r"��ʾ��ֻ��ģʽ��
    file = fopen("student.csv", "r");
    if (file == NULL) {
        perror("�޷����ļ�");
        menu();
    }

    // ��ȡ�ļ����ݣ�������洢���ṹ��ʵ����
    char line[MAX_VALUE];
    while (1)
        {
            int i = 0;
            if (fgets(line, sizeof(line), file) == NULL) {
                    exit(0);
                }
            //ȡǰ��ѧ����idֵ������
            char *token;
            //ȡѧ����idֵ
            token = strtok(line, ",");
            student_info[i].student_id = atoi(token);
            //ȡѧ��������
            token = strtok(NULL, ",");
            student_info[i].student_name = token; 
            //ȡ����γ̵�idֵ
            for (int j = 0; j < MAX_COURSE; j++)
            {
                int temp;
                token = strtok(NULL, ",");
                token = strtok(NULL, ",");
                temp = atoi(token);

                if (token == NULL)
                {
                    break;
                }
                
                selectedCourseId[j] = temp;
            }
            i++;

        }

    // �ر��ļ�
    fclose(file);
    
    
}

int writeStudentInfo(struct student new_student) // ����ѧ����Ϣ������д���ļ�student.csv

{
    FILE *file;

    // ��CSV�ļ���"a"��ʾ��׷��ģʽ��
    file = fopen("student.csv", "a");
    if (file == NULL) {
        perror("�޷����ļ�");
        exit(0);
    }

    fprintf(file, "%d,%s", 
            new_student.student_id, 
            new_student.student_name);
            for (int i = 0; i < 50; i++)
            {
                if (new_student.student_selectedCourseId[i] == -1)
                {
                    break;
                }
                fprintf(file, ",%d", new_student.student_selectedCourseId[i]);
            }
            
    // �ر��ļ�
    fclose(file);
    
    return 0;
}