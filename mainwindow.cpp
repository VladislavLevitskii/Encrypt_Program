/*
 * Autor je Vladislav Levitskii, jestli chcete, můžete ten kód zkopírovat, mně to nevadí, můj GitHub: https://github.com/VladislavLevitskii
 * Tato maturitní práce byla vytvořena s dodržením všech pravidel autorského práva a za podpory mého vyučujícího, Mgr. Pavla Mádlého.
 * SPŠ Liberec 2024
 * Celý kód okomentoval ChatGpt, protože se mi trošku nechtělo
*/
#include "mainwindow.h" // Vložení vlastní hlavičkové souboru pro hlavní okno
#include "ui_mainwindow.h" // Vložení generovaného souboru pro uživatelské rozhraní
#include <chrono> // Vložení hlavičkového souboru pro časové funkce
#include <QDateTime> // Vložení hlavičkového souboru pro práci s datem a časem v Qt
#include <QTimer> // Vložení hlavičkového souboru pro časovač v Qt
#include <QClipboard> // Vložení hlavičkového souboru pro práci se schránkou v Qt
#include <QCoreApplication> // Vložení hlavičkového souboru pro jádro aplikace v Qt
#include <QTextStream> // Vložení hlavičkového souboru pro práci se vstupně-výstupními daty v Qt
#include <QInputDialog> // Vložení hlavičkového souboru pro dialog s vstupním polem v Qt
#include <QMessageBox> // Vložení hlavičkového souboru pro zobrazování oken s vzkazy v Qt
#include <QLineEdit> // Vložení hlavičkového souboru pro vstupní pole v Qt
#include <numeric> // Vložení hlavičkového souboru pro algoritmy v C++
#include <QDebug> // Vložení hlavičkového souboru pro ladění v Qt
#include <QRegularExpression> // Vložení hlavičkového souboru pro regulární výrazy v Qt
#include <QtGui/QMatrix4x4> // Vložení hlavičkového souboru pro práci s 4x4 maticemi v Qt
#include <QRandomGenerator> // Vložení hlavičkového souboru pro generování náhodných čísel v Qt
#include <Eigen/Dense> // Vložení hlavičkového souboru pro vektorovou a maticovou knihovnu Eigen

