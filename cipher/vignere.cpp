//Vigenere Cipher cyclic key
#include<bits/stdc++.h>
using namespace std;

string generateKey(int len, string key)
{
	int i=0;
	while(key.size()<len) key+=key[i++];
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
	string str = "TANMAYISASTUDENT";
	string keyword = "JIIT";

	string key = generateKey(str.length(), keyword);

	string cipher = encrypt(str, key);

	cout << "Ciphertext : "<< cipher << "\n";
	cout << "Decrypted Text : " << decrypt(cipher, key);
	return 0;
}
