#include "HTMLEncode.h"
#include <string>

std::string HTMLEncode(std::string const& text)
{
    std::string htmlText;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '&')
        {
            htmlText += "&apos";
            i += 4;
            continue;
        }
        if (text[i] == '/"')
        {
            htmlText += "&quot";
            i += 4;
            continue;
        }
        if (text[i] == '<')
        {
            htmlText += "&lt";
            i += 2;
            continue;
        }
        if (text[i] == '>')
        {
            htmlText += "&gt";
            i += 2;
            continue;
        }
        if (text[i] == '&')
        {
            htmlText += "&amp";
            i += 3;
            continue;
        }
        htmlText += text[i];
    }
    return htmlText;
}
