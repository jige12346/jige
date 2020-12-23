#include"yg.h"


int main()
{
    info head;
    head=creat_head();//定义头结点
    printf("==================================================================\n");
    printf("||                      员工收入支出表                          ||\n");
    int choose,i=0;
    i=read_file(head);//检测是否存在文件,如果存在则读取进内存
    while(1)//循环让用户选择功能
    {
        choose=user_choose();
        switch(choose)
        { 
            case 1 :if(i==0) 
                    {
                        new_list(head);
                        save_file(head);
                        i=1;
                        break;
                    } //如果没有存在文件,则新建数据并保存
                    else if(i==1) //如果存在文件
                    {
                        int a;
                        a=free_list(head);//询问是否要销毁,然后重新创建
                        if(a==0) break;//不重新创建
                        else if(a==1)
                        {
                            new_list(head);
                            save_file(head);
                            break;
                        }//重新创建并保存到文件
                    }
            case 2 :if(i==0) 
                    {
                        printf("||                         你还没有进入信息表                   ||\n");
                        printf("||                           请先进入信息表                     ||\n");
                        break;
                    }//如果没有存在文件,引导至新建数据
                    else
                    {
                        modify_list(head);
                        save_file(head);
                        break;
                    }//若存在,修改数据并保存文件
            case 3 :if(i==0) 
                    {
                        printf("||                         你还没有进入信息表                   ||\n");
                        printf("||                           请先进入信息表                     ||\n");
                        break;
                    }//如果没有存在文件,引导至新建数据
                    else
                    {
                        insert_list(head);
                        save_file(head);
                        break;
                    }//若存在数据,则进行插入操作
            case 4 :if(i==0) 
                    {
                        printf("||                         你还没有进入信息表                   ||\n");
                        printf("||                           请先进入信息表                     ||\n");
                        break;
                    }//如果没有存在文件,引导至新建数据
                    else
                    {
                        delete_list(head);
                        save_file(head);
                        break;
                    }//若存在数据,则进行删除操作
            case 5 :if(i==0) 
                    {
                        printf("||                          你还没有进入信息表                  ||\n");
                        printf("||                            请先进入信息表                    ||\n");
                        break;
                    }//如果没有存在文件,引导至新建数据
                    else
                    {
                        search_list(head);
                        save_file(head);
                        break;
                    }//若存在数据,则进行查找操作
            case 6 :if(i==0) 
                    {
                        printf("||                          你还没有进入信息表                  ||\n");
                        printf("||                           请先进入信息表                     ||\n");
                        break;
                    }//如果没有存在文件,引导至新建数据
                    else
                    {
                        count_list(head);
                        break;
                    }//若存在数据,则进行统计操作
            case 0 :exit(0);//退出程序
        }
    }
    return 0 ;
}
