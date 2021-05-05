#include <bits/stdc++.h>
#include <sys/stat.h>
#include <string>
using namespace std;

int main()
{
    string stringpath = "D:\test_folder"; 
    int status = mkdir(stringpath.c_str(),0777);

    if(status!=0)
    {
        //.....
    }
    else
    {
        //....
    }
}