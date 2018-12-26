# Rôle de <makefile>
# un fichier pour faciliter la compilation et l’éditer des liens des codes sources

ECHO=@echo	
RM=rm		
COMP=g++ -c 
EDL=g++ -o
CPPFLAGS= -g  -ansi -pedantic -Wall -std=c++11
EDLFLAGS=
RMFLAGS= -f
EFFACE=clean
EXE=menu
MODULE=TrajetSimple.h TrajetCompose.h ListeTrajet.h
INT=$(MODULE) Trajet.h
REAL=$(MODULE:.h=.cpp)
OBJ=$(MODULE:.h=.o)
LIBS=
INCPATH=
LIBPATH=

.PHONY:$(EFFACE)

$(EXE): $(OBJ) menu.o
	$(ECHO) "Edl de executable"
	$(EDL) $(EDLFLAGS)$(LIBPATH) $(EXE) menu.o $(OBJ) $(LIBS)
menu.o: $(INT) $(REAL) $(EXE).cpp
	$(ECHO) "Compil de <menu.cpp>"
	$(COMP) $(CPPFLAGS) $(INCPATH) menu.cpp
TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h
	$(ECHO) "Compil de <TrajetSimple.cpp>"
	$(COMP) $(CPPFLAGS) $(INCPATH) TrajetSimple.cpp
TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.h
	$(ECHO) "Compil de <TrajetCompose.cpp>"
	$(COMP) $(CPPFLAGS) $(INCPATH) TrajetCompose.cpp
ListeTrajet.o: $(INT) $(REAL)
	$(ECHO) "Compil de <ListeTrajet.cpp>"
	$(COMP) $(CPPFLAGS) $(INCPATH) ListeTrajet.cpp
$(EFFACE):
	$(RM) $(RMFLAGS) $(OBJ) core 
