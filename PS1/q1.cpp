#include <iostream>

int main(void)
{
    int flag;

    for (int i = 3; i <= 100; i++) 
    {
        flag = 1;
        for (int j = 2; j * j <= i; j++) 
        {
            if (i % j == 0) 
            {
                flag = 0;
                break; 
            }
        }
        if (flag)
            std::cout << i << " ";
    }
    return 0;
}
