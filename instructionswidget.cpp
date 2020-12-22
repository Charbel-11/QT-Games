#include "instructionswidget.h"

InstructionsWidget::InstructionsWidget(user *_player, int _gameID, QWidget *parent) : QWidget(parent)
{
    player = _player;
    gameID = _gameID;
    QString s = (gameID == 1 ? "Kill Covid-19" : "Reversi");
    title = new QLabel(s + " Instructions");
    title->setStyleSheet("font: 50px");
    setWindowTitle(s + " Instructions");

    backButton = new QPushButton("Back");
    backButton->setStyleSheet("background-color: red; font: 40px;");
    backButton->setFixedSize(QSize(250, 100));

    if (gameID == 1){
        QString s("There are 3 types of viruses: small (red), medium (blue) and large (green).\n"
                  "Each virus type is represented by a distinctly colored game piece token.\n"
                  "There are 3 counters for the different types of viruses and a total score:\n"
                  "- Small (Red) viruses are worth 3 points\n"
                  "- Medium (Blue) viruses are worth 5 points\n"
                  "- Large (Green) viruses are worth 7 points\n\n"
                  "You shoot by pressing on any key.\n"
                  "You collect points when you successfully hits the target.\n"
                  "The score is incremented according to the type of the killed virus.\n"
                  "To win the game, you must collect 150 points regardless of the counter.\n"
                  "If the total score is more than a 150, the last shot is excluded and the\n"
                  "game continues until the total score is exactly 150.\n"
                  "The rolling speed starts slowly and doubles after shooting 5 viruses.\n"
                  "You loose if you miss shooting 3 viruses (or 5 in easy mode).\n");
        instructions = new QLabel(s);
    }
    else{
        QString s("The game is played on an 8x8 gridded board. Each player gets 32 discs in\n"
                  "total. Player 1 has the black discs while Player 2 has the white discs.\n"
                  "2 black and 2 white discs are placed at the center of the board.\n"
                  "Black always moves first. Players should place their discs to outflank\n"
                  "the other player's discs. All outflanked discs are then flipped.\n"
                  "A placed disc can never be moved again in the game.\n"
                  "When a player has no valid moves, he passes his turn.\n"
                  "However, a player cannot pass in case there is some valid move.\n"
                  "The game alternate between black and white and ends when:\n"
                  "i)  A player cannot make a move to outflank the opponent\n"
                  "ii) Both players have no valid moves\n"
                  "The player with the most discs wins the game.\n"
                  "\n"
                  "The difficulty chosen for the game determines the total time each player\n"
                  "has to make moves: Easy (15 min), Medium (10 min), Hard (5min)\n"
                  "When one player's time is over, he looses the game.");
        instructions = new QLabel(s);
    }
    instructions->setStyleSheet("font: 20px");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(title, 0, Qt::AlignCenter);
    layout->addWidget(instructions);
    layout->addWidget(backButton, 0, Qt::AlignCenter);
    layout->addItem(new QSpacerItem(30, 30));

    setLayout(layout);

    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(goBack()));
}

void InstructionsWidget::goBack(){
    Helper::openWidget(new gameInfoWidget(gameID, player));
    this->close();
}