MainWindow::MainWindow(QWidget *parent) // Definice konstruktoru třídy MainWindow
    : QMainWindow(parent) // Volání konstruktoru rodiče
    , ui(new Ui::EncryptProgram) // Inicializace uživatelského rozhraní
{
    ui->setupUi(this); // Nastavení uživatelského rozhraní pro hlavní okno
    dialog = new Dialog(globalIterations, this); // Vytvoření nové instance dialogového okna s počátečním počtem iterací
    // Připojení signálů a slotů
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked); // Připojení tlačítka "pushButton" k metodě "on_pushButton_clicked"
    connect(dialog, &Dialog::iterationsChanged, this, &MainWindow::updateGlobalIterations); // Připojení signálu "iterationsChanged" z dialogového okna k metodě "updateGlobalIterations"
    // Lambda funkce pro reakci na změnu indexu v comboBoxu
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index){
        // Podmínky pro nastavení hodnoty proměnné "playfair" a povolení/zakázání vstupních polí podle vybraného indexu
        if (index == 0) {
            playfair = 2;
            // Nastavení proměnné "playfair" na hodnotu 2
            // Nastavení povolení/zakázání vstupních polí
            ui->lineEdit->setDisabled(false);
            ui->lineEdit_2->setDisabled(false);
            ui->lineEdit_3->setDisabled(true);
            ui->lineEdit_4->setDisabled(false);
            ui->lineEdit_5->setDisabled(false);
            ui->lineEdit_6->setDisabled(true);
            ui->lineEdit_7->setDisabled(true);
            ui->lineEdit_8->setDisabled(true);
            ui->lineEdit_9->setDisabled(true);
            ui->lineEdit_10->setDisabled(true);
            ui->lineEdit_11->setDisabled(true);
            ui->lineEdit_12->setDisabled(true);
            ui->lineEdit_13->setDisabled(true);
            ui->lineEdit_14->setDisabled(true);
            ui->lineEdit_15->setDisabled(true);
            ui->lineEdit_16->setDisabled(true);
            ui->lineEdit_17->setDisabled(true);
            ui->lineEdit_18->setDisabled(true);
            ui->lineEdit_19->setDisabled(true);
            ui->lineEdit_20->setDisabled(true);
            ui->lineEdit_21->setDisabled(true);
            ui->lineEdit_22->setDisabled(true);
            ui->lineEdit_23->setDisabled(true);
            ui->lineEdit_24->setDisabled(true);
            ui->lineEdit_25->setDisabled(true);
        } else if (index == 1) {
            playfair = 3;
            ui->lineEdit->setDisabled(false);
            ui->lineEdit_2->setDisabled(false);
            ui->lineEdit_3->setDisabled(false);
            ui->lineEdit_4->setDisabled(false);
            ui->lineEdit_5->setDisabled(false);
            ui->lineEdit_6->setDisabled(false);
            ui->lineEdit_7->setDisabled(false);
            ui->lineEdit_8->setDisabled(false);
            ui->lineEdit_9->setDisabled(false);
            ui->lineEdit_10->setDisabled(true);
            ui->lineEdit_11->setDisabled(true);
            ui->lineEdit_12->setDisabled(true);
            ui->lineEdit_13->setDisabled(true);
            ui->lineEdit_14->setDisabled(true);
            ui->lineEdit_15->setDisabled(true);
            ui->lineEdit_16->setDisabled(true);
            ui->lineEdit_17->setDisabled(true);
            ui->lineEdit_18->setDisabled(true);
            ui->lineEdit_19->setDisabled(true);
            ui->lineEdit_20->setDisabled(true);
            ui->lineEdit_21->setDisabled(true);
            ui->lineEdit_22->setDisabled(true);
            ui->lineEdit_23->setDisabled(true);
            ui->lineEdit_24->setDisabled(true);
            ui->lineEdit_25->setDisabled(true);
        } else if (index == 2) {
            playfair = 4;
            ui->lineEdit->setDisabled(false);
            ui->lineEdit_2->setDisabled(false);
            ui->lineEdit_3->setDisabled(false);
            ui->lineEdit_4->setDisabled(false);
            ui->lineEdit_5->setDisabled(false);
            ui->lineEdit_6->setDisabled(false);
            ui->lineEdit_7->setDisabled(false);
            ui->lineEdit_8->setDisabled(false);
            ui->lineEdit_9->setDisabled(false);
            ui->lineEdit_10->setDisabled(false);
            ui->lineEdit_11->setDisabled(false);
            ui->lineEdit_12->setDisabled(false);
            ui->lineEdit_13->setDisabled(true);
            ui->lineEdit_14->setDisabled(true);
            ui->lineEdit_15->setDisabled(true);
            ui->lineEdit_16->setDisabled(false);
            ui->lineEdit_17->setDisabled(false);
            ui->lineEdit_18->setDisabled(false);
            ui->lineEdit_19->setDisabled(false);
            ui->lineEdit_20->setDisabled(true);
            ui->lineEdit_21->setDisabled(true);
            ui->lineEdit_22->setDisabled(true);
            ui->lineEdit_23->setDisabled(true);
            ui->lineEdit_24->setDisabled(true);
            ui->lineEdit_25->setDisabled(true);
        } else {
            playfair = 5;
            ui->lineEdit->setDisabled(false);
            ui->lineEdit_2->setDisabled(false);
            ui->lineEdit_3->setDisabled(false);
            ui->lineEdit_4->setDisabled(false);
            ui->lineEdit_5->setDisabled(false);
            ui->lineEdit_6->setDisabled(false);
            ui->lineEdit_7->setDisabled(false);
            ui->lineEdit_8->setDisabled(false);
            ui->lineEdit_9->setDisabled(false);
            ui->lineEdit_10->setDisabled(false);
            ui->lineEdit_11->setDisabled(false);
            ui->lineEdit_12->setDisabled(false);
            ui->lineEdit_13->setDisabled(false);
            ui->lineEdit_14->setDisabled(false);
            ui->lineEdit_15->setDisabled(false);
            ui->lineEdit_16->setDisabled(false);
            ui->lineEdit_17->setDisabled(false);
            ui->lineEdit_18->setDisabled(false);
            ui->lineEdit_19->setDisabled(false);
            ui->lineEdit_20->setDisabled(false);
            ui->lineEdit_21->setDisabled(false);
            ui->lineEdit_22->setDisabled(false);
            ui->lineEdit_23->setDisabled(false);
            ui->lineEdit_24->setDisabled(false);
            ui->lineEdit_25->setDisabled(false);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialog;
}

using namespace Eigen;
using namespace std;

int globalIterations = 1; // Počáteční počet iterací
int playfair = 2; // Počet prvků pro Playfair šifru
const int mod = 26; // Modulární hodnota pro šifrování (zde 26 pro anglickou abecedu)

QVector<QVector<int>> MainWindow::multiplyMatrix(QVector<QVector<int>>& a, QVector<QVector<int>>& b, int n) {
    // Vytvoření matice pro výsledek
    QVector<QVector<int>> result(n, QVector<int>(1, 0));
    // Iterace přes řádky matice a
    for (int i = 0; i < n; ++i) {
        // Iterace přes sloupce matice b
        for (int j = 0; j < 1; ++j) {
            // Vynásobení řádku a sloupcem, přičtení do výsledku
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
            // Výsledek modulo 26 (počet písmen v abecedě)
            result[i][j] %= 26;
        }
    }
    return result;
}

QString MainWindow::hillCipherEncrypt(QString text, QVector<QVector<int>>& keyMatrix, int n) {
    QString result = "";
    // Iterace přes bloky textu
    for (int i = 0; i < text.length(); i += n) {
        // Vytvoření bloku pro šifrování
        QVector<QVector<int>> block(n, QVector<int>(1));
        // Naplnění bloku hodnotami písmen textu
        for (int j = 0; j < n; ++j) {
            block[j][0] = text[i + j].toLatin1() - 'a';
        }
        // Šifrování bloku
        auto encryptedBlock = multiplyMatrix(keyMatrix, block, n);
        // Přidání zašifrovaného bloku do výsledku
        for (int j = 0; j < n; ++j) {
            result += QChar(encryptedBlock[j][0] + 'a');
        }
    }
    return result;
}

// Tato funkce hledá inverzní prvek modulo 26 pro zadané číslo 'a'.
int MainWindow::modInverseFor4x4(int a) {
    // Zajištění, že 'a' je v rozsahu 0 až 25 (včetně), což umožňuje provádět operace modulo 26.
    a = a % 26;

    // Procházení všech čísel od 1 do 25 (včetně), abychom našli inverzní prvek.
    for (int x = 1; x < 26; x++) {
        // Výpočet součinu 'a' a 'x' a aplikace modulo 26.
        int result = (a * x) % 26;

        // Pokud je výsledek záporný, přičte se k němu 26, aby byl v rozsahu 0 až 25 (včetně).
        if (result < 0)
            result += 26;

        // Pokud je výsledek roven 1, znamená to, že 'x' je inverzní prvek k 'a'.
        if (result == 1)
            return x;
    }

    // Pokud se nepodaří najít inverzní prvek, vrátí -1 (označení pro neplatný výsledek).
    return -1;
}

// Tato funkce vytváří minorovou matici pro daný řádek a sloupec vstupní matice.
QVector<QVector<int>> MainWindow::getMinor(const QVector<QVector<int>>& matrix, int row, int col) {
    // Získání rozměru vstupní matice
    int n = matrix.size();

    // Vytvoření prázdné minorové matice s rozměry (n - 1) x (n - 1)
    QVector<QVector<int>> minor(n - 1, QVector<int>(n - 1));

    // Inicializace indexů pro minorovou matici
    int minorRow = 0, minorCol = 0;

    // Procházení každého řádku vstupní matice
    for (int i = 0; i < n; ++i) {
        // Pokud se index řádku rovná zadanému řádku, přeskočí se tento řádek
        if (i == row) {
            continue;
        }

        // Resetování indexu sloupce pro minorovou matici
        minorCol = 0;

        // Procházení každého sloupce vstupní matice
        for (int j = 0; j < n; ++j) {
            // Pokud se index sloupce rovná zadanému sloupci, přeskočí se tento sloupec
            if (j == col) {
                continue;
            }

            // Přiřazení hodnoty z vstupní matice do minorové matice
            minor[minorRow][minorCol] = matrix[i][j];
            // Inkrementace indexu sloupce minorové matice
            ++minorCol;
        }
        // Inkrementace indexu řádku minorové matice
        ++minorRow;
    }
    // Vrácení minorové matice
    return minor;
}


// Tato funkce vypočítá determinant matici
int MainWindow::determinant(const QVector<QVector<int>>& matrix) {
    // Získání rozměru matice
    int n = matrix.size();

    // Pokud je matice 1x1, determinant je jednoduše prvek této matice
    if (n == 1) {
        return matrix[0][0];
    }
    // Pokud je matice 2x2, použije se vzorec pro determinant 2x2 matice
    else if (n == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26;
    }
    // Pro větší matice se použije Laplaceův rozvoj
    else {
        int det = 0; // Inicializace determinantu

        // Pro každý sloupec prvního řádku matice
        for (int j = 0; j < n; ++j) {
            // Vypočítání minorové matice pro daný sloupec
            QVector<QVector<int>> minor = getMinor(matrix, 0, j);

            // Určení znaménka pro tento sloupec pomocí vzoru (-1)^j
            int sign = (j % 2 == 0) ? 1 : -1;

            // Rekurzivní volání determinantu pro minorovou matici a její násobení s odpovídajícím prvkem z původní matice
            det = (det + sign * matrix[0][j] * determinant(minor)) % 26;
        }
        // Návrat vypočítaného determinantu modulo 26
        return det;
    }
}


// Tato funkce spočítá matici koeficientů (cofactor matrix).
QVector<QVector<int>> MainWindow::cofactorMatrix(const QVector<QVector<int>>& matrix) {
    // Získání rozměru matice
    int n = matrix.size();

    // Inicializace matice koeficientů s rozměry n x n
    QVector<QVector<int>> cofactor(n, QVector<int>(n));

    // Procházení každého prvku matice
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Výpočet minorové matice pro daný prvek
            QVector<QVector<int>> minor = getMinor(matrix, i, j);

            // Určení znaménka pro daný prvek pomocí vzoru (-1)^(i+j)
            int sign = ((i + j) % 2 == 0) ? 1 : -1;

            // Vypočítání determinantu minorové matice, násobení znaménka a přičtení 26 pro zajištění nezáporného výsledku, a nakonec modulo 26
            cofactor[i][j] = (sign * determinant(minor) + 26) % 26;
        }
    }
    // Vrácení matice koeficientů
    return cofactor;
}


// Tato funkce provádí transpozici matice.
QVector<QVector<int>> MainWindow::transposeMatrix(const QVector<QVector<int>>& matrix) {
    // Získání rozměru matice
    int n = matrix.size();

    // Inicializace matice transpozice s rozměry n x n
    QVector<QVector<int>> transpose(n, QVector<int>(n));

    // Procházení každého prvku matice
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Přiřazení hodnoty z původní matice na odpovídající pozici v transponované matici
            transpose[i][j] = matrix[j][i];
        }
    }
    // Vrácení transponované matice
    return transpose;
}


