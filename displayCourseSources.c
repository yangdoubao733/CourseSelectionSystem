#include <csv.h>
void displayCourseSources(struct course readCourseInfo[])
{
    while (1)
    {
        int i=0;
        if (readCourseInfo[i].course_id==-1)
        {
            break;
        }
        printf("%d %s %s %d %d %d\n", readCourseInfo[i].course_id, 
        readCourseInfo[i].course_name,
        readCourseInfo[i].course_property, 
        readCourseInfo[i].course_credit,
        readCourseInfo[i].course_totalHour,
        readCourseInfo[i].course_classHour,
        readCourseInfo[i].course_practiceHour,
        readCourseInfo[i].course_term);
        i++;
    }
    
    
}