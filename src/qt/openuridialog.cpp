// Copyright (c) 2011-2013 The Bitcoin Core developers
// Copyright (c) 2015-2018 The Bitcoin Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "openuridialog.h"
#include "ui_openuridialog.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

OpenURIDialog::OpenURIDialog(const Config *_cfg, QWidget *parent)
    : QDialog(parent), ui(new Ui::OpenURIDialog), cfg(_cfg)
{
    ui->setupUi(this);
    ui->uriEdit->setPlaceholderText(GUIUtil::triponeURIScheme(*cfg) + ":");
}

OpenURIDialog::~OpenURIDialog() { delete ui; }
QString OpenURIDialog::getURI() { return ui->uriEdit->text(); }
void OpenURIDialog::accept()
{
    SendCoinsRecipient rcp;
    QString uriScheme = GUIUtil::triponeURIScheme(*cfg);
    if (GUIUtil::parseTriponeURI(uriScheme, getURI(), &rcp))
    {
        /* Only accept value URIs */
        QDialog::accept();
    }
    else
    {
        ui->uriEdit->setValid(false);
    }
}

void OpenURIDialog::on_selectFileButton_clicked()
{
    QString filename = GUIUtil::getOpenFileName(this, tr("Select payment request file to open"), "", "", NULL);
    if (filename.isEmpty())
        return;
    QUrl fileUri = QUrl::fromLocalFile(filename);
    ui->uriEdit->setText(GUIUtil::triponeURIScheme(*cfg) + ":?r=" + QUrl::toPercentEncoding(fileUri.toString()));
}
