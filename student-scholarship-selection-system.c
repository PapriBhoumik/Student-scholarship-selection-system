#include<stdio.h>

int student_ID()
{
    int id;
    printf("ID Number: ");
    scanf("%d", &id);
    return id;
}
float Attendance_Percentage()
{   
    float attendance;
    printf("Attendance in percentage: ");
    scanf("%f", &attendance);
    return attendance;
}
float Exam_Marks()
{
    float marks;
    printf("Total marks achieved in Scholarship exam: ");
    scanf("%f", &marks);
    return marks;
}
int annual_Income(int incomeAmount)
{
    int incomePoints;
    if (incomeAmount <= 100000) 
    incomePoints = 100;
    else if (incomeAmount <= 250000) 
    incomePoints = 70;
    else if (incomeAmount <= 500000) 
    incomePoints = 40;
    else 
    incomePoints = 10;
    return incomePoints;
}
int category (int choice)
{
    int categoryPoints;
    if (choice == 1) 
    categoryPoints = 100;
    else if (choice == 2) 
    categoryPoints = 70;
    else 
    categoryPoints = 40;
    return categoryPoints;
}
float Calculate_Final_Score(int incomePoints,int categoryPoints,float marks,float attendance)
{
    float finalScore;
    finalScore = (incomePoints * 0.40) + (categoryPoints * 0.20) + (marks * 0.30) + (attendance * 0.10);
    return finalScore;
}
int main()
{
    int totalStudents, quota, i, j;

    printf("Enter the number of students applying: ");
    scanf("%d", &totalStudents);

    printf("Enter the number of scholarships available : ");
    scanf("%d", &quota);

    int studentID[totalStudents];
    float finalScore[totalStudents];

    for (i = 0; i < totalStudents; i++)
    {
        float attendance,marks, income;
        int incomePoints, categoryPoints, choice;

        printf("\n** REGISTRATION FOR STUDENT %d **\n", i + 1);

        studentID[i] = student_ID();
        attendance = Attendance_Percentage();
        marks = Exam_Marks();

        printf("Annual Income: ");
        scanf("%f", &income);
        incomePoints = annual_Income(income);

        printf("Category (1:SC/ST, 2:OBC, 3:Gen): ");
        scanf("%d", &choice);
        categoryPoints = category(choice);

        finalScore[i] = Calculate_Final_Score(incomePoints, categoryPoints, marks, attendance);
    }

    for (i = 0; i < totalStudents - 1; i++)
    {
        for (j = 0; j < totalStudents - i - 1; j++)
        {
            if (finalScore[j] < finalScore[j + 1])
            {
                float Score = finalScore[j];
                finalScore[j] = finalScore[j + 1];
                finalScore[j + 1] = Score;

                int ID = studentID[j];
                studentID[j] = studentID[j + 1];
                studentID[j + 1] = ID;
            }
        }
    }
    printf("\n--- SELECTED CANDIDATES ---\n");
    for (i = 0; i < quota && i < totalStudents; i++)
    {
        printf("Rank %d \n ID: %d \n Score: %.2f\n", i + 1, studentID[i], finalScore[i]);
    }
    printf("\n--- WAITING LIST (TOP 5) ---\n");
    for (i = quota; i < quota + 5 && i < totalStudents; i++)
    {
        printf("Waitlist %d \n ID: %d \n Score: %.2f\n", (i - quota) + 1, studentID[i], finalScore[i]);
    }
    return 0;
}