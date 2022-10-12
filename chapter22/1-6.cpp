#include <iostream>
#include <random>

class matrix{
    public:
        // default constructor
        matrix(){
            length_ = 10;
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // see the generator
            std::uniform_int_distribution<> distr(0,length_ - 1);
            std::uniform_int_distribution<> distZeroOne(0,1);
            int target_num = distr(gen);

            /* init a 10 * 10 matrix with all zeros*/
            int matrix[length_][length_] = {};
            /* populate the matrix with either zeros or ones */
            for (int row = 0; row < length_; row ++){
                if (row == target_num){
                    for (int col =0; col < length_; col++){
                    matrix[row][col] = 0;
                }
                } else {
                    for (int col =0; col < length_; col++){
                        matrix[row][col] = distZeroOne(gen);
                    } // col loop 
                }
            } // row loop
            /* replace target row and col with the feature of universal sink
                where a vertex with in-degree = |V| - 1 and out-degree = 0
                which means cols are all one except for the diagnol and rows
                are all zero
             */
            for (unsigned col = 0; col < length_; col++){
                if (col == target_num){
                    unsigned i = 0;
                    while (i < length_){
                        (i != target_num) ? matrix[i][col] = 1 : matrix[i][col]=0;
                    }
                    
                }
            }

        }

        // default destructor
        ~matrix();
    private:
        int length_;
};