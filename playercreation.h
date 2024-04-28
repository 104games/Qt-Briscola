#ifndef PLAYERCREATION_H
#define PLAYERCREATION_H

#include <QMainWindow>

namespace Ui {
class PlayerCreation;
}

class PlayerCreation : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerCreation(QWidget *parent = nullptr);
    ~PlayerCreation();
    void passa_mod(int m);

private slots:
    void on_pushButton_clicked();

    void on_crea_clicked();

private:
    Ui::PlayerCreation *ui;
};

#endif // PLAYERCREATION_H
