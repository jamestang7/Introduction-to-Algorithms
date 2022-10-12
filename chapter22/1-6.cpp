#include <iostream>
#include <random>

class matrix{
    public:
        // default constructor
        matrix(){
            length_ = 10;
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // see the generator
            std::uniform_int_distribution<> distr(1,length_);
            int target_num = distr(gen);
        }


    private:
        int length_;
};