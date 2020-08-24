#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include "Token.h"
#include "ExeToken.h"
#include "ConnToken.h"
#include <memory>
using namespace std;

vector<Token*> tokenize (vector<string> &wholetokens);

#endif
