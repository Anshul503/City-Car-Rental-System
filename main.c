#include <stdio.h>
#include <stdlib.h>  //ye kyu liya??
#include"conio2.h"
#include "car.h"  //isme addAdmin() ka declaration hai...
int main()
{
    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    _getch();
    textcolor(YELLOW);
    addAdmin();
   // addEmp();
    User *usr;
    int result;
    int choice,type,i;
    while(1)
    {

        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");  //upper line
        gotoxy(1,8);
        textcolor(YELLOW);
        for(i=0;i<80;i++)
            printf("*");

    //lower line
    gotoxy(1,17);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(32,10);
    textcolor(YELLOW);
    printf("1.ADMIN");
    gotoxy(32,12);
    printf("2.EMPLOYEE");
    gotoxy(32,14);
    textcolor(WHITE);
    int k;
    printf("Select your role:");
    do
    {
        scanf("%d",&type);
        k=0;
        if(type==1)
        {
            //code for handling admin login
        do
        {
            usr=getInput();
            if(usr!=NULL)
            {

                                   //code for validating userid and password
          k=checkUserExist(*usr,"admin");
           }


            else
            {
                break;
            }
        }while(k==0);

        if(k==1)
        {
            gotoxy(30,14);
            textcolor(LIGHTGREEN);
            printf("Login Accepted");
            gotoxy(1,20);
            textcolor(WHITE);
            printf("Press any key to continue");
            _getch();
            while(1)
            {
                clrscr();
                choice=adminMenu();
                if(choice==7)
                {
                    clrscr();
                    break;

                    }
                    switch(choice)
                    {
                    case 1:
                        clrscr();
                        addEmployee();
                        break;

                    case 2:
                        clrscr();
                        addCarDetails();

                        break;

                    case 3:
                      clrscr();
                      viewEmployee();

                      break;
                    case 4:
                        clrscr();
                        showCarDetails();
                      //  _getch();
                        break;

                    case 5:
                        clrscr();
                        int result=deleteEmp();
                        if(result==0)
                        {
                            gotoxy(15,14);
                            textcolor(LIGHTRED);
                            printf("Sorry!,No employee found with the given Employee ID");
                            textcolor(WHITE);
                            printf("\n\nPress any key to go back to the main menu");
                            _getch();
                        }
                        else if(result==1)
                            {

                                gotoxy(25,14);
                                textcolor(LIGHTGREEN);
                                printf("Record Deleted Successfully");
                                textcolor(WHITE);
                                printf("\n\nPress any key to go back to the main menu");
                                _getch();
                            }


                        break;
                    case 6:
                         clrscr();
                        int res=deleteCarModel();
                        if(res==0)
                        {
                            gotoxy(15,14);
                            textcolor(LIGHTRED);
                            printf("Sorry!,No Car found with the given Car ID");
                            textcolor(WHITE);
                            printf("\n\nPress any key to go back to the main menu");
                            _getch();
                        }
                        else if(res==1)
                            {

                                gotoxy(25,14);
                                textcolor(LIGHTGREEN);
                                printf("Record Deleted Successfully");
                                textcolor(WHITE);
                                printf("\n\nPress any key to go back to the main menu");
                                _getch();
                            }
                        break;

                    default:
                        printf("Incorrect Choice:");
                        _getch();
                    }

            }
        }



        }
        else if(type==2)
        {

            //code for handling employee login
       do
       {

           usr=getInput();
           if(usr!=NULL)
           {
               k=checkUserExist(*usr,"emp");
           }
           else
           {
               break;
           }
       }while(k==0);
       if(k==1)
       {

            gotoxy(30,14);
            textcolor(LIGHTGREEN);
            printf("Login Accepted");
            gotoxy(1,20);
            textcolor(WHITE);
            printf("Press any key to continue");
            _getch();
            while(1)
            {
                clrscr();
                choice=empMenu();
                if(choice==5)
                {
                    clrscr();
                    break;
                }
                switch(choice)
                {

                case 1:
                    clrscr();
                    int j;
                    do
                    {
                    j=rentCar();
                    if(j==0)
                        printf("Booking Cancelled\n Try Again");
                    _getch();
                }while(j==0);
                _getch();
                    break;

                case 2:
                    clrscr();
                    bookedCarDetails();
                    _getch();
                    break;

                case 3:
                    clrscr();
                      checkAvailability();
                    break;

                case 4:
                    clrscr();
                    showAllCarDetails();
                    break;
                default:
                    printf("Incorrect choice:");
                }
       }

        }
        }
        else
        {
            textcolor(YELLOW);
            gotoxy(30,20);
            printf("Invalid User Type");
            _getch();
            gotoxy(30,20);
            printf("\t\t\t");// \t 8 char. ka space dega...yaha ye Invalid msg. remove krega isliye 3 \t
            gotoxy(50,14);  //ye position isliye to remove previous value which was given by the user...therefore 1 \t
            printf("\t");  //** ye kyu lagaya?? jab pichla remove hi nhi ho rha toh??
            gotoxy(50,14);
            textcolor(WHITE);
        }


    }

    while(type!=1 && type!=2);

    }
    return 0;
}