// Tato funkce spočítá inverzní matici zadané matice.
QVector<QVector<int>> MainWindow::inverseMatrix(const QVector<QVector<int>>& matrix) {
    // Získání rozměru matice
    int n = matrix.size();

    // Inicializace inverzní matice s rozměry n x n
    QVector<QVector<int>> inverse(n, QVector<int>(n));

    // Vypočítání determinantu zadané matice
    int det = determinant(matrix);

    // Pokud je determinant roven 0, není možné vytvořit inverzní matici
    if (det == 0) {
        // Vypsání chybového hlášení, pokud determinant je 0
        QMessageBox::critical(this, "Chyba", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matice.");
        return inverse; // Návrat prázdné matice
    }

    // Výpočet inverzní hodnoty determinantu
    int detInverse = modInverseFor4x4(det);

    // Výpočet matice koeficientů (cofactor matrix)
    QVector<QVector<int>> cofactorMat = cofactorMatrix(matrix);

    // Výpočet adjungované matice (adjoint matrix)
    QVector<QVector<int>> adjointMat = transposeMatrix(cofactorMat);

    // Výpočet hodnot jednotlivých prvků inverzní matice
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Násobení hodnoty odpovídajícího prvku adjungované matice a inverzní hodnoty determinantu, a aplikace modulo 26
            inverse[i][j] = (adjointMat[i][j] * detInverse) % 26;
            // Pokud je hodnota záporná, přičte se k ní 26, aby byla v rozsahu 0 až 25 (včetně)
            if (inverse[i][j] < 0) {
                inverse[i][j] += 26;
            }
        }
    }

    // Návrat inverzní matice
    return inverse;
}

// Tato funkce vypočítá inverzní prvek čísla 'a' modulo 'm'.
int MainWindow::modInverse(int a, int m) {
    // Zajištění, že 'a' je v rozsahu 0 až (m-1) (včetně), což umožňuje provádět operace modulo 'm'.
    a = a % m;

    // Procházení všech čísel od 1 do (m-1) (včetně), aby se hledal inverzní prvek.
    for (int x = 1; x < m; x++) {
        // Výpočet součinu 'a' a 'x' a aplikace modulo 'm'.
        int result = (a * x) % m;

        // Pokud je výsledek záporný, přičte se k němu 'm', aby byl v rozsahu 0 až (m-1) (včetně).
        if (result < 0)
            result += m;

        // Pokud je výsledek roven 1, znamená to, že 'x' je inverzní prvek k 'a'.
        if (result == 1)
            return x;
    }
    // Pokud se nepodaří najít inverzní prvek, vrátí -1 (označení pro neplatný výsledek).
    return -1;
}


// Definice maximální velikosti matice a globálního dvourozměrného pole pro ukládání prvků matice.
const int MAXN = 105;
double a[MAXN][MAXN];


// Tato funkce vypočítá determinant čtvercové matice 'a' o velikosti 'n'.
double MainWindow::determinant(int n) {
    double det = 1.0; // Inicializace determinantu na 1.0

    // Procházení každého řádku matice 'a'
    for (int i = 0; i < n; i++) {
        int pivot = i; // Inicializace indexu pivotu na aktuální řádek
        // Procházení každého řádku pod pivotem
        for (int j = i + 1; j < n; j++) {
            // Hledání řádku s největším absolutním hodnotou prvku v pivotovém sloupci
            if (std::abs(a[j][i]) > std::abs(a[pivot][i])) {
                pivot = j;
            }
        }
        // Pokud pivot není na aktuálním řádku, prohodí řádky a změní znaménko determinantu
        if (pivot != i) {
            for (int j = 0; j < n; j++) {
                std::swap(a[i][j], a[pivot][j]);
            }
            det *= -1;
        }
        // Pokud prvek na diagonále je 0, determinant je roven 0
        if (a[i][i] == 0) {
            return 0;
        }
        // Aktualizace determinantu
        det *= a[i][i];
        // Eliminace prvků pod diagonálou
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = i + 1; k < n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }
    // Návrat vypočítaného determinantu
    return det;
}


/*Caesar*/


// Tato metoda slouží k aktualizaci globální proměnné 'globalIterations' na zadanou hodnotu ze spinBoxu.
void MainWindow::updateGlobalIterations(int newIterations) {
    globalIterations = newIterations; // Nastavení hodnoty 'globalIterations' na novou hodnotu 'newIterations'
}

// Tato metoda je vyvolána po stisknutí tlačítka a provádí šifrování textu pomocí Caesarovy šifry.
void MainWindow::on_pushButton_clicked() {
    // Získání hodnoty posunu ze spin boxu
    int step = ui->spinBox->value();

    // Inicializace proměnné pro celkový čas šifrování v mikrosekundách
    double totalMicroseconds = 0;

    // Získání vstupního textu z textového pole
    QString inputText = ui->textEdit->toPlainText();

    // Regularní výraz pro kontrolu vstupního textu - povolené jsou pouze písmena a mezery
    QRegularExpression rx("[A-Za-z ]*");

    // Kontrola vstupního textu pomocí regularního výrazu
    if (!rx.match(inputText).hasMatch()) {
        // Pokud vstupní text obsahuje nepovolené znaky, zobrazí se chybové hlášení
        QMessageBox::critical(this, "Chyba", "Input musí obsahovat jenom symboly (a-z, A-Z) a mezery");
        return;
    }

    QString result; // Proměnná pro ukládání zašifrovaného textu

    // Provedení šifrování 'globalIterations'-krát
    for (int iteration = 0; iteration < globalIterations; ++iteration) {
        // Začátek měření času
        auto start = std::chrono::high_resolution_clock::now();

        result.clear(); // Vymazání předchozího zašifrovaného textu

        // Procházení každého znaku vstupního textu
        for (int i = 0; i < inputText.length(); i++) {
            QChar ch = inputText.at(i);
            if (ch.isLetter()) {
                // Pokud je znak písmeno, provede se šifrování
                QChar base = ch.isUpper() ? 'A' : 'a'; // Určení základního písmene ('A' nebo 'a')
                // Výpočet posunutého písmene pomocí Caesarovy šifry
                QChar shiftedChar = QChar(((ch.toLatin1() - base.toLatin1() + step) % 26) + base.toLatin1());
                // Přidání posunutého písmene do výsledného textu
                result.append(shiftedChar);
            } else {
                // Pokud znak není písmeno, zůstane nezměněný
                result.append(ch);
            }
        }

        // Konec měření času
        auto end = std::chrono::high_resolution_clock::now();

        // Výpočet trvání šifrování v mikrosekundách
        std::chrono::duration<double, std::micro> elapsed = end - start;

        // Aktualizace celkového času šifrování
        totalMicroseconds += elapsed.count();
    }

    // Nastavení zašifrovaného textu do textového pole pro výstup
    ui->textBrowser->setPlainText(result);

    // Výpočet průměrného času šifrování
    double averageMicroseconds = totalMicroseconds / globalIterations;

    // Aktualizace textu v popisku pro zobrazení průměrného času šifrování
    ui->label_5->setText("Čas šifrování je: " + QString::number(averageMicroseconds) + " µs");
}


void MainWindow::on_pushButton_10_clicked() //dešifrování pomocí Caesarovy sifry
{
    int step = ui->spinBox->value();
    double totalMicroseconds = 0;
    QString inputText = ui->textEdit->toPlainText();
    QRegularExpression rx("[A-Za-z ]*");

    if (!rx.match(inputText).hasMatch()) {
        QMessageBox::critical(this, "Chyba", "Input musí obsahovat jenom symboly (a-z, A-Z) a mezery");
        return;
    }

    QString result;

    for (int iteration = 0; iteration < globalIterations; ++iteration) {
        auto start = std::chrono::high_resolution_clock::now();
        result.clear();
        for (int i = 0; i < inputText.length(); i++) {
            QChar ch = inputText.at(i);
            if (ch.isLetter()) {
                QChar base = ch.isUpper() ? 'A' : 'a';
                int shiftedValue = ch.toLatin1() - base.toLatin1() - step; // tady je změna (odecitani step)
                if (shiftedValue < 0) {
                    shiftedValue += 26;
                }
                QChar shiftedChar = QChar((shiftedValue % 26) + base.toLatin1());
                result.append(shiftedChar);
            } else {
                result.append(ch);
            }
        }

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> elapsed = end - start;
        totalMicroseconds += elapsed.count();
    }

    ui->textBrowser->setPlainText(result);

    double averageMicroseconds = totalMicroseconds / globalIterations;
    ui->label_5->setText("Čas dešifrování je: " + QString::number(averageMicroseconds) + " µs");
}

/*Vigener*/

