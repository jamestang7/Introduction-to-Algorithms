#include <iostream>
#include <random>
#include <ostream>
#include <vector>
using std::vector;

class matrix{
    private: 
        int length_;
        // static constexpr int length_ = 10;
    public:
        vector<vector<int>> matrix_;
        // default constructor
        vector<vector<int>> getMatrix(){
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // see the generator
            std::uniform_int_distribution<> distr(0,length_ - 1);
            std::uniform_int_distribution<> distZeroOne(0,1);
            int target_num = distr(gen);

            matrix_.resize(length_, vector<int>(length_, 0));
            /* populate the matrix with either zeros or ones */
            for (int row = 0; row < length_; row ++){
                if (row == target_num){
                    for (int col =0; col < length_; col++){
                    matrix_[row][col] = 0;
                }
                } else {
                    for (int col =0; col < length_; col++){
                        matrix_[row][col] = distZeroOne(gen);
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
                        (i != target_num) ? matrix_[i][col] = 1 : matrix_[i][col]=0;
                        i++;
                    }
                    
                }
            }
            return matrix_;
        };
        // customized constructor
        vector<vector<int>> getMatrix(const int target_num){
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // see the generator
        std::uniform_int_distribution<> distr(0,length_ - 1);
        std::uniform_int_distribution<> distZeroOne(0,1);

        /* populate the matrix with either zeros or ones */
        for (int row = 0; row < length_; row ++){
            if (row == target_num){
                for (int col =0; col < length_; col++){
                matrix_[row][col] = 0;
            }
            } else {
                for (int col =0; col < length_; col++){
                    matrix_[row][col] = distZeroOne(gen);
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
                    (i != target_num) ? matrix_[i][col] = 1 : matrix_[i][col]=0;
                    i++;
                }
                
            }
        }
        return matrix_;
    }
        // get helper function
        int get(const int row, const int col){
            return matrix_[row][col];
        };
        // destructor
        ~matrix();
        // print helper function
        friend std::ostream& operator<<(std::ostream& os, matrix& m){
            os << "Printing matrix..." << std::endl;
            for (unsigned row=0; row < m.length_; row++){
                for (unsigned col=0; col < m.length_; col++){
                    os << m.get(row, col) << ", ";
                }
                os << std::endl;
            }
        };
};
int main(){
    

}