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
string GetExePath()     //��ȡ��ǰ�ļ���·��
{
        char szFilePath[MAX_PATH+1]={0};
        GetModuleFileNameA(NULL,szFilePath,MAX_PATH);
        (strrchr(szFilePath,'\\'))[0]=0;
        string path=szFilePath;
        return path;
}
void open(char a[])
{
        puts("���дʿ⣺");
        string argv=GetExePath();
        vector<string>files;
        //��ȡ��·���µ�����.in .txt�ļ�
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        int size=files.size(); //�ܹ��ļ���
        for (int i=0; i<size; i++)
                cout<<i+1<<" ->"<<files[i].c_str()<<endl;
        Color(8); printf("%d -> back\n",size+1); Color(7);
        printf("�������֣�ѡ��ʿ�:");
        int choose;
        cin>>choose;
        if (choose==size+1)
        {
                return Custom(a);
        }
        if (choose>size+1 || choose<=0)
        {
                system("cls");
                puts("������������Χ�����֣�");
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
        printf("��ѡ��%s\n�����������",a);
        char temp=getchar();
}

void edit_choose(char in[])
{
        system("cls");
        cout<< "��ѡ�� "<<in<<endl;
        printf("1 ->ɾ��\n");
        printf("2 ->�༭�ʿ�\n");
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
                puts("������������Χ�����֣�");
                Sleep(888);
                system("cls");
                edit_choose(in);
                return;
        }
        if (choose==1)
        {
                system("cls");
                printf("ɾ����...\n");
                remove(in);
                Sleep(666);
                printf("ɾ���ɹ�!!!\n");
                Sleep(666);
                return;
        }
        else if (choose==2)
        {
                system("cls");
                printf("������...\n");
                system(in);
                Sleep(666);
                printf("�༭�ɹ�!!!\n");
                Sleep(666);
                return;
        }
}
void edit(char a[])
{
        system("cls");
        puts("�޷��޸�ϵͳ�Դ��ʿ�");
        puts("�����޸��û�������Ӵʿ�");
        puts("���дʿ⣺");
        string argv=GetExePath();
        vector<string>files;
        //��ȡ��·���µ�����.in .txt�ļ�
//	    getFiles(argv,"in",files);
        getFiles(argv,"txt",files);
        int size=files.size(); //�ܹ��ļ���
        for (int i=0; i<size; i++)
                cout<<i+1<<" ->"<<files[i].c_str()<<endl;
        Color(8); printf("%d -> back\n",size+1); Color(7);
        printf("������Ҫ�༭�Ĵʿ�ı��:");
        int choose;
        cin>>choose;
        if (choose==size+1)
        {
                return Custom(a);
        }
        if (choose>size+1 || choose<=0)
        {
                system("cls");
                puts("������������Χ�����֣�");
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
        printf("1 ->�����´ʿ�\n");
        printf("2 ->�����дʿ�,��ʼ��ϰ\n");
        printf("3 ->�༭���дʿ�\n");
        Color(8); printf("4 ->back\n"); Color(7);
        printf("��ѡ��:");
        char choose;
        cin>>choose;
        switch(choose)
        {
        case '1': system("cls"); create(a); z_choose=1; return;
        case '2': system("cls"); open(a); z_choose=2; return;
        case '3': system("cls"); edit(a); return;
        case '4': system("cls"); choose_pattern(a); return;
        default: system("cls"); puts("������������Χ�����֣�"); Sleep(1000); system("cls"); Custom(a); break;
        }
}
void choose_pattern(char a[])
{
        system("cls");
        Color(8); puts("��ӭʹ�� writing master"); Color(7);
        Sleep(666);
        system("cls");
        puts("��ҳ:");
        puts("1 ->��ʼ��ϰ�Դ��ʿ�");
        puts("2 ->�Զ���ʿ�");
        puts("3 ->ʹ���ֲ�");
        Color(8); puts("4 ->�˳�"); Color(7);
        printf("��ѡ��:");
        char choose;
        cin>>choose;
        switch(choose)
        {
        case '1': z_add("bx1unit",a); z_choose=0; system("cls"); return;
        case '2': system("cls"); Custom(a); return;
        case '3': system("cls"); puts("������..."); system("ʹ���ֲ�.pdf"); choose_pattern(a); return;
        case '4': exit(0);
        default: system("cls"); puts("������������Χ�����֣�"); Sleep(1000); choose_pattern(a); break;
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
                cout<<"����ҪĬд�ĵ�Ԫ"<<"\n"<<unit;
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
        puts("����'>>'��������ǰ����,����'.'��������");
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
