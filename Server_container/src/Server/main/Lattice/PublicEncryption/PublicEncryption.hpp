#pragma once

#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

namespace Pub{
    const int siz=2;
    class PublicEncryption{
    public:
        static vector<vector<double> > generatePubKey(vector<vector<double> > U,vector<vector<double> > B);
    };
}