#include "matrix.hpp"

template <class T>
vector<vector<T> > Mat::matrix<T>::Inversematrix(vector<vector<T> > mat){
    vector<vector<T> > inv_matrix(Mat::siz,vector<T>(Mat::siz));

    for(int i=0;i<Mat::siz;i++){
        for(int j=0;j<Mat::siz;j++){
            inv_matrix[i][j]=(i==j)?1.0:0.0;
        }
    }

    for(int i=0;i<Mat::siz;i++){
        double buf=1/mat[i][i];
        for(int j=0;j<Mat::siz;j++){
            mat[i][j]       *=buf;
            inv_matrix[i][j]*=buf;
        }
        
        for(int j=0;j<Mat::siz;j++){
            if(i==j)continue;
            else{
                buf=mat[j][i];
                for(int k=0;k<Mat::siz;k++){
                    mat[j][k]-=mat[i][k]*buf;
                    inv_matrix[j][k]-=inv_matrix[i][k]*buf;
                }
            }
        }
    }   
    return inv_matrix;
}

template <class T>
void Mat::matrix<T>::output(vector<T> mat){
    for(int i=0;i<Mat::siz;i++)cout << (int)mat[i]<<" ";
    cout <<endl;
}

template <class T>
vector<T> Mat::matrix<T>::mul(vector<T> mat1,vector<vector<T> > mat2){
    vector<T> result(Mat::siz,0);
    for(int i=0;i<Mat::siz;i++){
        for(int j=0;j<Mat::siz;j++){
            result[i]+=mat1[j]*mat2[j][i];
        }
    }
    return result;
}

template class Mat::matrix<double>;