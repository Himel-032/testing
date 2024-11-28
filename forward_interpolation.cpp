#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n<=1) return 1;
    else return n*fact(n-1);
}
double calculate(vector<double>&x,vector<vector<double>>&ay,double xTar)
{
    int n=x.size();
    double h=x[1]-x[0];
    double u=(xTar-x[0])/h;
    double sum=ay[0][0];
    for(int i=1;i<n;i++)
    {
        double term=ay[0][i];
        for(int j=0;j<i;j++)
        {
            term *= (u-j);
        }
        term /= fact(i);
        sum+=term;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    vector<double>x(n);
    vector<double>y(n);
    vector<vector<double>>ay(n,vector<double>(n,0.0));
    for(int i=0;i<n;i++)
    {
        cin>>x[i];

    }
    for(int i=0;i<n;i++)
    {
        cin>>y[i];
        ay[i][0]=y[i];
    }
    // forward difference table
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            ay[j][i]=ay[j+1][i-1]-ay[j][i-1];
        }
    }
    double xTar;
    cin>>xTar;
    cout<<"y: "<<calculate(x,ay,xTar)<<endl;
}