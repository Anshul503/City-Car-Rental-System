#include <stdio.h>
#include "car.h"   //ye  2nd , 3rd aur 5th header file kyu li???
#include <string.h> // used for strchr()
#include "conio2.h"
#include <time.h>
#include<stdlib.h>
void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)


        {
        fp=fopen("admin.bin","wb");
          //FILE *fp=fopen("admin.bin","wb");
            User u[2]={{"admin","abc","Nitin"},{"admin","abc","Anshul"}};  //Anshul is username and abc is it's password
            fwrite(u,sizeof(u),1,fp);
            fclose (fp);
            //printf("File Saved!");
            _getch();
        }
        else
        {
            fclose(fp);
        }

}
/*
void addEmp()
{
    FILE *fp=fopen("emp.bin","rb");
    if(fp==NULL)


        {
        fp=fopen("emp.bin","wb");
          //FILE *fp=fopen("admin.bin","wb");
            User u[2]={{"admin","abc","Nitin"},{"123","abc","Pranay"}};
            fwrite(u,sizeof(u),1,fp);
            fclose (fp);
          //  printf("File Saved!");
            _getch();
        }
        else
        {
            fclose(fp);
        }

}

*/


User * getInput()
{
 int i;
 clrscr();
 textcolor(YELLOW);
 gotoxy(32,1);
 printf("CAR RENTAL SYSTEM\n");
 for(i=1;i<80;i++)
 printf("%c",247);  //247 is the ASCII of tilde like character...
 gotoxy(32,5);
 printf("* LOGIN PANEL *");
 gotoxy(1,7);
 textcolor(LIGHTCYAN);
 for(i=1;i<80;i++)
 printf("%c",247);
 gotoxy(1,15);
 for(i=1;i<80;i++)
 printf("%c",247);
 gotoxy(60,8);
 textcolor(WHITE);
 printf("Press 0 to exit");
 gotoxy(25,10);
 textcolor(LIGHTCYAN);
 printf("Enter User Name:");
 fflush(stdin);  //Enter ko flush krega..
 textcolor(WHITE);
 static User usr;  //static bcoz we want this till the prog. exec. does not get over...
 fgets(usr.name,20,stdin);  // we have not used gets() bcoz agar wo data array ke range ke bahar padega toh crash bhi ho sakta hai and not scanf bcoz it can't read space
char *pos;
pos=strchr(usr.name,'\n');
*pos='\0';  //there will be two \0 in array ,but it will read till first occurrence of null char.
 if(strcmp(usr.name,"0")==0)
{
    textcolor(LIGHTRED);
    gotoxy(30,17);
    printf("Login Cancelled!");
    _getch();
    textcolor(YELLOW);
    return NULL;

}

gotoxy(25,11);
textcolor(LIGHTCYAN);
printf("Enter Password");
fflush(stdin);

i=0;
textcolor(WHITE);
for( ; ; )
{
 /*
    usr.pwd[i]=getch();  //HW to handle case of backspace too...
    if(usr.pwd[i]==13)  //ASCII of enter is 13
    {
        break;
    }
    printf("*");
    i++;
    */
    char ch;
   usr.pwd[i]=_getch();
    //ch=getch();
     if(usr.pwd[i]==13)  //ASCII of enter is 13
    {
        break;
    }
   else if(usr.pwd[i]==8)
      {

      //ch=getch();
        printf("\b ");
        i--;
        continue;
      }

      //  usr.pwd[i]=getch();  //HW to handle case of backspace too...
 /*   if(usr.pwd[i]==13)  //ASCII of enter is 13
    {
        break;
    }
    */
   printf("*");
    i++;
      }
usr.pwd[i]='\0';




//usr.pwd[i]='\0';


 //static bcoz we want this till the prog. exec. does not get over...
   //there will be two \0 in array ,but it will read till first occurrence of null char.
 if(strcmp(usr.pwd,"0")==0)
{
    textcolor(LIGHTRED);
    gotoxy(30,17);
    printf("Login Cancelled!");
    _getch();
    textcolor(YELLOW);
    return NULL;  //kuch na kuch return karna hai,toh address NULL.NULL return means to exit

}

return &usr;

}


