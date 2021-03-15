#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <io.h>
//#define txet cout<<"get here!";Sleep(1000);
using namespace std;
const int N=100;
int n,z_choose;
struct node
{
        string totEh,Eh[N],Ch;
        int cntEh;
} word[N];
namespace zm
{
void choose_pattern(char a[]);
void z_add(char temp[],char into[]);
void create(char a[]);
void Custom(char a[]);
string_char(string a,char b[])
{
        for (int i=0; i<a.size(); i++)
                b[strlen(b)]=a[i];
}
char_string(char a[],string b)
{
        for (int i=0; i<strlen(a); i++)
                b[b.size()]=a[i];
}
void Color(int color)
{
        /*
           color ==  1 -> blue
                  2 -> green
                  4 -> red
                  7 -> white
         */
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | color);

}
void z_add(char temp[],char into[])
{
        for(int i=0; i<strlen(temp); i++)
                into[strlen(into)]=temp[i];
}
void create(char a[])
{
        char name[1000]="";
        printf("请输入新词库名(不含空格):");
        cin>>name;
        char txt[12]=".txt";
        z_add(txt,name);
        z_add(name,a);
        ofstream Thesaurus;
        Thesaurus.open(name);
        Thesaurus<<"第一行填单词总数\n";
        Thesaurus<<"接着一行英语单词或词组(末尾不能有空格)\n";
        Thesaurus<<"接着一行该单词的中文意思\n";
        for (int i=1; i<=6; i++) Thesaurus<<"              .\n";
        Thesaurus<<"最后一行要换行(其余详见使用手册)\n";
        Thesaurus.close();
        system(name);
        system("cls");
}
void getFiles(string path,string exd,vector<string>&files)
{
        long hFile=0;
        struct _finddata_t fileinfo;
        string pathName,exdName;
        if (0 != strcmp(exd.c_str(), "")) exdName="\\*."+exd;
        else exdName="\\*";
        if((hFile=_findfirst(pathName.assign(path).append(exdName).c_str(),&fileinfo))!=  -1)
        {
                do
                {
                        if(strcmp(fileinfo.name,".")!=0&&strcmp(fileinfo.name,"..")!=0)
                                files.push_back(fileinfo.name);
                }while(_findnext(hFile, &fileinfo)==0);
                _findclose(hFile);
        }
}
string GetExePath()     //获取当前文件夹路径
{
        char szFilePath[MAX_PATH+1]={0};
        GetModuleFileNameA(NULL,szFilePath,MAX_PATH);
        (strrchr(szFilePath,'\\'))[0]=0;
        string path=szFilePath;
        return path;
}
void open(char a[])
{
        puts("已有词库：");
        string argv=GetExePath();
        vector<string>files;
        //获取该路径下的所有.in .txt文件
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        int size=files.size(); //总共文件数
        for (int i=0; i<size; i++)
                cout<<i+1<<" ->"<<files[i].c_str()<<endl;
        Color(8); printf("%d -> back\n",size+1); Color(7);
        printf("输入数字，选择词库:");
        int choose;
        cin>>choose;
        if (choose==size+1)
        {
                return Custom(a);
        }
        if (choose>size+1 || choose<=0)
        {
                system("cls");
                puts("请输入所给范围的数字！");
                Sleep(888);
                system("cls");
                open(a);
                return;
        }
        choose-=1;
        //string -> char[]
        string tem=files[choose].c_str();
        for (int i=0; i<tem.size(); i++)
                a[i]=files[choose].c_str()[i];
        printf("已选择%s\n按任意键继续",a);
        char temp=getchar();
}

void edit_choose(char in[])
{
        system("cls");
        cout<< "已选中 "<<in<<endl;
        printf("1 ->删除\n");
        printf("2 ->编辑词库\n");
        Color(8); printf("3 ->back\n"); Color(7);
        int choose;
        cin>>choose;
        if (choose==3)
        {
                return;
        }
        if (choose>3 || choose<=0)
        {
                system("cls");
                puts("请输入所给范围的数字！");
                Sleep(888);
                system("cls");
                edit_choose(in);
                return;
        }
        if (choose==1)
        {
                system("cls");
                printf("删除中...\n");
                remove(in);
                Sleep(666);
                printf("删除成功!!!\n");
                Sleep(666);
                return;
        }
        else if (choose==2)
        {
                system("cls");
                printf("进入中...\n");
                system(in);
                Sleep(666);
                printf("编辑成功!!!\n");
                Sleep(666);
                return;
        }
}
void edit(char a[])
{
        system("cls");
        puts("无法修改系统自带词库");
        puts("仅可修改用户自行添加词库");
        puts("已有词库：");
        string argv=GetExePath();
        vector<string>files;
        //获取该路径下的所有.in .txt文件
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        int size=files.size(); //总共文件数
        for (int i=0; i<size; i++)
                cout<<i+1<<" ->"<<files[i].c_str()<<endl;
        Color(8); printf("%d -> back\n",size+1); Color(7);
        printf("输入需要编辑的词库的编号:");
        int choose;
        cin>>choose;
        if (choose==size+1)
        {
                return Custom(a);
        }
        if (choose>size+1 || choose<=0)
        {
                system("cls");
                puts("请输入所给范围的数字！");
                Sleep(888);
                system("cls");
                edit(a);
                return;
        }
        choose--;
        char tem[100]="";
        string_char(files[choose].c_str(),tem);
        edit_choose(tem);
        edit(a);
}

