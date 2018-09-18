// Copyright (c) 2009-2015 The Bitcoin Core developers
// Copyright (c) 2015-2018 The Bitcoin Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRIPONE_QT_TEST_URITESTS_H
#define TRIPONE_QT_TEST_URITESTS_H

#include <QObject>
#include <QTest>

class URITests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void uriTestsBase58();
    void uriTestsCashAddr();
    void uriTestFormatURI();
    void uriTestScheme();
};

#endif // TRIPONE_QT_TEST_URITESTS_H