// Tato metoda je vyvolána po stisknutí tlačítka a provádí šifrování textu pomocí Vigenèrovy šifry.
void MainWindow::on_pushButton_2_clicked() {
    // Inicializace proměnné pro celkový čas šifrování v mikrosekundách
    double totalMicroseconds = 0;

    // Získání vstupního textu ze vstupního textového pole
    QString inputText = ui->textEdit_2->toPlainText();

    // Získání klíče ze vstupního textového pole a převod na malá písmena
    QString key = ui->textEdit_3->toPlainText().toLower();

    // Inicializace proměnné pro ukládání zašifrovaného textu
    QString result;

    // Kontrola, zda je klíč prázdný
    if (key.isEmpty()) {
        QMessageBox::critical(this, "Chyba", "Klíč není");
        return;
    }

    // Kontrola klíče, zda obsahuje pouze písmena a číslice
    for (QChar ch : key) {
        if (!ch.isLetterOrNumber() && ch != ' ') {
            QMessageBox::critical(this, "Chyba", "Klíč musí obsahovat jenom symboly (a-z, A-Z) a číslice");
            return;
        }
    }

    // Kontrola vstupního textu, zda obsahuje pouze písmena a číslice
    for (QChar ch : inputText) {
        if (!ch.isLetterOrNumber() && ch != ' ') {
            QMessageBox::critical(this, "Chyba", "Input musí obsahovat jenom symboly (a-z, A-Z) a číslice");
            return;
        }
    }

    // Provedení šifrování 'globalIterations'-krát
    for (int iteration = 0; iteration < globalIterations; ++iteration) {
        // Začátek měření času
        auto start = std::chrono::high_resolution_clock::now();

        // Vymazání předchozího zašifrovaného textu
        result.clear();

        // Procházení každého znaku vstupního textu
        for (int i = 0; i < inputText.length(); ++i) {
            QChar currentChar = inputText.at(i);

            if (currentChar.isLetter()) {
                // Pokud je znak písmeno, provede se šifrování
                QChar base = currentChar.isUpper() ? 'A' : 'a'; // Určení základního písmene ('A' nebo 'a')

                // Získání písmene z klíče na pozici 'i % key.length()' (cyklický posun)
                QChar keyChar = key.at(i % key.length());
                QChar keyBase = keyChar.isUpper() ? 'A' : 'a'; // Určení základního písmene klíče
                int shift = keyChar.toLatin1() - keyBase.toLatin1(); // Výpočet posunu dle písmene klíče

                // Výpočet posunu aktuálního písmene vstupního textu a aplikace Vigenèrovy šifry
                int currentShift = currentChar.toLatin1() - base.toLatin1();
                QChar shiftedChar = QChar(((currentShift + shift) % 26) + base.toLatin1());

                // Přidání zašifrovaného písmene do výsledného textu
                result.append(shiftedChar);
            } else {
                // Pokud znak není písmeno, zůstane nezměněný
                result.append(currentChar);
            }
        }

        // Konec měření času
        auto end = std::chrono::high_resolution_clock::now();

        // Výpočet trvání šifrování v mikrosekundách
        std::chrono::duration<double, std::micro> elapsed = end - start;

        // Aktualizace celkového času šifrování
        totalMicroseconds += elapsed.count();
    }

    // Nastavení zašifrovaného textu do textového pole pro výstup
    ui->textBrowser_2->setPlainText(result);

    // Výpočet průměrného času šifrování
    double averageMicroseconds = totalMicroseconds / globalIterations;

    // Aktualizace textu v popisku pro zobrazení průměrného času šifrování
    ui->label_6->setText("Čas šifrování je: " + QString::number(averageMicroseconds) + " µs");
}

void MainWindow::on_pushButton_3_clicked() //dešifrování
{
    double totalMicroseconds = 0;
    QString inputText = ui->textEdit_2->toPlainText();
    QString key = ui->textEdit_3->toPlainText().toLower();
    QString result;

    if (key.isEmpty()) {
        QMessageBox::critical(this, "Chyba", "Klíč není");
        return;
    }

    for (QChar ch : key) {
        if (!ch.isLetterOrNumber() && ch != ' ') {
            QMessageBox::critical(this, "Chyba", "Klíč musí obsahovat jenom symboly (a-z, A-Z) a číslice");
            return;
        }
    }

    for (QChar ch : inputText) {
        if (!ch.isLetterOrNumber() && ch != ' ') {
            QMessageBox::critical(this, "Chyba", "Input musí obsahovat jenom symboly (a-z, A-Z) a číslice");
            return;
        }
    }

    for (int iteration = 0; iteration < globalIterations; ++iteration) {
        auto start = std::chrono::high_resolution_clock::now();

        result.clear();

        for (int i = 0; i < inputText.length(); ++i) {
            QChar currentChar = inputText.at(i);

            if (currentChar.isLetter()) {
                QChar base = currentChar.isUpper() ? 'A' : 'a';
                QChar keyChar = key.at(i % key.length());
                QChar keyBase = keyChar.isUpper() ? 'A' : 'a';
                int shift = keyChar.toLatin1() - keyBase.toLatin1();
                int currentShift = currentChar.toLatin1() - base.toLatin1();

                int shiftedIndex = currentShift - shift; //tady je změna
                if (shiftedIndex < 0)
                    shiftedIndex += 26;

                QChar shiftedChar = QChar((shiftedIndex % 26) + base.toLatin1());

                result.append(shiftedChar);
                } else {
                result.append(currentChar);
            }
        }



        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> elapsed = end - start;
        totalMicroseconds += elapsed.count();
    }

    ui->textBrowser_2->setPlainText(result);

    double averageMicroseconds = totalMicroseconds / globalIterations;
    ui->label_6->setText("Čas dešifrování je: " + QString::number(averageMicroseconds) + " µs");
}

// Tato metoda je vyvolána po stisknutí tlačítka a vytváří nové dialogové okno pro změnu počtu iterací.
void MainWindow::on_pushButton_4_clicked() {
    // Pokud už existuje instance dialogového okna, odstraní ji
    if (dialog)
        delete dialog;

    // Vytvoření nové instance dialogového okna a předání aktuálního počtu iterací
    dialog = new Dialog(globalIterations, this);

    // Propojení signálu změny iterací z dialogového okna s metodou aktualizace globálního počtu iterací
    connect(dialog, &Dialog::iterationsChanged, this, &MainWindow::updateGlobalIterations);

    // Zobrazení dialogového okna
    dialog->show();
}


// Tato metoda je vyvolána po stisknutí tlačítka a kopíruje text z textového pole do schránky, zatímco zobrazuje dočasnou ikonu potvrzení.
void MainWindow::on_pushButton_5_clicked() {
    // Získání ukazatele na tlačítko
    QPushButton *button = ui->pushButton_5;

    // Uložení aktuální ikony tlačítka
    QIcon oldIcon = button->icon();

    // Nastavení ikony tlačítka na ikonu potvrzení
    button->setIcon(QIcon(":/img/img/tick-svgrepo-com.svg"));

    // Nastavení časovače pro vrácení původní ikony po 3000 ms (3 sekundy)
    QTimer::singleShot(3000, this, [button, oldIcon]() {
        button->setIcon(oldIcon);
    });

    // Získání textu k zkopírování z textového pole
    QString textToCopy = ui->textEdit_2->toPlainText();

    // Kopírování textu do schránky
    QApplication::clipboard()->setText(textToCopy);
}

// buttony 5-9, 11, 13 dělají to samé

void MainWindow::on_pushButton_6_clicked()
{
    QPushButton *button = ui->pushButton_6;
    QIcon oldIcon = button->icon();
    button->setIcon(QIcon(":/img/img/tick-svgrepo-com.svg"));
    QTimer::singleShot(3000, this, [button, oldIcon]() {
        button->setIcon(oldIcon);
    });
    QString textToCopy = ui->textBrowser_2->toPlainText();
    QApplication::clipboard()->setText(textToCopy);
}

