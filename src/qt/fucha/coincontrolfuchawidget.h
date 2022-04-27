// Copyright (c) 2019 The fucha developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLfuchaWIDGET_H
#define COINCONTROLfuchaWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlfuchaWidget;
}

class CoinControlfuchaWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlfuchaWidget(QWidget *parent = nullptr);
    ~CoinControlfuchaWidget();

private:
    Ui::CoinControlfuchaWidget *ui;
};

#endif // COINCONTROLfuchaWIDGET_H
