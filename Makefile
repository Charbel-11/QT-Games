#############################################################################
# Makefile for building: Project
# Generated by qmake (2.01a) (Qt 4.8.7) on: Mon Nov 30 21:59:59 2020
# Project:  Project.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile Project.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = arrow.cpp \
		authenticationwidget.cpp \
		difficultywidget.cpp \
		gamechoicewidget.cpp \
		gameinfowidget.cpp \
		helper.cpp \
		instructionswidget.cpp \
		killcovidscene.cpp \
		main.cpp \
		reversiscene.cpp \
		scores.cpp \
		signinwidget.cpp \
		signupwidget.cpp \
		syringe.cpp \
		user.cpp \
		usersdata.cpp \
		virus.cpp moc_arrow.cpp \
		moc_authenticationwidget.cpp \
		moc_difficultywidget.cpp \
		moc_gamechoicewidget.cpp \
		moc_gameinfowidget.cpp \
		moc_instructionswidget.cpp \
		moc_killcovidscene.cpp \
		moc_reversiscene.cpp \
		moc_scores.cpp \
		moc_signinwidget.cpp \
		moc_signupwidget.cpp \
		moc_syringe.cpp \
		moc_virus.cpp \
		qrc_resources_images.cpp
OBJECTS       = arrow.o \
		authenticationwidget.o \
		difficultywidget.o \
		gamechoicewidget.o \
		gameinfowidget.o \
		helper.o \
		instructionswidget.o \
		killcovidscene.o \
		main.o \
		reversiscene.o \
		scores.o \
		signinwidget.o \
		signupwidget.o \
		syringe.o \
		user.o \
		usersdata.o \
		virus.o \
		moc_arrow.o \
		moc_authenticationwidget.o \
		moc_difficultywidget.o \
		moc_gamechoicewidget.o \
		moc_gameinfowidget.o \
		moc_instructionswidget.o \
		moc_killcovidscene.o \
		moc_reversiscene.o \
		moc_scores.o \
		moc_signinwidget.o \
		moc_signupwidget.o \
		moc_syringe.o \
		moc_virus.o \
		qrc_resources_images.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Project.pro
QMAKE_TARGET  = Project
DESTDIR       = 
TARGET        = Project

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Project.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile Project.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Project.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Project1.0.0 || $(MKDIR) .tmp/Project1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Project1.0.0/ && $(COPY_FILE) --parents arrow.h authenticationwidget.h difficultywidget.h gamechoicewidget.h gameinfowidget.h helper.h instructionswidget.h killcovidscene.h reversiscene.h scores.h signinwidget.h signupwidget.h syringe.h user.h usersdata.h virus.h .tmp/Project1.0.0/ && $(COPY_FILE) --parents resources_images.qrc .tmp/Project1.0.0/ && $(COPY_FILE) --parents arrow.cpp authenticationwidget.cpp difficultywidget.cpp gamechoicewidget.cpp gameinfowidget.cpp helper.cpp instructionswidget.cpp killcovidscene.cpp main.cpp reversiscene.cpp scores.cpp signinwidget.cpp signupwidget.cpp syringe.cpp user.cpp usersdata.cpp virus.cpp .tmp/Project1.0.0/ && (cd `dirname .tmp/Project1.0.0` && $(TAR) Project1.0.0.tar Project1.0.0 && $(COMPRESS) Project1.0.0.tar) && $(MOVE) `dirname .tmp/Project1.0.0`/Project1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Project1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_arrow.cpp moc_authenticationwidget.cpp moc_difficultywidget.cpp moc_gamechoicewidget.cpp moc_gameinfowidget.cpp moc_instructionswidget.cpp moc_killcovidscene.cpp moc_reversiscene.cpp moc_scores.cpp moc_signinwidget.cpp moc_signupwidget.cpp moc_syringe.cpp moc_virus.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_arrow.cpp moc_authenticationwidget.cpp moc_difficultywidget.cpp moc_gamechoicewidget.cpp moc_gameinfowidget.cpp moc_instructionswidget.cpp moc_killcovidscene.cpp moc_reversiscene.cpp moc_scores.cpp moc_signinwidget.cpp moc_signupwidget.cpp moc_syringe.cpp moc_virus.cpp
moc_arrow.cpp: arrow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) arrow.h -o moc_arrow.cpp

moc_authenticationwidget.cpp: authenticationwidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) authenticationwidget.h -o moc_authenticationwidget.cpp

moc_difficultywidget.cpp: gameinfowidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		scores.h \
		instructionswidget.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h \
		difficultywidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) difficultywidget.h -o moc_difficultywidget.cpp

moc_gamechoicewidget.cpp: user.h \
		gamechoicewidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) gamechoicewidget.h -o moc_gamechoicewidget.cpp

moc_gameinfowidget.cpp: gamechoicewidget.h \
		user.h \
		helper.h \
		scores.h \
		gameinfowidget.h \
		instructionswidget.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h \
		gameinfowidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) gameinfowidget.h -o moc_gameinfowidget.cpp

moc_instructionswidget.cpp: gameinfowidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		scores.h \
		instructionswidget.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h \
		instructionswidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) instructionswidget.h -o moc_instructionswidget.cpp

moc_killcovidscene.cpp: helper.h \
		gamechoicewidget.h \
		user.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		killcovidscene.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) killcovidscene.h -o moc_killcovidscene.cpp