void MainWindow::on_pushButton_7_clicked()
{
    QPushButton *button = ui->pushButton_7;
    QIcon oldIcon = button->icon();
    button->setIcon(QIcon(":/img/img/tick-svgrepo-com.svg"));
    QTimer::singleShot(3000, this, [button, oldIcon]() {
        button->setIcon(oldIcon);
    });
    QString textToCopy = ui->textEdit_3->toPlainText();
    QApplication::clipboard()->setText(textToCopy);
}


void MainWindow::on_pushButton_8_clicked()
{
    QPushButton *button = ui->pushButton_8;
    QIcon oldIcon = button->icon();
    button->setIcon(QIcon(":/img/img/tick-svgrepo-com.svg"));
    QTimer::singleShot(3000, this, [button, oldIcon]() {
        button->setIcon(oldIcon);
    });
    QString textToCopy = ui->textEdit->toPlainText();
    QApplication::clipboard()->setText(textToCopy);
}


void MainWindow::on_pushButton_9_clicked()
{
    QPushButton *button = ui->pushButton_9;
    QIcon oldIcon = button->icon();
    button->setIcon(QIcon(":/img/img/tick-svgrepo-com.svg"));
    QTimer::singleShot(3000, this, [button, oldIcon]() {
        button->setIcon(oldIcon);
    });
    QString textToCopy = ui->textBrowser->toPlainText();
    QApplication::clipboard()->setText(textToCopy);
}

void MainWindow::on_pushButton_13_clicked()
{
    QPushButton *button = ui->pushButton_13;
    QIcon oldIcon = button->icon();
    button->setIcon(QIcon(":/img/img/tick-svgrepo-com.svg"));
    QTimer::singleShot(3000, this, [button, oldIcon]() {
        button->setIcon(oldIcon);
    });
    QString textToCopy = ui->textEdit_5->toPlainText();
    QApplication::clipboard()->setText(textToCopy);
}


void MainWindow::on_pushButton_11_clicked()
{
    QPushButton *button = ui->pushButton_11;
    QIcon oldIcon = button->icon();
    button->setIcon(QIcon(":/img/img/tick-svgrepo-com.svg"));
    QTimer::singleShot(3000, this, [button, oldIcon]() {
        button->setIcon(oldIcon);
    });
    QString textToCopy = ui->textBrowser_3->toPlainText();
    QApplication::clipboard()->setText(textToCopy);
}

bool MainWindow::isValidInput(const QString& input) {
    QRegularExpression regex("^[a-z\\s]*$");
    return regex.match(input).hasMatch();
}

/*

Hill Cipher \
            \
            \
            V
*/


