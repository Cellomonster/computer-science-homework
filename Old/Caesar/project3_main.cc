//===========================================================
// This client program uses project3.h to crack a Caesar cipher.
// Written by Matt Kretchmar and adapted by Jaimie Kelley
// September 17, 2018
//===========================================================

#include "project3.h"
#define N 6000
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    char cipher[N];         // the original ciphertext as read in
    int n = 0;              // the length of the ciphertext message
    char plain[N];          // place to hold the plaintext message
    float freq[26];         // frequencies we compute from our plaintext
    int key;                // the decoding key
    float score;            // the alignment score

    // letter frequencies for A..Z in regular English writing
    float knownfreq[] =
    { 0.08167, 0.01492, 0.02782, 0.04253, 0.12702,
      0.02228, 0.02015, 0.06094, 0.06966, 0.00153,
      0.00772, 0.04025, 0.02406, 0.06749, 0.07507,
      0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
      0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074 };

    /* This block of code will read a character of input at a time
     from cin until it hits the end of the input (end-of-file).
     The characters are stored in the character array cipher.  */
    while ( cin )
    {
        char c;
        cin >> noskipws >> c;   // noskipws allows us to read spaces
        if ( cin )
            cipher[n++] = c;
    }
    cipher[n] = 0;  // end of buffer

    cout << "Ciphertext = " << cipher << endl;  // comment this out later

    key = 3;
    decode( cipher, key, plain );
    cout << "Test Decode " << key << " " << plain << endl;

    frequency( plain, freq );
    cout << "Test Frequency" << endl;
    for(int i = 0; i < 26; i++){
        cout << i << " " << freq[i] << endl;
    }

    float testScore = alignScore ( freq, knownfreq);
    cout << "Test Alignment Score " << testScore << endl;

    autoDecode(cipher, plain, key);
    cout << key << " " << plain << endl;

    return 0;
}
