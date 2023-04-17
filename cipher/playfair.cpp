//play cipher
#include <bits/stdc++.h>
using namespace std;

void generateKeyTable(char key[], int ks, char keyT[5][5])
{
	int i, j, k, flag = 0;

	int freq[26] = { 0 };
	for (i = 0; i < ks; i++) {
		if (key[i] != 'j')
			freq[key[i] - 'a'] = 2;
	}

	freq['j' - 'a'] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (freq[key[k] - 'a'] == 2) {
			freq[key[k] - 'a']--;
			keyT[i][j] = key[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (freq[k] == 0) {
			keyT[i][j] = k + 'a';
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

//search the positions of the characters
void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;
	if (a == 'j') a = 'i';
	else if (b == 'j') b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (keyT[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

int mod5(int a) { return (a % 5); }

int makeEven(char str[], int sz)
{
	if (sz % 2 != 0) {
		str[sz++] = 'z';
		str[sz] = '\0';
	}
	return sz;
}

void encrypt(char str[], char keyT[5][5], int len)
{
	int i, a[4];

	for (i = 0; i < len; i += 2) {

		search(keyT, str[i], str[i + 1], a);

        //same row
		if (a[0] == a[2]) {
			str[i] = keyT[a[0]][mod5(a[1] + 1)];
			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
		}
        //same comlumn
		else if (a[1] == a[3]) {
			str[i] = keyT[mod5(a[0] + 1)][a[1]];
			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
		}
        //rectangle opp ends
		else {
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
}

void encryptByPlayfairCipher(char str[], char key[])
{
	char keyT[5][5];
	int klen = strlen(key);
	int slen = strlen(str);

	slen = makeEven(str, slen);

	generateKeyTable(key, klen, keyT);

	encrypt(str, keyT, slen);
}

int main()
{
	char str[30], key[30];
	strcpy(key, "monarchy");
	strcpy(str, "instruments");
	cout << "\nText: " << str << "\n";
	cout << "Key: " << key << "\n";

	encryptByPlayfairCipher(str, key);
	cout << "Cipher text: " << str << "\n\n";
	return 0;
}
