
#ifndef CAR_RENTAL_H_INCLUDED
#define CAR_RENTAL_H_INCLUDED
#include<time.h>
struct User
{
    char userid[20];
    char pwd[20];
    char name[20];

};

struct Car
{
    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;
};

struct Customer_Car_Details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd,ed;
};

typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;


    void addAdmin();
    void addEmp();
    User* getInput();
    int CheckUserExist(User,char*);
    int adminMenu();
    void addEmployee();
    void viewEmployee();
    void addCarDetails();
    //Car* addCarDetails();
   // void showCarDetails();
    void showCarDetails();
     void showAllCarDetails();
    int deleteEmp();
    int deleteCarModel();
    void sub_str(char*,char*,char);
int empMenu();
void checkAvailability();
int rentCar();
int selectCarModel();
void updateCarCount(int);
void bookedCarDetails();
char * getCarName(int);
int isValidDate(struct tm);

iscorrectdate(struct tm,struct tm);
#endif // CAR_RENTAL_H_INCLUDED
