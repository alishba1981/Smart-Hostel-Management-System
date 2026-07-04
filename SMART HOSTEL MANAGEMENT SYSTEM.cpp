#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student
{
    int id;
    char name[50];
    int room;
};

struct StudentLogin
{
    char name[50];
    char nic[20];
    char father[50];
    char address[100];
    char password[20];
};

// Function Prototypes
void addStudent();
void viewStudent();
void searchStudent();
void editStudent();
void deleteStudent();

int main()
{
    int choice;
    int adminChoice;
    int staffChoice;
    int password;

    while(1)
    {
        printf("\n===========================================");
        printf("\n  WELCOME TO SMART HOSTEL MANAGEMENT SYSTEM");
        printf("\n===========================================");

        printf("\n1. Admin");
        printf("\n2. Staff");
        printf("\n3. Student");
        printf("\n4. Exit");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\nEnter Admin Password : ");
            scanf("%d",&password);

            if(password==1234)
            {
                while(1)
                {
                    printf("\n\n===== ADMIN MENU =====");
                    printf("\n1. Add Student");
                    printf("\n2. View Students");
                    printf("\n3. Search Student");
                    printf("\n4. Edit Student");
                    printf("\n5. Delete Student");
                    printf("\n6. Exit");

                    printf("\nEnter Choice : ");
                    scanf("%d",&adminChoice);

                    if(adminChoice==1)
                        addStudent();
                        
                    else if(adminChoice==2)
                        viewStudent();

                    else if(adminChoice==3)
                        searchStudent();

                    else if(adminChoice==4)
                        editStudent();

                    else if(adminChoice==5)
                        deleteStudent();

                    else if(adminChoice==6)
                        break;

                    else
                        printf("\nInvalid Choice");
                }
            }
            else
            {
                printf("\nWrong Password");
            }
        }
       
else if(choice==2)
{
    printf("\nEnter Staff Password : ");
    scanf("%d",&password);

    if(password==1234)
    {
        while(1)
        {
            printf("\n===== STAFF MENU =====");
            printf("\n1. Add Student");
            printf("\n2. View Student");
            printf("\n3. Search Student");
            printf("\n4. Edit Student");
            printf("\n5. Delete Student");
            printf("\n6. Exit");

            printf("\nEnter Choice : ");
            scanf("%d",&staffChoice);

            if(staffChoice==1)
                addStudent();

            else if(staffChoice==2)
                viewStudent();

            else if(staffChoice==3)
                searchStudent();

            else if(staffChoice==4)
                editStudent();

            else if(staffChoice==5)
                deleteStudent();

            else if(staffChoice==6)
                break;

            else
                printf("\nInvalid Choice");
        }
    }
    else
    {
        printf("\nWrong Password");
    }
}
else if(choice==3)
{
    int studentChoice;

    printf("\n===== STUDENT MENU =====");
    printf("\n1. Sign Up");
    printf("\n2. Login");
    printf("\n3. Back");

    printf("\nEnter Choice : ");
    scanf("%d",&studentChoice);

    if(studentChoice==1)
    {
        FILE *fp;
struct StudentLogin s;

fp = fopen("signup.txt","a");

printf("Enter Name: ");
scanf("%s",s.name);

printf("Enter NIC: ");
scanf("%s",s.nic);

printf("Enter Father Name: ");
scanf("%s",s.father);

printf("Enter Address: ");
scanf("%s",s.address);

printf("Create Password: ");
scanf("%s",s.password);

fprintf(fp,"%s %s %s %s %s\n",
        s.name,
        s.nic,
        s.father,
        s.address,
        s.password);

fclose(fp);

printf("\nSignup Successful.\n");
}
    else if(studentChoice==2)
    {
       FILE *fp;
struct StudentLogin s;

char loginNIC[20];
char loginPassword[20];
int found = 0;

fp = fopen("signup.txt","r");

printf("Enter NIC: ");
scanf("%s",loginNIC);

printf("Enter Password: ");
scanf("%s",loginPassword);

while(fscanf(fp,"%s %s %s %s %s",
s.name,
s.nic,
s.father,
s.address,
s.password)!=EOF)
{
    if(strcmp(loginNIC,s.nic)==0 &&
       strcmp(loginPassword,s.password)==0)
    {
        found = 1;
        break;
    }
}

fclose(fp);

if(found)
{
    printf("\nLogin Successful\n");

int roomNumber;
int roomType;
int acOption;
int windowOption;
int bathOption;
int totalFee = 0;

printf("\nBOOK ROOM\n");

printf("Enter Room Number: ");
scanf("%d",&roomNumber);

if(roomNumber == 405)
{
    printf("Room Not Available\n");
}
else
{
    printf("Room Available\n");

    printf("\n1. Separate Room\n");
    printf("2. Shared Room\n");
    printf("Select Room Type: ");
    scanf("%d",&roomType);

    if(roomType == 1)
    {
        totalFee = totalFee + 4000;
    }
    else if(roomType == 2)
    {
        totalFee = totalFee + 2000;
    }

    printf("\n1. AC Room\n");
    printf("2. Without AC\n");
    printf("Select Option: ");
    scanf("%d",&acOption);

    if(acOption == 1)
    {
        totalFee = totalFee + 2000;
    }
   else if(acOption == 2)
    {
        totalFee = totalFee + 1000;
    } 

    printf("\n1. Window Room\n");
    printf("2. Without Window\n");
    printf("Select Option: ");
    scanf("%d",&windowOption);

    if(windowOption == 1)
    {
        totalFee = totalFee + 1000;
    }
    else if(windowOption  == 2)
    {
        totalFee = totalFee + 500;
    }
    printf("\n1. Attached Bath\n");
    printf("2. Common Bath\n");
    printf("Select Option: ");
    scanf("%d",&bathOption);

    if(bathOption == 1)
    {
        totalFee = totalFee + 1000;
    }
    else if(bathOption  == 2)
    {
        totalFee = totalFee + 500;
    }
    printf("\nROOM BOOKED SUCCESSFULLY\n");
    printf("Room Number: %d\n",roomNumber);
    printf("Total Fee: %d\n",totalFee);
	}
}
else
{
    printf("\nInvalid Login\n");
}
}
else if(choice==4)
{
    printf("\nThank You For Using Smart Hostel Management System.\n");
    break;
}
else
{
    printf("\nInvalid Choice");
}
}
return 0;
}
}
          void addStudent()
{
    struct Student s;
    FILE *fp;

    fp = fopen("student.txt","a");

    if(fp==NULL)
    {
        printf("\nFile Cannot Open.");
        return;
    }

    printf("\nEnter Student ID : ");
    scanf("%d",&s.id);

    printf("Enter Student Name : ");
    scanf("%s",s.name);

    printf("Enter Room Number : ");
    scanf("%d",&s.room);

    fprintf(fp,"%d %s %d\n",s.id,s.name,s.room);

    fclose(fp);

    printf("\nStudent Added Successfully.\n");
}  

