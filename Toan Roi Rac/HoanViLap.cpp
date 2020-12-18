#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
 
void swap(char& x,char &y)
{
     char temp = x;
     x = y;
     y = temp;
}
 
int main()
{
    string s = "MISSIPI";
    int n = s.length();
    int count = 0 , i , j, k;
    for (i = 0;i < n - 1;i++)
        for (j = i + 1;j < n;j++)
            if (s[i] > s[j]) swap(s[i],s[j]);
    do
    {
       count++;
       cout << count << ": " << s << endl;
       i = n - 2;
       while (i >=0 && s[i] >= s[i+1]) i--;
       if (i >= 0)
       {
          k = n - 1;
          while (s[k] <= s[i]) k--;
          swap(s[i],s[k]);
          int a = i + 1;
          int b = n - 1;
          while (a < b)
          {
                swap(s[a],s[b]);
                a++;
                b--;
          }
       }
    }
    while (i >= 0);
    system("pause");
    return 0;
}