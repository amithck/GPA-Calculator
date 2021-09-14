//  CGPA and Percentage calculator
#include <stdio.h>
#include <stdlib.h>
int calcGP(int marks, int y);
float calcSGPA(int gp[]);
float calcPer(float s);
char calcGrade(int gp);
int m[16];

int main()
{
    int i, c, gp[16];
    char usn[10], name[20], grade[16];
    char sub[16][10] = {"18MAT11", "18PHY12", "18ELE13", "18CIV14", "18EGDL15", "18PHYL16", "18ELEL17", "18EGH18", "18MAT21", "18CHE22", "18CPS23", "18ELN24", "18MECH25", "18CHEL26", "18CPL27", "18EGH28"};
    char subName[16][50] = {"Calculus and Linear Algebra", "Engineering Physics", "Basic Electrical Engineering", "Elements of Civil Engineering and Mechanics", "Engineering Graphics", "Engineering Physics Laboratory", "Basic Electrical Engineering Laboratory", "Technical English-I", "Advanced Calculus and Numerical Methods", "Engineering Chemistry", "C Programming for Problem Solving", "Basic Electronics", "Elements of Mechanical Engineering", "Engineering Chemistry Laboratory", "C Programming Laboratory", "Technical English-II"};
    float sgpa1, per1, sgpa2, per2, cgpa, per;

    do
    {
        printf("Enter your USN : ");
        gets(usn);
        printf("Enter your name : ");
        gets(name);

        //Input Physics Cycle marks and calculate grade points
        printf("\n* Physics Cycle *\n");
        for (i = 0; i < 8; i++)
        {
            printf("Enter your %s marks: ", subName[i]);
            scanf("%d", &m[i]);
            gp[i] = calcGP(m[i], i);
            grade[i] = calcGrade(gp[i]);
        }

        //Input Chemistry Cycle marks and calculate grade points
        printf("\n* Chemistry Cycle *\n");
        for (i = 0; i < 8; i++)
        {
            printf("Enter your %s marks: ", sub[i + 8]);
            scanf("%d", &m[i + 8]);
            gp[i + 8] = calcGP(m[i + 8], (i + 8));
            grade[i + 8] = calcGrade(gp[i + 8]);
        }

        //SGPA for 1st Semester
        sgpa1 = calcSGPA(gp);
        per1 = calcPer(sgpa1);

        //SGPA for 2nd Semester
        sgpa2 = calcSGPA(gp + 8);
        per2 = calcPer(sgpa2);

        //CGPA calculation
        cgpa = (sgpa1 + sgpa2) / 2;
        per = calcPer(cgpa);

        system("clear");
        //Report Card
        printf("\n\n                                                         ****VTU RESULT***\n\n");
        printf("USN  : %s\n", usn);
        printf("Name : %s\n", name);
        printf("\n < Ist SEMESTER >   \n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%s%56s%28s%23s%29s\n", "|Subject", "|Subject Code", "|Marks Obtained", "|Grade point", "|Letter grade |");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < 8; i++)
        {
            printf("|%50s|%25s|%25d|%25d|%13c|\n", subName[i], sub[i], m[i], gp[i], grade[i]);
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("SGPA of Ist semester:%.2f\n", sgpa1);
        printf("Percentage of Ist semester:%.2f%%", per1);
        printf("\n\n\n");
        printf("\n < IInd SEMESTER >   \n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%s%56s%28s%23s%29s\n", "|Subject", "|Subject Code", "|Marks Obtained", "|Grade point", "|Letter grade |");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < 8; i++)
        {
            printf("|%50s|%25s|%25d|%25d|%13c|\n", subName[i + 8], sub[i + 8], m[i + 8], gp[i + 8], grade[i + 8]);
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("SGPA of IInd semester:%.2f\n", sgpa2);
        printf("Percentage of IInd semester:%.2f%%\n\n\n", per2);
        printf("Final CGPA:%.2f\n", cgpa);
        printf("Percentage of the first year:%.2f%%\n\n\n", per);

        printf("\nEnter 1 to calculate SGPA again. Enter 0 to exit. \n ");
        scanf("%d", &c);
        while ((getchar()) != '\n')
            ; //Clears input buffer
    } while (c == 1);
    printf("THANK YOU!\n\n");
    return 0;
}
//To calculate grade points
int calcGP(int marks, int y)
{
    int x;
    if (marks > 100)
    {
        printf("Invalid Input, please enter the marks again:");
        scanf("%d", &m[y]);
        calcGP(m[y], y);
    }
    if (marks >= 90)
        return 10;
    else if (marks >= 80)
        return 9;
    else if (marks >= 70)
        return 8;
    else if (marks >= 60)
        return 7;
    else if (marks >= 45)
        return 6;
    else if (marks >= 40)
        return 4;
    else
        return 0;
}
//To calculate grades
char calcGrade(int gp)
{
    switch (gp)
    {
    case (10):
        return 'S';
    case (9):
        return 'A';
    case (8):
        return 'B';
    case (7):
        return 'C';
    case (6):
        return 'D';
    case (4):
        return 'E';
    default:
        return 'F';
    }
}
//To calculate SGPA
float calcSGPA(int gp[])
{
    return ((gp[0] * 4 + gp[1] * 4 + gp[2] * 3 + gp[3] * 3 + gp[4] * 3 + gp[5] + gp[6] + gp[7]) / 20.0);
}
//To calculate Percentage
float calcPer(float s)
{
    return ((s - 0.75) * 10);
}
