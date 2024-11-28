#include<bits/stdc++.h>
using namespace std;
double f(double a,double b,double x)
{
    return a*pow(b,x);
}
void backsubstitution(vector<vector<double>> &v, vector<double> &coeff)
{
    int n = v.size();
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

bool gaussElimination(vector<vector<double>>&v,vector<double>&coeff)
{
    cout<<"augemented matrix:"<<endl;
    for(auto e:v)
    {
        for(auto i:e)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int n=v.size();
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(v[i][i]==0)
        {
            int c=1;
            while((i+c)<n && v[i+c][i]==0) 
            c++;
            if(i+c == n)
            {
                flag=1; break;
            }
            swap(v[i+c],v[i]);
        }
        for(int j=i+1;j<n;j++)
        {
            double frac=v[j][i]/v[i][i];
            for(int k=0;k<=n;k++)
            {
                v[j][k] -= frac*v[i][k];
            }
        }
    }
    return flag;
}
void polynomialFit(vector<double> &x, vector<double> &y,int degree, vector<double>&coeff)
{
    int n=degree+1;
    int N=x.size();

    // augemented matrix
    vector<vector<double>> A(n,vector<double>(n,0.0));
    vector<double>b(n,0.0);
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
    // augemnted matrix
    vector<vector<double>>v(n,vector<double>(n+1,0.0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            v[i][j]=A[i][j];
        }
        v[i][n]=b[i];
    }
    
    // solve using gaussian eliminiation
    bool flag=gaussElimination(v,coeff);
    backsubstitution(v,coeff);


}
void linearFit(vector<double> &x, vector<double> &y)
{
    vector<double> coeff;
    polynomialFit(x, y, 1, coeff);
    cout << " Linear fit (y=a+bx): " << "a: " << coeff[0] << " b: " << coeff[1] << endl;
}

void quadraticFit(vector<double>&x,vector<double>&y)
{
    cout<<setprecision(4)<<fixed<<endl;
   vector<double>coeff;
   polynomialFit(x,y,2,coeff);
   double a = coeff[0], b = coeff[1], c = coeff[2];
   cout<<"a: "<<coeff[0]<<" b: "<<coeff[1]<<" c: "<<coeff[2]<<endl;

   
}
void exponentialFit_abx(vector<double>&x,vector<double>&y)
{
    int n=x.size();
  vector<double>logY(n);
  for(int i=0;i<n;i++)
  {
    logY[i]=log(y[i]);
  }
  vector<double>coeff;
  polynomialFit(x,logY,1,coeff);
  double a=exp(coeff[0]);
  double b=exp(coeff[1]);
  cout<<"a: "<<a<<" b: "<<b<<endl;
 
  for (int i = 0; i < x.size(); i++)
  {
      cout << f(a, b, x[i]) << " " << abs(y[i] - f(a, b, x[i])) << endl;
  }
  double sum = 0.0;
  for (int i = 0; i < x.size(); i++)
  {
      sum += abs(y[i] - f(a, b,  x[i]));
  }
  cout << sum / x.size() << endl;
}

void exponentialFit_axb(vector<double> &x, vector<double> &y)
{
    int n = x.size();
    vector<double> logX(n),logY(n);
    for (int i = 0; i < n; i++)
    {
        logX[i] = log(x[i]);
        logY[i]=log(y[i]);
    }
    vector<double> coeff;
    polynomialFit(logX, logY, 1, coeff);
    double a = exp(coeff[0]);
    double b = coeff[1];
    cout << "a: " << a << " b: " << b << endl;
}

int main()
{
     int n; cin>>n;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)
    cin>>x[i];
    for(int i=0;i<n;i++)
    cin>>y[i];

    linearFit(x,y);
 //  quadraticFit(x,y);
  //  exponentialFit_abx(x,y);
   // exponentialFit_axb(x, y);
}