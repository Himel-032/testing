#include <bits/stdc++.h>
using namespace std;

double calculateInterval(vector<double> &v)
{
    int n = v.size() - 1;
    double an = v[0];
    double an_minus1 = (n >= 1) ? v[1] : 0;
    double an_minus2 = (n >= 2) ? v[2] : 0;
    return sqrt(pow(an_minus1 / an, 2) - 2 * (an_minus2 / an));
}

double polynomial(double x, vector<double> &v)
{
    double res = 0.0;
    int n = v.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        res += v[i] * pow(x, n - i);
    }
    return res;
}

double findRootInterval(double a, double b, vector<double> &v, double epsilon, int maxIt)
{
    double f_a = polynomial(a, v);
    double f_b = polynomial(b, v);
    if (f_a * f_b > 0)
        return NAN;

    int iteration = 0;
    double c;
    while (fabs(b - a) > epsilon && iteration < maxIt)
    {
        double f_a = polynomial(a, v);
        double f_b = polynomial(b, v);
        c = (a * f_b - b * f_a) / (f_b - f_a);
        double f_c = polynomial(c, v);
        if (fabs(f_c) < epsilon)
            return c;
        if (f_a * f_c < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
        iteration++;
    }
    return (a + b) / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<double> v(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> v[i];
    }

    double epsilon = 1e-6;
    int maxIt = 20000;
    vector<double> roots;
    double intervalLimit = calculateInterval(v);
    double lowerBound = -intervalLimit, upperBound = intervalLimit;
    int num_intervals = 5000;
    double step = (upperBound - lowerBound) / num_intervals;

    cout << "Interval limit: " << intervalLimit << endl;
    cout << "Lower bound: " << lowerBound << ", Upper bound: " << upperBound << endl;

    for (int i = 0; i < num_intervals; i++)
    {
        double a = lowerBound + i * step;
        double b = a + step;
        double root = findRootInterval(a, b, v, epsilon, maxIt);
        if (!isnan(root))
        {
            bool is_repeated = false;
            for (double r : roots)
            {
                if (fabs(r - root) < epsilon)
                {
                    is_repeated = true;
                    break;
                }
            }
            if (!is_repeated)
            {
                roots.push_back(root);
              //  cout << "Found root: " << root << endl;
            }
        }
    }
    cout << "Roots are: ";
    for (auto r : roots)
    {
        cout << r << "  ";
    }
    cout << endl;
    return 0;
}
