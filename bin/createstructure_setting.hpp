/* createstructure_setting library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_SETTING
// If not imported yet
#define CREATESTRUCTURE_SETTING

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class setting
{
/* Setting: manage the settings
 */
private:
    string username;
    string token;
    string filename = string(getenv("HOME")) + "/createstructure.setting";

public:
    setting();
    setting(string username, string token);
    bool load();
    bool save();
    string get_username();
    string get_token();
    string to_string();
};

// Function(s)
setting::setting()
{
    /* Setting Normal Constructor: the constructor of the settings class
	 */
    try
    {
        if (!load())
            throw runtime_error("Load setting failed");
    }
    catch (...)
    {
        cout << "Login configuration missing" << endl
             << "Run ... [--login | -l] [[--username | -u] YOUR_USERNAME [--token | -t] YOUR_TOKEN]" << endl
             << "More info: createstructure [--help | -h]" << endl;
        exit(0);
    }
}

setting::setting(string username, string token)
{
    /* Setting Save Constructor: the constructor to save new settings
	 *
	 * inputs:
	 * 	- username: the GitHub username
	 *	- token: the GitHub token
	 */
    this->username = username;
    this->token = token;
    save();
}

bool setting::load()
{
    /* Setting Load: try to load saved settings
     *
	 * output:
	 *	- true if it's loaded correctly, false overwise
	 */
    try
    {
        // Open the file
        ifstream settingFile(filename);

        if (!getline(settingFile, username))
            throw runtime_error("Username missing");
        if (!getline(settingFile, token))
            throw runtime_error("Token missing");

        // Close the file
        settingFile.close();

        // Check
        assert(username != "" && token != "");

        // Return
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool setting::save()
{
    /* Setting Save: save all settings
     *
	 * output:
	 *	- true if it's saved correctly, false overwise
	 */
    try
    {
        // Initial check
        assert(username != "" && token != "");

        // Open the file
        ofstream settingFile(filename.c_str());

        settingFile << username << endl;
        settingFile << token << endl;

        // Close the file
        settingFile.close();

        // Return true
        return true;
    }
    catch (...)
    {
        return false;
    }
}

string setting::get_username()
{
    /* Setting Get Username: get the username
     *
	 * output:
	 *	- the username
	 */
    return username;
}

string setting::get_token()
{
    /* Setting Get Token: get the token
     *
	 * output:
	 *	- the token
	 */
    return token;
}

string setting::to_string()
{
    /* Setting to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("") +
           "setting{\n" +
           "\tusername: " + username + ",\n" +
           "\ttoken: " + token + "\n" +
           "}";
}

#endif
