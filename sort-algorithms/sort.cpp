#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

vector<int> insert_sort(vector<int> input)
{
    int size=input.size();
    for(int i=1;i<size;i++)
    {
        int temp = input[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(input[j]>temp)
                input[j+1]=input[j];
            else
                break;
        }
        input[j+1]=temp;
    }
    return input;
}

vector<int> bubble_sort(vector<int> input)
{
    int size=input.size();
    for(int i=0;i<size;i++)
    {
        for(int j=1;j<size-i;j++)
        {
            if(input[j]<input[j-1])
            {
                int temp=input[j];
                input[j]=input[j-1];
                input[j-1]=temp;
            }
        }
    }
    return input;
}

vector<int> select_sort(vector<int> input)
{
    for(int i=0;i<input.size();i++)
    {
        int minVal=input[i];
        int minIndex=i;
        for(int j=i;j<input.size();j++)
        {
            if(input[j]<minVal){minVal=input[j];minIndex=j;}
        }
        input[minIndex]=input[i];
        input[i]=minVal;
    }
    return input;
}

void partial_merge(vector<int> input,vector<int>& output,int start,int n)
{
    int i=start;
    int j=start+n;
    int cur=start;
    while(i<start+n&&j<start+2*n)
    {
        cout<<cur<<"\t"<<i<<"\t"<<j<<endl;
        if(input[i]<input[j])
        {
            output[cur++]=input[i++];
        }
        else
        {
            output[cur++]=input[j++];
        }
    }
    while(i<start+n)output[cur++]=input[i++];
    while(j<start+2*n)output[cur++]=output[j++];
}
vector<int> merge_sort(vector<int> input)
{
    vector<int> output(input.size());
    int size=input.size();
    int gap=2;
    for(int i=0;i+2*gap-1<size;i=i+2*gap)
    {
        partial_merge(input,output,i,gap);
    }
    
    return output;
}


vector<int> quick_sort(vector<int>& input,int left,int right)
{
    if(left>=right)return input;
    
    int i=left;int j=right;
    while(i<j)
    {
        while(input[j]>=input[left]&&i<j)j--;
        while(input[i]<=input[left]&&i<j)i++;
        if(i<j){
            int tmp=input[i];   
            input[i]=input[j];
            input[j]=tmp;
        }
    }
    int tmp=input[i];
    input[i]=input[left];
    input[left]=tmp;
    quick_sort(input,left,i-1);
    quick_sort(input,i+1,right);
    return input;
}

vector<int> shell_sort(vector<int> input)
{
    int gap,i,j;
    int size= input.size();
    for(gap=size/2;gap>0;gap/=2)
    {
        for(i=0;i<gap;i++)
        {
            for(j=i+gap;j<size;j+=gap)
            {
                if(input[j]<input[j-gap])
                {
                    int temp=input[j];
                    int index=j-gap;
                    while(index>=0&&input[index]>temp){
                        input[index+gap]=input[index];
                        index-=gap;
                    }
                    input[index+gap]=temp;
                }
            }
        }
    }
    return input;
}
int main()
{
    int raw[]={3,4,1,2,0};
    vector<int> output=quick_sort(std::vector<int>(raw,raw+sizeof(raw)/sizeof(int)),0,4);
    //vector<int> output=shell_sort(vector<int>(raw,raw+sizeof(raw)/sizeof(int)));
    for(int i=0;i<output.size();i++)cout<<output[i]<<"\t";
}