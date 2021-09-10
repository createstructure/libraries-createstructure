/* createstructure_debian library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_DEBIAN
// If not imported yet
#define CREATESTRUCTURE_DEBIAN

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"
#include "createstructure_inputs.hpp"
#include "createstructure_setting.hpp"
#include "createstructure_emoji.hpp"
#include "createstructure_positive.hpp"
#include "createstructure_rest.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG
#define RESET       "\033[0m"
#define BLACK       "\033[30m"              // Black
#define RED         "\033[31m"              // Red
#define GREEN       "\033[32m"              // Green
#define YELLOW      "\033[33m"              // Yellow
#define BLUE        "\033[34m"              // Blue
#define MAGENTA     "\033[35m"              // Magenta
#define CYAN        "\033[36m"              // Cyan
#define WHITE       "\033[37m"              // White
#define BOLDBLACK   "\033[1m\033[30m"       // Bold Black
#define BOLDRED     "\033[1m\033[31m"       // Bold Red
#define BOLDGREEN   "\033[1m\033[32m"       // Bold Green
#define BOLDYELLOW  "\033[1m\033[33m"       // Bold Yellow
#define BOLDBLUE    "\033[1m\033[34m"       // Bold Blue
#define BOLDMAGENTA "\033[1m\033[35m"       // Bold Magenta
#define BOLDCYAN    "\033[1m\033[36m"       // Bold Cyan
#define BOLDWHITE   "\033[1m\033[37m"       // Bold White

// Classes prototipe(s)
class debian
{
/* debian: the class to handle normal-use requestes for the debian package
 */
private:
    struct question
    {
        string id;                                 // id of the question
        string question;                           // The question
        bool boolean;                              // If the answer is a boolean
        vector<debian::question> ifTrue;  // Questions if true
        vector<debian::question> ifFalse; // Questions if false
    };
    string data;
    vector<question> questions =
        {
            {"name", "Please, insert the repo name: ", false},
            {"template", "Please, insert the template name: ", false},
            {"descr", "Please, insert the repo description: ", false},
            {"prefix", "Please, insert the repo prefix (if you want once): ", false},
            {"isOrg", "Please, insert if you want to put the new repo into an Organization [y/N]: ", true, {{"org", "Please, insert the organization name: ", false}, {"team", "Please, insert the team name (if didn't exist yet, I want to create that for you): ", false}}},
            {"private", "Please, insert do you want that this repo is private [y/N]: ", true}};
    void elaborate_question(question q, json &data);

public:
    debian(inputs i, setting s);
    string to_string();
};

// Function(s)
debian::debian(inputs i, setting s)
{
    /* debian Constructor: the constructor of the debian class
	 *
	 * inputs:
	 * 	- i: the CLI arguments
	 * 	- s: the loaded settings
	 */
    // Get repo data
    json data;
    if (i.exist("--batch") && i.exist("--values"))
    {
        data = json::parse(i.getValue("--values"));
    }
    else
    {
        string tmp;
        bool c = true; // continue

        for (question &q : questions)
            elaborate_question(q, data);
    }

#ifdef DEBUG
    cout << data.dump() << endl;
#endif // DEBUG

    // Run the web-request
    json payload;
    payload["answers"] = data;
    payload["username"] = s.get_username();
    payload["token"] = s.get_token();

#ifdef DEBUG
    cout << payload.dump() << endl;
#endif // DEBUG

#ifdef DEBUG
    cout << textRequest(
        string("https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/create.php"),
        "",
        payload,
        "POST")
        << endl;
#else // DEBUG
    json r = jsonRequest(
        string("https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/create.php"),
        "",
        payload,
        "POST");
    if (r["message"].get<string>().compare("error") == 0) {
        cout << getEmoji("X") << RED << " " << r["error"].get<string>() << RESET << endl;
    } else {
        cout << getEmoji("check") << GREEN << " " << r["message"].get<string>() << RESET << endl;
    }
#endif // DEBUG
}

void debian::elaborate_question(question q, json &data)
{
    /* debian Elaborate Question: elaborates the given question
	 *
	 * inputs:
	 * 	- q: the question
	 * 	- data: the place where to save the answer
	 */
    string tmp;
    cout << getEmoji("info") << "\t" << q.question;
    getline(cin, tmp);

    if (q.boolean)
    {
        bool positive = isPositive(tmp);
        data[q.id] = positive;

        if (positive)
            for (question &q2 : q.ifTrue)
                elaborate_question(q2, data);
        else
            for (question &q2 : q.ifFalse)
                elaborate_question(q2, data);
    }
    else
    {
        data[q.id] = tmp;
    }
}

string debian::to_string()
{
    /* debian to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("debian {\n\tdata: ") + data + "\n}";
}

#endif
