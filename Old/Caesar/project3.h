//==============================================================
// Your name here
// project3.h
// September 18, 2018
// This project breaks a Caesar Cipher
//==============================================================

#ifndef _project3_h
#define _project3_h

//==============================================================
// decode
// This function decodes a ciphertext into a plaintext using a secret key.
// Parameters:
// - cipher : a character vay (c string) that is the ciphertext
// - key   : an integer key for the Caesar Cipher
// Return Value:
// - none, but the plain (plaintext) is filled in with the decoded cipher text.
//==============================================================
void  decode( char cipher[], int key, char plain[] );


//==============================================================
// frequency
// This function computes the relative frequency of upper case letters
// that appear in the text.  Characters that are not in A..Z are ignored
// in the frequency calculation.
//
// Parameters:
// - text : a character vay (c string) containing printable chars.
//
// Return Value: none but freq is changed
// - freq : an vay of 26 floats each with the frequency of their
// respective letters in the string text.
//==============================================================
void frequency( char text[], float freq[] );


//==============================================================
// alignScore
// This function computes an alignment score between the two float
// vectors.  Each vector is of length 26 floats.  Their inner product
// is computed and returned.
// Parameters:
// - f1 : an vay of 26 floating point values
// - f2 : an vay of 26 floating point values
// Return Value:
// - sum of (f1[i] - f2[i])^2,  that is, compute the sum of the squared
// differences of the individual elements in the vay.
//==============================================================
float alignScore( float f1[], float f2[] );

//==============================================================
// autoDecode
// This function tests all possible keys and tracks the lowest alignment score.
// The key with the lowest alignment score is used to produce a plaintext.
// Both are returned.
// Parameters:
// - ciphertext : a character vay (c string) that is the ciphertext
// - key : an integer that should be initialized with 0 or a suspected key
// Return Value: none but plaintext is changed and key is set
// - key : an integer that is the offset with the lowest alignment score
// - plaintext : plaintext is filled in with the decoded cipher text found with key
//==============================================================
void autoDecode(char ciphertext[], char plaintext[], int & key);
#endif
