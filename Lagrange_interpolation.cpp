#include<bits/stdc++.h>
using namespace std;
double calculate(vector<double>&x,vector<double>&y,double x_tar)
{
    int n=x.size();

    double res=0;
    for(int i=0;i<n;i++)
    {
        double term=y[i];
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            term *= (x_tar- x[j])/(x[i]-x[j]);
        }
        res+=term;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)
    cin>>x[i];
    for(int i=0;i<n;i++)
    cin>>y[i];
    double x_tar; cin>>x_tar;
    cout<<calculate(x,y,x_tar)<<endl;
}