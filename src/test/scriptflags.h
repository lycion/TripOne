// Copyright (c) 2018 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRIPONE_TEST_SCRIPTFLAGS_H
#define TRIPONE_TEST_SCRIPTFLAGS_H

#include <string>

uint32_t ParseScriptFlags(std::string strFlags);
std::string FormatScriptFlags(uint32_t flags);

#endif // TRIPONE_TEST_SCRIPTFLAGS_H
