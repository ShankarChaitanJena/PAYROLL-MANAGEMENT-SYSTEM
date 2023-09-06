// Payroll Magement System
#include <stdio.h>
#include <string.h>

struct Employ
{
    int slno;
    char emp_name[50];
    char adress[50];
    char phn[13];
    char id[50];
    float salary;
} e;

FILE *fptr;
// welcome
void welcom()
{
    printf("\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t                                                                                                  \n");
    printf("\t\t\t\t\t\t\t                                                                                                  \n");
    printf("\t\t\t\t\t\t\t                                   PAYROLL MANAGEMENT                                             \n");
    printf("\t\t\t\t\t\t\t                                        SYSTEM                                                    \n");
    printf("\t\t\t\t\t\t\t                           _____________________________________                                  \n");
    printf("\t\t\t\t\t\t\t                                                                                                  \n");
    printf("\t\t\t\t\t\t\t------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t www.creativecollege.in \n");
    printf("\t\t\t\t\t\t\t------------------------------------------------------------------------------------------------\n");
    getch();
    system("cls");
    return 0;
}

// Show All record
void Show_rec()
{
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t Show All Records ");

    printf("\n  %-20s %-20s %-30s %-30s %-30s %s\n\n", "Serial Number", "ID", "Name", "Phone No.", "Adress", "salary");

    fptr = fopen("Employ.txt", "rb");

    while (fread(&e, sizeof(e), 1, fptr) == 1)
    {
        printf("\n  %-20d %-20s %-30s %-30s %-30s %f\n\n", e.slno, e.id, e.emp_name, e.phn, e.adress, e.salary);
    }

    fclose(fptr);

    getch();
    system("cls");
}

// Add employ
void Add_employ()
{
    system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t <--Add Employ-->>\n");

    fptr = fopen("Employ.txt", "ab");

    printf("\n\n\n\t\t\t\t\t Enter Sl.No.:");
    scanf("%d", &e.slno);

    printf("\n\n\t\t\t\t\t Enter Employ ID. :");
    fflush(stdin);
    gets(e.id);

    printf("\n\n\t\t\t\t\t Enter Full Name :");
    fflush(stdin);
    gets(e.emp_name);

    printf("\n\n\t\t\t\t\t Enter Employ Phone No. : ");
    fflush(stdin);
    gets(e.phn);

    printf("\n\n\t\t\t\t\t Enter Employ Adress : ");
    fflush(stdin);
    gets(e.adress);

    printf("\n\n\t\t\t\t\t Enter Employ sallary : ");
    scanf("%f", &e.salary);

    fwrite(&e, sizeof(e), 1, fptr);

    printf("\n\n\n\n\t\t\t\t\t\t SUCCESSFULLY\n");

    fclose(fptr);
    getch();
}
// print slip
void print_slip()
{
    system("cls");
    int n, i, f = 0;
    printf("\n\t\t\t\t\tEnter sl.no : ");
    scanf("%d", &n);

    fptr = fopen("Employ.txt", "rb");
    if (fptr == NULL)
    {
        printf("File error");
        exit(1);
    }

    while (fread(&e, sizeof(e), 1, fptr) == 1)
    {
        if (n == e.slno)
        {
            printf("\n\n\t\t\t\t Selial No.: %d", e.slno);
            printf("\n\n\t\t\t\t Employ ID : %s ", e.id);
            printf("\n\n\t\t\t\t Name : %s", e.emp_name);
            printf("\n\n\t\t\t\t Phone No. : %s", e.phn);
            printf("\n\n\t\t\t\t Salary : %f", e.salary);
        }
        else
        {
            printf("re-enter");
        }
    }

    fclose(fptr);
    getch();
    system("cls");
}
//update employ
void update()
{
    system("cls");
    int n, f = 0;
    FILE *ptr;
    printf("\n\t\t\t\t\tEnter the update persion Sl. No. : ");
    scanf("%d", &n);

    fptr = fopen("Employ.txt", "rb");
    ptr = fopen("temp.txt", "wb");
    while (fread(&e, sizeof(e), 1, fptr) == 1)
    {
        if (n == e.slno)
        {
            printf("\n\n\t\t\t\t Selial No.: %d", e.slno);
            printf("\n\n\t\t\t\t Employ ID : %s ", e.id);
            printf("\n\n\t\t\t\t Name : %s", e.emp_name);
            printf("\n\n\t\t\t\t Phone No. : %s", e.phn);
            printf("\n\n\t\t\t\t Salary : %f", e.salary);

            printf("\n\n\n\t\t\t\t\t Enter Sl.No.:");
            scanf("%d", &e.slno);

            printf("\n\n\t\t\t\t\t Enter Employ ID. :");
            fflush(stdin);
            gets(e.id);

            printf("\n\n\t\t\t\t\t Enter Full Name :");
            fflush(stdin);
            gets(e.emp_name);

            printf("\n\n\t\t\t\t\t Enter Employ Phone No. : ");
            fflush(stdin);
            gets(e.phn);

            printf("\n\n\t\t\t\t\t Enter Employ Adress : ");
            fflush(stdin);
            gets(e.adress);

            printf("\n\n\t\t\t\t\t Enter Employ sallary : ");
            scanf("%f", &e.salary);

            fwrite(&e, sizeof(e), 1, ptr);

            printf("\n\n\n\n\t\t\t\t\t\t SUCCESSFULLY\n");
            
            f=1;
        }
        else
        {
            fwrite(&e, sizeof(e), 1, ptr);
        }
    }
    if (f = 1)
    {
        printf("\n\n\n\t\t\t\t\t Record updated ");
    }
    else
    {
        printf("\n\n\n\t\t\t\t\t Record updated faild");
    }

    fclose(ptr);
    fclose(fptr);

    remove("Employ.txt");
    rename("temp.txt", "Employ.txt");
    getch();
    system("cls");
}

void Manage_employ()
{
    system("cls");
    int ch;
    while (1)
    {
        printf("\n\n\t\t\t\t\t   EMPLOYEE PAYROLL SYSTEM \n");
        printf("\n\t\t\t\t\t*****CHOOSE YOUR OPTION*****\n");
        printf("\n\n\n\t\t\t\t\t1) SHOW ALL RECORDS\n");
        printf("\n\t\t\t\t\t2) ADD NEW EMPLOYEE RECORD\n");
        printf("\n\t\t\t\t\t3) PRINT THE SALARY SLIP\n");
        printf("\n\t\t\t\t\t4) UPDATE EMPLOYEE RECORD\n");
        printf("\n\t\t\t\t\t5) EXIT\n");
        printf("\n\n\t\t\t\t\t\t\t Choose any number ->>>");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        system("cls");
            Show_rec();
            break;
        case 2:
            Add_employ();
            break;
        case 3:
            print_slip();
            break;
        case 4:
            update();
            break;

        case 5:
            exit(0);
            break;
        }
    }
    getch();
    system("cls");
}

int main()
{
    welcom();
    char id[20]="creative";
    char pwd[20]="creat@123";
    char tid[20],tpwd[20];
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t LOGIN \n\n\n\n");
    while (1)
    {
   
    printf("\n\t\t\t\t\tEnter your ID : ");
    fflush(stdin);
    gets(tid);

    printf("\n\t\t\t\t\tEnter your POSSWORD : ");
    fflush(stdin);
    gets(tpwd);

        if (strcmp(tid, id) == 0)
        {
            if (strcmp(tpwd, pwd) == 0)
            {
                Manage_employ();
            }
            else
            {
                printf("\n\n\t\t\t\t\tEnter Again");
            }
        }
    }
    fclose(fptr);
    return 0;

    return 0;
}