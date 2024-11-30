//zhangyanhe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"


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
        int course_id = atoi(token);
        token = strtok(NULL, ",");
        char course_name[100];
        strcpy(course_name, token);
        token = strtok(NULL, ",");
        char course_property[100];
        strcpy(course_property, token);
        token = strtok(NULL, ",");
        int course_credit = atoi(token);
        token = strtok(NULL, ",");
        int course_totalHour = atoi(token);
        token = strtok(NULL, ",");
        int course_classHour = atoi(token);
        token = strtok(NULL, ",");
        int course_practiceHour = atoi(token);
        token = strtok(NULL, ",");
        int course_term = atoi(token);
        course_info = (struct course*)realloc(course_info, (i+1)*sizeof(struct course));
        course_info[i].course_id = course_id;
        sprintf(course_info[i].course_name, "%s", course_name);
        sprintf(course_info[i].course_property, "%s", course_property);
        course_info[i].course_credit = course_credit;
        course_info[i].course_totalHour = course_totalHour;
        course_info[i].course_classHour = course_classHour;
        course_info[i].course_practiceHour = course_practiceHour;
        course_info[i].course_term = course_term;
        i++;

    }
    //��β�ͣ������������,����-1��ʾ��������ˡ�
    course_info->course_classHour= -1;
    course_info->course_practiceHour= -1;
    course_info->course_term= -1;
    course_info->course_totalHour= -1;
    course_info->course_credit= -1;
    course_info->course_property= NULL;
    course_info->course_name= NULL;
    course_info->course_id= -1;
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
        exit(0);
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
            token = strtok(line, ",");
            int student_id = atoi(token);
            strcpy(student_info[i].student_id, student_id);
            token = strtok(NULL, ",");
            char student_name[100];
            strcpy(student_name, token);
            strcpy(student_info[i].student_name, student_name);
            //ȡ����γ̵�idֵ
            int selectedCourseId[50];
            i++;
            // printf("%d,%s,%d\n", student_info[i].student_id, student_info[i].student_name, student_info[i].student_selectedCourseId[i]);
            //���Ա��ã�ai˵�ģ�
            for (int j = 0; j < 50; j++)
            {
                int temp;
                token = strtok(NULL, ",");
                temp = atoi(token);
                if (token == NULL)
                {
                    break;
                }
                
                selectedCourseId[j] = temp;
            }


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