int checkUserExist(User u,char*usertype)
{

    if(strcmp(u.name,"")==0 || strcmp(u.pwd,"")==0)
    {

        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("BOTH FIELDS ARE MANDATORY");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");   //itne zyada /t kyu???   , 5 se kaam ho jayega na??    aur module mein itne zyada /t hai ...see once***
        return 0;
        //gotoxy(39,10);
    }
    int found=0;
    if(!(strcmp(usertype,"admin")))  //agar match kar gya...
    {
     FILE *fp=fopen("admin.bin","rb");
    User user;
    while(fread(&user,sizeof(User),1,fp)==1)  //User structure se verify karega...
    {
        if(strcmp(u.name,user.name)==0 && strcmp(u.pwd,user.pwd)==0)
        {

            found=1;
            break;
        }

    }
    if(!found)//found==0
    {
        gotoxy(27,20);
        textcolor(LIGHTRED);
        printf("INVALID USERNAME OR PASSWORD");
        _getch();
        fclose(fp);
        return 0;
    }

  fclose(fp);

    return 1;

}

   else if(!(strcmp(usertype,"emp")))
   {
   //code for reading emp.bin  HW...

   //  int found=0;
    //if(!(strcmp(usertype,"emp")))  //agar match kar gya...

     FILE *fp=fopen("employee.bin","rb");
    User user;
    while(fread(&user,sizeof(User),1,fp)==1)  //User structure se verify karega...
    {
        if(strcmp(u.name,user.name)==0 && strcmp(u.pwd,user.pwd)==0)
        {

            found=1;
            break;
        }

    }
    if(!found)//found==0
    {
        gotoxy(27,20);
        textcolor(LIGHTRED);
        printf("INVALID USERNAME OR PASSWORD");
        _getch();
        fclose(fp);
        return 0;
    }

  fclose(fp);

    return 1;
}
   }




int adminMenu()
{
    int choice,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
        textcolor(LIGHTGREEN);
        gotoxy(35,6);
        printf("ADMIN MENU\n");
        for(i=0;i<80;i++)
        {
            printf("*");
        }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Add Employee");
    gotoxy(32,9);
printf("2. Add Car Details");
//gotoxy(32,9);

gotoxy(32,10);
printf("3. Show Employee");
gotoxy(32,11);
printf("4. Show Car Details");
gotoxy(32,12);
printf("5. Delete Employee");
gotoxy(32,13);
printf("6. Delete Car Details");
gotoxy(32,14);
printf("7. Exit");
gotoxy(32,16);
printf("Enter choice:");
textcolor(WHITE);
scanf("%d",&choice);
return choice;

}