// Tato metoda je vyvolána po stisknutí tlačítka pro šifrování metodou Hill Cipher.
void MainWindow::on_pushButton_14_clicked()
{
    double totalMicroseconds = 0;
    QString inputText = ui->textEdit_5->toPlainText();
    // Odstranění všech mezerníků ze vstupního textu
    inputText.remove(QRegularExpression("\\s"));

    // Kontrola platnosti vstupního textu
    if (!isValidInput(inputText)) {
        QMessageBox::critical(this, "Chyba", "Input obsahuje neplatné znaky. Povolena jsou pouze písmena a až z a mezery.");
        return;
    }

    QString result;
    int sum = 0;

    for (int iteration = 0; iteration < globalIterations; ++iteration) {
        auto start = std::chrono::high_resolution_clock::now();

        if (playfair == 2) {
            // kontrola, zda je délka vstupního textu sudá, případně doplňte znak 'x' na konec
            int remainder = inputText.length() % 2;
            if (remainder != 0) {
                inputText += QString(2 - remainder, 'x');
            }

            // Vytvoření matice klíče 2x2
            QVector<QVector<int>> keyMatrix(2, QVector<int>(2));
            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();

            // Výpočet determinantu matice klíče
            int determinant = keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0];
            // Kontrola determinantu a modulu na vzájemnou prvočíselnost
            if (std::gcd(determinant, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            int detInverse;

            // Výpočet inverzního determinantu
            detInverse = modInverse(determinant, mod);

            // Kontrola validity determinantu a jeho inverzní hodnoty
            if (determinant == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Chyba", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            // Šifrování vstupního textu pomocí Hill Cipher s klíčem 2x2
            result.clear();

            for (int k = 0; k < inputText.size(); k += 2) {
                // Procházení klíče a výpočet součtu pro každý znak
                for (int i = 0; i < 2; ++i) {
                    sum = 0;
                    int temp = k;
                    // Iterace přes 2x2 matici klíče
                    for (int j = 0; j < 2; ++j) {
                        QChar currentChar = inputText[temp++];
                        // Kontrola, zda je znak písmeno a malé písmeno
                        if (currentChar.isLetter() && currentChar.isLower()) {
                            // Výpočet součtu pro písmeno a přidání k součtu
                            sum += (keyMatrix[i][j] % 26) * ((currentChar.unicode() - 'a' + 26) % 26);
                        } else {
                            // Přidání znaku do výsledku, pokud není písmeno
                            result += currentChar;
                         }
                    }
                    // Přidání zašifrovaného znaku do výsledku
                    if (sum != 0) {
                    sum %= 26;
                    if (sum < 0)
                        sum += 26;
                    result += QChar(sum + 'a');
                    }
                }
            }
        } else if (playfair == 3) { //bude se to opakovat stejně jako u 2 × 2, jenom místo 2 je 3

            int remainder = inputText.length() % 3;
            if (remainder != 0) {
                inputText += QString(3 - remainder, 'x');
            }
            QVector<QVector<int>> keyMatrix(3, QVector<int>(3));
            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[0][2] = ui->lineEdit_3->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();
            keyMatrix[1][2] = ui->lineEdit_6->text().toInt();
            keyMatrix[2][0] = ui->lineEdit_7->text().toInt();
            keyMatrix[2][1] = ui->lineEdit_8->text().toInt();
            keyMatrix[2][2] = ui->lineEdit_9->text().toInt();

            int determinant = keyMatrix[0][0] * (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][1]) - keyMatrix[0][1] * (keyMatrix[1][0] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][0]) + keyMatrix[0][2] * (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[1][1] * keyMatrix[2][0]);

            if (std::gcd(determinant, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            int detInverse;

            detInverse = modInverse(determinant, mod);

            if (determinant == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Chyba", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }
            result.clear();
                for (int k = 0; k < inputText.size(); k += 3) {
                    int sum[3] = {0, 0, 0};
                    for (int i = 0; i < 3; ++i) {
                        int temp = k;
                        for (int j = 0; j < 3; ++j) {
                            QChar currentChar = inputText[temp++];
                            if (currentChar.isLetter() && currentChar.isLower()) {
                                sum[i] += (keyMatrix[i][j] % 26) * ((currentChar.unicode() - 'a' + 26) % 26);
                            } else {
                                result += currentChar;
                            }
                        }
                    }
                    for (int i = 0; i < 3; ++i) {
                        sum[i] %= 26;
                        if (sum[i] < 0)
                            sum[i] += 26;
                        result += QChar(sum[i] + 'a');
                    }
                }


        } else if (playfair == 4) {
            int remainder = inputText.length() % 4;
            if (remainder != 0) {
                inputText += QString(4 - remainder, 'x');
            }
            int n = 4;
            QVector<QVector<int>> keyMatrix(4, QVector<int>(4));
            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[0][2] = ui->lineEdit_3->text().toInt();
            keyMatrix[0][3] = ui->lineEdit_12->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();
            keyMatrix[1][2] = ui->lineEdit_6->text().toInt();
            keyMatrix[1][3] = ui->lineEdit_11->text().toInt();
            keyMatrix[2][0] = ui->lineEdit_7->text().toInt();
            keyMatrix[2][1] = ui->lineEdit_8->text().toInt();
            keyMatrix[2][2] = ui->lineEdit_9->text().toInt();
            keyMatrix[2][3] = ui->lineEdit_10->text().toInt();
            keyMatrix[3][0] = ui->lineEdit_17->text().toInt();
            keyMatrix[3][1] = ui->lineEdit_16->text().toInt();
            keyMatrix[3][2] = ui->lineEdit_18->text().toInt();
            keyMatrix[3][3] = ui->lineEdit_19->text().toInt();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = keyMatrix[i][j];
                }
            }

            double det = determinant(n);
            int determinant_rounded = static_cast<int>(std::round(det));

            int detInverse = modInverse(determinant_rounded, mod);

            if (std::gcd(determinant_rounded, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            if (determinant_rounded == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Ошибка", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné maticи.");
                return;
            }
            result.clear();

                for (int k = 0; k < inputText.size(); k += 4) {
                    int sum[4] = {0, 0, 0, 0};
                    for (int i = 0; i < 4; ++i) {
                        int temp = k;
                        for (int j = 0; j < 4; ++j) {
                            QChar currentChar = inputText[temp++];
                            if (currentChar.isLetter() && currentChar.isLower()) {
                                sum[i] += (keyMatrix[i][j] % 26) * ((currentChar.unicode() - 'a' + 26) % 26);
                            } else {
                                result += currentChar;
                            }
                        }
                    }
                    for (int i = 0; i < 4; ++i) {
                        sum[i] %= 26;
                        if (sum[i] < 0)
                            sum[i] += 26;
                        result += QChar(sum[i] + 'a');
                    }
                }
        } else {
            int remainder = inputText.length() % 5;
            if (remainder != 0) {
                inputText += QString(5 - remainder, 'x');
            }

            int n = 5;
            QVector<QVector<int>> keyMatrix(5, QVector<int>(5));
            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[0][2] = ui->lineEdit_3->text().toInt();
            keyMatrix[0][3] = ui->lineEdit_12->text().toInt();
            keyMatrix[0][4] = ui->lineEdit_14->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();
            keyMatrix[1][2] = ui->lineEdit_6->text().toInt();
            keyMatrix[1][3] = ui->lineEdit_11->text().toInt();
            keyMatrix[1][4] = ui->lineEdit_13->text().toInt();
            keyMatrix[2][0] = ui->lineEdit_7->text().toInt();
            keyMatrix[2][1] = ui->lineEdit_8->text().toInt();
            keyMatrix[2][2] = ui->lineEdit_9->text().toInt();
            keyMatrix[2][3] = ui->lineEdit_10->text().toInt();
            keyMatrix[2][4] = ui->lineEdit_15->text().toInt();
            keyMatrix[3][0] = ui->lineEdit_17->text().toInt();
            keyMatrix[3][1] = ui->lineEdit_16->text().toInt();
            keyMatrix[3][2] = ui->lineEdit_18->text().toInt();
            keyMatrix[3][3] = ui->lineEdit_19->text().toInt();
            keyMatrix[3][4] = ui->lineEdit_20->text().toInt();
            keyMatrix[4][0] = ui->lineEdit_22->text().toInt();
            keyMatrix[4][1] = ui->lineEdit_21->text().toInt();
            keyMatrix[4][2] = ui->lineEdit_23->text().toInt();
            keyMatrix[4][3] = ui->lineEdit_24->text().toInt();
            keyMatrix[4][4] = ui->lineEdit_25->text().toInt();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = keyMatrix[i][j];
                }
            }

            double det = determinant(n);
            int determinant_rounded = static_cast<int>(std::round(det));

            int detInverse = modInverse(determinant_rounded, mod);

            if (std::gcd(determinant_rounded, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            if (determinant_rounded == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Ошибка", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné maticи.");
                return;
            }

                result.clear();

                result = hillCipherEncrypt(inputText, keyMatrix, n);
        }

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> elapsed = end - start;
        totalMicroseconds += elapsed.count();
    }

    ui->textBrowser_3->setPlainText(result);
    double averageMicroseconds = totalMicroseconds / globalIterations;
    ui->label_9->setText("Čas šifrování je: " + QString::number(averageMicroseconds) + " µs");
}

void MainWindow::on_pushButton_15_clicked() //dešifrování Hill (velmi podobné jako u šifrování až na několik vyjimek)
{

    double totalMicroseconds = 0;
    QString inputText = ui->textEdit_5->toPlainText();
    inputText.remove(QRegularExpression("\\s"));

    if (!isValidInput(inputText)) {
        QMessageBox::critical(this, "Chyba", "Input obsahuje neplatné znaky. Povolena jsou pouze písmena a až z a mezery.");
        return;
    }

    QString result;

    for (int iteration = 0; iteration < globalIterations; ++iteration) {
        auto start = std::chrono::high_resolution_clock::now();

        if (playfair == 2) {

            QVector<QVector<int>> keyMatrix(2, QVector<int>(2));
            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();

            int determinant = keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0];
            int detInverse;

            if (std::gcd(determinant, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            detInverse = modInverse(determinant, mod);

            if (determinant == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Ошибка", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            //inverzní matice 2 × 2
            QVector<QVector<int>> inverseMatrix(2, QVector<int>(2));
            inverseMatrix[0][0] = keyMatrix[1][1];
            inverseMatrix[0][1] = -keyMatrix[0][1];
            inverseMatrix[1][0] = -keyMatrix[1][0];
            inverseMatrix[1][1] = keyMatrix[0][0];

            //uplatneni mod na matici
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    inverseMatrix[i][j] = (inverseMatrix[i][j] * detInverse) % mod;
                    if (inverseMatrix[i][j] < 0) {
                        inverseMatrix[i][j] += mod;
                    }
                }
            }

            //dešifrování
            result.clear();
                for (int k = 0; k < inputText.size(); k += 2) {
                    QString pair = inputText.mid(k, 2);
                    QVector<int> cipherPair(2);
                    for (int i = 0; i < 2; ++i) {
                        cipherPair[i] = pair[i].unicode() - 'a';
                    }

                    //rozdělení na páry (v dalších případech to bude na trojice atd.)
                    QVector<int> decryptedPair(2);
                    decryptedPair[0] = (inverseMatrix[0][0] * cipherPair[0] + inverseMatrix[0][1] * cipherPair[1]) % mod;
                    decryptedPair[1] = (inverseMatrix[1][0] * cipherPair[0] + inverseMatrix[1][1] * cipherPair[1]) % mod;

                    for (int i = 0; i < 2; ++i) {
                        if (decryptedPair[i] < 0) {
                            decryptedPair[i] += mod;
                        }
                        result += QChar(decryptedPair[i] + 'a');
                    }
                }

        } else if (playfair == 3) {

            QVector<QVector<int>> keyMatrix(3, QVector<int>(3));
            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[0][2] = ui->lineEdit_3->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();
            keyMatrix[1][2] = ui->lineEdit_6->text().toInt();
            keyMatrix[2][0] = ui->lineEdit_7->text().toInt();
            keyMatrix[2][1] = ui->lineEdit_8->text().toInt();
            keyMatrix[2][2] = ui->lineEdit_9->text().toInt();

            int determinant = keyMatrix[0][0] * (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][1]) - keyMatrix[0][1] * (keyMatrix[1][0] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][0]) + keyMatrix[0][2] * (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[1][1] * keyMatrix[2][0]);
            int detInverse;

            if (std::gcd(determinant, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            detInverse = modInverse(determinant, mod);

            if (determinant == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Ошибка", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné maticи.");
                return;
            }

            //invertibilita
            QVector<QVector<int>> inverseMatrix(3, QVector<int>(3));
            inverseMatrix[0][0] = (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][1]) % mod;
            inverseMatrix[0][1] = ((keyMatrix[0][2] * keyMatrix[2][1] - keyMatrix[0][1] * keyMatrix[2][2]) % mod + mod) % mod;
            inverseMatrix[0][2] = (keyMatrix[0][1] * keyMatrix[1][2] - keyMatrix[0][2] * keyMatrix[1][1]) % mod;
            inverseMatrix[1][0] = ((keyMatrix[1][2] * keyMatrix[2][0] - keyMatrix[1][0] * keyMatrix[2][2]) % mod + mod) % mod;
            inverseMatrix[1][1] = (keyMatrix[0][0] * keyMatrix[2][2] - keyMatrix[0][2] * keyMatrix[2][0]) % mod;
            inverseMatrix[1][2] = ((keyMatrix[0][2] * keyMatrix[1][0] - keyMatrix[0][0] * keyMatrix[1][2]) % mod + mod) % mod;
            inverseMatrix[2][0] = (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[1][1] * keyMatrix[2][0]) % mod;
            inverseMatrix[2][1] = ((keyMatrix[0][1] * keyMatrix[2][0] - keyMatrix[0][0] * keyMatrix[2][1]) % mod + mod) % mod;
            inverseMatrix[2][2] = (keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0]) % mod;

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    inverseMatrix[i][j] = (inverseMatrix[i][j] * detInverse) % mod;
                    if (inverseMatrix[i][j] < 0) {
                        inverseMatrix[i][j] += mod;
                    }
                }
            }
            result.clear();
                for (int k = 0; k + 2 < inputText.size(); k += 3) {
                    QString triple = inputText.mid(k, 3);
                    QVector<int> cipherTriple(3);
                    for (int i = 0; i < 3; ++i) {
                        cipherTriple[i] = triple[i].unicode() - 'a';
                    }

                    //rozdeleni na trojice
                    QVector<int> decryptedTriple(3);
                    decryptedTriple[0] = (inverseMatrix[0][0] * cipherTriple[0] + inverseMatrix[0][1] * cipherTriple[1] + inverseMatrix[0][2] * cipherTriple[2]) % mod;
                    if (decryptedTriple[0] < 0) {
                        decryptedTriple[0] += mod;
                    }
                    decryptedTriple[1] = (inverseMatrix[1][0] * cipherTriple[0] + inverseMatrix[1][1] * cipherTriple[1] + inverseMatrix[1][2] * cipherTriple[2]) % mod;
                    if (decryptedTriple[1] < 0) {
                        decryptedTriple[1] += mod;
                    }
                    decryptedTriple[2] = (inverseMatrix[2][0] * cipherTriple[0] + inverseMatrix[2][1] * cipherTriple[1] + inverseMatrix[2][2] * cipherTriple[2]) % mod;
                    if (decryptedTriple[2] < 0) {
                        decryptedTriple[2] += mod;
                    }

                    for (int i = 0; i < 3; ++i) {
                        result += QChar(decryptedTriple[i] + 'a');
                    }
                }

        } else if (playfair == 4) {

            int n = 4;
            QVector<QVector<int>> keyMatrix(4, QVector<int>(4));

            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[0][2] = ui->lineEdit_3->text().toInt();
            keyMatrix[0][3] = ui->lineEdit_12->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();
            keyMatrix[1][2] = ui->lineEdit_6->text().toInt();
            keyMatrix[1][3] = ui->lineEdit_11->text().toInt();
            keyMatrix[2][0] = ui->lineEdit_7->text().toInt();
            keyMatrix[2][1] = ui->lineEdit_8->text().toInt();
            keyMatrix[2][2] = ui->lineEdit_9->text().toInt();
            keyMatrix[2][3] = ui->lineEdit_10->text().toInt();
            keyMatrix[3][0] = ui->lineEdit_17->text().toInt();
            keyMatrix[3][1] = ui->lineEdit_16->text().toInt();
            keyMatrix[3][2] = ui->lineEdit_18->text().toInt();
            keyMatrix[3][3] = ui->lineEdit_19->text().toInt();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = keyMatrix[i][j];
                }
            }

            double det = determinant(n);
            int determinant_rounded = static_cast<int>(std::round(det));

            int detInverse = modInverse(determinant_rounded, mod);

            if (std::gcd(determinant_rounded, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            if (determinant_rounded == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Ошибка", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné maticи.");
                return;
            }

            QVector<QVector<int>> inverse(4, QVector<int>(4));
            //uplatneni metody inverze
            inverse = inverseMatrix(keyMatrix);
            result.clear();
                for (int k = 0; k + 3 < inputText.size(); k += 4) {
                    QString quadruple = inputText.mid(k, 4);
                    QVector<int> cipherQuadruple(4);
                    for (int i = 0; i < 4; ++i) {
                        cipherQuadruple[i] = quadruple[i].unicode() - 'a';
                    }

                    QVector<int> decryptedQuadruple(4);
                    for (int i = 0; i < 4; ++i) {
                        decryptedQuadruple[i] = 0;
                        for (int j = 0; j < 4; ++j) {
                            decryptedQuadruple[i] += static_cast<int>(inverse[i][j] * cipherQuadruple[j]);
                        }
                        decryptedQuadruple[i] %= mod;
                        if (decryptedQuadruple[i] < 0) {
                            decryptedQuadruple[i] += mod;
                        }
                    }

                    for (int i = 0; i < 4; ++i) {
                        result += QChar(decryptedQuadruple[i] + 'a');
                    }
                }

        } else {

            int n = 5;
            QVector<QVector<int>> keyMatrix(5, QVector<int>(5));

            keyMatrix[0][0] = ui->lineEdit->text().toInt();
            keyMatrix[0][1] = ui->lineEdit_2->text().toInt();
            keyMatrix[0][2] = ui->lineEdit_3->text().toInt();
            keyMatrix[0][3] = ui->lineEdit_12->text().toInt();
            keyMatrix[0][4] = ui->lineEdit_14->text().toInt();
            keyMatrix[1][0] = ui->lineEdit_4->text().toInt();
            keyMatrix[1][1] = ui->lineEdit_5->text().toInt();
            keyMatrix[1][2] = ui->lineEdit_6->text().toInt();
            keyMatrix[1][3] = ui->lineEdit_11->text().toInt();
            keyMatrix[1][4] = ui->lineEdit_13->text().toInt();
            keyMatrix[2][0] = ui->lineEdit_7->text().toInt();
            keyMatrix[2][1] = ui->lineEdit_8->text().toInt();
            keyMatrix[2][2] = ui->lineEdit_9->text().toInt();
            keyMatrix[2][3] = ui->lineEdit_10->text().toInt();
            keyMatrix[2][4] = ui->lineEdit_15->text().toInt();
            keyMatrix[3][0] = ui->lineEdit_17->text().toInt();
            keyMatrix[3][1] = ui->lineEdit_16->text().toInt();
            keyMatrix[3][2] = ui->lineEdit_18->text().toInt();
            keyMatrix[3][3] = ui->lineEdit_19->text().toInt();
            keyMatrix[3][4] = ui->lineEdit_20->text().toInt();
            keyMatrix[4][0] = ui->lineEdit_22->text().toInt();
            keyMatrix[4][1] = ui->lineEdit_21->text().toInt();
            keyMatrix[4][2] = ui->lineEdit_23->text().toInt();
            keyMatrix[4][3] = ui->lineEdit_24->text().toInt();
            keyMatrix[4][4] = ui->lineEdit_25->text().toInt();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = keyMatrix[i][j];
                }
            }

            double det = determinant(n);
            int determinant_rounded = static_cast<int>(std::round(det));

            int detInverse = modInverse(determinant_rounded, mod);

            if (std::gcd(determinant_rounded, mod) != 1) {
                QMessageBox::critical(this, "Chyba", "Determinant a modul nejsou vzájemně prvočíselné. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné matici.");
                return;
            }

            if (determinant_rounded == 0 || detInverse == -1) {
                QMessageBox::critical(this, "Ошибка", "Není možné vytvořit inverzní matici. Zvolte jiný klíč nebo použijte tlačítko pro generaci náhodné maticи.");
                return;
            }

            QVector<QVector<int>> inverse(5, QVector<int>(5));
            inverse = inverseMatrix(keyMatrix);
            result.clear();
                for (int k = 0; k + 4 < inputText.size(); k += 5) {
                    QString quintuple = inputText.mid(k, 5);
                    QVector<int> cipherQuintuple(5);
                    for (int i = 0; i < 5; ++i) {
                        cipherQuintuple[i] = quintuple[i].unicode() - 'a';
                    }

                    QVector<int> decryptedQuintuple(5);
                    for (int i = 0; i < 5; ++i) {
                        decryptedQuintuple[i] = 0;
                        for (int j = 0; j < 5; ++j) {
                            decryptedQuintuple[i] += static_cast<int>(inverse[i][j] * cipherQuintuple[j]);
                        }
                        decryptedQuintuple[i] %= mod;
                        if (decryptedQuintuple[i] < 0) {
                            decryptedQuintuple[i] += mod;
                        }
                    }

                    for (int i = 0; i < 5; ++i) {
                        result += QChar(decryptedQuintuple[i] + 'a');
                    }
                }
        }

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> elapsed = end - start;
        totalMicroseconds += elapsed.count();
    }

    ui->textBrowser_3->setPlainText(result);

    double averageMicroseconds = totalMicroseconds / globalIterations;
    ui->label_9->setText("Čas dešifrování: " + QString::number(averageMicroseconds) + " µs");
}

