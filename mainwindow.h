#ifndef MAINWINDOW_H
#define MAINWINDOW_H

extern int globalIterations;
extern int playfair;

#include <QMainWindow>
#include "dialog.h"
#include <Eigen/Dense>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class EncryptProgram;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void updateGlobalIterations(int newIterations);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::EncryptProgram *ui;
    Dialog *dialog;

    int modInverse(int a, int m);

    bool isValidInput(const QString& input);

    QVector<QVector<int>> inverseMatrix(const QVector<QVector<int>>& matrix);

    QVector<QVector<int>> transposeMatrix(const QVector<QVector<int>>& matrix);

    QVector<QVector<int>> cofactorMatrix(const QVector<QVector<int>>& matrix);

    int determinant(const QVector<QVector<int>>& matrix);

    QVector<QVector<int>> getMinor(const QVector<QVector<int>>& matrix, int row, int col);

    int modInverseFor4x4(int a);

    double determinant(int n);

    QVector<QVector<int>> multiplyMatrix(QVector<QVector<int>>& a, QVector<QVector<int>>& b, int n);

    QString hillCipherEncrypt(QString text, QVector<QVector<int>>& keyMatrix, int n);
};

#endif // MAINWINDOW_H