void addEmployee()
{

    /*

    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)


        {
        fp=fopen("admin.bin","wb");
          //FILE *fp=fopen("admin.bin","wb");
            User u[2]={{"admin","abc","Nitin"},{"admin","abc","Anshul"}};
            fwrite(u,sizeof(u),1,fp);
            fclose (fp);
            printf("File Saved!");
            _getch();
        }
        else
        {
            fclose(fp);
        }


    */




   FILE *fp=fopen("employee.bin","rb");
//   User u[2]={{"admin","abc","Nitin"},{"admin","abc","Anshul"}};
  //          fwrite(u,sizeof(u),1,fp);
            /*fclose (fp);
            printf("File Saved!");
            _getch();
            */
   int id;
   char uchoice;
   char emp[10]="EMP-";
   char empid[10];
   User u,ur;
   if(fp==NULL)
   {
       fp=fopen("employee.bin","ab");
  //   User u[2]={{"admin","abc","Nitin"},{"admin","abc","Anshul"}};
    //        fwrite(u,sizeof(u),1,fp);
       id=1;
       sprintf(empid,"%d",id); //converting integer to string
       strcat(emp,empid);
       strcpy(u.userid,emp);
       strcpy(emp,"EMP-");
   }

else
{
    fp=fopen("employee.bin","ab+");
    fseek(fp,-60,SEEK_END);
    fread(&ur,sizeof(ur),1,fp);
    char sub[3];
    char str[20];
    strcpy(str,ur.userid);
    sub_str(str,sub,'-');
    id=atoi(sub);   //atoi function in C ?
    id++;
    sprintf(empid,"%d",id);
    strcat(emp,empid);
    strcpy(u.userid,emp);
    strcpy(emp,"EMP-");

}
do
{

clrscr();
gotoxy(32,2);
textcolor(LIGHTRED);
printf("CAR RENTAL APP");
textcolor(LIGHTGREEN);
int i;
gotoxy(1,3);
for(i=0;i<80;i++)
{
    printf("*");
}
textcolor(WHITE);
gotoxy(25,5);
printf("***** ADD EMPLOYEE DETAILS *****");
gotoxy(1,8);
textcolor(YELLOW);



//printf("Enter ")





printf("Enter Employee Name:");
fflush(stdin);
textcolor(WHITE);
fgets(u.name,20,stdin);  //add extra \n at the end
char *pos;
pos=strchr(u.name,'\n');
*pos='\0';
textcolor(YELLOW);
printf("Enter Employee Pwd:");
fflush(stdin);
textcolor(WHITE);
fgets(u.pwd,20,stdin);
pos=strchr(u.pwd,'\n');
*pos='\0';
textcolor(YELLOW);
fseek(fp,0,SEEK_END);
fwrite(&u,sizeof(User),1,fp);
gotoxy(30,15);
textcolor(LIGHTGREEN);
printf("EMPLOYEE ADDED SUCCESSFULLY");
printf("\n EMPLOYEE ID IS: %s",u.userid);
_getch();
gotoxy(1,20);
textcolor(LIGHTRED);
printf("Do you want to add more employee(Y/N) :");
textcolor(WHITE);
fflush(stdin);
scanf("%c",&uchoice);
id++;
sprintf(empid,"%d",id);
strcat(emp,empid);
strcpy(u.userid,emp);
strcpy(emp,"EMP-");

}
while(uchoice=='Y' || uchoice=='y');
fclose(fp);

}
void sub_str(char *str, char *sub, char c)
{
    int i,f=0,j=0;
    for(i=0;str[i]!=c;i++)  //we can remove first for loop and in second loop start from i=4...see once
    {
        f++ ;
    }
    for(i=++f; str[i]!='\0';i++); //   (initalisation) i=++f;
    {
        sub[j]=str[i];
        j++;
    }
    sub[j]='\0';
}

