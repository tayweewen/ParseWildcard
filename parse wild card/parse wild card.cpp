// parse wild card.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool IsMatch(char *pString, char *pMatch)
{
    while(*pMatch)
    {
        if(*pMatch == '?')
        {
            if(!*pString)
                return false;

            pMatch++;
            pString++;
        }
    
        else if(*pMatch == '*')
        {
            if(IsMatch(pString, pMatch + 1))
                return true;

            if(IsMatch(pString + 1, pMatch))
                return true;

            return false;
        }
        else
        {
            if(*pMatch++ != *pString++)
                return false;
        }
    }
    // both must be at zero for a match
    return !(*pString || *pMatch); 
}

int _tmain(int argc, _TCHAR* argv[])
{
    bool isMatch = IsMatch("abc", "*");
    return 0;
}

