#include"yg.h"

info creat_head()
{
    info head;
    head=(info)malloc(sizeof(infor));
    head->prior=NULL;
    head->next=NULL;
    return head;
}//初始化头结点

int user_choose()
{
    printf("||                    员工收入与支出信息表!                     ||\n");
    printf("||                     按以下数字进行选择!                      ||\n");
    printf("||       1--进入信息               2--修改信息                  ||\n");
    printf("||       3--插入信息               4--删除信息                  ||\n");
    printf("||       5--查找信息               6--统计信息                  ||\n");
    printf("||                    0--退出信息表                             ||\n");
    printf("                          你的选择:");
    int choose;
    scanf("%d",&choose);
    return choose;
}//用户选择界面

void sc(info p)
{
    printf("||                        基本信息表                            ||\n");
    printf("                     工作 ID:");
    scanf("%s",p->basic.work_ID);
    printf("                     ID 号码:");
    scanf("%s",p->basic.ID_number);
    printf("                     姓名:");
    scanf("%s",p->basic.name);
    printf("                     性别:");
    scanf("%s",p->basic.gender);
    printf("                     年龄:");
    scanf("%d",&p->basic.age);
    printf("                     工龄:");
    scanf("%d",&p->basic.work_age);
    printf("                     部门:");
    scanf("%s",p->basic.department);
    printf("                     工作:");
    scanf("%s",p->basic.job);
    printf("                     工作 ID:");
    scanf("%d",&p->basic.job_ID);
    printf("                     家庭电话:");
    scanf("%s",p->basic.home_number);
    printf("                     私人电话:");
    scanf("%s",p->basic.person_number);
    printf("||                       基本工资信息                           ||\n");
    printf("                     基本收入:");
    scanf("%d",&p->wage.basic_wage);
    printf("                     工作收入:");
    scanf("%d",&p->wage.job_wage);
    printf("                     业余收入:");
    scanf("%d",&p->wage.else_wage);
    printf("                     奖金:");
    scanf("%d",&p->wage.reward);
    printf("||                       支出信息表                             ||\n");
    printf("                     家庭支出:");
    scanf("%d",&p->cost.home_cost);
    printf("                     工作保险:");
    scanf("%d",&p->cost.job_insurance);
    printf("                     人寿保险:");
    scanf("%d",&p->cost.age_insurance);
    p->wage.wage_total=p->wage.basic_wage+p->wage.else_wage+p->wage.job_wage+p->wage.reward;
    if(p->wage.wage_total<3500) p->cost.person_tax=0;
    else p->cost.person_tax=(p->wage.wage_total-3500)*0.1;
    printf("||                       收费信息表                             ||\n");
    printf("                     水费:");
    scanf("%d",&p->fee.water_fee);
    printf("                     电费:");
    scanf("%d",&p->fee.electricity_fee);
    printf("                     清洁费:");
    scanf("%d",&p->fee.clean_fee);
    printf("                     电视费:");
    scanf("%d",&p->fee.TV_fee);
}//用户界面输入

void pr(info p)
{
    printf("||                     基本信息:                                ||\n");
    printf("                       工作 ID:%s                                 \n",p->basic.work_ID);
    printf("                       ID 号码:%s                                 \n",p->basic.ID_number);
    printf("                       姓名:%s                                    \n",p->basic.name);
    printf("                       性别:%s                                    \n",p->basic.gender);
    printf("                       年龄:%d                                    \n",p->basic.age);
    printf("                       工龄:%d                                    \n",p->basic.work_age);
    printf("                       部门:%s                                    \n",p->basic.department);
    printf("                       工作:%s                                    \n",p->basic.job);
    printf("                       工作 ID:%d                                 \n",p->basic.job_ID);
    printf("                       家庭号码:%s                                \n",p->basic.home_number);
    printf("                       私人号码:%s                                \n",p->basic.person_number);
    printf("||                     基本工资信息:                              \n");
    printf("                       基本收入:%d                                \n",p->wage.basic_wage);
    printf("                       工作收入:%d                                \n",p->wage.job_wage);
    printf("                       业余收入:%d                                \n",p->wage.else_wage);
    printf("                       奖金:%d                                    \n",p->wage.reward);
    printf("||                     消费信息:                                ||\n");
    printf("                       家庭支出:%d                                \n",p->cost.home_cost);
    printf("                       工作保险:%d                                \n",p->cost.job_insurance);
    printf("                       人寿保险:%d                                \n",p->cost.age_insurance);
    printf("                       个人税:%d                                  \n",p->cost.person_tax);
    printf("||                     收费信息:                                ||\n");
    printf("                       水费:%d                                    \n",p->fee.water_fee);
    printf("                       电费:%d                                    \n",p->fee.electricity_fee);
    printf("                       清洁费:%d                                  \n",p->fee.clean_fee);
    printf("                       电视费:%d                                  \n",p->fee.TV_fee);
}//用户界面输出

