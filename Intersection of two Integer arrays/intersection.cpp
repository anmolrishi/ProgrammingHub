#include <cstdlib>
#include <time.h>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    int v1[5];
    int v2[5];
    list<int> intersection;
    for(int i=0;i<5;i++)
    {
        v1[i]=(rand()%10)+1;
        v2[i]=(rand()%10)+1;
        cout<<v1[i]<<" "<<v2[i]<<endl;
    }
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            if(v1[i]==v2[j])
                intersection.push_back(v1[i]);
        }
    cout<<endl<<"INTERSECTION:"<<endl;
    intersection.sort();
    intersection.unique();

    for(list<int>::iterator it=intersection.begin();it!=intersection.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;

}