moc_reversiscene.cpp: helper.h \
		gamechoicewidget.h \
		user.h \
		usersdata.h \
		reversiscene.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) reversiscene.h -o moc_reversiscene.cpp

moc_scores.cpp: gameinfowidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		scores.h \
		instructionswidget.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h \
		scores.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) scores.h -o moc_scores.cpp

moc_signinwidget.cpp: signinwidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) signinwidget.h -o moc_signinwidget.cpp

moc_signupwidget.cpp: signupwidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) signupwidget.h -o moc_signupwidget.cpp

moc_syringe.cpp: syringe.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) syringe.h -o moc_syringe.cpp

moc_virus.cpp: virus.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) virus.h -o moc_virus.cpp

compiler_rcc_make_all: qrc_resources_images.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources_images.cpp
qrc_resources_images.cpp: resources_images.qrc \
		images/Background.jpg \
		images/EmptyDiscToSelect.png \
		images/WhiteDisc.png \
		images/SmallVirusSmashed.png \
		images/EmptyDisc.png \
		images/SmallVirus.png \
		images/LargeVirusSmashed.png \
		images/ReversiLogo.png \
		images/Arrow.png \
		images/syringe.png \
		images/MediumVirusSmashed.png \
		images/BlackDisc.png \
		images/LargeVirus.png \
		images/MediumVirus.png \
		images/covidPic.jpeg
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name resources_images resources_images.qrc -o qrc_resources_images.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

arrow.o: arrow.cpp arrow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o arrow.o arrow.cpp

authenticationwidget.o: authenticationwidget.cpp authenticationwidget.h \
		signinwidget.h \
		signupwidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		usersdata.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o authenticationwidget.o authenticationwidget.cpp

difficultywidget.o: difficultywidget.cpp difficultywidget.h \
		gameinfowidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		scores.h \
		instructionswidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o difficultywidget.o difficultywidget.cpp

gamechoicewidget.o: gamechoicewidget.cpp gamechoicewidget.h \
		user.h \
		authenticationwidget.h \
		gameinfowidget.h \
		helper.h \
		scores.h \
		instructionswidget.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamechoicewidget.o gamechoicewidget.cpp

gameinfowidget.o: gameinfowidget.cpp gameinfowidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		scores.h \
		instructionswidget.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameinfowidget.o gameinfowidget.cpp

helper.o: helper.cpp helper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o helper.o helper.cpp

instructionswidget.o: instructionswidget.cpp instructionswidget.h \
		gameinfowidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		scores.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o instructionswidget.o instructionswidget.cpp

killcovidscene.o: killcovidscene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o killcovidscene.o killcovidscene.cpp

main.o: main.cpp authenticationwidget.h \
		helper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

reversiscene.o: reversiscene.cpp reversiscene.h \
		helper.h \
		gamechoicewidget.h \
		user.h \
		usersdata.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o reversiscene.o reversiscene.cpp

scores.o: scores.cpp scores.h \
		gameinfowidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		instructionswidget.h \
		difficultywidget.h \
		killcovidscene.h \
		syringe.h \
		virus.h \
		arrow.h \
		usersdata.h \
		reversiscene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scores.o scores.cpp

signinwidget.o: signinwidget.cpp signinwidget.h \
		authenticationwidget.h \
		gamechoicewidget.h \
		user.h \
		helper.h \
		usersdata.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o signinwidget.o signinwidget.cpp

signupwidget.o: signupwidget.cpp signupwidget.h \
		usersdata.h \
		user.h \
		helper.h \
		authenticationwidget.h \
		gamechoicewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o signupwidget.o signupwidget.cpp

syringe.o: syringe.cpp syringe.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o syringe.o syringe.cpp

user.o: user.cpp user.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o user.o user.cpp

usersdata.o: usersdata.cpp usersdata.h \
		user.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o usersdata.o usersdata.cpp

virus.o: virus.cpp virus.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o virus.o virus.cpp

moc_arrow.o: moc_arrow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_arrow.o moc_arrow.cpp

moc_authenticationwidget.o: moc_authenticationwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_authenticationwidget.o moc_authenticationwidget.cpp

moc_difficultywidget.o: moc_difficultywidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_difficultywidget.o moc_difficultywidget.cpp

moc_gamechoicewidget.o: moc_gamechoicewidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gamechoicewidget.o moc_gamechoicewidget.cpp

moc_gameinfowidget.o: moc_gameinfowidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameinfowidget.o moc_gameinfowidget.cpp

moc_instructionswidget.o: moc_instructionswidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_instructionswidget.o moc_instructionswidget.cpp

moc_killcovidscene.o: moc_killcovidscene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_killcovidscene.o moc_killcovidscene.cpp

moc_reversiscene.o: moc_reversiscene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_reversiscene.o moc_reversiscene.cpp

moc_scores.o: moc_scores.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_scores.o moc_scores.cpp

moc_signinwidget.o: moc_signinwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_signinwidget.o moc_signinwidget.cpp

moc_signupwidget.o: moc_signupwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_signupwidget.o moc_signupwidget.cpp

moc_syringe.o: moc_syringe.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_syringe.o moc_syringe.cpp

moc_virus.o: moc_virus.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_virus.o moc_virus.cpp

qrc_resources_images.o: qrc_resources_images.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources_images.o qrc_resources_images.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

