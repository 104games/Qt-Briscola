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

private:
    Ui::PlayerCreation *ui;
};

#endif // PLAYERCREATION_H
