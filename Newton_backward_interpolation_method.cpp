#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

void printDifferenceTable(vector<vector<double>> &ay, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ay[i][j];
        }
        cout << endl;
    }
}
double calculate(vector<double>&ax,vector<vector<double>>&ay,double x,int n)
{
    double h=ax[1]-ax[0];
    double u=(x-ax[n-1])/h;
    double res=ay[n-1][0];
    for(int i=1;i<n;i++)
    {
        double term=ay[n-1][i];
        for(int j=0;j<i;j++)
        {
            term *= u+j;
        }
        term /= factorial(i);
        res += term;
    }
    return res;
}

int main()
{
    cout << setprecision(6) << fixed;
    int n;
    cin >> n;
    vector<double> ax(n);
    vector<vector<double>> ay(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        cin >> ax[i];
    for (int i = 0; i < n; i++)
        cin >> ay[i][0];
    double target_x;
    cin >> target_x;
    // calculate difference table
    for(int i=1;i<n;i++)
    {
        for(int j=n-1;j>=1;j--)
        {
            ay[j][i]=ay[j][i-1]-ay[j-1][i-1];
        }
    }
    cout<<calculate(ax,ay,target_x,n)<<" "<<"hello"<<endl;
}