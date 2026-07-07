#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 345

typedef struct{
    char id[20];
    char name[50];
    char department[50];
    char semester[20];
    float cgpa;
    int attendance;
}Student;

Student students[MAX_STUDENTS];
int total=0;

void saveRecords();
void loadRecords();


void flushInput(){
    while(getchar()!='\n');
}

void addStudent(){
    if(total>=MAX_STUDENTS){
        printf("\nStorage Full\n");
        return;
    }

    flushInput();

    printf("\nStudent ID: ");
    fgets(students[total].id, 20, stdin);
    students[total].id[strcspn(students[total].id, "\n")] = 0;

    for(int i=0; i<total; i++){
        if(strcmp(students[i].id, students[total].id) == 0){
            printf("\nID Already Exists\n");
            return;
        }
    }

    printf("Student Name: ");
    fgets(students[total].name,50,stdin);
    students[total].name[strcspn(students[total].name,"\n")]=0;

    printf("Department: ");
    fgets(students[total].department,50,stdin);
    students[total].department[strcspn(students[total].department,"\n")]=0;

    printf("Semester: ");
fgets(students[total].semester,20,stdin);
students[total].semester[strcspn(students[total].semester,"\n")] = 0;

if(strcmp(students[total].semester,"1st") == 0)
{
    students[total].cgpa = 0.00;
    printf("Newly Admitted Student. CGPA Set To 0.00\n");
}
else
{
    printf("CGPA: ");
    scanf("%f",&students[total].cgpa);
    flushInput();

    if(students[total].cgpa < 0.0 || students[total].cgpa > 4.0)
    {
        printf("\nInvalid CGPA! Must Be Between 0.0 and 4.0\n");
        return;
    }
}

    printf("Attendance Percentage: ");
    scanf("%d",&students[total].attendance);
    flushInput();

    if(students[total].attendance<0 || students[total].attendance>100){
        printf("\nInvalid Attendance, Must Be Between 0 and 100\n");
        return;
    }

           total++;
          saveRecords();
           printf("\nRecord Added Successfully\n");
}

