//Vigenere Cipher non cyclic
#include<bits/stdc++.h>
using namespace std;

string generateKey(string s, string key)
{
    int n=s.length();
	int i=0;
	while(key.size()<n) key+=s[i++];
	return key;
}

string encrypt(string str, string key)
{
	string cipher;
	for (int i = 0; i < str.size(); i++)
		cipher+= (str[i] + key[i])%26 +'A';

	return cipher;
}

string decrypt(string cipher, string key)
{
	string dec;
	for (int i = 0 ; i < cipher.size(); i++)
		dec+= (cipher[i] - key[i] + 26) %26 +'A';

	return dec;
}

int main()
{
	string str = "WEAREDISCOVEREDSAVEYOURSELF";
	string keyword = "DECEPTIVE";

	string key = generateKey(str, keyword);
    cout<<"\nnew key: "<<key<<endl;

	string cipher = encrypt(str, key);

	cout << "Ciphertext : "<< cipher << "\n";
	cout << "Decrypted Text : " << decrypt(cipher, key)<<endl;
	return 0;
}
