//4.5
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <io.h>
//#define txet cout<<"get here!";Sleep(1000);
using namespace std;
const int N=600;
int n;
struct node
{
        string totEh,Eh[N],Ch;
        int cntEh;
} word[N];
namespace twy
{
typedef struct Frame
{
        COORD position[2];
        int flag;
}Frame;

void SetPos(COORD a)
{
        HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(out, a);
}

void SetPos(int i, int j)
{
        COORD pos={i, j};
        SetPos(pos);
}
/*=============== 画面 ===============*/

void drawRow(int x, int y1, int y2, char ch)    //把第x行，[y1, y2] 之间的坐标填充为 ch
{
        SetPos(y1,x);
        for(int i=0; i<=(y2-y1+1); i++)
                printf("%c",ch);
}
void Draw_opt(int size,string s[])
{
        SetPos(2,6);
        cout<<">>";
        for(int i=1; i<=size; i++)
        {
                SetPos(5,2*i+4);
                cout<<i<<". "<<s[i];
        }
}
void Draw_opt(int size,vector<string> s)
{
        SetPos(2,6);
        cout<<">>";
        for(int i=1; i<=size; i++)
        {
                SetPos(5,2*i+4);
                cout<<i<<". "<<s[i-1];
        }
}
void Draw(int n)
{
        switch (n)
        {
        case -1:    //====初始化
        {
                system("cls");
                SetPos(15, 0);
                printf("默 写 大 师");
                SetPos(15, 2);
                printf("按'w'和's'选择,回车确定");
                drawRow(1, 0, 40, '-');
                drawRow(3, 0, 40, '-');
                puts("");
                break;
        }
        }
}
int drawp(int l,int r,int &j,int m)
{
        int x=getch();
        if(x==-32) x=getch();
        SetPos(2,2*j+4);
        printf("  ");
        if(x=='w'|| x=='W' || x==72)
        {
                j--;
                if(j==l-1) j=r;
                SetPos(2,2*j+m);
                printf(">>");
        }
        else if(x=='s'|| x=='S'|| x==80)
        {
                j++;
                if(j==r+1) j=l;
                SetPos(2,2*j+m);
                printf(">>");
        }
        else if(x==13)//谁再用'k'，谁死马
        {
                Draw(-1);
                return j;
        }
        else
        {
                SetPos(2,2*j+4);
                printf(">>");
        }
        return -1;
}
}
using namespace twy;
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
        getchar();
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
string GetExePath()       //获取当前文件夹路径
{
        char szFilePath[MAX_PATH+1]={0};
        GetModuleFileNameA(NULL,szFilePath,MAX_PATH);
        (strrchr(szFilePath,'\\'))[0]=0;
        string path=szFilePath;
        return path;
}
void open(char a[])
{
        string argv=GetExePath();
        vector<string> files;
        //获取该路径下的所有.in .txt文件
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        files.push_back("Back");
        int size=files.size();  //总共文件数
        Draw_opt(size,files);
        int choose=1;
        while(drawp(1,size,choose,4)==-1);
        choose--;
        if(choose==size-1) return Custom(a);
        string tem=files[choose].c_str();
        for (int i=0; i<tem.size(); i++)
                a[i]=files[choose].c_str()[i];
}

void edit_choose(char in[])
{
        Draw(-1);
        string opt[10]=
        {
                "",
                "删除",
                "编辑词库",
                "Back"
        };
        Draw_opt(3,opt);
        int choose=1;
        while(drawp(1,3,choose,4)==-1);
        if (choose==1)
        {
                system("cls");
                printf("删除中...\n");
                remove(in);
                printf("删除成功!!!\n");
                Sleep(666);
                return;
        }
        else if (choose==2)
        {
                system("cls");
                printf("进入中...\n");
                system(in);
                printf("编辑成功!!!\n");
                Sleep(666);
                return;
        }
        else if (choose==3)
        {
                return;
        }
        else
        {
                system("cls");
                puts("请输入所给范围的数字！");
                Sleep(888);
                system("cls");
                edit_choose(in);
                return;
        }
}
void edit(char a[])
{
        string argv=GetExePath();
        vector<string>files;
        //获取该路径下的所有.in .txt文件
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        files.push_back("back");
        int size=files.size();  //总共文件数
        Draw(-1);
        Draw_opt(size,files);
        int choose=1;
        while(drawp(1,size,choose,4)==-1);
        if (choose==size) return Custom(a);
        choose--;
        char tem[100]="";
        string_char(files[choose].c_str(),tem);
        edit_choose(tem);
        edit(a);
}
void Custom(char a[])
{
        Draw(-1);
        string opt[10]=
        {
                "",
                "创造新词库",
                "打开已有词库",
                "编辑已有词库",
                "Back"
        };
        Draw_opt(4,opt);
        int choose=1;
        while(drawp(1,4,choose,4)==-1);
        switch(choose)
        {
        case 1: system("cls"); create(a); return;
        case 2: open(a); return;
        case 3: system("cls"); edit(a); return;
        case 4: system("cls"); choose_pattern(a); return;
        }
}
void Own_Thesaurus(char a[])
{
        string argv=GetExePath();
        vector<string> files;
        //获取该路径下的所有.in .txt文件
        getFiles(argv,"in",files);
//        getFiles(argv,"txt",files);
        files.push_back("Back");
        int size=files.size();  //总共文件数
        Draw_opt(size,files);
        int choose=1;
        while(drawp(1,size,choose,4)==-1);
        choose--;
        if(choose==size-1) return choose_pattern(a);
        string tem=files[choose].c_str();
        for (int i=0; i<tem.size(); i++)
                a[i]=files[choose].c_str()[i];
}
void morre()
{
        puts("了解更多twt-tec软件资讯请进入我们的主页：");
        puts("https://twt-tec.github.io/");
        Sleep(1500);
        system("start https://twt-tec.github.io/");
        Sleep(3000);
}
void choose_pattern(char a[])
{
        system("cls");
        Draw(-1);
        string opt[10]=
        {
                "",
                "【官方词库】             ",
                "【自定义词库】         ",
                "【使用手册】             ",
                "【更多】             ",
                "【退出】"
        };
        Draw_opt(5,opt);
        int choose=1;
        while(drawp(1,5,choose,4)==-1);
        switch(choose)
        {
        case 1: Own_Thesaurus(a); system("cls"); return;
        case 2: Custom(a); return;
        case 3: system("cls"); puts("进入中..."); system("使用手册.pdf"); choose_pattern(a); return;
        case 4: system("cls"); morre(); choose_pattern(a); return;
        case 5: system("cls"); exit(0);
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
        for (int i=0; i<=n; i++)
                for (int j=0; j<N; j++)
                        word[i].Eh[j]="",word[i].cntEh=0;
}
void main()
{
        char unit[N]="",ordinal[N]="";
        zm::choose_pattern(unit);

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
        puts("输入'>>'跳过单词,'?'去除单词,'.'结束测试");
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
                        if(init==">>") {cout<<word[r].Eh[1]<<endl; Sleep(666); return;}
                        if(init=="?") return (void)(n--,Sleep(333),pick[r]=1);
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
namespace window
{
void main()
{
        system("chcp 936");
        system("title writing master");//设置cmd窗口标题
        system("mode con cols=42 lines=30");//窗口宽度高度
        system("cls");
}
}
int main()
{
        window::main();
        init::main();
        work::main();
}
