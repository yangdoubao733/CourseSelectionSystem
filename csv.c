//zhangyanhe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#define max_value 514 // 最大值

int writeCourseInfo(struct course new_course) // 输入课程信息并将其写入文件course.csv
{
    FILE *file;
    struct course new_course; // 创建结构体实例

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

struct course* readCourseInfo()//返回一个数组指针，指向数组首地址，数组内包含所有课程信息
{
    FILE *file;
    struct course *course_info; // 创建结构体指针数组
    int i = 0;

    // 打开CSV文件，"r"表示以只读模式打开
    file = fopen("course.csv", "r");
    if (file == NULL) {
        perror("无法打开文件");
        return NULL;
    }

    // 读取文件内容，并将其存储到结构体指针数组中
    while (1) {
        char line[max_value];
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
        strcpy(course_info[i].course_name, course_name);
        strcpy(course_info[i].course_property, course_property);
        course_info[i].course_credit = course_credit;
        course_info[i].course_totalHour = course_totalHour;
        course_info[i].course_classHour = course_classHour;
        course_info[i].course_practiceHour = course_practiceHour;
        course_info[i].course_term = course_term;
        i++;

    }
    // 关闭文件
    fclose(file);
    return course_info;
    
}


    

