/*Input

The first line of input file contains an integer N that represents the number of test cases that follows. Each test case contains two numbers V and E, respectively the number of Vertices and Edges of the graph. Follow E lines, each one representing one of the edges that connect such vertex. Each vertex is represented by a lowercase letter of the alphabet. This mean 26 vertex at maximum (a-z). Each graph has at least one connected component. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct oi{
    char a1, a2;
    }oi;
    int co (const void * a , const void * b) {
    oi h;
    oi g;
    h=*(oi*)a;
    g=*(oi*)b;
    if (h.a1>g.a1){
            return 1;
    }
    if (h.a1<g.a1){
            return -1;
    }
    if (h.a1==g.a1){
            if (h.a2>g.a2){
            return 1;
    }
    if (h.a2<g.a2){
            return -1;
    }
    else {
            return -1;
    }
    }
    }
int main (){
        char o, p;
        oi ui[100];
        int a, s, d, k,q, w[50][50], lo, li, e , r, t[50], vd, ki;
        scanf ("%d",  &a);
        for (s=1; s<=a; s++){
                scanf ("%d %d", &d, &e);
                for (r=0; r<=d; r++){
                        t[r]=0;
                        for (k=0; k<=d; k++){
                                w[r][k]=0;
                        }
                }
                for(r=0; r<e;  r++){
                        getchar();
                        scanf ("%c %c", &ui[r].a1, &ui[r].a2 );
                }
                qsort (ui, e, sizeof (oi), co);
                  
                for (r=0; r<e; r++){
                     o=ui[r].a1;
                     p=ui[r].a2;
                     q=o-97;
                     k=p-97;
                     w[q][k]=1;
                     w[k][q]=1;
                     t[q]=1;
                     t[k]=1;
                        for (lo=0; lo<=d; lo++){
                                if (w[lo][q]==1 || w[q][lo]==1){
                                    w[lo][k]=1;
                                    w[k][lo]=1;
                                    for (li=0; li<=d; li++){
                                            if (w[k][li]==1||w[li][k]==1){
                                            w[li][k]=1;
                                            w[lo][k]=1;
                                            w[k][lo]=1;
                                            w[li][lo]=1;
                                            w[lo][li]=1;
                                            w[k][li]=1;
                                            w[q][li]=1;
                                            w[li][q]=1;
                                        }
                                    }
                                }
                                if (w[lo][k]==1||w[k][lo]==1){
                                    w[lo][q]=1;
                                    w[q][lo]=1;
                                    for (li=0; li<=d; li++){
                                            if (w[q][li]==1 || w[li][q]==1){
                                            w[li][k]=1;
                                            w[lo][k]=1;
                                            w[k][lo]=1;
                                            w[li][lo]=1;
                                            w[lo][li]=1;
                                            w[k][li]=1;
                                            w[q][li]=1;
                                            w[li][q]=1;
                                        }
                                    }
                                    }
                                }
                        }
                          
                  
                vd=0;
                ki=0;
                printf ("Case #%d:\n", s);
                for (r=0; r<d; r++){
                        if (t[r]==1){
                            printf ("%c," , r+97);
                            ki=vd;
                            for (int u=0; u<d; u++){
                                    if (w[r][u]==1 && r!=u){
                                            if (ki+1>vd){
                                                    vd++;
                                            }
                                            t[u]=-1;
                                            printf ("%c,",  u+97);
                                    }
                            }
                            puts("");
                        }
                        if (t[r]==0) {
                            vd++;
                                printf ("%c,\n" , r+97);
                        }
                }
                printf ("%d connected components\n", vd);
        printf ("\n");
        }
    }
