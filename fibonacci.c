#include<stdio.h>

void main()
{
    int n,term;
    printf("Enter the term of the fibonacci series\n");
    scanf("%d",&n);
    term=fab(n);
    printf("The %d term is %d\n",n,term);

    getch();

}

int fab(int n)
{
    if(n==1||n==2)
    {
        return(1);
    }
    else
    {
        return(fab(n-1)+fab(n-2));
    }
}
