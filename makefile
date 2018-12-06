EXE = chess
CXX = g++
CXXFLAGS = -Wall -g

$(EXE): ChessMain.o ChessBoard.o King.o Queen.o Bishop.o Castle.o Pawn.o Knight.o Piece.o
	$(CXX) -g ChessMain.o ChessBoard.o King.o Queen.o Bishop.o Castle.o Pawn.o Knight.o Piece.o -o $(EXE)

ChessMain.o: ChessMain.cpp
	$(CXX) $(CXXFLAGS) -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h King.h Queen.h Castle.h Bishop.h Knight.h Pawn.h Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c ChessBoard.cpp

King.o: King.cpp King.h Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c King.cpp

Queen.o: Queen.cpp Queen.h Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c Queen.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c Bishop.cpp

Castle.o: Castle.cpp Castle.h Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c Castle.cpp

Pawn.o: Pawn.cpp Pawn.h Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c Pawn.cpp

Knight.o: Knight.cpp Knight.h Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c Knight.cpp

Piece.o: Piece.cpp Piece.h Color.h
	$(CXX) $(CXXFLAGS) -c Piece.cpp

clean:
	rm -f *.o $(EXE)
