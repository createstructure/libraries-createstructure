/* createstructure_help library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_HELP
// If not imported yet
#define CREATESTRUCTURE_HELP

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"
#include "createstructure_inputs.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class help
{
/* Help: the class to handle help requestes
 */
private:
    bool is_help;

public:
    help(inputs i, string package);
    string to_string();
};

// Function(s)
help::help(inputs i, string package)
{
    /* Help Constructor: the constructor of the help class
	 *
	 * inputs:
	 * 	- i: the CLI arguments
	 */
    if (i.exist("--help"))
    {
        is_help = true;
        system((string("man ") + package).c_str());
        exit(0);
    }
    else
    {
        is_help = false;
    }
}

string help::to_string()
{
    /* Help to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("help {\n\t") + (is_help ? "true" : "false") + "\n}";
}

#endif
