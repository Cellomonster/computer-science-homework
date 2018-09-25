//==============================================================
// Julian Triveri
// project3.cc
// September 18, 2018
// This program attempts to crack a given Caesar Cipher
// A tale of two cities
//==============================================================

#include <iostream>
#include <math.h>
using namespace std;
#define N 6000

//==============================================================
// decode
// This function decodes a ciphertext into a plaintext using a secret key.
// Parameters:
// - cipher : a character array (c string) that is the ciphertext
// - key   : an integer key for the Caesar Cipher
// Return Value:
// - none, but the plain (plaintext) is filled in with the decoded cipher text.
//==============================================================
void decode( char cipher[], int key, char plain[] ){
	for(int i = 0; i < N; i++){
		//If a capital character
		if(64 < cipher[i] && cipher[i] < 91){
			//Subtract 65 (code for A) to bring down to 0
			int toTest = cipher[i] - key - 65;
			//Check for negative numbers. If so, add 26 to avoid mod-op issues
			plain[i] = ((toTest < 0)? (toTest + 26) % 26 : toTest % 26) + 65;
		}else{
			plain[i] = cipher[i];
		}
	}
	//Set final character to NUL
	plain[N - 1] = 0;
}


//==============================================================
// frequency
// This function computes the relative frequency of upper case letters
// that appear in the text.  Characters that are not in A..Z are ignored
// in the frequency calculation.
//
// Parameters:
// - text : a character array (c string) containing printable chars.
//
// Return Value: none but freq is changed
// - freq : an array of 26 floats each with the frequency of their
// respective letters in the string text.
//==============================================================
void frequency( char text[], float freq[] ){
	int numberOfCharacters = 0;

	for(int i = 0; i < 26; i++)
		freq[i] = 0;

	for(int i = 0; i < N; i++){
		if(64 < text[i] && text[i] < 91){
			//65 subtracted from the ascii code of the character is the index of the
			//value within freq which represents how many occurences of that character
			//are in the input
			freq[text[i] - 65]++;
			numberOfCharacters++;
		}
	}

	for(int i = 0; i < 26; i++)
		freq[i]/=numberOfCharacters;
};


//==============================================================
// alignScore
// This function computes an alignment score between the two float
// vectors.  Each vector is of length 26 floats.  Their inner product
// is computed and returned.
// Parameters:
// - f1 : an array of 26 floating point values
// - f2 : an array of 26 floating point values
// Return Value:
// - sum of (f1[i] - f2[i])^2,  that is, compute the sum of the squared
// differences of the individual elements in the array.
//==============================================================
float alignScore( float f1[], float f2[] ){
	float sum;
	for(int i = 0; i < 26; i++)
		sum += pow(f1[i] - f2[i], 2);
	return sum;
};

//==============================================================
// autoDecode
// This function tests all possible keys and tracks the lowest alignment score.
// The key with the lowest alignment score is used to produce a plaintext.
// Both are returned.
// Parameters:
// - ciphertext : a character array (c string) that is the ciphertext
// - key : an integer that should be initialized with 0 or a suspected key
// Return Value: none but plaintext is changed and key is set
// - key : an integer that is the offset with the lowest alignment score
// - plaintext : plaintext is filled in with the decoded cipher text found with key
//==============================================================
void autoDecode(char ciphertext[], char plaintext[], int & key){
	float freq[26];
	float knownfreq[] =
	{ 0.08167, 0.01492, 0.02782, 0.04253, 0.12702,
		0.02228, 0.02015, 0.06094, 0.06966, 0.00153,
		0.00772, 0.04025, 0.02406, 0.06749, 0.07507,
		0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
		0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074 };

	//Sum of squared differences will never be above 1
	float lowestDifference = 1;


	cout << "Keys and Alignment Scores" << endl;

	//Brute force with each key
	for(int i = 0; i < 26; i++){
		decode(ciphertext, i, plaintext);
		frequency(plaintext, freq);

		//Variable to avoid repetitive function calling
		float alignedScore = alignScore(freq, knownfreq);

		cout << i << ":" << alignedScore << endl;

		if(lowestDifference > alignedScore){
			lowestDifference = alignedScore;
			key = i;
		}
	}

	//Final decode with presumed correct key
	decode(ciphertext, key, plaintext);
	cout << "\n\nOptimal Key and Alignment Score: " << key << " " << lowestDifference << endl;
	cout << "\n\nOptimal Decoded Message\n" << plaintext;
}
