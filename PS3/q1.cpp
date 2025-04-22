#include <iostream>

class HotDogStand{
    public:
        HotDogStand();
        HotDogStand(int new_id, unsigned int new_num_sold);
        int GetID();
        void SetID(int new_id);
        void JustSold();
        int GetNumSold();
        static int GetTotalSold();

    private:
        int id;
        int numSold;
        static int totalSold;
};

int HotDogStand::totalSold = 0;

HotDogStand::HotDogStand() : id(0), numSold(0) {}

HotDogStand::HotDogStand(int new_id, unsigned int new_num_sold) : id(new_id), numSold(new_num_sold){
    totalSold += new_num_sold;
}

int HotDogStand::GetID(){
    return (id);
}

void HotDogStand::SetID(int new_id){
    id = new_id;
}

void HotDogStand::JustSold(){
    ++numSold;
    ++totalSold;
}

int HotDogStand::GetNumSold(){
    return (numSold);
}

int HotDogStand::GetTotalSold(){
    return (totalSold);
}

int main()
{
    HotDogStand stand_a(4242, 21);
    HotDogStand stand_b(1923, 7);
    HotDogStand stand_c(569, 5);

    std::cout << "Stand A sold " << stand_a.GetNumSold() << " hotdogs." << std::endl;
    std::cout << "Stand B sold " << stand_b.GetNumSold() << " hotdogs." << std::endl;
    std::cout << "Stand C sold " << stand_c.GetNumSold() << " hotdogs." << std::endl;
    std::cout << "In total " << HotDogStand::GetTotalSold() << " hotdogs were sold.\n" << std::endl;

    for (int i = 0; i < 54; i++)
    {
        stand_a.JustSold();
        if (i % 2 == 0)
            stand_b.JustSold();
        if (i % 3 == 0)
            stand_c.JustSold();
    }
    
    std::cout << "Stand A sold " << stand_a.GetNumSold() << " hotdogs." << std::endl;
    std::cout << "Stand B sold " << stand_b.GetNumSold() << " hotdogs." << std::endl;
    std::cout << "Stand C sold " << stand_c.GetNumSold() << " hotdogs." << std::endl;
    std::cout << "In total " << HotDogStand::GetTotalSold() << " hotdogs were sold." << std::endl;

    return (0);
}
