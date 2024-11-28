#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n<=1) return 1;
    else return n*fact(n-1);
}
double ds(double s,int n)
{
    double sum=0;
    for(int i=0;i<n;i++)
    {
        double mul=1.0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                mul *= s-j;
            }
        }
        sum +=mul;
    }
    return sum;
}
int main()
{
   int n;
   cin>>n;
   vector<double>x(n);
   vector<vector<double>>y(n,vector<double>(n,0.0));
   for(int i=0;i<n;i++)
   cin>>x[i];
   for(int i=0;i<n;i++)
   cin>>y[i][0];

double xtar;
cin>>xtar;
   // firward differnece table
   for(int i=1;i<n;i++)
   {
    for(int j=0;j<n-i;j++)
    {
        y[j][i]= y[j+1][i-1]-y[j][i-1];
    }
   }
   double h=x[1]-x[0];
   double u=(xtar-x[0])/h;
   //double res=y[0][1];
   double res=0.0;
    for(int i=1;i<n;i++)
    {
        /*  double term=y[0][i+1];
          for(int j=0;j<i;j++)
          {
              term *= (u-j);
          }
          term /=i+1;
          */
         double delta=y[0][i];
         res += delta*ds(u,i)/fact(i);


      //  res += term;
    }
    cout<<res/h<<endl;


}