#include <iostream>

const int max_digit = 20;

void fill_arr(int *num)
{
    char num_with_char[max_digit + 1];
    std::cin >> num_with_char;

    int len = 0;
    while (num_with_char[len] != '\0')
    {
        if (num_with_char[len] < '0' || num_with_char[len] > '9')
        {
            std::cout << "Invalid input!!" << std::endl;
            fill_arr(num);
            return;
        }
        len++;
    }

    for (int i = 0; i < max_digit; i++)
        num[i] = 0;

    for (int i = 0; i < len; i++)
        num[max_digit - len + i] = num_with_char[i] - '0';
}

void add(int number_one[max_digit], int number_two[max_digit], int result[max_digit])
{
    int carry = 0;

    for (int i = max_digit - 1; i >= 0; --i)
    {
        int digit_sum = number_one[i] + number_two[i] + carry;
        result[i] = digit_sum % 10;
        carry = digit_sum / 10;
    }

    if (carry)
        std::cerr << "Integer overflow!" << std::endl;
}

void print_number(int result[max_digit])
{
    int flag = 1;

    for (int i = 0; i < max_digit; ++i)
    {
        if (result[i] != 0)
            flag = 0;
        
        if (!flag)
            std::cout << result[i];
    }
    
    if (flag)
        std::cout << 0;
}

int main(void)
{
    int number_one[max_digit] = {0};
    int number_two[max_digit] = {0};
    int result[max_digit] = {0};

    int entered_num;

    do
    {
        std::cout << "(1) for enter two number" << std::endl
                  << "(0) for exit program" << std::endl;

        std::cin >> entered_num;

        if (entered_num == 1)
        {
            std::cout << "Please enter two positive number with max " << max_digit << " digits." << std::endl;

            number_one[max_digit] = {0};
            number_two[max_digit] = {0};
            result[max_digit] = {0};

            fill_arr(number_one);
            fill_arr(number_two);

            add(number_one, number_two, result);
            std::cout << "The result is: ";
            print_number(result);
            std::cout << std::endl;
        }
        else if (entered_num != 0)
            std::cerr << "Invalid input!!" << std::endl;
    } while (entered_num);

    return 0;
}
