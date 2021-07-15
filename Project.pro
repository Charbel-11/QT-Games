QT += widgets
QT += charts

SOURCES += \
    Game1/arrow.cpp \
    UI/authenticationwidget.cpp \
    UI/difficultywidget.cpp \
    UI/gamechoicewidget.cpp \
    UI/gameinfowidget.cpp \
    UI/helper.cpp \
    UI/instructionswidget.cpp \
    Game1/killcovidscene.cpp \
    main.cpp \
    Game2/reversiscene.cpp \
    UI/scores.cpp \
    UI/signinwidget.cpp \
    UI/signupwidget.cpp \
    Game1/syringe.cpp \
    Users/user.cpp \
    Users/usersdata.cpp \
    Game1/virus.cpp

HEADERS += \
    Game1/arrow.h \
    UI/authenticationwidget.h \
    UI/difficultywidget.h \
    UI/gamechoicewidget.h \
    UI/gameinfowidget.h \
    UI/helper.h \
    UI/instructionswidget.h \
    Game1/killcovidscene.h \
    Game2/reversiscene.h \
    UI/scores.h \
    UI/signinwidget.h \
    UI/signupwidget.h \
    Game1/syringe.h \
    Users/user.h \
    Users/usersdata.h \
    Game1/virus.h

RESOURCES += \
    resources.qrc

#QMAKE_CXXFLAGS += -pg
#QMAKE_LFLAGS += -pg