void new_list(info head)
{
    info p,q;
    p=head;
    int a;
    do
    {
        q=(info)malloc(sizeof(infor));
        printf("||                        进入信息表                        ||\n");
        sc(q);
        p->next=q;
        q->prior=p;
        p=q;
        p->next=NULL;
        printf("                         是否继续    1/0  ");
        scanf("%d",&a);
    }while(a==1);
}//建立新的数据链表

int read_file(info head)
{
    info p=head,q;
    FILE *fp;
    if((fp=fopen("initial_list.dat","rb"))==NULL) return 0;//如果读取文件为空,则没有创建过数据文件,返回0
    else
    {
        fp=fopen("initial_list.dat","rb");
        while(!feof(fp))
        {
            q=(info)malloc(sizeof(infor));
            fread(q,sizeof(infor),1,fp);
            p->next=q;
            q->prior=p;
            q->next=NULL;
            p=q;
        }
        p->prior->next=NULL;
        free(p);
        fclose(fp);
        return 1;//如果已经创建过数据文件,则读取到内存中,然后返回1
    }
}//读取文件中的数据

void save_file(info head)
{
    info p=head;
    FILE *fp;
    fp=fopen("initial_list.dat","wb+");
    while(p->next!=NULL)
    {
        p=p->next;
        fwrite(p,sizeof(infor),1,fp);
    }
    fclose(fp);
}//把内存中的数据保存到文件

info search_key(info head)
{
    info p=head;
    int choose;
    printf("关键词:\n1--工作_ID\n2--姓名\n你的选择:");
    scanf("%d",&choose);//选择以哪种关键字来查询
    if(choose==1)
    {
        char a[80];
        printf("work_ID:");
        scanf("%s",a);
        while(p->next!=NULL)
        {
            p=p->next;
            if(!strcmp(a,p->basic.work_ID)) return p;//如果查询成功,则返回指针
        }
        if(p->next==NULL) return NULL;//如果查询失败,返回空
    }
    else if(choose==2)
    {
        char b[80];
        printf("name:");
        scanf("%s",b);
        while(p->next!=NULL)
        {
            p=p->next;
            if(!strcmp(b,p->basic.name)) return p;//如果查询成功,则返回指针
        }
        if(p->next==NULL) return NULL;//如果查询失败,返回空
    }
}//用关键词语查询信息

void search_list(info head)
{
    info p=head,q;
    int choose;
    printf("||                         选择进行信息查找                     ||\n");
    printf("||      1--查找全部信息                      2--查找关键词信息  ||\n");
    printf("                       你的选择: ");
    scanf("%d",&choose);//选择那种方式查询
    if(choose==1)
    {
        printf("||                          信息表:                         ||\n");
        int a=1;
        while(p->next!=NULL)
        {
            p=p->next;
            printf("                            (%d)                                  \n",a++);
            pr(p);
        }//循环链表把链表显示出来
    }
    else if(choose==2)
    {
        q=search_key(head);//接收关键词语查询信息返回的指针
        if(q!=NULL)
        {
        printf("||                     请输入你想要搜索的信息:              ||\n");
            pr(q);//若指针不为空,显示指针指向的结构体信息
        }
        else if(q==NULL) printf("||          没有找到关键词                 ||\n");//若指针为空,显示找不到
    }
}//查询信息

