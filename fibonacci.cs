 using System;  
      public class FibonacciSeries  
       {  
         public static void Main(string[] args)  
          {  
             int n1=0,n2=1,n3,i,count;    
             Console.Write("Enter the number of elements: ");    
             count = int.Parse(Console.ReadLine());  
             Console.Write(n1+" "+n2+" ");  
             for(i=2;i<count;++i)    
             {    
              n3=n1+n2;    
              Console.Write(n3+" ");    
              n1=n2;    
              n2=n3;    
             }    
          }  
       }   
