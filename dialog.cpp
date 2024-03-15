#include "dialog.h"
#include "ui_dialog.h"

/* Třída Dialog */

Dialog::Dialog(int initialIterations, QWidget *parent) : /* Konstruktor třídy Dialog */
    QDialog(parent), /* Volání konstruktoru rodiče */
    ui(new Ui::Dialog) /* Inicializace uživatelského rozhraní */
{
    ui->setupUi(this); /* Nastavení uživatelského rozhraní */
    ui->spinBox->setValue(initialIterations); /* Nastavení počáteční hodnoty spin boxu */
}

Dialog::~Dialog() /* Destruktor třídy Dialog */
{
    delete ui; /* Uvolnění paměti uživatelského rozhraní */
}

void Dialog::on_buttonBox_accepted() /* Metoda reakce na akceptování dialogu */
{
    int newIterations = ui->spinBox->value(); /* Získání hodnoty ze spin boxu */
    emit iterationsChanged(newIterations); /* Vyslání signálu s novou hodnotou iterací */
    close(); /* Zavření dialogu */
}

void Dialog::on_buttonBox_rejected() /* Metoda reakce na zamítnutí dialogu */
{
    close(); /* Zavření dialogu */
}