//generace náhodné matici
void MainWindow::on_pushButton_12_clicked()
{
    QVector<QVector<int>> previousKey;
    int mod = 26;
    if (playfair == 2) {
        QVector<QVector<int>> matrix(2, QVector<int>(2));

        //cyklus, který se zruší při načtení funkce break;
        while (true) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    matrix[i][j] = QRandomGenerator::global()->bounded(25);
                }
            }

            int determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            //pokud se splní nějaká podmínka, tak cyklus se spustí znovu
            if (determinant == 0) {
                continue;
            }

            if (std::gcd(determinant, mod) != 1) {
                continue;
            }

            ui->lineEdit->setText(QString::number(matrix[0][0]));
            ui->lineEdit_2->setText(QString::number(matrix[0][1]));
            ui->lineEdit_4->setText(QString::number(matrix[1][0]));
            ui->lineEdit_5->setText(QString::number(matrix[1][1]));

            break;
        }

    } else if (playfair == 3) {
        QVector<QVector<int>> matrix(3, QVector<int>(3));

        while (true) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    matrix[i][j] = QRandomGenerator::global()->bounded(25);
                }
            }

            int determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
            if (determinant == 0) {
                continue;
            }

            if (std::gcd(determinant, mod) != 1) {
                continue;
            }

            ui->lineEdit->setText(QString::number(matrix[0][0]));
            ui->lineEdit_2->setText(QString::number(matrix[0][1]));
            ui->lineEdit_3->setText(QString::number(matrix[0][2]));
            ui->lineEdit_4->setText(QString::number(matrix[1][0]));
            ui->lineEdit_5->setText(QString::number(matrix[1][1]));
            ui->lineEdit_6->setText(QString::number(matrix[1][2]));
            ui->lineEdit_7->setText(QString::number(matrix[2][0]));
            ui->lineEdit_8->setText(QString::number(matrix[2][1]));
            ui->lineEdit_9->setText(QString::number(matrix[2][2]));

            break;
        }

    } else if (playfair == 4) {

        QVector<QVector<int>> matrix(4, QVector<int>(4));
        int n = 4;

        while (true) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    matrix[i][j] = QRandomGenerator::global()->bounded(25);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = matrix[i][j];
                }
            }

            double det = determinant(n);
            int determinant_rounded = static_cast<int>(std::round(det));

            if (det == 0) {
                continue;
            }

            if (std::gcd(determinant_rounded, 26) != 1) {
                continue;
            }

            ui->lineEdit->setText(QString::number(matrix[0][0]));
            ui->lineEdit_2->setText(QString::number(matrix[0][1]));
            ui->lineEdit_3->setText(QString::number(matrix[0][2]));
            ui->lineEdit_12->setText(QString::number(matrix[0][3]));
            ui->lineEdit_4->setText(QString::number(matrix[1][0]));
            ui->lineEdit_5->setText(QString::number(matrix[1][1]));
            ui->lineEdit_6->setText(QString::number(matrix[1][2]));
            ui->lineEdit_11->setText(QString::number(matrix[1][3]));
            ui->lineEdit_7->setText(QString::number(matrix[2][0]));
            ui->lineEdit_8->setText(QString::number(matrix[2][1]));
            ui->lineEdit_9->setText(QString::number(matrix[2][2]));
            ui->lineEdit_10->setText(QString::number(matrix[2][3]));
            ui->lineEdit_17->setText(QString::number(matrix[3][0]));
            ui->lineEdit_16->setText(QString::number(matrix[3][1]));
            ui->lineEdit_18->setText(QString::number(matrix[3][2]));
            ui->lineEdit_19->setText(QString::number(matrix[3][3]));

            break;
        }

    } else {

        QVector<QVector<int>> matrix(5, QVector<int>(5));
        int n = 5;

        while (true) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    matrix[i][j] = QRandomGenerator::global()->bounded(25);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = matrix[i][j];
                }
            }

            double det = determinant(n);
            int determinant_rounded = static_cast<int>(std::round(det));

            if (determinant_rounded == 0) {
                continue;
            }

            if (std::gcd(determinant_rounded, mod) != 1) {
                continue;
            }

            ui->lineEdit->setText(QString::number(matrix[0][0]));
            ui->lineEdit_2->setText(QString::number(matrix[0][1]));
            ui->lineEdit_3->setText(QString::number(matrix[0][2]));
            ui->lineEdit_12->setText(QString::number(matrix[0][3]));
            ui->lineEdit_14->setText(QString::number(matrix[0][4]));

            ui->lineEdit_4->setText(QString::number(matrix[1][0]));
            ui->lineEdit_5->setText(QString::number(matrix[1][1]));
            ui->lineEdit_6->setText(QString::number(matrix[1][2]));
            ui->lineEdit_11->setText(QString::number(matrix[1][3]));
            ui->lineEdit_13->setText(QString::number(matrix[1][4]));

            ui->lineEdit_7->setText(QString::number(matrix[2][0]));
            ui->lineEdit_8->setText(QString::number(matrix[2][1]));
            ui->lineEdit_9->setText(QString::number(matrix[2][2]));
            ui->lineEdit_10->setText(QString::number(matrix[2][3]));
            ui->lineEdit_15->setText(QString::number(matrix[2][4]));

            ui->lineEdit_17->setText(QString::number(matrix[3][0]));
            ui->lineEdit_16->setText(QString::number(matrix[3][1]));
            ui->lineEdit_18->setText(QString::number(matrix[3][2]));
            ui->lineEdit_19->setText(QString::number(matrix[3][3]));
            ui->lineEdit_20->setText(QString::number(matrix[3][4]));

            ui->lineEdit_22->setText(QString::number(matrix[4][0]));
            ui->lineEdit_21->setText(QString::number(matrix[4][1]));
            ui->lineEdit_23->setText(QString::number(matrix[4][2]));
            ui->lineEdit_24->setText(QString::number(matrix[4][3]));
            ui->lineEdit_25->setText(QString::number(matrix[4][4]));

            break;
        }

    }
}

