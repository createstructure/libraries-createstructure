/**
 * @file cryptation.cpp
 *
 * @brief Library to manage the cryptation of data.
 *
 * @author: Castellani Davide (@DavideC03)
 */

// Dependencies
#include "cryptation.hpp"

// Definitions
// #define DEBUG

/**
 * @brief Constructor
 *
 * @param privateKey Private key to use for decryption
 * @param publicKey Public key to use for encryption
 */
Cryptation::Cryptation(string privateKey, string publicKey)
{
	this->privateKey = privateKey;
	this->publicKey = publicKey;
}

/**
 * @brief Constructor
 *
 * @param privateKey Private key to use for decryption
 * @param isPublic True if the private key is the public key, false otherwise
 */
Cryptation::Cryptation(string privateKey, bool isPublic)
{
	if (isPublic)
	{
		this->privateKey = "";
		this->publicKey = privateKey;
	}
	else
	{
		this->privateKey = privateKey;
		this->publicKey = "";
	}
}

/**
 * @brief Empty constructor
 */
Cryptation::Cryptation()
{
	this->privateKey = "";
	this->publicKey = "";
}

/**
 * @brief Encode using base64
 *
 * @param in Input string
 * @return string base64 of the string
 */
string Cryptation::base64_encode(const string &in)
{
	string out;

	int val = 0, valb = -6;
	for (unsigned char c : in)
	{
		val = (val << 8) + c;
		valb += 8;
		while (valb >= 0)
		{
			out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
			valb -= 6;
		}
	}
	if (valb > -6)
		out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
	while (out.size() % 4)
		out.push_back('=');
	return out;
}

/**
 * @brief Decode using base64
 *
 * @param in Input string
 * @return string Decoded string
 */
string Cryptation::base64_decode(const string &in)
{
	string out;
	vector<int> T(256, -1);

	for (int i = 0; i < 64; i++)
		T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

	int val = 0, valb = -8;
	for (unsigned char c : in)
	{
		if (T[c] == -1)
			break;
		val = (val << 6) + T[c];
		valb += 6;
		if (valb >= 0)
		{
			out.push_back(char((val >> valb) & 0xFF));
			valb -= 8;
		}
	}
	return out;
}

/**
 * @brief Create a RSA object from a key
 *
 * @param key The key to use
 * @param isPublic True if the key is public, False id the key is private
 * @return RSA* The RSA object
 */
RSA *Cryptation::createRSA(string key, bool isPublic)
{
	RSA *rsa = NULL;
	BIO *keybio;
	keybio = BIO_new_mem_buf((unsigned char *)key.c_str(), -1);

	if (keybio == NULL)
	{
#ifdef DEBUG
		cerr << "Failed to create key BIO" << endl;
#endif
		return NULL;
	}
	if (isPublic)
	{
		rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
	}
	else
	{
		rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
	}
	if (rsa == NULL)
	{
#ifdef DEBUG
		cerr << "Failed to create RSA" << endl;
#endif
		return NULL;
	}
	return rsa;
}

/**
 * @brief Decrypt a string
 *
 * @param data The string to decrypt
 * @return string The decrypted string
 */
string Cryptation::decrypt(string data)
{
	data = Cryptation::base64_decode(data);
	RSA *rsa = createRSA(Cryptation::privateKey, false);
	if (rsa == NULL)
	{
#ifdef DEBUG
		cerr << "Failed to create RSA" << endl;
#endif
		return "";
	}

	int rsa_len = RSA_size(rsa);
	char *decrypted = (char *)malloc(rsa_len);
	int result = RSA_private_decrypt(rsa_len, (unsigned char *)data.c_str(), (unsigned char *)decrypted, rsa, RSA_PKCS1_PADDING);
	if (result == -1)
	{
#ifdef DEBUG
		cerr << "Failed to decrypt" << endl;
#endif
		return "";
	}
	string decrypted_string = decrypted;
	free(decrypted);
	RSA_free(rsa);
	return decrypted_string;
}

/**
 * @brief Encrypt a string
 *
 * @param data The string to encrypt
 * @return string The encrypted string
 */
string Cryptation::encrypt(string data)
{
	RSA *rsa = createRSA(Cryptation::publicKey, true);
	if (rsa == NULL)
	{
#ifdef DEBUG
		cerr << "Failed to create RSA" << endl;
#endif
		return "";
	}
	int rsa_len = RSA_size(rsa);
	int data_len = strlen(data.c_str()) + 1;
	char *encrypted = (char *)malloc(rsa_len);
	int result = RSA_public_encrypt(data_len, (unsigned char *)data.c_str(), (unsigned char *)encrypted, rsa, RSA_PKCS1_PADDING);
	if (result == -1)
	{
#ifdef DEBUG
		cerr << "Failed to encrypt" << endl;
#endif
		return "";
	}

	// Avoid errors correlated with \0 char
	string tmp = "";
	for (int i = 0; i < rsa_len; i++)
		tmp += encrypted[i];

	string encrypted_string = Cryptation::base64_encode(tmp);
	free(encrypted);
	RSA_free(rsa);
	return encrypted_string;
}

/**
 * @brief Decrypt a string
 *
 * @param data The string to decrypt
 * @param privateKey The private key to use
 *
 * @return string The decrypted string
 */
string Cryptation::decrypt(string data, string privateKey)
{
	return Cryptation(privateKey, false).decrypt(data);
}

/**
 * @brief Encrypt a string
 *
 * @param data The string to encrypt
 * @param publicKey The public key to use
 *
 * @return string The encrypted string
 */
string Cryptation::encrypt(string data, string publicKey)
{
	return Cryptation(publicKey, true).encrypt(data);
}

#undef DEBUG
