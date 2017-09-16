/*
Problem Description:
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
#define INT_MAX       2147483647
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

union f2l{
    struct {
        float k;
        float b;
    }point;
    unsigned long long data;
};

int maxPoints(vector<Point> &points) {
    vector<unsigned long long > lineFeatures(points.size()*(points.size()-1)/2);
    int count=0;
    for(int i=0;i<points.size();i++)
    {
        for(int j=i+1;j<points.size();j++)
        {
            float k=0,b=0;
            if(points[i].x-points[j].x!=0)
            {  k=(float)(points[i].y-points[j].y)/(float)(points[i].x-points[j].x); b=(float)(points[j].x*points[i].y-points[i].x*points[j].y)/(float)(points[j].x-points[i].x); }
            else
            {   k=INT_MAX; b=points[i].x; }
            if(k==0)b=points[i].y;
            f2l data;
            data.point.k=k;
            data.point.b=b;
            lineFeatures[count++]=data.data;
            //printf("(%d,%d)---(%d,%d) k=%.2f b=%.2f %llu\n",points[i].x,points[i].y,points[j].x,points[j].y,k,b,data.data); 
        }
    }
    sort(lineFeatures.begin(),lineFeatures.end() );
    int maxHit=0;
    int hit=0;
    unsigned long long lastStore=lineFeatures[0];
    for(int i=0;i<lineFeatures.size();i++)
    {
        //cout<<lineFeatures[i]<<endl;
        if(lineFeatures[i]==lastStore)hit++;
        else {
            if(hit>maxHit)maxHit=hit;
            hit=1;
            lastStore=lineFeatures[i];
        }
    }
    if(hit>maxHit)maxHit=hit;
    //cout<<"#\n";
    //cout<<maxHit<<endl;
    return ((int)sqrt(1+8*(float)maxHit)+1)/2;
}



int main()
{
    //Point raw[]={Point(0,0),Point(1,0),Point(1,1),Point(0,1),Point(2,2),Point(12,12)};
    Point raw[]={Point(3,4),Point(6,8),Point(9,12),Point(0,1)};
    vector<Point> input(raw,raw+sizeof(raw)/sizeof(Point));;
    cout<<maxPoints(input)<<endl;
}