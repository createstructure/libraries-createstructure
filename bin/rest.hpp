/**
 * Rest.hpp
 *
 * This library is used to send and receive data from a REST API.
 *
 * @author: Castellani Davide (@DavideC03)
 */

#ifndef REST
// If not imported yet
#define REST

// Dependencies
#include <bits/stdc++.h>
#include <curl/curl.h> // Remember to compile adding curl (eg. g++ a.cpp -o a -lcurl)
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Rest
{
private:
	string link = "";
	string token = "";
	json data = {};
	bool POST = false;

	static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
	{
		/**
		 * Write callback function
		 *
		 * @param contents: pointer to the data to be written
		 * @param size: size of the data to be written
		 * @param nmemb: number of times the data is written
		 * @param userp: pointer to the user data
		 * @return message size
		 * @note: this function is called by libcurl as soon as there is data to be written
		 */
		((string *)userp)->append((char *)contents, size * nmemb);
		return size * nmemb;
	}

public:
	Rest(string link, string token, json data, bool POST);

	inline static const string CREATESTRUCTURE_REST_API = "https://www.castellanidavide.it/other/createstructure/api/";
	inline static const string GITHUB_REST_API = "https://api.github.com/";

	string textRequest();
	json jsonRequest();
	void request();

	static string textRequest(string link, string token, json data, bool POST);
	static json jsonRequest(string link, string token, json data, bool POST);
	static void request(string link, string token, json data, bool POST);
};

// Function(s)
Rest::Rest(string link, string token, json data, bool POST)
{
	/** Rest Constructor: the constructor of the Rest class
	 *
	 * @param link: the link to the server
	 * @param token: the token to be used
	 * @param data: the data to be sent
	 * @param POST: if the request is a POST or a GET
	 */
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

string Rest::textRequest()
{
	/**
	 * textRequest: sends the request to the server and returns the response
	 *
	 * @return: the response as a string
	 */
	// Function variable(s)
	CURL *curl;
	CURLcode res;
	string readBuffer = "";
	struct curl_slist *slist1;
	string data = Rest::data.dump();

	// Setting header
	slist1 = NULL;
	if (Rest::token != "")
		slist1 = curl_slist_append(slist1, (string("Authorization: token ") + Rest::token).c_str());
	slist1 = curl_slist_append(slist1, "Content-Type: application/json");

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
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	// Return the output string
	return readBuffer;
}

json Rest::jsonRequest()
{
	/**
	 * jsonRequest: sends the request to the server and returns the response
	 *
	 * @return: the response in json format
	 */
	// Function variable(s)
	json response = json::parse(Rest::textRequest());

	// Return the output json
	return response;
}

void Rest::request()
{
	/**
	 * request: sends the request to the server and returns nothing
	 */
	Rest::textRequest();
}

string Rest::textRequest(string link, string token, json data, bool POST)
{
	/**
	 * textRequest: sends the request to the server and returns the response
	 *
	 * @return: the response as a string
	 */
	return Rest(link, token, data, POST).textRequest();
}

json Rest::jsonRequest(string link, string token, json data, bool POST)
{
	/**
	 * jsonRequest: sends the request to the server and returns the response
	 *
	 * @return: the response in json format
	 */
	return Rest(link, token, data, POST).jsonRequest();
}

void Rest::request(string link, string token, json data, bool POST)
{
	/**
	 * request: sends the request to the server and returns nothing
	 */
	Rest(link, token, data, POST).request();
}
#endif
