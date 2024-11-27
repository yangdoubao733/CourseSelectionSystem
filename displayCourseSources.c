void displayCourseSources(struct course* readCourseInfo)
{
    for (int i = 0; i < 50; i++)
    {
        if (readCourseInfo[i].course_id == -1)
        {
            break;
        }
        printf("Course ID: %d\n", readCourseInfo[i].course_id)
    }
    
}