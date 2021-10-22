#include "PublicEncryption.hpp"

vector<vector<double> > Pub::PublicEncryption::generatePubKey(vector<vector<double> > U,vector<vector<double> > B){
    vector<vector<double> > res(Pub::siz,vector<double>(Pub::siz,0));
    for(int i=0;i<Pub::siz;i++){
        for(int j=0;j<Pub::siz;j++){
            for(int k=0;k<Pub::siz;k++){
                res[i][j]+=U[i][k]*B[k][j];
            }
        }
    }
    return res;
}