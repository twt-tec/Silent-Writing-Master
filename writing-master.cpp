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
/*=============== ���� ===============*/

void drawRow(int x, int y1, int y2, char ch)    //�ѵ�x�У�[y1, y2] ֮����������Ϊ ch
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
        case -1:    //====��ʼ��
        {
                system("cls");
                SetPos(15, 0);
                printf("Ĭ д �� ʦ");
                SetPos(15, 2);
                printf("��'w'��'s'ѡ��,�س�ȷ��");
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
        else if(x==13)//˭����'k'��˭����
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
        printf("�������´ʿ���(�����ո�):");
        cin>>name;
        char txt[12]=".txt";
        z_add(txt,name);
        z_add(name,a);
        ofstream Thesaurus;
        Thesaurus.open(name);
        Thesaurus<<"��һ���������\n";
        Thesaurus<<"����һ��Ӣ�ﵥ�ʻ����(ĩβ�����пո�)\n";
        Thesaurus<<"����һ�иõ��ʵ�������˼\n";
        for (int i=1; i<=6; i++) Thesaurus<<"              .\n";
        Thesaurus<<"���һ��Ҫ����(�������ʹ���ֲ�)\n";
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
string GetExePath()       //��ȡ��ǰ�ļ���·��
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
        //��ȡ��·���µ�����.in .txt�ļ�
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        files.push_back("Back");
        int size=files.size();  //�ܹ��ļ���
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
                "ɾ��",
                "�༭�ʿ�",
                "Back"
        };
        Draw_opt(3,opt);
        int choose=1;
        while(drawp(1,3,choose,4)==-1);
        if (choose==1)
        {
                system("cls");
                printf("ɾ����...\n");
                remove(in);
                printf("ɾ���ɹ�!!!\n");
                Sleep(666);
                return;
        }
        else if (choose==2)
        {
                system("cls");
                printf("������...\n");
                system(in);
                printf("�༭�ɹ�!!!\n");
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
                puts("������������Χ�����֣�");
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
        //��ȡ��·���µ�����.in .txt�ļ�
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        files.push_back("back");
        int size=files.size();  //�ܹ��ļ���
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
                "�����´ʿ�",
                "�����дʿ�",
                "�༭���дʿ�",
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
        //��ȡ��·���µ�����.in .txt�ļ�
        getFiles(argv,"in",files);
//        getFiles(argv,"txt",files);
        files.push_back("Back");
        int size=files.size();  //�ܹ��ļ���
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
        puts("�˽����twt-tec�����Ѷ��������ǵ���ҳ��");
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
                "���ٷ��ʿ⡿             ",
                "���Զ���ʿ⡿         ",
                "��ʹ���ֲ᡿             ",
                "�����ࡿ             ",
                "���˳���"
        };
        Draw_opt(5,opt);
        int choose=1;
        while(drawp(1,5,choose,4)==-1);
        switch(choose)
        {
        case 1: Own_Thesaurus(a); system("cls"); return;
        case 2: Custom(a); return;
        case 3: system("cls"); puts("������..."); system("ʹ���ֲ�.pdf"); choose_pattern(a); return;
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
void initialization()    //��ʼ��
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
        puts("��ȷ��:");
        for(int i=1; i<=word[r].cntEh; i++)
                cout<<word[r].Eh[i]<<endl;
        system("pause");
        system("cls");
        puts("��Ĭһ�飺");
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
        printf("����: %d/%d\n",level,n);
        printf("��ȷ��:%.1lf% (%d/%d)\n",T*100.0/(T+F),T,T+F);
        puts("����'>>'��������,'?'ȥ������,'.'��������");
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
void initialization()    //��ʼ��
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
        printf("��ȷ��:%.1lf% (%d/%d)\n",ture*100.0/(ture+flase),ture,ture+flase);
        if (res) {puts("�����..."),system("pause");}
        else {
                printf("����� %d/%d\n",level,n);
                puts("��r���ص�����,�������ص���ҳ");
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
        system("title writing master");//����cmd���ڱ���
        system("mode con cols=42 lines=30");//���ڿ�ȸ߶�
        system("cls");
}
}
int main()
{
        window::main();
        init::main();
        work::main();
}
