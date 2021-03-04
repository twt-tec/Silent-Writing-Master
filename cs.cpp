#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int N=100;
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
        cout<<"输入要默写的单元"<<"\n"<<unit;
        scanf("%s",ordinal);
        getchar();
        add(ordinal);
        add(suffix);
        ifstream read;
        read.open(unit);
        read>>n;
        getline(read,word[0].Eh);
        for(int i=1; i<=n; i++)
                getline(read,word[i].Eh),getline(read,word[i].Ch);
        system("cls");
}
}
namespace work
{
int level,flase,ture,r;
bool pick[N];
string init;
void Interface(int flag)
{
        if(flag==1)
        {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                puts("WA");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                puts("正确答案:");
                cout<<word[r].Eh<<endl;
                system("pause");
                system("cls");
                puts("再默一遍：");
        }
        printf("进度: %d/%d\n",level,n);
        printf("正确率:%.1lf% (%d/%d)\n",ture*100.0/(ture+flase),ture,ture+flase);
        puts("输入>>可跳过当前单词");
        cout<<word[r].Ch<<endl;
}
bool check()
{
        if(init==word[r].Eh) return 1;
        return 0;
}
void Selection()
{

        r=rand()%n+1;
        while(pick[r]) r=rand()%n+1;
        pick[r]=1;
        Interface(0);
        getline(cin,init);
        if(!check())
        {
                pick[r]=0;
                while(!check())
                {
                        if(init==">>") {return;}
                        flase++;
                        Interface(1);
                        getline(cin,init);
                }
        }
        else level++;
        ture++;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        puts("AC");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        Sleep(1000);
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
        system("cls");
        init::main();
        work::main();
}
