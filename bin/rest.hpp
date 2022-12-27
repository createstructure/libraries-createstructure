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
#include <string>
#include <curl/curl.h> // Remember to compile adding curl (eg. g++ a.cpp -o a -lcurl)
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

class Rest
{
private:
	static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp);

	string link = "";
	string token = "";
	json data = {};
	bool POST = false;

public:
	Rest(string link, string token, json data, bool POST);

	inline static const string CREATESTRUCTURE_REST_API = "https://www.castellanidavide.it/other/createstructure/api/";
	inline static const string GITHUB_REST_API = "https://api.github.com/";

	string textRequest();
	json jsonRequest();
	void request();

	static string textRequest(string link, string token = "", json data = {}, bool POST = false);
	static json jsonRequest(string link, string token = "", json data = {}, bool POST = false);
	static void request(string link, string token = "", json data = {}, bool POST = false);
};

#endif
