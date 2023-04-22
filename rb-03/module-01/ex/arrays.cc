#include <iostream>

using namespace std;


void make_m1d(int n){
    int * a = new int[n];
    for (int i = 0; i < n; ++i){
        std::cout << *(a + i) << " ";
    }
    std::cout << endl;
    delete[] a;

}

void make_m2d(int rows, int cols){
    int ** a2d = new int * [rows];

    for (int i = 0; i < rows; ++i){
        a2d[i] = new int[cols];
    }


    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << a2d[i][j] << " ";
        }
        std::cout << "\n";
        /* code */
    }
    


    for (size_t i = 0; i < rows; i++)
    {
        delete[] a2d[i];

    }
    

    delete[] a2d;
}

template <typename T>
T ** create_2d(size_t nrows, size_t ncols){
    T ** m = new T * [nrows];
    m[0] = new T[nrows * ncols];
    for (size_t i = 1; i < nrows; i++)
    {
        m[i] = m[i - 1] + ncols;
    }
    return m;
}
template <typename T>
void free_2d(T ** m){
    delete[] m[0];
    delete[] m;
}


int main(){



    int ** a = create_2d<int>(3,3);
    free_2d<int>(a);

    return 0;
}