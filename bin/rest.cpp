/**
 * @file Rest.cpp
 *
 * @brief This library is used to send and receive data from a REST API.
 *
 * @author: Castellani Davide (@DavideC03)
 */

// Dependencies
#include "rest.hpp"

// Definitions
// #define DEBUG

/** @brief Constructor of the Rest class
 *
 * @param link The link to the server
 * @param token The token to be used
 * @param data The data to be sent
 * @param POST True if the request is a POST, False if it's a GET
 */
Rest::Rest(string link, string token, json data, bool POST)
{
	Rest::link = link;
	Rest::token = token;
	Rest::data = data;
	Rest::POST = POST;

#ifdef DEBUG
	cout << "link:" << Rest::link << endl;
	cout << "token:" << Rest::token << endl;
	cout << "data:" << Rest::data << endl;
	cout << "POST:" << (Rest::POST ? "True" : "False") << endl;
#endif // DEBUG
}

/**
 * @brief Write callback function
 * @note This function is called by libcurl as soon as there is data to be written
 *
 * @param contents Pointer to the data to be written
 * @param size Size of the data to be written
 * @param nmemb Number of times the data is written
 * @param userp Pointer to the user data
 * @return size_t Message size
 */
size_t Rest::WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
	((string *)userp)->append((char *)contents, size * nmemb);
	return size * nmemb;
}

/**
 * @brief Sends the request to the server and returns the response
 *
 * @return string The response as a string
 */
string Rest::textRequest()
{
	// Function variable(s)
	CURL *curl;
	string readBuffer = "";
	struct curl_slist *slist1;
	string data = Rest::data.dump();

	// Setting header
	slist1 = NULL;
	if (Rest::token != "" && !Rest::token.empty())
	{
		slist1 = curl_slist_append(slist1, (string("Authorization: token ") + Rest::token).c_str());
	}
	slist1 = curl_slist_append(slist1, "Content-Type: application/json");
	slist1 = curl_slist_append(slist1, "Accept: application/json");
	slist1 = curl_slist_append(slist1, "Accept: application/vnd.github.v3+json");

	// Setup curl call
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, Rest::link.c_str());
		if (Rest::POST)
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.38.0");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);
		curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, Rest::POST ? "POST" : "GET");
		curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Rest::WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	// Return the output string
	return readBuffer;
}

/**
 * @brief Sends the request to the server and returns the response
 *
 * @return json The response in json format
 */
json Rest::jsonRequest()
{
	// Function variable(s)
	json response = json::parse(Rest::textRequest());

	// Return the output json
	return response;
}

/**
 * @brief Sends the request to the server and returns nothing
 */
void Rest::request()
{
	Rest::textRequest();
}

/**
 * @brief Sends the request to the server and returns the response, without constructor
 *
 * @return string the response as a string
 */
string Rest::textRequest(string link, string token, json data, bool POST)
{
	return Rest(link, token, data, POST).textRequest();
}

/**
 * Sends the request to the server and returns the response, without constructor
 *
 * @return json The response in json format
 */
json Rest::jsonRequest(string link, string token, json data, bool POST)
{
	return Rest(link, token, data, POST).jsonRequest();
}

/**
 * @brief Sends the request to the server and returns nothing, without constructor
 */
void Rest::request(string link, string token, json data, bool POST)
{
	Rest(link, token, data, POST).request();
}

#undef DEBUG
