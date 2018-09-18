// Copyright (c) 2017 The Bitcoin Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/test/triponeaddressvalidatortests.h"
#include "chainparams.h"
#include "qt/triponeaddressvalidator.h"
#include <QValidator>

void TriponeAddressValidatorTests::inputTests() {
    const std::string prefix = Params(CBaseChainParams::MAIN).CashAddrPrefix();
    TriponeAddressEntryValidator v(prefix, nullptr);

    int unused = 0;
    QString in;

    // invalid base58 because of I, invalid cashaddr
    in = "BIIC";
    QVERIFY(QValidator::Invalid == v.validate(in, unused));

    // invalid base58, invalid cashaddr
    in = "TRIPONECASHH";
    QVERIFY(QValidator::Invalid == v.validate(in, unused));

    // invalid base58 because of I, but could be a cashaddr prefix
    in = "BITC";
    QVERIFY(QValidator::Acceptable == v.validate(in, unused));

    // invalid base58, valid cashaddr
    in = "TRIPONECASH:QP";
    QVERIFY(QValidator::Acceptable == v.validate(in, unused));

    // valid base58, invalid cash
    in = "BBBBBBBBBBBBBB";
    QVERIFY(QValidator::Acceptable == v.validate(in, unused));
}
