/*
* get prime numbers in a integer number; 
* athor: hades 
* date: 2018-2-28 
*/
#include <iostream>
#include <math.h>
using namespace std;
 
int main()
{
    long int input;
 
    //方法一
    //while (cin >> input)
    //{
    //  while (input != 1)
    //  {
    //      for (int i = 2; i <= input; i++)
    //      {
    //          if (input % i == 0)
    //          {
    //              input /= i;
    //              cout << i << ' ';
    //              break;  //只要能被i整除，i总是从2开始
    //          }
    //      }
    //  }
 
    //}
 
    //方法二
    //while (cin >> input)
    //{
    //  for (int i = 2; i <= input; i++)
    //  {
    //      //只要能被i整除，i总是从2开始
    //      if (input%i == 0)
    //      {
    //          input /= i;
    //          cout << i << " ";
    //          i = 1;//经i++之后 i又变为2开始
    //      }
    //  }
    //}
 
    //方法三
    while (cin >> input)
    {
        for (int a = 2; a<= sqrt(input); a++)
        {
            //此处是while,把a整除结束才可加1
            while (input%a == 0)
            {
                cout << a << ' ';
                input = input / a;
            }
        }
        if (input>1) cout << input << ' ';
    }
 
    //system("pause");
    return 0;
}
