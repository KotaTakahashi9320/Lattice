#include "main.hpp"

vector<double> test::Encryptiontest(vector<double> get_m,vector<vector<double> > get_B,vector<vector<double> > get_U,vector<double> get_e){
    Lat::Lattice tmp;
    tmp.input_Message(get_m);
    tmp.input_Secret_key(get_B);
    tmp.input_Unimodular(get_U);
    tmp.input_Error_value(get_e);
    tmp.Encryption();
    return tmp.return_Ciphertext();
}

vector<double> test::Decryptiontest(vector<double> get_m,vector<vector<double> > get_B,vector<vector<double> > get_U,vector<double> get_e){
    Lat::Lattice tmp;
    tmp.input_Message(get_m);
    tmp.input_Secret_key(get_B);
    tmp.input_Unimodular(get_U);
    tmp.input_Error_value(get_e);
    tmp.Encryption();
    tmp.Decryption();
    return tmp.return_Message();
}
   
