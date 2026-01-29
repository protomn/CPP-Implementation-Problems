/*
Problem Statement
Implement a Matrix class backed by std::vector<std::vector<int>>. Support:
    - Constructor (rows, cols) initializing all values to 0
    - get(r, c)
    - set(r, c, value)
    - numRows() / numCols()

Constraints:
    - Must check bounds and throw std::out_of_range on invalid access.
    - No raw pointers.
    - Matrix must be rectangular (all rows same length).
    - Prefer size_t for indexing.
*/

#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix
{
    private:
        std::vector<std::vector<int>> data_;
        size_t rows_;
        size_t cols_;

    public:

        Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols)
        {
            if (rows == 0 || cols == 0)
            {
                throw std::invalid_argument("Matrix dimensions must be > 0.");
            }

            data_.resize(rows, std::vector<int>(cols, 0));
        }

        //Dimension getters
        size_t numRows() const { return rows_; }
        size_t numCols() const { return cols_; }

        void set(size_t r, size_t c, int value)
        {
            if(r >= rows_)
            {
                throw std::out_of_range("Row index out of bounds.");
            }

            if(c >= cols_)
            {
                throw std::out_of_range("Column index out of bounds.");
            }

            data_[r][c] = value;
        }

        int get(size_t r, size_t c) const
        {
            if (r >= rows_ || c >= cols_)
            {
                throw std::out_of_range("Index out of bounds.");
            }

            return data_[r][c];
        }
};

int main()
{
    try
    {
        Matrix mat(3, 3);

        mat.set(1, 1, 42);
        std::cout << "Elem(1, 1): " << mat.get(1, 1) << '\n';

        mat.set(0, 0, 1);
        mat.set(2, 2, 9);

        //Invalid access attempt;
        mat.get(5, 5);
    }

    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}
