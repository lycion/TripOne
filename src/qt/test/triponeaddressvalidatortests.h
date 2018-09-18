// Copyright (c) 2017 The Bitcoin Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRIPONE_QT_TEST_TRIPONEADDRESSVALIDATORTESTS_H
#define TRIPONE_QT_TEST_TRIPONEADDRESSVALIDATORTESTS_H

#include <QObject>
#include <QTest>

class TriponeAddressValidatorTests : public QObject {
    Q_OBJECT

private Q_SLOTS:
    void inputTests();
};

#endif
