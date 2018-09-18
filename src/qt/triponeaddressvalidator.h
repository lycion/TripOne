// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2015-2018 The Bitcoin Unlimited developers
// Copyright (c) 2017 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRIPONE_QT_TRIPONEADDRESSVALIDATOR_H
#define TRIPONE_QT_TRIPONEADDRESSVALIDATOR_H

#include <QValidator>

/**
 * Tripone address entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class TriponeAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TriponeAddressEntryValidator(const std::string &cashaddrprefix, QObject *parent);

    State validate(QString &input, int &pos) const;

private:
    std::string cashaddrprefix;
};

/** Tripone address widget validator, checks for a valid tripone address.
 */
class TriponeAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TriponeAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // TRIPONE_QT_TRIPONEADDRESSVALIDATOR_H
