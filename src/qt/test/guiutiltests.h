// Copyright (c) 2017 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRIPONE_QT_TEST_GUIUTILTESTS_H
#define TRIPONE_QT_TEST_GUIUTILTESTS_H

#include <QObject>
#include <QTest>

class GUIUtilTests : public QObject {
    Q_OBJECT

private Q_SLOTS:
    void dummyAddressTest();
    void toCurrentEncodingTest();
};

#endif // TRIPONE_QT_TEST_GUIUTILTESTS_H
