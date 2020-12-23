#ifndef yg_h
#define yg_h
#include<stdio.h>//头文件
#include<stdlib.h>
#include<string.h>


typedef struct Basic_information
{
    char work_ID[80];
    char ID_number[80];
    char name[80];
    char gender[80];
    int age;
    int work_age;
    char department[80];
    char job[80];
    int job_ID;
    char home_number[80];
    char person_number[80];
}BI;//定义职工基本信息结构体

typedef struct Basic_wage_information
{
    int basic_wage;
    int job_wage;
    int else_wage;
    int reward;
    int wage_total;
}BW;//定义工资基础信息结构体

typedef struct Cost_information
{
    int home_cost;
    int job_insurance;
    int age_insurance;
    int person_tax;
}CI;//定义费用扣除结构体

typedef struct fee_information
{
    int water_fee;
    int electricity_fee;
    int clean_fee;
    int TV_fee;
}FI;//定义工资单数据结构体

typedef struct information
{
    BI basic;
    BW wage;
    CI cost;
    FI fee;
    struct information *prior;
    struct information *next;
}*info,infor;//定义总信息结构体


info creat_head();

int user_choose();

void sc(info p);
void pr(info p);
void new_list(info head);
int read_file(info head);

void save_file(info head);

info search_key(info head);
void search_list(info head);

void modify_list(info head);
void delete_list(info head);
void insert_list(info head);
int free_list(info head);
void count_list(info head);

#endif