void viewEmployee()
{

    FILE *fp=fopen("employee.bin","rb");
    User ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf(" Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
{

    gotoxy(2,x);
    printf("%s",ur.userid);
    gotoxy(33,x);
    printf("%s",ur.name);
    gotoxy(57,x);
    printf("%s",ur.pwd);
    x++;

}
fclose(fp);
_getch();

}

int deleteEmp()
{
    FILE *fp1=fopen("employee.bin","rb");
    char empid[10];
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE EMPLOYEE RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(1,12);
    for(i=1;i<80;i++)
        printf("%c",247);
        if(fp1==NULL)
        {

            textcolor(LIGHTRED);
            printf("\nNo Employee Added Yet!");
        return -1;

        }
FILE *fp2=fopen("temp.bin","wb+");
gotoxy(10,9);
textcolor(YELLOW);
printf("Enter Employee Id to delete the record:");
textcolor(WHITE);
scanf("%s",empid);
User U;
int found=0;
while(fread(&U,sizeof(U),1,fp1)==1)
{

    if(strcmp(U.userid,empid)!=0)
    {
        fwrite(&U,sizeof(U),1,fp2);
    }
else
{
    found=1;
}
}
fclose(fp1);
if(found==1)
{
    rewind(fp2);
    fp1=fopen("employee.bin","wb");
    while(fread(&U,sizeof(U),1,fp2)==1)
    {
        fwrite(&U,sizeof(U),1,fp1);
    }
    fclose(fp1);
}
fclose(fp2);
remove("temp.bin");
return found;
}
int empMenu()
{
    int choice,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0;i<80;i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Rent a Car");
    gotoxy(32,9);
    printf("2. Booking Details");
     gotoxy(32,10);
    printf("3. Available Car Details");
    gotoxy(32,11);
    printf("4. Show All Car Details");
     gotoxy(32,12);
    printf("5. Exit");
     gotoxy(32,15);
    printf("Enter Choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;
}
int selectCarModel()
{

    int flag;
    FILE *fp=fopen("Cars.bin","rb");
    Car C;
    int choice,x=9;
    gotoxy(34,x);
    while(fread(&C,sizeof(C),1,fp)==1)
    {

        if(C.car_count>0)
        {

            printf("%d . %s",C.car_id,C.car_name);
            gotoxy(34,++x);
        }
    }
    gotoxy(34,x+2);
    printf("Enter your choice:");
    while(1)
    {

        flag=0;
        scanf("%d",&choice);
        rewind(fp);
    while(fread(&C,sizeof(C),1,fp)==1)
    {

        if(C.car_id==choice && C.car_count>0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {

        fclose(fp);
        return choice;
    }
    else
    {
        gotoxy(37,x+4);
    textcolor(LIGHTRED);
    printf("Wrong Input");
    _getch();
    gotoxy(35,x+4);
    printf("\t\t");
    gotoxy(52,x+2);
    printf("\t");
    gotoxy(52,x+2);
    textcolor(WHITE);
    }
    }
}
int isValidDate(struct tm dt)
{
    if(dt.tm_year>=2020 && dt.tm_year<=2022)
    {

        if(dt.tm_mon>=1 && dt.tm_mon<=12)
        {
if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1  || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 ||dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
       return 1;
else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4  || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11 ))
            return 1;
else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2 ))
          return 1;
else if((dt.tm_mday==29 && dt.tm_mon==2) && (dt.tm_year%400==0  || (dt.tm_year%4==0 && dt.tm_year%100!=0 )))
            return 1;
else
            return 0;

        }
        else
        {
            return 0;
        }
    }
    else{
        return 0;
    }

    /*
    if(dt2.tm_year > dt1.tm_year)  //dt2 is ending date
{
    return 1;
}

else if(dt2.tm_year == dt1.tm_year)
{
    if(dt2.tm_mon>dt1.tm_mon)
{
    return 1;
}

else if(dt2.tm_mon==dt1.tm_mon)
{
 if(dt2.tm_mday>dt1.tm_mday)
    {
        return 1;
    }
    else if(dt2.tm_mday==dt1.tm_mday)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
else
{
    return 0;
}

}
else
{
    return o;
}
}


*/





}


int iscorrectdate(struct tm dt1,struct tm dt2)
{
  /*
    if(dt.tm_year>=2020 && dt.tm_year<=2022)
    {

        if(dt.tm_mon>=1 && dt.tm_mon<=12)
        {
if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1  || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 ||dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
       return 1;
else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4  || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11 ))
            return 1;
else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2 ))
          return 1;
else if((dt.tm_mday==29 && dt.tm_mon==2) && (dt.tm_year%400==0  || (dt.tm_year%4==0 && dt.tm_year%100!=0 )))
            return 1;
else
            return 0;

        }
        else
        {
            return 0;
        }
    }
    else{
        return 0;
    }
    */
if(dt2.tm_year > dt1.tm_year)  //dt2 is ending date
{
    return ;
}

else if(dt2.tm_year == dt1.tm_year)
{
    if(dt2.tm_mon>dt1.tm_mon)
{
    return ;
}

else if(dt2.tm_mon==dt1.tm_mon)
{
 if(dt2.tm_mday>dt1.tm_mday)
    {
        return ;
    }
    else if(dt2.tm_mday==dt1.tm_mday)
    {
        return ;
    }
    else
    {
        return 0;
    }
}
else
{
    return 0;
}

}
else
{
    return 0;
}
}