void modify_list(info head)
{
    info q=head,p;
    printf("请选择你要修改的信息\n请输入你想要搜索的信息的关键词\n");
    p=search_key(q);//用关键词语查询信息查询出要修改的信息
    printf("你想要修改的信息:\n");
    pr(p);//显示出来查看修改哪一数据
    printf("你想修改哪一项数据\n");
    printf("1--工作 ID\n2--ID 号码\n3--姓名\n4--性别\n5--年龄\n6--工龄\n7--部门\n8--工作\n9--工作 ID\n10--家庭号码\n11--p个人号码\n12--基本工资\n13--工作收入\n14--业余收入\n15--奖金\n16--家庭支出\n17--工作保险\n18--人寿保险\n19--个人税\n20--水费\n21--电费\n22--清洁费\n23--电视费\n你的选择: ");
    int a;
    scanf("%d",&a);
    printf("新数据:");
    switch(a)
    {
        case 1 :scanf("%s",p->basic.work_ID);break;
        case 2 :scanf("%s",p->basic.ID_number);break;
        case 3 :scanf("%s",p->basic.name);break;
        case 4 :scanf("%s",p->basic.gender);break;
        case 5 :scanf("%d",&p->basic.age);break;
        case 6 :scanf("%d",&p->basic.work_age);break;
        case 7 :scanf("%s",p->basic.department);break;
        case 8 :scanf("%s",p->basic.job);break;
        case 9 :scanf("%d",&p->basic.job_ID);break;
        case 10:scanf("%s",p->basic.home_number);break;
        case 11:scanf("%s",p->basic.person_number);break;
        case 12:scanf("%d",&p->wage.basic_wage);break;
        case 13:scanf("%d",&p->wage.job_wage);break;
        case 14:scanf("%d",&p->wage.else_wage);break;
        case 15:scanf("%d",&p->wage.reward);break;
        case 16:scanf("%d",&p->cost.home_cost);break;
        case 17:scanf("%d",&p->cost.job_insurance);break;
        case 18:scanf("%d",&p->cost.age_insurance);break;
        case 19:scanf("%d",&p->cost.person_tax);break;
        case 20:scanf("%d",&p->fee.water_fee);break;
        case 21:scanf("%d",&p->fee.electricity_fee);break;
        case 22:scanf("%d",&p->fee.clean_fee);break;
        case 23:scanf("%d",&p->fee.TV_fee);break;
    }//修改数据
}//修改信息

void delete_list(info head)
{
    info p=head,q;
    printf("用关键词查询信息查询出要删除的信息\n");
    q=search_key(p);//用关键词语查询信息查询出要删除的信息
    if(q==NULL) printf("没有找到关键词\n");
    else if(q!=NULL)
    {
        printf("你想要删除的信息:\n");
        pr(q);
        printf("是否删除 1/0  ");//是否确定删除
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            if(q->next!=NULL)
            {
                q->prior->next=q->next;
                q->next->prior=q->prior;
                free(q);
            }
            else
            {
                q->prior->next=q->next;
                q->prior=NULL;
                free(q);
            }
        }//删除数据
    }

}//删除信息

void insert_list(info head)
{
    info p=head,q,l;
    printf("用关键词查询\n");
    q=search_key(p);//用关键词语查询要添加的信息的节点位置
    if(q==NULL) printf("没有找到关键词\n");
    else if(q!=NULL)
    {
        printf("你想要插入的信息:\n");
        pr(q);
        printf("你想要添加在节点前面还是后面 1/0  ");//询问要添加在节点前面还是后面
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            if(q->next!=NULL)
            {
                l=(info)malloc(sizeof(infor));
                sc(l);
                l->next=q->next;
                l->prior=q;
                q->next->prior=l;
                q->next=l;
            }//非最后一个的添加
            else 
            {
                l=(info)malloc(sizeof(infor));
                sc(l);
                q->next=l;
                l->prior=q;
                l->next=NULL;
            }//最后一个的添加
        }//添加后面
        else if(a==0)
        {
            l=(info)malloc(sizeof(infor));
            sc(l);
            l->prior=q->prior;
            l->next=q;
            q->prior->next=l;
            q->prior=l;
        }//添加前面
    }
}//插入信息

int free_list(info head)
{
    info p=head;
    int choose;
    printf("||                          你已经进入信息表                    ||\n");
    printf("||                       是否用新信息代替旧信息                 ||\n");
    printf("                            你的选择:(1/0)  ");
    scanf("%d",&choose);//询问是否销毁链表
    if(choose==1)
    {
        p->next->prior=NULL;
        p->next=NULL;
        printf("你的旧信息已经被删除\n");
        return 1;//销毁链表返回1
    }
    else if(choose==0) return 0;//不销毁链表返回0
}//销毁链表

