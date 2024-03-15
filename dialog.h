#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int initialIterations, QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void iterationsChanged(int newIterations);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