void updateCarCount(int c)
{
    FILE *fp=fopen("Cars.bin","rb+");
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
{

    if(C.car_id==c)
    {

        fseek(fp,-8,SEEK_CUR);
        int cc_new=C.car_count-1;
        fwrite(&cc_new,sizeof(cc_new),1,fp);
        break;
    }
}
fclose(fp);
}
char * getCarName(int car_id)
{

    FILE *fp=fopen("Cars.bin","rb");
    static Car C;  //to stay till execution gets over
    while(fread(&C,sizeof(C),1,fp)==1)
    {

        if(C.car_id==car_id)
    {
        break;
    }
    }
    fclose(fp);
    return C.car_name;
}

void bookedCarDetails()  //isme agar dusre Employee se ye chalega toh,jis emp. ne book kari thi car uski details aa jayegi but aisa hona nhi chahiye...
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("Model\t  Cust Name\t  Pick Up\t  Drop\t\t  S_Date\t  E_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    int x=10;
    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {

        gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(13,x);
        printf("%s",CC.cust_name);
         gotoxy(27,x);
        printf("%s",CC.pick);
         gotoxy(44,x);
        printf("%s",CC.drop);
         gotoxy(58,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
         gotoxy(70,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;
    }
    fclose(fp);
    _getch();
}

int rentCar()
{

    Customer_Car_Details CC;
    char pick[30],drop[30];
    int c,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0;i<80;i++)
{
    printf("*");
}
textcolor(YELLOW);
gotoxy(32,8);
c=selectCarModel();
CC.car_id=c;
clrscr();
textcolor(LIGHTRED);
gotoxy(32,2);
printf("CAR RENTAL SYSTEM");
textcolor(LIGHTGREEN);
gotoxy(35,6);
printf("EMPLOYEE MENU\n");
for(i=0;i<80;i++)
{
    printf("*");
}
textcolor(YELLOW);
gotoxy(27,9);
printf("Enter Customer Name:");
fflush(stdin);
textcolor(WHITE);
fgets(CC.cust_name,30,stdin);
char *pos;
pos=strchr(CC.cust_name,'\n');
*pos='\0';
gotoxy(27,10);
textcolor(YELLOW);
printf("Enter Pickup Point:");
fflush(stdin);
textcolor(WHITE);
fgets(CC.pick,30,stdin);
pos=strchr(CC.pick,'\n');
*pos='\0';
gotoxy(27,11);
textcolor(YELLOW);
printf("Enter Drop Point:");
fflush(stdin);
textcolor(WHITE);
fgets(CC.drop,30,stdin);
pos=strchr(CC.drop,'\n');
*pos='\0';
gotoxy(27,12);
textcolor(YELLOW);
printf("Enter Start date (dd/m/yyyy):");
textcolor(WHITE);
do
{
    scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
    int datevalid=isValidDate(CC.sd);
    if(datevalid==0)
    {
gotoxy(27,18);
textcolor(LIGHTRED);
printf("Wrong Date");
_getch();
gotoxy(27,18);
printf("\t\t");
gotoxy(56,12);
printf("\t\t\t");
gotoxy(56,12);
textcolor(WHITE);

}
else
break;
}
while(1);
gotoxy(27,13);
textcolor(YELLOW);
printf("Enter end date (dd/m/yyyy):");
textcolor(WHITE);
do
{
    scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);


    int correctdate=iscorrectdate(CC.sd,CC.ed);

     if(correctdate==0)
    {
gotoxy(27,18);
textcolor(LIGHTRED);
printf("Please Input Corrrect Date");
_getch();
gotoxy(27,18);
printf("\t\t");
gotoxy(54,13);
printf("\t\t\t");
gotoxy(54,13);
textcolor(WHITE);
return;
}

int datevalid=isValidDate(CC.ed);
    if(datevalid==0)
    {
gotoxy(27,18);
textcolor(LIGHTRED);
printf("Wrong Date");
_getch();
gotoxy(27,18);
printf("\t\t");
gotoxy(54,13);
printf("\t\t\t");
gotoxy(54,13);
textcolor(WHITE);

}
else
break;
}
while(1);
FILE *fp;
fp=fopen("customer.bin","ab");
fwrite(&CC,sizeof(Customer_Car_Details),1,fp);
printf("\nPress any key to continue...");
_getch();
fclose(fp);
updateCarCount(c);
//bookedCarDetails();
return 1;

}