void count_list(info head)
{
    info p=head;
    int choose;
    printf("你能进行以下统计\n1--年龄统计\n2--工资统计\n3--税收统计\n4--工资排序\n你的选择: ");
    scanf("%d",&choose);//选择哪种统计
    switch(choose)
    {
        case 1 :
            {
                int a=0,b=0,c=0;
                while(p->next!=NULL)
                {
                    p=p->next;
                    if((p->basic.age)<20) a++;
                    else if((p->basic.age)>=20&&(p->basic.age)<=55) b++;
                    else if((p->basic.age)>55) c++;
                }
                printf("年轻员工人数:%d\n中年员工人数:%d\n退休员工人数:%d\n",a,b,c);
                break;
            }//统计人数
        case 2 :
            {
                int basic_wage1=0,job_wage1=0,else_wage1=0,wage_total1=0;
                int basic_wage2=0,job_wage2=0,else_wage2=0,wage_total2=0;
                int basic_wage3=0,job_wage3=0,else_wage3=0,wage_total3=0;
                int d=0,e=0,f=0;
                while(p->next!=NULL)
                {
                    p=p->next;
                    if(!strcmp(p->basic.job,"human"))
                    {
                        basic_wage1=basic_wage1+p->wage.basic_wage;
                        job_wage1=job_wage1+p->wage.job_wage;
                        else_wage1=else_wage1+p->wage.else_wage;
                        wage_total1=wage_total1+basic_wage1+job_wage1+else_wage1;
                        d++;
                    }//统计工资同时统计人数
                    else if(!strcmp(p->basic.job,"finance"))
                    {
                        basic_wage2=basic_wage2+p->wage.basic_wage;
                        job_wage2=job_wage2+p->wage.job_wage;
                        else_wage2=else_wage2+p->wage.else_wage;
                        wage_total2=wage_total2+basic_wage2+job_wage2+else_wage2;
                        e++;
                    }//统计工资同时统计人数
                    else if(!strcmp(p->basic.job,"technology"))
                    {
                        basic_wage3=basic_wage3+p->wage.basic_wage;
                        job_wage3=job_wage3+p->wage.job_wage;
                        else_wage3=else_wage3+p->wage.else_wage;
                        wage_total3=wage_total3+basic_wage3+job_wage3+else_wage3;
                        f++;
                    }//统计工资同时统计人数
                }
                printf("人事部:\n人数:%d\n总基本工资:%d\n总工作收入:%d\n总业余收入:%d\n总收入:%d\n平均收入:%d\n",d,basic_wage1,job_wage1,else_wage1,wage_total1,wage_total1/d);
                printf("财政部:\n人数:%d\n总基本工资:%d\n总工作收入:%d\n总业余收入:%d\n总收入:%d\n平均收入:%d\n",e,basic_wage2,job_wage2,else_wage2,wage_total2,wage_total2/e);
                printf("技术部:\n人数:%d\n总基本o工资:%d\n总工作收入:%d\n总业余收入:%d\n总收入:%d\n平均收入:%d\n",f,basic_wage3,job_wage3,else_wage3,wage_total3,wage_total3/f);
                printf("公司总收入:%d\n",wage_total1+wage_total2+wage_total3);
                break;
            }//统计工资
        case 3 :
            {
                int total,tax,tax_total=0,tax_year;
                while(p->next!=NULL)
                {
                    p=p->next;
                    total=(p->wage.basic_wage)+(p->wage.else_wage)+(p->wage.job_wage)+(p->wage.reward);
                    if(total<3500) tax=0;
                    else tax=(total-3500)*0.1;
                    tax_total=tax_total+tax;
                }//统计一个月的税金
                tax_year=tax_total*12;//统计一年的税金
                printf("公司月税收:%d\n公司年税收:%d\n",tax_total,tax_year);
                break;
            }//统计税金
        case 4 :
            {
                info head1=creat_head();
                info head_max=creat_head();
                info n=head_max;
                info l=head_max;
                info m=head1;
                info q,max;
                info t=head;
                int a=1;
                while(t->next!=NULL)
                {
                    t=t->next;
                    q=(info)malloc(sizeof(infor));
                    *q=*t;
                    m->next=q;
                    q->prior=m;
                    q->next=NULL;
                    m=q;
                }//复制一个链表
                while(head1->next!=NULL)
                {
                    max=head1->next;
                    q=head1->next;
                    while(q!=NULL)
                    {
                        if(((max->wage.basic_wage)+(max->wage.else_wage)+(max->wage.job_wage)+(max->wage.reward))<((q->wage.basic_wage)+(q->wage.else_wage)+(q->wage.job_wage)+(q->wage.reward)))
                            max=q;
                        q=q->next;
                    }
                    m=max;//找出链表中应发工资的最大值
                    if(max->next!=NULL)
                    {
                        max->prior->next=max->next;
                        max->next->prior=max->prior;
                    }
                    else
                    {
                        max->prior->next=max->next;
                        max->prior=NULL;
                    }
                    n->next=m;
                    m->prior=n;
                    m->next=NULL;
                    n=m;//将最大值的数据依次接入链表头节点
                }
                free(head1);
                while(l->next!=NULL)
                {
                    l=l->next;
                    printf("                            (%d)                                  \n",a++);
                    pr(l);
                }//把排序后的链表显示出来
                head_max->next->prior=NULL;
                head_max->next=NULL;//销毁排序后链表
                break;
            }//按应发工资排序
    }
}//统计

