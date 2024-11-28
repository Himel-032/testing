#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n==0 || n==1) return 1;
    else
    return n*fact(n-1);
}
void printDifferenceTable(vector<vector<double>> &v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout<<v[i][j]<<"    ";
        }
        cout<<endl;
    }
}
double calculate(vector<double> &ax,vector<vector<double>>&ay,double x)
{
    double h=ax[1]-ax[0];
    double u=(x-ax[0])/h;
    double res=ay[0][0];
    for(int i=1;i<ax.size();i++)
    {
        double term=ay[0][i];
        for(int j=0;j<i;j++)
        {
            term = term*(u-j);
        }
        term =term/fact(i);
        res += term;
    }
    return res;
}
int main()
{
    cout<<setprecision(4)<<fixed;
    int n;
    cin>>n;
    vector<double>ax(n);
    for(int i=0;i<n;i++)
    {
        cin>>ax[i];
    }
    vector<vector<double>>ay(n,vector<double>(n,0));
    for(int i=0;i<n;i++)
    {
        cin>>ay[i][0];
    }
    // making difference table
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            ay[j][i]=ay[j+1][i-1] - ay[j][i-1];
        }
    }
    //printDifferenceTable(ay);
    cout<<"traget x: "; double x_tar; cin>>x_tar;
    cout<<"y: "<<calculate(ax,ay,x_tar);

    return 0;
}