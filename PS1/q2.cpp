#include <iostream>
#include <ctime>

int roll_again()
{
    return rand() % 6 + 1;
}

int computerTurn(int &computerTotalScore) 
{
    int dice_computer = roll_again();
    std::cout << "Dice for computer: " << dice_computer << std::endl;
    computerTotalScore += dice_computer;
    std::cout << "Computer total score: " << computerTotalScore << std::endl;

    return computerTotalScore;
}

int humanTurn(int &humanTotalScore)
{
    char choice;
    std::cout << "Enter a choice: ";
    std::cin >> choice;

    if (choice == 'r')
    {
        int dice_human = roll_again();
        std::cout << "Dice for human: " << dice_human << std::endl;

        if (dice_human == 1)
        {
            humanTotalScore = 0;
            std::cout << "You rolled a 1! Your total score is reset to 0." << std::endl;
            return humanTotalScore;
        }
        else
            humanTotalScore += dice_human;
    }
    else if (choice == 'h')
        std::cout << "You chose to hold. Your total score remains: " << humanTotalScore << std::endl;

    return humanTotalScore;
}

int main()
{
    srand(time(0)); 

    int humanTotalScore = 0;
    int computerTotalScore = 0;

    while (1)
    {
        while ("This is for human")
        {
            humanTotalScore = humanTurn(humanTotalScore);

            if (humanTotalScore == 0)
                break;
        }

        if (humanTotalScore >= 100)
        {
            std::cout << "Human won!" << std::endl;
            break;
        }

        int tempScore = 0;
        while (tempScore < 20)
        {
            computerTurn(computerTotalScore);
            tempScore = computerTotalScore;
        }

        if (computerTotalScore >= 100)
        {
            std::cout << "Computer won!" << std::endl;
            break;
        }
    }

    return 0;
}
