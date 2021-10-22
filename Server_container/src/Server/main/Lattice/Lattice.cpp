#include "Lattice.hpp"
#include "PublicEncryption/PublicEncryption.hpp"
#include "matrix/matrix.hpp"
void Lat::Lattice::Encryption(){
    Public_key=Pub::PublicEncryption::generatePubKey(Unimodular,Secret_key);
    Ciphertext=Mat::matrix<double>::mul(Message,Public_key);

    for(int i=0;i<Lat::siz;i++){
        Ciphertext[i]+=Error_value[i];
    }
}

void Lat::Lattice::Decryption(){
    vector<double>         tmp(Lat::siz,0);
    vector<vector<double> > Inv_Secret_key=Mat::matrix<double>::Inversematrix(Secret_key);

    tmp=Mat::matrix<double>::mul(Ciphertext,Inv_Secret_key);

    for(int i=0;i<Lat::siz;i++){
        tmp[i]=round(tmp[i]);
    }

    vector<vector<double> > Inv_Unimodular=Mat::matrix<double>::Inversematrix(Unimodular);

    Res=Mat::matrix<double>::mul(tmp,Inv_Unimodular);
}

void Lat::Lattice::input_Message(vector<double> get_m){
    for(int i=0;i<Lat::siz;i++){
        Message[i]=get_m[i];
    }
}

void Lat::Lattice::input_Secret_key(vector<vector<double> > get_S){
    for(int i=0;i<Lat::siz;i++){
        for(int j=0;j<Lat::siz;j++){
            Secret_key[i][j]=get_S[i][j];
        }
    }
}

void Lat::Lattice::input_Unimodular(vector<vector<double> > get_U){
    for(int i=0;i<Lat::siz;i++){
        for(int j=0;j<Lat::siz;j++){
            Unimodular[i][j]=get_U[i][j];
        }
    }
}

void Lat::Lattice::input_Error_value(vector<double> get_e){
    for(int i=0;i<Lat::siz;i++){
        Error_value[i]=get_e[i];
    }
}

vector<double> Lat::Lattice::return_Ciphertext(){
    return Ciphertext;
}

vector<double> Lat::Lattice::return_Message(){
    return Res;
}