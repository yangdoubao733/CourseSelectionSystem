#include<stdio.h>
#include<string.h>
#include"csv.h"
#include"menu.h"

void searchSelectedCourse(){
    printf("请输入学生学号,返回主页请输入0:");
    int id;
    scanf("%d",&id);
    if(id == 0)menu();
    printf("请输入学生姓名:");
    char name[10];
    scanf("%s",name);
    struct course courseInfo[MAX_VALUE];
    struct student studentInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    readStudentInfo(studentInfo);
    int i=0;
    while(studentInfo[i].student_id != id){
        i++;
    }
    if(strcmp(studentInfo[i].student_name,name) != 0 ){
        printf("学号姓名不匹配，请重新输入\n");
        searchSelectedCourse();
    }
    printf("id 课程名 课程性质 学分 总学时 授课学时 实验学时 学期\n");
    for(int m=0;m<MAX_VALUE;m++){
        int courseId = studentInfo[i].student_selectedCourseId[m];
        if(courseId == -1){
            break;
        }
        for(int j=0;j<MAX_VALUE;j++){
            if(courseInfo[j].course_id == -1)break;
            if(courseInfo[j].course_id == courseId){
                printf("%d %s %s %d %d %d %d %d\n", courseId, 
                    courseInfo[j].course_name,
                    courseInfo[j].course_property, 
                    courseInfo[j].course_credit,
                    courseInfo[j].course_totalHour,
                    courseInfo[j].course_classHour,
                    courseInfo[j].course_practiceHour,
                    courseInfo[j].course_term);
                break;
            }
        }

    }
    printf("\n");
    menu();

}