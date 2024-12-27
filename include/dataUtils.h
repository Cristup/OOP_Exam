#ifndef DATAUTILS_H_INCLUDED
#define DATAUTILS_H_INCLUDED

#include "libs.h"
#include "util.h"

void read(const string& filename, map<string, int>& word_count, map<string, set<int>>& word_location, set<string>& urls);

#endif
