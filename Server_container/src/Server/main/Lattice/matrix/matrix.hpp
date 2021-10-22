#pragma once

#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
namespace Mat{
    const int siz=2;
    template <class T>
    class matrix{
    public: 
        static vector<vector<T> > Inversematrix(vector<vector<T> > mat);
        static vector<T>         mul(vector<T> mat1,vector<vector<T> > mat2);
        static void              output(vector<T> mat);
    }; 
}