void addCarDetails()
{
   /*
   int choice,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
        textcolor(LIGHTGREEN);
        gotoxy(35,6);
        printf("ADD CAR DETAILS\n");
        for(i=0;i<80;i++)
        {
            printf("*");
        }

     */
FILE *fp=fopen("Cars.bin","rb");
int static id;
char uchoice;
char car[10]="CAR-";
char carid[10];
   Car c,cr;

/*
 gotoxy(32,2);
printf("hello");
_getch();
  */
  if(fp==NULL)
   {
//printf("Hello");
//_getch();
       fp=fopen("Cars.bin","ab");
    //Car c[1]={{"CAR-1","BMW","4","3","50000"}};
      // fwrite(c,sizeof(c),1,fp);
       id=1;
//       sprintf(carid,"%d",id); //converting integer to string
  //     strcat(car,carid);
    //   strcpy(c.car_id,car);
      // strcpy(car,"CAR-");
   c.car_id=id;
   }

else
{
//    printf("%d",sizeof(int));
//  _getch();

    fp=fopen("Cars.bin","ab+");
    fseek(fp,-66,SEEK_END);
    fread(&cr,sizeof(cr),1,fp);
  //  char sub[3];
   // char str[20];
    //strcpy(str,cr.car_id);
    //sub_str(str,sub,'-');
    //id=atoi(sub);   //atoi function in C ?
    id++;
    //sprintf(carid,"%d",id);
    //strcat(car,carid);
    //strcpy(c.car_id,car);
    //strcpy(car,"CAR-");
c.car_id=id;
}



do
{
 //  printf("%d",sizeof(int));
// _getch();


clrscr();
gotoxy(32,2);
textcolor(LIGHTRED);
printf("CAR RENTAL APP");
textcolor(LIGHTGREEN);
int i;
gotoxy(1,3);
for(i=0;i<80;i++)
{
    printf("*");
}
textcolor(WHITE);
gotoxy(25,5);
printf("***** ADD CAR DETAILS *****");
gotoxy(1,8);
textcolor(YELLOW);
printf("Enter Car Model:");
fflush(stdin);
textcolor(WHITE);
fgets(c.car_name,20,stdin);  //add extra \n at the end
char *pos;
pos=strchr(c.car_name,'\n');
*pos='\0';
textcolor(YELLOW);
//printf("\n Enter Car Capacity:");

printf("Enter Car Capacity:");
textcolor(WHITE);
scanf("%d",&c.capacity);            //capacity 0 hui toh error baad mein sambhalna.......AST
//if(c.capacity==0 ||)
textcolor(YELLOW);
printf("Enter Car Count:");
textcolor(WHITE);
scanf("%d",&c.car_count);
textcolor(YELLOW);
printf("Enter Car price for per day:");
textcolor(WHITE);
scanf("%d",&c.price);






textcolor(YELLOW);
fseek(fp,0,SEEK_END);
fwrite(&c,sizeof(Car),1,fp);
gotoxy(30,15);
textcolor(LIGHTGREEN);
printf("CAR ADDED SUCCESSFULLY");
printf("\n CAR ID IS: %d",c.car_id);
_getch();
gotoxy(1,20);
textcolor(LIGHTRED);
printf("Do you want to add more Car(Y/N) :");
textcolor(WHITE);
fflush(stdin);
scanf("%c",&uchoice);
//id++;
//sprintf(carid,"%d",id);
//strcat(car,carid);
//strcpy(c.car_id,car);
//strcpy(car,"CAR-");

}
while(uchoice=='Y' || uchoice=='y');
fclose(fp);

}
/*
void sub_str(char *str, char *sub, char c)
{
    int i,f=0,j=0;
    for(i=0;str[i]!=c;i++)  //we can remove first for loop and in second loop start from i=4...see once
    {
        f++ ;
    }
    for(i=++f; str[i]!='\0';i++); //   (initalisation) i=++f;
    {
        sub[j]=str[i];
        j++;
    }
    sub[j]='\0';
}

*/










