#include  "modAlphaCipher.h"

void check(const string& Text, const string& key)
{
    try {
        string cipherText;
        string decryptedText;
        if (key.empty())
            throw cipher_error("Empty key");
        if (stoi(key) > 0) {
            modAlphaCipher cipher(stoi(key));
            cipherText = cipher.encrypt(Text);
            decryptedText = cipher.decrypt(cipherText);
            cout<<"key="<<key<<endl;
            cout<<"Encrypted text:  "<<cipherText<<endl;
            cout<<"Decrypted text:  "<<decryptedText<<endl;
        } else
            throw cipher_error(std::string("Invalid key ")+key);
    } catch (const cipher_error & e) {
        cerr<<"Error:  "<<e.what()<<endl;
    }
    cout<<""<<endl;
}

int main(int argc, char **argv)
{
    check ("LIMB","0");
    check ("LIMB","");
    check ("SOCCER", "7");
    check("S O C C E R","7");
    check("718","7");
}