#include <iostream>
#include <time.h>

void charlie_gun_down(int &aaron_is_alive, int &bob_is_alive, int &charlie_is_alive)
{
    if (!charlie_is_alive)
        return ;

    if (bob_is_alive) bob_is_alive = 0;
    else aaron_is_alive = 0;
}

void bob_gun_down(int &aaron_is_alive, int &bob_is_alive, int &charlie_is_alive)
{
    if (!bob_is_alive)
        return ;
    
    bool successful_shoot = !(rand() % 2);

    if (successful_shoot)
    {
        if (charlie_is_alive)
            charlie_is_alive = 0;
        else
            aaron_is_alive = 0;
    }
}

void aaron_gun_down(int &aaron_is_alive, int &bob_is_alive, int &charlie_is_alive)
{
    if (!aaron_is_alive) 
        return;
    
    bool successful_shoot = !(rand() % 3);

    if (successful_shoot)
    {
        if (charlie_is_alive)
            charlie_is_alive = 0;
        else
            bob_is_alive = 0;
    }
}

void killing_strangers(int &aaron_count, int &bob_count, int &charlie_count)
{
    int aaron_is_alive = 1;
    int bob_is_alive = 1;
    int charlie_is_alive = 1;

    do
    {
        aaron_gun_down(aaron_is_alive, bob_is_alive, charlie_is_alive);
        bob_gun_down(aaron_is_alive, bob_is_alive, charlie_is_alive);
        charlie_gun_down(aaron_is_alive, bob_is_alive, charlie_is_alive);
    } while ((aaron_is_alive && bob_is_alive) || 
            (bob_is_alive && charlie_is_alive) || 
            (aaron_is_alive && charlie_is_alive));
    
    if (charlie_is_alive)
        charlie_count++;
    else if (bob_is_alive)
        bob_count++;
    else if (aaron_is_alive)
        aaron_count++;
}

int main(void)
{
    srand(time(0));

    int aaron_count = 0;
    int bob_count = 0;
    int charlie_count = 0;
    int duels = 10000;

    for (int i = 0; i < duels; i++)
        killing_strangers(aaron_count, bob_count, charlie_count);

    std::cout << "Aaron won " << aaron_count << "/" << duels << " dueals or " 
        << aaron_count / static_cast<double>(duels) * 100 << "%\n";
    
    std::cout << "Bob won " << bob_count << "/" << duels << " dueals or " 
        << bob_count / static_cast<double>(duels) * 100 << "%\n";

    std::cout << "Charlie won " << charlie_count << "/" << duels << " dueals or " 
        << charlie_count / static_cast<double>(duels) * 100 << "%\n";
    
    return (0);
}
