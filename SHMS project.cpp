#include<stdio.h>
int main()
{
int choice;
// Admin Student Record Variables
int id;
int searchID;
int roomNo;
char Name[30];
// Staff Record Variables
int staffID;
int searchStaffID;
int salary;
int staffChoice;
char staffName[50];
int roomCheck;
char staffNIC[20];
char designation[30];
// Student Signup Variables
char studentName[50];
char nic[20];
char fatherName[50];
char address[100];
char accountNo[30];
char password[20];
// Student Login Variables
int NIC;
int Password;
int loginNIC;
int loginPassword;

int roomNumber;
int roomType;
int totalFee=0;
int portalChoice;
int paid = 0;
char block;
int floor;


printf("WELCOME SMART HOSTEL MANAGEMENT SYSTEM\n");

printf("1. Admin\n");
printf("2. Staff\n");
printf("3. Student\n");
printf("Enter your choice: ");
scanf("%d", &choice);

// Admin Section Start
 if(choice == 1)
{
int adminChoice;

printf("\nADMIN MENU\n");
printf("1. Add Student\n");
printf("2. View Student\n");
printf("3. Search Student\n");
printf("4. Edit Student\n");
printf("5. Delete Student\n");
printf("Enter your choice: ");
scanf("%d",&adminChoice);

if(adminChoice == 1)
{
printf("Enter Student ID: ");
scanf("%d",&id);
printf("Enter Student Name: ");
scanf("%s", Name);
printf("Enter Room Number: ");
scanf("%d",&roomNo);
}

else if(adminChoice == 2)
{
printf("\nStudent Record\n");
printf("ID: %d\n", id);
printf("Name: %s\n", Name);
printf("Room No: %d\n", roomNo);
}

else if(adminChoice == 3)
{
    printf("Enter Student ID to Search: ");
    scanf("%d",&searchID);

if(searchID == id)
{
printf("Student Found\n");
printf("Name: %s\n",Name);
}
else
{
printf("Student Not Found");
}
}
else if(adminChoice == 4)
{
printf("Enter ID to Edit: ");
scanf("%d",&searchID);

if(searchID == id)
    {
printf("Enter New Name: ");
scanf("%s",Name);

printf("Enter New Room No: ");
scanf("%d",&roomNo);
}
}

else if(adminChoice == 5)
{
printf("Enter ID to Delete: ");
scanf("%d",&searchID);

if(searchID == id)
{
id = 0;
roomNo = 0;

printf("Student Deleted");
}
}	
}// Admin ends here
// Staff Section Start
else if(choice == 2)
{
char username[20];
int password;
// Staff Login System
printf("\nSTAFF LOGIN\n");

printf("Enter Username: ");
scanf("%s", username);
printf("Enter Password: ");
scanf("%d", &password);

if(password == 1234)
{
printf("\nLogin Successful\n");
        
printf("\nSTAFF MENU\n");

printf("1. Add Student\n");
printf("2. View Student\n");
printf("3. Search Student\n");
printf("4. Edit Student\n");
printf("5. Delete Student\n");
printf("6. Check Room Status\n");

printf("Enter Choice: ");
scanf("%d",&staffChoice);

if(staffChoice == 1)
{
printf("Enter Student ID: ");
scanf("%d",&id);
printf("Enter Student Name: ");
scanf("%s", Name);
printf("Enter Room Number: ");
scanf("%d",&roomNo);
}

else if(staffChoice == 2)
{
printf("\nStudent Record\n");
printf("ID: %d\n", id);
printf("Name: %s\n", Name);
printf("Room No: %d\n", roomNo);
}

else if(staffChoice == 3)
{
printf("Enter Student ID to Search: ");
scanf("%d",&searchID);

if(searchID == id)
{
printf("Student Found\n");
printf("Name: %s\n",Name);
}
else
{
printf("Student Not Found");
}
}
else if(staffChoice == 4)
{
printf("Enter ID to Edit: ");
scanf("%d",&searchID);

if(searchID == id)
{
printf("Enter New Name: ");
scanf("%s",Name);

printf("Enter New Room No: ");
scanf("%d",&roomNo);
}
}

else if(staffChoice == 5)
{
printf("Enter ID to Delete: ");
scanf("%d",&searchID);

if(searchID == id)
{
id = 0;
roomNo = 0;
printf("Student Deleted");
}
}
else if(staffChoice == 6)
{
printf("Enter Room Number: ");
scanf("%d",&roomCheck);
printf("Room %d Checked\n", roomCheck);
}
}
} // Staff ends here

// Student Section Start
else if(choice == 3)
{
int studentChoice;
printf("\nSTUDENT MENU\n");
printf("1. Sign Up\n");
printf("2. Login\n");
printf("Enter Choice: ");
scanf("%d",&studentChoice);


if(studentChoice == 1)
{
printf("\nSTUDENT SIGN UP\n");
printf("Enter Name: ");
scanf("%s", studentName);
printf("Enter NIC: ");
scanf("%s", nic);
printf("Enter Father Name: ");
scanf("%s", fatherName);

printf("Enter Address: ");
scanf("%s", address);
printf("Create Password: ");
scanf("%s", password);
printf("\nSignup Successful!\n");
printf("\nStudent Details\n");
printf("Name: %s\n", studentName);
printf("NIC: %s\n", nic);
printf("Father Name: %s\n", fatherName);
printf("Address: %s\n", address);
}
else if(studentChoice == 2)
{
printf("Enter NIC: ");
scanf("%d",&loginNIC);
printf("Enter Password: ");
scanf("%d",&loginPassword);

if(loginPassword == 123)
{
    printf("Login Successful\n");

    printf("\nSTUDENT PORTAL\n");
    printf("1. Book Room\n");
    printf("2. View My Room\n");
    printf("3. Payment\n");
    printf("4. Fee Status\n");
    printf("5. Complaint\n");
    printf("6. Check Out Room\n");
    printf("7. Hostel Rules\n");

   printf("Enter Choice: ");
scanf("%d",&portalChoice);

if(portalChoice == 1)
{
    printf("Enter Room Number: ");
    scanf("%d",&roomNumber);

    if(roomNumber == 405 || roomNumber == 402)
    {
        printf("Already Booked\n");
    }
    else
    {
        printf("Available\n");

        printf("\nROOM TYPE\n");
        printf("1. Separate Room\n");
        printf("2. Shared Room\n");
        scanf("%d",&roomType);

        if(roomType == 1)
            totalFee = 4000;
        else if(roomType == 2)
            totalFee = 2000;

        int acChoice;
        printf("\nAC OPTION\n");
        printf("1. AC Room\n");
        printf("2. Non AC Room\n");
        scanf("%d",&acChoice);

        if(acChoice == 1)
            totalFee += 2000;

        int windowChoice;
        printf("\nWINDOW OPTION\n");
        printf("1. Window Room\n");
        printf("2. Without Window\n");
        scanf("%d",&windowChoice);

        if(windowChoice == 1)
            totalFee += 1000;

        int bathChoice;
        printf("\nBATHROOM OPTION\n");
        printf("1. Attached Bath\n");
        printf("2. Common Bath\n");
        scanf("%d",&bathChoice);

        if(bathChoice == 1)
            totalFee += 1500;

        printf("Enter Block: ");
        scanf(" %c",&block);

        printf("Enter Floor: ");
        scanf("%d",&floor);

        printf("\nROOM BOOKED SUCCESSFULLY\n");
        printf("Room Number: %d\n",roomNumber);
        printf("Total Fee: %d\n",totalFee);
    }
}

else if(portalChoice == 2)
{
    if(roomNumber == 0)
    {
        printf("No Room Booked\n");
    }
    else
    {
        printf("\nMY ROOM DETAILS\n");
        printf("Room Number: %d\n",roomNumber);
        printf("Block: %c\n",block);
        printf("Floor: %d\n",floor);
        printf("Room Status : Booked\n");
    }
}

else if(portalChoice == 3)
{
    int paymentChoice;

    printf("\nPAYMENT METHOD\n");
    printf("1. Cash\n");
    printf("2. Online\n");
    printf("3. Installment\n");
    printf("Enter Choice: ");
    scanf("%d",&paymentChoice);

    if(paymentChoice == 1)
    {
        printf("Cash Payment Selected\n");
        paid = 1;
    }
    else if(paymentChoice == 2)
    {
        printf("Online Payment Selected\n");
        paid = 1;
    }
    else if(paymentChoice == 3)
    {
        int installment;

        printf("Enter Number of Installments: ");
        scanf("%d",&installment);

        printf("Monthly Installment = %d\n",
               totalFee/installment);

        paid = 1;
    }
}

else if(portalChoice == 4)
{
    if(paid == 1)
        printf("Fee Paid\n");
    else
        printf("Fee Not Paid\n");
}

else if(portalChoice == 5)
{
    char complaint[100];

    printf("Enter Complaint: ");
    scanf("%s",complaint);

    printf("Complaint Submitted\n");
}

else if(portalChoice == 6)
{
    roomNumber = 0;
    totalFee = 0;

    printf("Room Checked Out Successfully\n");
    printf("Room is now Available\n");
}

else if(portalChoice == 7)
{
    printf("\nHOSTEL RULES\n");
    printf("1. No Smoking\n");
    printf("2. Maintain Cleanliness\n");
    printf("3. No Loud Music After 10 PM\n");
    printf("4. Visitors Not Allowed Without Permission\n");
}

else
{
    printf("Invalid Choice\n");
}

}

} // Student ends here
}
 return 0;
}   // Main ends here
