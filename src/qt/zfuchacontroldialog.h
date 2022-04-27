// Copyright (c) 2017-2019 The fucha developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZfuchaCONTROLDIALOG_H
#define ZfuchaCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zfucha/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZfuchaControlDialog;
}

class CZfuchaControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZfuchaControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZfuchaControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZfuchaControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZfuchaControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZfuchaControlDialog(QWidget *parent);
    ~ZfuchaControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZfuchaControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZfuchaControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZfuchaCONTROLDIALOG_H
