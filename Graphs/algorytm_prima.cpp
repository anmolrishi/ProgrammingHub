//podstawa do II projektu!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int v;//wierzcholek
    int len;//dlugosc
    edge(int _v, int _l)
    {
        v = _v;
        len = _l;
    }
};

vector <edge> vert[6];

int main ()
{
    int p[6], pp[6];
    int dist[6];

    vert[0].push_back(edge(1,2));
    vert[0].push_back(edge(3,7));
    vert[0].push_back(edge(4,6));
    vert[0].push_back(edge(5,4));
    vert[1].push_back(edge(0,2));
    vert[1].push_back(edge(2,4));
    vert[2].push_back(edge(1,4));
    vert[2].push_back(edge(3,4));
    vert[2].push_back(edge(5,2));
    vert[3].push_back(edge(0,7));
    vert[3].push_back(edge(2,4));
    vert[3].push_back(edge(4,2));
    vert[4].push_back(edge(0,6));
    vert[4].push_back(edge(3,2));
    vert[4].push_back(edge(5,4));
    vert[5].push_back(edge(0,4));
    vert[5].push_back(edge(2,2));
    vert[5].push_back(edge(4,4));

    /*
        for(int i=0; i<vert[0].size();i++)
            cout<<"0 sasiaduje z "<<(vert[0][i]).v<<" krawedzia dlugosci "<<(vert[0][i].len)<<endl;
    */

    for(int i = 0; i < 6; i++)
    {
        p[i] = pp[i] = -1;
        dist[i] = 100;
    }

    for (int krok = 0; krok < 6; krok++)
    {
        int w = -1;
        int d = 200;
        for(int i = 0; i < 6; i++)
            if(dist[i] > 0 && dist[i] < d)
            {
                w = i;
                d = dist[i];
            }
        dist[w] = 0;
        p[w] = pp[w];
        for (int i = 0; i < vert[w].size(); i++)
        {
            if(dist[vert[w][i].v] > vert[w][i].len)
            {
                dist[vert[w][i].v] = vert[w][i].len;
                pp[vert[w][i].v] = w;
            }
        }
    }

    for(int i = 0; i < 6; i++)//wyswietla
    {
        cout<<p[i]<<" - "<<i<<endl;
    }

    return 0;
}