//smazani vseho v matici
void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit->QLineEdit::clear();
    ui->lineEdit->QLineEdit::clear();
    ui->lineEdit_2->QLineEdit::clear();
    ui->lineEdit_3->QLineEdit::clear();
    ui->lineEdit_4->QLineEdit::clear();
    ui->lineEdit_5->QLineEdit::clear();
    ui->lineEdit_6->QLineEdit::clear();
    ui->lineEdit_7->QLineEdit::clear();
    ui->lineEdit_8->QLineEdit::clear();
    ui->lineEdit_9->QLineEdit::clear();
    ui->lineEdit_10->QLineEdit::clear();
    ui->lineEdit_11->QLineEdit::clear();
    ui->lineEdit_12->QLineEdit::clear();
    ui->lineEdit_13->QLineEdit::clear();
    ui->lineEdit_14->QLineEdit::clear();
    ui->lineEdit_15->QLineEdit::clear();
    ui->lineEdit_16->QLineEdit::clear();
    ui->lineEdit_17->QLineEdit::clear();
    ui->lineEdit_18->QLineEdit::clear();
    ui->lineEdit_19->QLineEdit::clear();
    ui->lineEdit_20->QLineEdit::clear();
    ui->lineEdit_21->QLineEdit::clear();
    ui->lineEdit_22->QLineEdit::clear();
    ui->lineEdit_23->QLineEdit::clear();
    ui->lineEdit_24->QLineEdit::clear();
    ui->lineEdit_25->QLineEdit::clear();
}
