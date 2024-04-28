#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <vector>
using namespace std;



namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();
    void passa_players(vector<QString> nomi, vector<bool> bt);

private:
    Ui::game *ui;
};

#endif // GAME_H
