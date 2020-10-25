//c++ program for radix sort
#include<iostream>

using namespace std;
//this function is used to divide the value and we get a new digit
int getMaxDivision(int value)
{
    int count = 0;
    while(value > 0)
    {
        value = value/10;
        count++;
    }
    return count;
}
//evaluates the remainder
int divideTimes(int value,int times)
{
    int temp = value;
    int remainder;
    for(int i = 0; i < times; i++)
    {
        remainder = temp % 10;
        temp /= 10;
    }
    return remainder;
}

int main()
{
    int array[] = {10,30,50,20,70,80,60,90,40,100};
    int arraySize = (sizeof(array)/sizeof(array[0]));
    int index,maxDivision = 0,temp,nestedIndex,i,j,count;

    for(index = 0; index < arraySize; index++)
    {
        /** find the length of number with maximum no. of digits**/
        temp = getMaxDivision(array[index]);
        if (temp > maxDivision)
            maxDivision = temp;
    }

    int radixArray[arraySize][10];

    for(index = 0; index < arraySize; index++)
    {
        /** Cleans the radix 2D matrix **/
        for(nestedIndex = 0; nestedIndex < 10; nestedIndex++)
        {
            radixArray[index][nestedIndex] = 0;
        }
    }

    for(index = 1; index <= maxDivision; index++)
    {
    /** Loop runs until maximum digits of the number found **/
        for(nestedIndex = 0; nestedIndex < arraySize; nestedIndex++)
        {
            /** This loop divides every element and put into radix array **/
            temp = divideTimes(array[nestedIndex], index);
            radixArray[nestedIndex][temp] = array[nestedIndex];
        }

        count = 0;
        for(i = 0; i < 10; i++)
        {
            /** from radix matrix put into original array **/
            for(j =0; j < arraySize; j++)
            {
                if(radixArray[j][i] != 0)
                {
                    array[count] = radixArray[j][i];
                    count++;
                }
            }
        }

        for(i = 0; i < arraySize; i++)
        {
            /** Again cleans the radix 2D matrix **/
            for(j = 0; j < 10; j++)
            {
                radixArray[i][j] = 0;
            }
        }
    }
    //display
    cout<<"Sorted Array is: "<<endl;
    for(index = 0; index <arraySize; index++)
    {
        cout<<array[index]<<"\t";
    }

    return 0;
}

