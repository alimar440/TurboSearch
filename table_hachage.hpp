#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H

#include <QDialog>

namespace Ui {
class table_hachage;
}

class table_hachage : public QDialog
{
    Q_OBJECT

public:
    explicit table_hachage(QWidget *parent = nullptr);
    ~table_hachage();

private:
    Ui::table_hachage *ui;
};

#endif // TABLE_HACHAGE_H
