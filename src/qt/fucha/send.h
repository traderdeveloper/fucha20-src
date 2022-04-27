// Copyright (c) 2019 The fucha developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SEND_H
#define SEND_H

#include <QWidget>
#include <QPushButton>

#include "qt/fucha/pwidget.h"
#include "qt/fucha/contactsdropdown.h"
#include "qt/fucha/sendmultirow.h"
#include "qt/fucha/sendcustomfeedialog.h"
#include "walletmodel.h"
#include "coincontroldialog.h"
#include "zfuchacontroldialog.h"
#include "qt/fucha/tooltipmenu.h"

static const int MAX_SEND_POPUP_ENTRIES = 8;

class fuchaGUI;
class ClientModel;
class WalletModel;
class WalletModelTransaction;

namespace Ui {
class send;
class QPushButton;
}

class SendWidget : public PWidget
{
    Q_OBJECT

public:
    explicit SendWidget(fuchaGUI* parent);
    ~SendWidget();

    void addEntry();

    void loadClientModel() override;
    void loadWalletModel() override;

signals:
    /** Signal raised when a URI was entered or dragged to the GUI */
    void receivedURI(const QString& uri);

public slots:
    void onChangeAddressClicked();
    void onChangeCustomFeeClicked();
    void onCoinControlClicked();
    void onOpenUriClicked();
    void onValueChanged();
    void refreshAmounts();
    void changeTheme(bool isLightTheme, QString &theme) override;

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onfuchaSelected(bool _isfucha);
    void onSendClicked();
    void onContactsClicked(SendMultiRow* entry);
    void onMenuClicked(SendMultiRow* entry);
    void onAddEntryClicked();
    void clearEntries();
    void clearAll();
    void refreshView();
    void onContactMultiClicked();
    void onDeleteClicked();
    void onResetCustomOptions(bool fRefreshAmounts);
private:
    Ui::send *ui;
    QPushButton *coinIcon;
    QPushButton *btnContacts;

    SendCustomFeeDialog* customFeeDialog = nullptr;
    bool isCustomFeeSelected = false;

    int nDisplayUnit;
    QList<SendMultiRow*> entries;
    CoinControlDialog *coinControlDialog = nullptr;

    ContactsDropdown *menuContacts = nullptr;
    TooltipMenu *menu = nullptr;
    // Current focus entry
    SendMultiRow* focusedEntry = nullptr;

    bool isfucha = true;
    void resizeMenu();
    QString recipientsToString(QList<SendCoinsRecipient> recipients);
    SendMultiRow* createEntry();
    bool send(QList<SendCoinsRecipient> recipients);
    bool sendZfucha(QList<SendCoinsRecipient> recipients);
    void updateEntryLabels(QList<SendCoinsRecipient> recipients);

};

#endif // SEND_H