void showCarDetails()

{

    FILE *fp=fopen("Cars.bin","rb");
     Car c,cr;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* ALL CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf(" Car ID\t\tModel\t\tCapacity\tAvailable\tPrice/Day");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);

    while(fread(&c,sizeof(c),1,fp)==1)
{

    gotoxy(3,x);
    printf("%d",c.car_id);
    gotoxy(17,x);
    printf("%s",c.car_name);
    gotoxy(38,x);
    printf("%d",c.capacity);
     gotoxy(51,x);
    printf("%d",c.car_count);
     gotoxy(66,x);
    printf("%d",c.price);
    x++;
//printf("hello");
//_getch();
}
fclose(fp);
_getch();

}



 int deleteCarModel()
{
    FILE *fp1=fopen("Cars.bin","rb");
    //char empid[10];
    int i,carid;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE CAR RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(1,12);
    for(i=1;i<80;i++)
        printf("%c",247);
        if(fp1==NULL)
        {

            textcolor(LIGHTRED);
            printf("\nNo Car Added Yet!");
        return -1;

        }
FILE *fp2=fopen("temp.bin","wb+");
gotoxy(10,9);
textcolor(YELLOW);
printf("Enter Car Id to delete the record:");
textcolor(WHITE);
scanf("%d",&carid);
Car c;
int found=0;
while(fread(&c,sizeof(c),1,fp1)==1)
{
//printf("hello");
    //if(strcmp(c.car_id,carid)!=0)   //agar match nhi hua
    if(c.car_id != carid)
    {
        fwrite(&c,sizeof(c),1,fp2);
    }
else
{
    found=1;
}
}
fclose(fp1);
if(found==1)
{
    rewind(fp2);
    fp1=fopen("Cars.bin","wb");
    while(fread(&c,sizeof(c),1,fp2)==1)
    {
        fwrite(&c,sizeof(c),1,fp1);
    }
    fclose(fp1);
}
fclose(fp2);
remove("temp.bin");
return found;
}

void checkAvailability()
{
     FILE *fp=fopen("Cars.bin","rb");
     Car c,cr;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* AVAILABLE CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf(" Car ID\t\tModel\t\tCapacity\tAvailable\tPrice/Day");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);

    while(fread(&c,sizeof(c),1,fp)==1)
{
     if(c.car_count>0)
     {


    gotoxy(3,x);
    printf("%d",c.car_id);
    gotoxy(17,x);
    printf("%s",c.car_name);
    gotoxy(38,x);
    printf("%d",c.capacity);
     gotoxy(51,x);
    printf("%d",c.car_count);
     gotoxy(66,x);
    printf("%d",c.price);
    x++;
     }
//printf("hello");
//_getch();
}
fclose(fp);
_getch();


}
 void showAllCarDetails()

{

    FILE *fp=fopen("Cars.bin","rb");
     Car c,cr;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* ALL CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf(" Car ID\t\tModel\t\tCapacity\tAvailable\tPrice/Day");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);

    while(fread(&c,sizeof(c),1,fp)==1)
{

    gotoxy(3,x);
    printf("%d",c.car_id);
    gotoxy(17,x);
    printf("%s",c.car_name);
    gotoxy(38,x);
    printf("%d",c.capacity);
     gotoxy(51,x);
    printf("%d",c.car_count);
     gotoxy(66,x);
    printf("%d",c.price);
    x++;
//printf("hello");
//_getch();
}
fclose(fp);
_getch();

}






                                   // sprintf copy non-primitive datatype to an array given by us. Ex sprintf(temp,"%d",a);
