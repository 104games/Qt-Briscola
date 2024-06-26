#ifndef PLAYERCREATION_H
#define PLAYERCREATION_H
#include <vector>
#include <QMainWindow>
using namespace std;
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
    int players;
    vector<string> player_names;
    vector<bool> bots;

private slots:
    void on_crea_clicked();

private:
    Ui::PlayerCreation *ui;

    int player_counts = 0;


};

#endif // PLAYERCREATION_H
