#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return 1/(1 + x*x);
}
double trapezoidal(double a,double b,int n)
{
    double h=(b-a)/n;
    vector<double>x(n+1),y(n+1);
    for(int i=0;i<=n;i++)
    {
        x[i]= a + i*h;
        y[i]=f(x[i]);
    }
    double ans=f(a)+f(b);
    for(int i=1;i<n;i++)
    {
        ans += 2*y[i];
    }
    ans = ans*h/2;
    return ans;
}
double simpson_1_3_rule(double a,double b,int n)
{
    if(n%2!=0)
    {
        cout<<"n is not even"<<endl;
        return NAN;
    }
    double h = (b - a) / n;
    vector<double> x(n + 1), y(n + 1);
    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    double ans=y[0]+y[n];
    for(int i=1;i<n;i++)
    {
        if(i%2!=0)
        ans += 4*y[i];
        else
        ans += 2*y[i];
    }
    ans = ans*h/3;
    return ans;
}
double simpsons_3_8_rule(double a,double b,int n)
{
    if(n%3!=0 )
    {
        cout<<"n is not a multiple of 3"<<endl;
        return NAN;
    }
    double h = (b - a) / n;
    vector<double> x(n + 1), y(n + 1);
    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    double ans=f(a)+f(b);
    for(int i=1;i<n;i++)
    {
        if(i%3!=0)
        {
            ans += 3*y[i];
        }
        else
        ans += 2*y[i];
    }
    ans = ans*3*h/8;
    return ans;
}
int main()
{
  cout<<setprecision(6)<<fixed;
  double a,b;
  int n;
  cin>>a>>b>>n;
  cout<<trapezoidal(a,b,n)<<endl;
  cout<<simpson_1_3_rule(a,b,n)<<endl;
  cout<<simpsons_3_8_rule(a,b,n)<<endl;
}