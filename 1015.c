// 德才论 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct{  
    int ID;  
    int D;  
    int C;  
}list;  

// 结构体二级排序
// http://blog.csdn.net/yuanjilai/article/details/7348345
// 升序排列时，
// 若第一个参数指针指向的“值”大于第二个参数指针指向的“值”，则返回正；
// 若第一个参数指针指向的“值”等于第二个参数指针指向的“值”，则返回零；
// 若第一个参数指针指向的“值”小于第二个参数指针指向的“值”，则返回负。
// 降序排列时，则刚好相反。
int cmp(const void *b,const void *a){//qsort的比较函数   
    list *c=(list*)a;  // 强制类型转换
    list *d=(list*)b;  
    int ret=0;  
    if((c->C+c->D)!=(d->C+d->D))  // 总分不等
    {  
        ret=(c->C+c->D)-(d->C+d->D);  // 降序排序
        // ret=(d->C+d->D)-(c->C+c->D);  // 升序排序(注意形参先后顺序)
    }else  // 总分相等
    {  
        if(c->D!=d->D)  // 先比较德分
        {  
            ret=c->D-d->D;  // 降序排序
        }else  // 再比较才分
        {  
            ret=d->ID-c->ID;  // 降序排序
        }  
    }  
    return ret;  // 返回值必须是int
}  
  
int main()  
{  
    int N,L,H,i;  
    scanf("%d %d %d",&N,&L,&H);  // 人数，优先录取，合格
    list *type1=(list*)malloc(N*sizeof(list));  
    list *type2=(list*)malloc(N*sizeof(list));  
    list *type3=(list*)malloc(N*sizeof(list));  
    list *type4=(list*)malloc(N*sizeof(list));//四个结构数组分别存储四类学生   
    list input;  
    int t1=0,t2=0,t3=0,t4=0;  // 四类学生的数量
    for(i=0;i<N;i++)  // 根据输入的数据填入四个结构数组中
    {  
        scanf("%d %d %d",&input.ID,&input.D,&input.C);  
        if(input.D>=L&&input.C>=L)  // 最低条件是合格
        {  
            if(input.D>=H&&input.C>=H)  //德才兼尽
            {  
                type1[t1]=input;  
                t1++;  
            }else if(input.D>=H)  // 德尽才亡
            {  
                type2[t2]=input;  
                t2++;  
            }else if(input.D>=input.C)  //德才兼亡但德胜才
            {  
                type3[t3]=input;  
                t3++;  
            }else  // 德才兼亡且德输才
            {  
                type4[t4]=input;  
                t4++;  
            }  
        }     
    }  

    // 重点
    // void qsort(void*base,size_t num,size_t width,int(__cdecl*compare)(const void*,const void*));
    // 1 待排序数组首地址 2 数组中待排序元素数量 
    // 3 各元素的占用空间大小 4 指向比较函数的指针
    qsort(type1,t1,sizeof(list),cmp);  
    qsort(type2,t2,sizeof(list),cmp);  
    qsort(type3,t3,sizeof(list),cmp);  
    qsort(type4,t4,sizeof(list),cmp);//对每类学生排序   

    // 打印
    printf("%d\n",t1+t2+t3+t4);  
    for(i=0;i<t1;i++)  
    {  
        printf("%d %d %d\n",type1[i].ID,type1[i].D,type1[i].C);  
    }  
    for(i=0;i<t2;i++)  
    {  
        printf("%d %d %d\n",type2[i].ID,type2[i].D,type2[i].C);  
    }  
    for(i=0;i<t3;i++)  
    {  
        printf("%d %d %d\n",type3[i].ID,type3[i].D,type3[i].C);  
    }  
    for(i=0;i<t4;i++)  
    {  
        printf("%d %d %d\n",type4[i].ID,type4[i].D,type4[i].C);  
    }  
    return 0;  
}  