void viewStudent()
{
    struct Student s;
    FILE *fp;

    fp = fopen("student.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Record Found.\n");
        return;
    }

    printf("\n==================================");
    printf("\nID\tName\t\tRoom");
    printf("\n==================================\n");

    while(fscanf(fp,"%d %s %d",&s.id,s.name,&s.room)!=EOF)
    {
        printf("%d\t%s\t\t%d\n",s.id,s.name,s.room);
    }

    fclose(fp);
} 
void searchStudent()
{
    struct Student s;
    FILE *fp;
    int searchID;
    int found=0;

    fp=fopen("student.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Record Found.\n");
        return;
    }

    printf("\nEnter Student ID : ");
    scanf("%d",&searchID);

    while(fscanf(fp,"%d %s %d",&s.id,s.name,&s.room)!=EOF)
    {
        if(s.id==searchID)
        {
            printf("\nStudent Found\n");
            printf("ID : %d\n",s.id);
            printf("Name : %s\n",s.name);
            printf("Room : %d\n",s.room);

            found=1;
            break;
        }
    }

    if(found==0)
    {
        printf("\nStudent Not Found.\n");
    }

    fclose(fp);
}
void editStudent()
{
    struct Student s;
    FILE *fp,*temp;

    int searchID;
    int found=0;

    fp=fopen("student.txt","r");
    temp=fopen("temp.txt","w");

    if(fp==NULL)
    {
        printf("\nNo Record Found.\n");
        return;
    }

    printf("\nEnter Student ID to Edit : ");
    scanf("%d",&searchID);

    while(fscanf(fp,"%d %s %d",&s.id,s.name,&s.room)!=EOF)
    {
        if(s.id==searchID)
        {
            found=1;

            printf("\nEnter New Name : ");
            scanf("%s",s.name);

            printf("Enter New Room Number : ");
            scanf("%d",&s.room);
        }

        fprintf(temp,"%d %s %d\n",s.id,s.name,s.room);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found)
        printf("\nStudent Record Updated Successfully.\n");
    else
        printf("\nStudent Not Found.\n");
}
void deleteStudent()
{
    struct Student s;
    FILE *fp,*temp;

    int searchID;
    int found=0;

    fp=fopen("student.txt","r");
    temp=fopen("temp.txt","w");

    if(fp==NULL)
    {
        printf("\nNo Record Found.\n");
        return;
    }

    printf("\nEnter Student ID to Delete : ");
    scanf("%d",&searchID);

    while(fscanf(fp,"%d %s %d",&s.id,s.name,&s.room)!=EOF)
    {
        if(s.id==searchID)
        {
            found=1;
        }
        else
        {
            fprintf(temp,"%d %s %d\n",s.id,s.name,s.room);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found)
        printf("\nStudent Deleted Successfully.\n");
    else
        printf("\nStudent Not Found.\n");
}

