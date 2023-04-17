//Hill Cipher 3x3
#include<bits/stdc++.h>
using namespace std;

void getKeyMatrix(string key, int keyMatrix[][3])
{
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
            keyMatrix[i][j] = (key[k++]) % 65;
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1])
{
	for (int i = 0; i < 3; i++)
	{
        cipherMatrix[i][0] = 0;
        for (int x = 0; x < 3; x++)
            cipherMatrix[i][0] += keyMatrix[i][x] * messageVector[x][0];
        cipherMatrix[i][0]%=26;
	}
}

// Function to implement Hill Cipher
string HillCipher(string message, string key)
{
	int keyMatrix[3][3];
	getKeyMatrix(key, keyMatrix);

	int messageVector[3][1];
	for (int i = 0; i < 3; i++)
		messageVector[i][0] = (message[i]) % 65;

	int cipherMatrix[3][1];
	encrypt(cipherMatrix, keyMatrix, messageVector);

	string CipherText;
	for (int i = 0; i < 3; i++)
		CipherText+= cipherMatrix[i][0] + 'A';

	return CipherText;
}

int main()
{
	string message = "HEY";
	string key = "DFJIBCRGH";
	string cipher=HillCipher(message, key);
    cout<<"\nmessage: "<<message;
    cout<<"\nkey: "<<key;
    cout<<"\ncipher: "<<cipher<<endl;
	return 0;
}
