#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
 char str[100],temp;
 int i,j=0;
 clrscr();
 cout<<"Enter any the string :";
 gets(str);  //  gets function for input string
 i=0;
 j=strlen(str)-1;
  while(i<j)
   {
   temp=str[i];
   str[i]=str[j];
   str[j]=temp;
   i++;
   j--;
   }


 cout<<"Reverse string is: "<<str;
 getch();
}


