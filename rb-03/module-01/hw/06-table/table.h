#include <algorithm>
#include <iostream>


template <typename T>
class Table { 
    private:
        size_t nrows_;
        size_t ncols_;
        T ** data_;
    public:
        Table(size_t nrows,size_t ncols) : 
            nrows_(nrows),
            ncols_(ncols),
            data_(init(nrows_,ncols_)) {}
        ~Table(){
            free(data_);
        }

        size_t GetNrows() const {return nrows_;}
        size_t GetNcols() const {return ncols_;}
        T * operator[](int i) {return data_[i];}
        const T * operator[](int i) const {return data_[i];}

        std::pair<size_t,size_t> Size() const {
            return std::make_pair(nrows_,ncols_);
        }

        void Resize(size_t nrows, size_t ncols) {

  
                T ** data_new = init(nrows,ncols);
                make_copy(data_,data_new, std::min(nrows_,nrows), std::min(ncols_,ncols));
                free(data_);
                data_ = data_new;
                nrows_ = nrows;
                ncols_ = ncols;


        }
        void Print() const {
            for (size_t i = 0; i < nrows_; i++)
            {
                for (size_t j = 0; j < ncols_; j++)
                {
                    std::cout << data_[i][j] << " ";
                }
                std::cout << "\n";
            }
            
        }


    private:


        void set_nrows(size_t nrows) {nrows_ = nrows;}
        void set_ncols(size_t ncols) {ncols_ = ncols;}



        void free(T ** data){
            delete[] data[0];
            delete[] data;

        }
        void make_copy(T ** src, T ** dst, size_t nrows, size_t ncols){
            for (size_t i = 0; i < nrows; i++)
                for (size_t j = 0; j < ncols; j++)
                    dst[i][j] = src[i][j];
        }
        T ** init(size_t nrows, size_t ncols){
            T ** data = new T *[nrows];
            data[0] = new T[nrows * ncols];
            for (size_t i = 1; i < nrows; i++)
                data[i] = data[i - 1] + ncols;   

            return data; 
    }


};