void saveRecords()
{
    FILE *fp = fopen("students.dat", "wb");

    if(fp == NULL)
    {
        printf("\nError Saving File!\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, fp);
    fwrite(students, sizeof(Student), total, fp);

    fclose(fp);
}

void loadRecords()
{
    FILE *fp = fopen("students.dat", "rb");

    if(fp == NULL)
        return;

    fread(&total, sizeof(int), 1, fp);
    fread(students, sizeof(Student), total, fp);

    fclose(fp);
}

void deleteStudent() {
    char search_id[20];
    int index = -1;

    flushInput();

    printf("\nEnter Student ID to Delete: ");
    fgets(search_id, 20, stdin);
    search_id[strcspn(search_id, "\n")] = 0;

    for(int i = 0; i < total; i++) {
        if(strcmp(students[i].id, search_id) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("\nStudent Not Found\n");
        return;
    }

    for(int i = index; i < total - 1; i++) {
        students[i] = students[i + 1];
    }

    total--;
       saveRecords();
    printf("\nStudent Deleted Successfully\n");
}

void searchStudent(){
    int opt;
    int found=0;

    flushInput();
    printf("\n1. Search by ID");
    printf("\n2. Search by Name");
    printf("\nEnter Choice: ");
    scanf("%d",&opt);
    flushInput();

    if(opt==1){
        char search_id[20];

        printf("\nEnter Student ID: ");
        fgets(search_id, 20, stdin);
        search_id[strcspn(search_id, "\n")] = 0;

        for(int i=0; i<total; i++){
            if(strcmp(students[i].id, search_id) == 0){
                found=1;
                printf("\nID: %s",students[i].id);
                printf("\nName: %s",students[i].name);
                printf("\nDepartment: %s",students[i].department);
                printf("\nSemester: %s",students[i].semester);
                printf("\nCGPA: %.2f",students[i].cgpa);
                printf("\nAttendance: %d%%\n",students[i].attendance);
            }
        }
    }
    else if(opt==2){
        char search_name[50];

        printf("\nEnter Name: ");
        fgets(search_name, 50, stdin);
        search_name[strcspn(search_name, "\n")] = 0;

        for(int i=0; i<total; i++){
            if(strstr(students[i].name, search_name) != NULL){
                found=1;
                printf("\nID: %s",students[i].id);
                printf("\nName: %s",students[i].name);
                printf("\nDepartment: %s",students[i].department);
                printf("\nSemester: %s",students[i].semester);
                printf("\nCGPA: %.2f",students[i].cgpa);
                printf("\nAttendance: %d%%\n",students[i].attendance);
            }
        }
    }
    else{
        printf("\nInvalid Choice\n");
        return;
    }

    if(!found)
        printf("\nRecord Not Found\n");
}

void displayStudentsRecord(){
    if(total==0){
        printf("\nNo Records Available\n");
        return;
    }

    printf("\n==\n");
    printf("%-10s %-20s %-15s %-10s %-6s %-6s\n","ID","Name","Department","Semester","CGPA","Att%");
    printf("==\n");

    for(int i=0; i<total; i++){
        printf("%-10s %-20s %-15s %-10s %-6.2f %-6d\n",
            students[i].id,
            students[i].name,
            students[i].department,
            students[i].semester,
            students[i].cgpa,
            students[i].attendance);
    }

    printf("\n");
    printf("Total Students: %d\n",total);
}

void manageStudentInformation(){
    char search_id[20];
    int index=-1;

    flushInput();
    printf("\nEnter ID to Update: ");
    fgets(search_id, 20, stdin);
    search_id[strcspn(search_id, "\n")] = 0;

    for(int i=0; i<total; i++){
        if(strcmp(students[i].id, search_id) == 0){
            index=i;
            break;
        }
    }

    if(index==-1){
        printf("\nStudent Not Found\n");
        return;
    }

    printf("\nCurrent Info:");
    printf("\nName: %s",students[index].name);
    printf("\nDepartment: %s",students[index].department);
    printf("\nSemester: %s",students[index].semester);
    printf("\nCGPA: %.2f",students[index].cgpa);
    printf("\nAttendance: %d%%\n",students[index].attendance);

    printf("\n1. Update Name");
    printf("\n2. Update Department");
    printf("\n3. Update Semester");
    printf("\n4. Update CGPA");
    printf("\n5. Update Attendance");
    printf("\n6. Update All");
    printf("\nEnter Choice: ");

    int opt;
    scanf("%d",&opt);
    flushInput();

    switch(opt){
        case 1:
            printf("New Name: ");
            fgets(students[index].name,50,stdin);
            students[index].name[strcspn(students[index].name,"\n")]=0;
            printf("\nUpdated Successfully\n");
            break;
        case 2:
            printf("New Department: ");
            fgets(students[index].department,50,stdin);
            students[index].department[strcspn(students[index].department,"\n")]=0;
            printf("\nUpdated Successfully\n");
            break;
        case 3:
            printf("New Semester: ");
            fgets(students[index].semester,20,stdin);
            students[index].semester[strcspn(students[index].semester,"\n")]=0;
            printf("\nUpdated Successfully\n");
            break;
        case 4:
            printf("New CGPA: ");
            scanf("%f",&students[index].cgpa);
            flushInput();
            printf("\nUpdated Successfully\n");
            break;
        case 5:
            printf("New Attendance: ");
            scanf("%d",&students[index].attendance);
            flushInput();
            printf("\nUpdated Successfully\n");
            break;
        case 6:
            printf("New Name: ");
            fgets(students[index].name,50,stdin);
            students[index].name[strcspn(students[index].name,"\n")]=0;

            printf("New Department: ");
            fgets(students[index].department,50,stdin);
            students[index].department[strcspn(students[index].department,"\n")]=0;

            printf("New Semester: ");
            fgets(students[index].semester,20,stdin);
            students[index].semester[strcspn(students[index].semester,"\n")]=0;

            printf("New CGPA: ");
            scanf("%f",&students[index].cgpa);
            flushInput();

            printf("New Attendance: ");
            scanf("%d",&students[index].attendance);
            flushInput();

            printf("\nUpdated Successfully\n");
            saveRecords();
            break;
        default:
            printf("\nInvalid Choice\n");
    }
}

int main(){
    int choice;
    
    loadRecords();
	
    do{
        printf("\n    UNIVERSITY MANAGEMENT SYSTEM ");
        printf("\n1. Add Student");
         printf("\n2. Delete Student");
        printf("\n3. Search Student");
        printf("\n4. Display Student record");
        printf("\n5. Manage Student Information");
        printf("\n6. Exit");
        printf("\nSelect Option: ");
        scanf("%d",&choice);

        switch(choice){
    case 1: addStudent(); break;
    case 2: deleteStudent(); break;
    case 3: searchStudent(); break;
    case 4: displayStudentsRecord(); break;
    case 5: manageStudentInformation(); break;
    case 6: printf("\nExiting...\n"); break;
    default: printf("\nInvalid Choice\n");
}

    }while(choice!=6);

    return 0;
}


