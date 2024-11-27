//zhangyanhe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

/*
int writeCourseInfo(struct course new_course) // 输入课程信息并将其写入文件course.csv
{
    FILE *file;
    //struct course new_course; 创建结构体实例

    // 打开CSV文件，"a"表示以追加模式打开
    file = fopen("course.csv", "a");
    if (file == NULL) {
        perror("无法打开文件");
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
    // 关闭文件
    fclose(file);
    
    return 0;
}

struct course* readCourseInfo(struct course course_info[])//接受一个数组，将文件中的课程信息读入数组中,并返回指针
{
    FILE *file;
    int i = 0;

    // 打开CSV文件，"r"表示以只读模式打开
    file = fopen("course.csv", "r");
    if (file == NULL) {
        perror("无法打开文件");
        exit(0);
    }

    // 读取文件内容，并将其存储到结构体指针数组中
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
    //续尾巴，告诉数组截至,读到-1表示数组截至了。
    course_info->course_classHour= -1;
    course_info->course_practiceHour= -1;
    course_info->course_term= -1;
    course_info->course_totalHour= -1;
    course_info->course_credit= -1;
    course_info->course_property= NULL;
    course_info->course_name= NULL;
    course_info->course_id= -1;
    // 关闭文件
    fclose(file);
    return course_info;
    
}

struct student* readStudentInfo(struct student student_info[]) // 读取文件student.csv中的学生信息并返回一个数组
    
{
    FILE *file;
    
    
    // 打开CSV文件，"r"表示以只读模式打开
    file = fopen("student.csv", "r");
    if (file == NULL) {
        perror("无法打开文件");
        exit(0);
    }

    // 读取文件内容，并将其存储到结构体实例中
    char line[MAX_VALUE];
    while (1)
        {
            int i = 0;
            if (fgets(line, sizeof(line), file) == NULL) {
                    exit(0);
                }
            //取前面学生的id值和姓名
            char *token;
            token = strtok(line, ",");
            int student_id = atoi(token);
            strcpy(student_info[i].student_id, student_id);
            token = strtok(NULL, ",");
            char student_name[100];
            strcpy(student_name, token);
            strcpy(student_info[i].student_name, student_name);
            //取后面课程的id值
            int selectedCourseId[50];
            i++;
            // printf("%d,%s,%d\n", student_info[i].student_id, student_info[i].student_name, student_info[i].student_selectedCourseId[i]);
            //测试备用，ai说的；
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

    // 关闭文件
    fclose(file);

    return student_info;
    
    
}

int writeStudentInfo(struct student new_student) // 输入学生信息并将其写入文件student.csv

{
    FILE *file;

    // 打开CSV文件，"a"表示以追加模式打开
    file = fopen("student.csv", "a");
    if (file == NULL) {
        perror("无法打开文件");
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
            
    // 关闭文件
    fclose(file);
    
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

int writeCourseInfo(struct course new_course) // 输入课程信息并将其写入文件course.csv
{
    FILE *file;
    file = fopen("course.csv", "a");
    if (file == NULL) {
        perror("无法打开文件");
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
    
    fclose(file);
    return 0;
}

struct course* readCourseInfo(struct course course_info[]) // 接受一个数组，将文件中的课程信息读入数组中,并返回指针
{
    FILE *file;
    int i = 0;

    file = fopen("course.csv", "r");
    if (file == NULL) {
        perror("无法打开文件");
        exit(0);
    }

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

        course_info = (struct course*)realloc(course_info, (i + 1) * sizeof(struct course));
        if (course_info == NULL) {
            perror("内存分配失败");
            exit(1);
        }

        course_info[i].course_id = course_id;
        strcpy(course_info[i].course_name, course_name);
        strcpy(course_info[i].course_property, course_property);
        course_info[i].course_credit = course_credit;
        course_info[i].course_totalHour = course_totalHour;
        course_info[i].course_classHour = course_classHour;
        course_info[i].course_practiceHour = course_practiceHour;
        course_info[i].course_term = course_term;
        i++;
    }

    course_info = (struct course*)realloc(course_info, (i + 1) * sizeof(struct course));
    if (course_info == NULL) {
        perror("内存分配失败");
        exit(1);
    }

    // 添加结束标记
    course_info[i].course_classHour = -1;
    course_info[i].course_practiceHour = -1;
    course_info[i].course_term = -1;
    course_info[i].course_totalHour = -1;
    course_info[i].course_credit = -1;
    course_info[i].course_property[0] = '\0'; // 字符串清空
    course_info[i].course_name[0] = '\0';     // 字符串清空
    course_info[i].course_id = -1;

    fclose(file);
    return course_info;
}

struct student* readStudentInfo(struct student student_info[]) // 读取文件student.csv中的学生信息并返回一个数组
{
    FILE *file;
    
    file = fopen("student.csv", "r");
    if (file == NULL) {
        perror("无法打开文件");
        exit(0);
    }

    char line[MAX_VALUE];
    int i = 0; // 将 i 移到这里，避免每次循环都重置
    while (1) {
        if (fgets(line, sizeof(line), file) == NULL) {
            break;
        }

        char *token;
        token = strtok(line, ",");
        int student_id = atoi(token);
        sprintf(student_info[i].student_id, "%d", student_id); // 将整数转换为字符串

        token = strtok(NULL, ",");
        char student_name[100];
        strcpy(student_name, token);
        strcpy(student_info[i].student_name, student_name);

        // 读后面课程的id值
        for (int j = 0; j < 50; j++) {
            token = strtok(NULL, ",");
            if (token == NULL) {
                break;
            }
            student_info[i].student_selectedCourseId[j] = atoi(token);
        }
        student_info[i].student_selectedCourseId[50] = -1; // 课程选择数组的结束标记

        i++;
    }
    
    fclose(file);
    return student_info;
}

int writeStudentInfo(struct student new_student) // 输入学生信息并将其写入文件student.csv
{
    FILE *file;

    file = fopen("student.csv", "a");
    if (file == NULL) {
        perror("无法打开文件");
        exit(0);
    }

    fprintf(file, "%d,%s", 
            new_student.student_id, 
            new_student.student_name);
    for (int i = 0; i < 50; i++) {
        if (new_student.student_selectedCourseId[i] == -1) {
            break;
        }
        fprintf(file, ",%d", new_student.student_selectedCourseId[i]);
    }

    fclose(file);
    return 0;
}


int main()
{
    //测试用例
    struct course course_info[100];
    struct student student_info[100];
    readCourseInfo(course_info);
    readStudentInfo(student_info);
    return 0;
}