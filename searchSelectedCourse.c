#include<stdio.h>
#include<string.h>
#include"csv.h"
#include"menu.h"

void searchSelectedCourse(){
    printf("������ѧ��ѧ��,������ҳ������0");
    int id;
    scanf("%d",&id);
    if(id == 0)menu();
    printf("������ѧ������");
    char name[10];
    gets(name);
    struct course courseInfo[MAX_VALUE];
    struct student studentInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    readStudentInfo(studentInfo);
    int i=0;
    while(studentInfo[i].student_id != id){
        i++;
    }
    if(strcmp(studentInfo[i].student_name,name) != 0 ){
        printf("ѧ��������ƥ�䣬����������");
        searchSelectedCourse();
    }
    printf("id �γ��� �γ����� ѧ�� ��ѧʱ �ڿ�ѧʱ ʵ��ѧʱ ѧ��");
    for(int m=0;m<MAX_VALUE;m++){
        int courseId = studentInfo[i].student_selectedCourseId[m];
        if(courseId == -1){
            break;
        }
        for(int j=0;j<MAX_VALUE;j++){
            if(courseInfo[j].course_id == courseId){
                printf("%d %s %s %d %d %d\n", courseInfo[i].course_id, 
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
    menu();

}