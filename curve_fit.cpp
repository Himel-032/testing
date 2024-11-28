#include<bits/stdc++.h>
using namespace std;
void backsubstitution(vector<vector<double>>&v,vector<double>&coeff)
{
    int n=v.size();
    vector<double> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = v[i][n];
        for (int j = i + 1; j < n; j++)
        {
            ans[i] -= v[i][j] * ans[j];
        }
        ans[i] /= v[i][i];
    }
    coeff.resize(n);
    coeff = ans;
}
void gaussElimination(vector<vector<double>>&v,vector<double>&coeff)
{
    int n=v.size();
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        if(v[i][i]==0)
        {
            int c=1;
            while((i+c)<n && v[i+c][i]==0)
            c++;
            if(i+c == n)
            {
                flag=true; break;
            }
            swap(v[i+c],v[i]);
           
        }
        for (int j = i + 1; j < n; j++)
        {
            double frac = v[j][i] / v[i][i];
            for (int k = 0; k <= n; k++)
            {
                v[j][k] -= frac * v[i][k];
            }
        }
    }



    
}
void polynomialFit(vector<double>&x,vector<double>&y,int degree,vector<double>&coeff)
{
    int n=degree+1;
    vector<vector<double>>A(n,vector<double>(n,0.0));
    vector<double>b(n,0.0);
    int N=x.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<N;k++)
            {
                A[i][j] += pow(x[k],i+j);
            }
        }
        for(int k=0;k<N;k++)
        {
            b[i] += y[k]*pow(x[k],i);
        }
    }
    vector<vector<double>>v(n,vector<double>(n+1,0.0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            v[i][j]=A[i][j];
        }
        v[i][n]=b[i];
    }
    gaussElimination(v,coeff);
    backsubstitution(v,coeff);

}
void linearFit(vector<double>&x,vector<double>&y)
{
    vector<double>coeff;
    polynomialFit(x,y,1,coeff);
    cout<<coeff[0]<<" "<<coeff[1]<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)
    cin>>x[i];
    for(int j=0;j<n;j++)
    cin>>y[j];
    linearFit(x,y);
}
