#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <regex>
using namespace std;
string str;
string b;
char geta;
regex reg("zip|rar|7z|exe|doc|txt|docx|vbs|js|cpp|jar|iso|img|ppt|pptx|pdf|xml|osz|mc|mcz|wav|mp3|mp4{1}");
regex regb("http|https|HTTP|HTTPS{1}");
int mb;
string str1;
fstream file;
char cha[512];
char* GCB()
{
    OpenClipboard(NULL);
    HANDLE data = GetClipboardData(CF_TEXT);
    char* a= (char*)GlobalLock(data);
    CloseClipboard();
    return a;
}
void fail(string a)
{
    cout << "文件丢失,无法继续!" << endl << "丢失文件为:" << a << endl << "如果为txt文件,新建此文件。";
    Sleep(2000);
}
void op(string tmp)
{
    file.open(tmp, ios::out | ios::trunc);
    if (file.fail())
    {
        fail(tmp);
        exit(0);
    }
}
void strtoch(char ch[512], string str)
{
    int i;
    for ( i = 0; i < str.length(); i++)
                 ch[i] = str[i];
    ch[i] = '\0';
}
int main()
{
    cout << "摁Q进入" << endl;
    cout << "摁D修改默认下载路径（默认为C:\\）" << endl;
    while (1)
    {
        a:
        if (regex_search(GCB(), reg) == true)
        {
               if (MessageBox(NULL, TEXT("检测到剪贴板中有下载内容，下载？"), TEXT("下载"), MB_OKCANCEL)==1)
               {
                   mb = 1;
                   goto l;
               }
               else
               {
                   system("echo off | clip");
                   goto a;
               }
       }
        if (_kbhit())
        {
            geta = _getch();
            if (geta == 'q')
            {
                l:
                system("cls");
                op("tmp.txt");
                if (mb != 1)
                {
                    cout << "输入HTTP地址:" << endl;
                    getline(cin, str);
                }
                else
                {
                    str =GCB();
                }
                /*if (regex_search(str, regb) != true)
                {
                    cout << "你确定这是个网址?（清屏后按Q重来）" << endl;
                    Sleep(1500);
                    system("cls");
                    continue;
                }*/
                file << str;
                file.close();
                file.open("tmp2.txt", ios::in);
                if (file.fail())
                {
                    fail("tmp2.txt");
                    return 0;
                }
                str = "";
                strtoch(cha, str);
                file.getline(cha, 512);
                str = cha;
                file.close();
                cout << "文件名？（加后缀）" << endl;
                cin >> str1;
                op("tmp1.txt");
                file << str + str1;
                file.close();
                file.open("download.bat", ios::out | ios::in);
                if (file.fail())
                {
                    fail("download.bat");
                    return 0;
                }
                file.close();
                cout << "您可以在弹出的cmd窗口中监视下载信息。过程中杀毒软件点击允许。" << endl;
                cout << "毫无卵用下载器 by千里扯淡" << endl;
                system("download.bat");
                system("pause");
                return 0;
            }
            if (geta == 's')
            {
                system("cls");
                cout << "修改:（注意最后加\\,不要有空格）";
                op("tmp2.txt");
                string aa;
                cin >> aa;
                file << aa;
                file.close();
                system("cls");
                continue;
            }
        }
    }
}
