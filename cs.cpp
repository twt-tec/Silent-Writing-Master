#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int N=200;
int wa[N];
int n;
struct node
{
        string Eh,Ch;
} word[N];
namespace init
{
char unit[N]="bx1unit",ordinal[N],suffix[N]=".in";
void add(char temp[])
{
        for(int i=0; i<strlen(temp); i++)
                unit[strlen(unit)]=temp[i];
}
void main()
{
        printf("输入要默写的单元\nbx1unit");
        scanf("%s",ordinal);
        add(ordinal);
        add(suffix);
        ifstream read;
        read.open(unit);
        read>>n;
        for(int i=1; i<=n; i++)
                read>>word[i].Eh>>word[i].Ch;
        system("cls");
}
}
namespace zm
{

void Color(unsigned short X,unsigned short Y)
{
        HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hCon,X|Y);
}
}
namespace work
{
int level,flase,ture;
bool pick[N];
void Selection()
{
        string init;
        bool k=1;
        int r=rand()%n+1;
        while(pick[r]) r=rand()%n+1;
        pick[r]=1;
FLAG:
        printf("进度: %d/%d\n",level,n);
        printf("正确率:%.1lf% (%d/%d)\n",ture*100.0/(ture+flase),ture,ture+flase);
        puts("输入>>可跳过当前单词");
        if(wa[r]) {
                zm::Color(0,6);
                cout<<
                        wa[r]<<endl;
        }
        cout<<word[r].Ch<<endl;
        zm::Color(15,15);
        cin>>init;
        if(init==">>") {pick[r]=0; return;}
        if(init==word[r].Eh)
        {
                zm::Color(0,2);
                puts("√");
                zm::Color(15,15);
                Sleep(800);
        }
        else
        {
                zm::Color(0,4);
                puts("×");
                zm::Color(15,15);
                puts("正确答案:");
                cout<<word[r].Eh<<endl;
                wa[r]++;
                system("pause");
                system("cls");
                puts("再默一遍：");
                k=0;
                flase++;
                goto FLAG;
        }
        if(!k) pick[r]=0;
        else level++;
        ture++;
}
void main()
{
        srand(time(0));
        while(level!=n)
        {
                Selection();
                system("cls");
        }
        system("cls");
        printf("正确率:%.1lf% (%d/%d)\n",level*100.0/(ture+flase),ture,ture+flase);
        puts("完成了。。。");
        system("pause");
}
}
int main()
{
        system("chcp 936");
        init::main();
        work::main();
}
