// Copyright (c) 2015-2017 The Bitcoin Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRIPONE_EXPEDITED_H
#define TRIPONE_EXPEDITED_H

#include "thinblock.h"

enum
{
    EXPEDITED_STOP = 1,
    EXPEDITED_BLOCKS = 2,
    EXPEDITED_TXNS = 4,
};

enum
{
    EXPEDITED_MSG_HDR = 1,
    EXPEDITED_MSG_XTHIN = 2,
};


// Checks to see if the node is configured in tripone.conf to
extern bool CheckAndRequestExpeditedBlocks(CNode *pfrom);

// be an expedited block source and if so, request them.
extern void SendExpeditedBlock(CXThinBlock &thinBlock, unsigned char hops, const CNode *skip = NULL);
extern void SendExpeditedBlock(const CBlock &block, const CNode *skip = NULL);
extern bool HandleExpeditedRequest(CDataStream &vRecv, CNode *pfrom);

// process incoming unsolicited block
extern bool HandleExpeditedBlock(CDataStream &vRecv, CNode *pfrom);

#endif
