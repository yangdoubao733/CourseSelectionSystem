//zhangyanhe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "menu.h"

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

void readCourseInfo(struct course course_info[])//接受一个数组，将文件中的课程信息读入数组中
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
        //取课程的id值
        int course_id = atoi(token);
        token = strtok(NULL, ",");
        //取课程的名称
        char course_name[100];
        strcpy(course_name, token);
        //取课程的属性
        token = strtok(NULL, ",");
        char course_property[100];
        //取课程的学分
        strcpy(course_property, token);
        token = strtok(NULL, ",");
        //取课程的总学时
        int course_credit = atoi(token);
        token = strtok(NULL, ",");
        //取课程的总学时
        int course_totalHour = atoi(token);
        token = strtok(NULL, ",");
        //取课程的上课学时
        int course_classHour = atoi(token);
        token = strtok(NULL, ",");
        //取课程的实践学时
        int course_practiceHour = atoi(token);
        token = strtok(NULL, ",");
        //取课程的学期
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
    //续尾巴，告诉数组截至,读到-1表示数组截至了。
    course_info[i].course_classHour= -1;
    course_info[i].course_practiceHour= -1;
    course_info[i].course_term= -1;
    course_info[i].course_totalHour= -1;
    course_info[i].course_credit= -1;
    course_info[i].course_property= NULL;
    course_info[i].course_name= NULL;
    course_info[i].course_id= -1;
    // 关闭文件
    fclose(file);
    
}

void readStudentInfo(struct student student_info[]) //接受一个数组，将文件中的学生信息读入数组中
    
{
    FILE *file;
    
    
    // 打开CSV文件，"r"表示以只读模式打开
    file = fopen("student.csv", "r");
    if (file == NULL) {
        perror("无法打开文件");
        menu();
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
            //取学生的id值
            token = strtok(line, ",");
            student_info[i].student_id = atoi(token);
            //取学生的姓名
            token = strtok(NULL, ",");
            student_info[i].student_name = token; 
            //取后面课程的id值
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

    // 关闭文件
    fclose(file);
    
    
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