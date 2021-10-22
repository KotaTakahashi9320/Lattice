#pragma once


#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

namespace Lat
{
    const int siz=2;
    class Lattice
    {
    private:
        vector<double>         Message;//平文
        vector<double>         Error_value;//誤差
        vector<double>         Ciphertext;//暗号文
        vector<vector<double> > Secret_key;//秘密鍵
        vector<vector<double> > Unimodular;//ユニモジュラ行列
        vector<vector<double> > Public_key;//公開鍵
        vector<double>         Res;//復号文
    public:
        Lattice()
            : Message(siz,0),
            Error_value(siz,0),
            Ciphertext(siz,0),
            Secret_key(siz,vector<double>(siz,0)),
            Unimodular(siz,vector<double>(siz,0)),
            Public_key(siz,vector<double>(siz,0)),
            Res(siz,0)
            {};
        void Encryption();
        void Decryption();
        void input_Message(vector<double> get_M);
        void input_Secret_key(vector<vector<double> > get_Secret_key);
        void input_Unimodular(vector<vector<double> > get_Unimodular);
        void input_Error_value(vector<double> get_E);
        vector<double> return_Ciphertext();
        vector<double> return_Message();
    };
}