void Custom(char a[])
{
        system("cls");
        printf("1 ->创造新词库\n");
        printf("2 ->打开已有词库,开始练习\n");
        printf("3 ->编辑已有词库\n");
        Color(8); printf("4 ->back\n"); Color(7);
        printf("请选择:");
        char choose;
        cin>>choose;
        switch(choose)
        {
        case '1': system("cls"); create(a); z_choose=1; return;
        case '2': system("cls"); open(a); z_choose=2; return;
        case '3': system("cls"); edit(a); return;
        case '4': system("cls"); choose_pattern(a); return;
        default: system("cls"); puts("请输入所给范围的数字！"); Sleep(1000); system("cls"); Custom(a); break;
        }
}
void choose_pattern(char a[])
{
        system("cls");
        Color(8); puts("欢迎使用 writing master"); Color(7);
        Sleep(666);
        system("cls");
        puts("主页:");
        puts("1 ->开始练习自带词库");
        puts("2 ->自定义词库");
        puts("3 ->使用手册");
        Color(8); puts("4 ->退出"); Color(7);
        printf("请选择:");
        char choose;
        cin>>choose;
        switch(choose)
        {
        case '1': z_add("bx1unit",a); z_choose=0; system("cls"); return;
        case '2': system("cls"); Custom(a); return;
        case '3': system("cls"); puts("进入中..."); system("使用手册.pdf"); choose_pattern(a); return;
        case '4': exit(0);
        default: system("cls"); puts("请输入所给范围的数字！"); Sleep(1000); choose_pattern(a); break;
        }
}
}
namespace init
{
void add(char temp[],char into[])
{
        for(int i=0; i<strlen(temp); i++)
                into[strlen(into)]=temp[i];
}
void initialization()    //初始化
{
        z_choose=0;
        for (int i=0; i<=n; i++)
                for (int j=0; j<N; j++)
                        word[i].Eh[j]="",word[i].cntEh=0;
}
void main()
{
        char unit[N]="",ordinal[N]="";
        zm::choose_pattern(unit);
        if (z_choose==0)
        {
                cout<<"输入要默写的单元"<<"\n"<<unit;
                scanf("%s",ordinal);
                getchar();
                add(ordinal,unit);
                add(".in",unit);
        }
        else if (z_choose==1||z_choose==2)
        {
                char tem=getchar();
        }
        ifstream read;
        read.open(unit);
        read>>n;
        getline(read,word[0].totEh);
        for(int i=1; i<=n; i++)
                getline(read,word[i].totEh),getline(read,word[i].Ch);
        initialization();
        for(int i=1; i<=n; i++)
        {
                string tem=word[i].totEh;
                word[i].cntEh=1;
                for(int j=0; j<tem.size(); j++)
                {
                        if(tem[j]=='|') {
                                word[i].cntEh++;
                                continue;
                        }
                        word[i].Eh[word[i].cntEh]+=tem[j];
                }
        }
        system("cls");
}
}
namespace Interface
{
void Color(int color)
{
        /*
           color ==  1 -> blue
                  2 -> green
                  4 -> red
                  7 -> white
         */
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | color);

}
void WrongAnswer(int r)
{
        Color(4);
        puts("WA");
        Color(7);
        puts("正确答案:");
        for(int i=1; i<=word[r].cntEh; i++)
                cout<<word[r].Eh[i]<<endl;
        system("pause");
        system("cls");
        puts("再默一遍：");
}
void Accept()
{
        Color(2);
        puts("AC");
        Color(7);
        Sleep(666);
}
void Usual(int level,int T,int F)
{
        printf("进度: %d/%d\n",level,n);
        printf("正确率:%.1lf% (%d/%d)\n",T*100.0/(T+F),T,T+F);
        puts("输入'>>'可跳过当前单词,输入'.'结束测试");
}
}
namespace work
{
int level,flase,ture,r;
bool pick[N];
string init;
bool check()
{
        int k=0;
        for(int i=1; i<=word[r].cntEh; i++)
                if (init==word[r].Eh[i]) k=1;
        if(k) return 1;
        return 0;
}
void initialization()    //初始化
{
        level=0; flase=0; ture=0; n=0;
        for (int i=0; i<=n; i++)
                for (int j=0; j<N; j++)
                        word[i].Eh[j]="";
        for (int i=0; i<N; i++)
                pick[i]=0;
}
void Finish(bool res)
{
        system("cls");
        printf("正确率:%.1lf% (%d/%d)\n",ture*100.0/(ture+flase),ture,ture+flase);
        if (res) {puts("完成了..."),system("pause");}
        else {
                printf("已完成 %d/%d\n",level,n);
                puts("按r键回到测试,其他键回到主页");
                char ret;
                ret=getch();
                if (ret=='r') return;
        }
        initialization();
        Sleep(300);
        system("cls");
        init::main();
        return;
}
void Selection()
{
        r=rand()%n+1;
        if (n==0||level==n) {Finish(true);}
        while(pick[r]) r=rand()%n+1;
        pick[r]=1;
        Interface::Usual(level,ture,flase);
        cout<<word[r].Ch<<endl;
        getline(cin,init);
        if(!check())
        {
                pick[r]=0;
                while(!check())
                {
                        if(init==">>") {cout<<word[r].Eh[1]<<endl; Sleep(500); return;}
                        if(init==".") {Finish(false); return;}
                        flase++;
                        Interface::WrongAnswer(r);
                        Interface::Usual(level,ture,flase);
                        cout<<word[r].Ch<<endl;
                        getline(cin,init);
                }
        }
        else level++;
        ture++;
        Interface::Accept();
}
void main()
{
        srand(time(0));
        while(1)
        {
                Selection();
                system("cls");
        }
}
}
int main()
{
        system("chcp 936");
        system("cls");
        init::main();
        work::main();
}
