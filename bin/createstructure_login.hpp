/* createstructure_login library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_LOGIN
// If not imported yet
#define CREATESTRUCTURE_LOGIN

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"
#include "createstructure_inputs.hpp"
#include "createstructure_setting.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class login
{
/* Login: the class to handle login requestes
 */
private:
    bool is_login;

public:
    login(inputs i);
    string to_string();
};

// Function(s)
login::login(inputs i)
{
    /* Login Constructor: the constructor of the login class
	 *
	 * inputs:
	 * 	- i: the CLI arguments
	 */
    if (i.exist("--login"))
    {
        if (i.exist("--username") && i.exist("--token"))
        {
            setting(i.getValue("--username"), i.getValue("--token"));
        }
        else
        {
            string username, token;
            cout << "Please insert your GitHub username: ";
            cin >> username;
            cout << "Please insert your GitHub token: ";
            cin >> token;
            cout << username << "\t" << token << endl;
            setting(username, token);
        }

        is_login = true;
        exit(0);
    }
    else
    {
        is_login = false;
    }
}

string login::to_string()
{
    /* Login to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("login {\n\t") + (is_login ? "true" : "false") + "\n}";
}

#endif
