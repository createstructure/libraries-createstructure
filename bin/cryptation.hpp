/**
 * cryptation.hpp
 *
 * Library to manage the cryptation of data.
 *
 * @author: Castellani Davide (@DavideC03)
 */

#ifndef CRYPTATION
// If not imported yet
#define CRYPTATION

// Dependencies
#include <iostream>
#include <string>
#include <vector>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>

// using ...
using namespace std;

// Class prototype(s)
class Cryptation
{
private:
	string privateKey;
	string publicKey;

	RSA *createRSA(string key, bool isPublic);
	string base64_encode(const string &in);
	string base64_decode(const string &in);
public:
	Cryptation(string privateKey, string publicKey);
	Cryptation(string privateKey, bool isPublic);
	Cryptation();
	string decrypt(string data);
	string encrypt(string data);

	static string decrypt(string data, string privateKey);
	static string encrypt(string data, string publicKey);
};

#endif
