#include <iostream>
#include "ChessBoard.h"

using namespace std;

int main() {
  
  ChessBoard cb;

 cb.submitMove("D2", "D4"); // good pawn two
  cout << endl;

  cb.submitMove("E7", "E5");  // good pawn one
  cout << endl;

  cb.submitMove("D1", "D2"); // false not right
  cout << endl;
  
  cb.submitMove("E5", "E4"); // full with own piece
  cout << endl;

  cb.submitMove("A2", "A4"); // good knight
  cout << endl;


  cb.submitMove("A7", "A5"); // good knight
  cout << endl;


  cb.submitMove("D2", "F4"); // good knight
  cout << endl;
  
  cb.submitMove("F7", "F5"); // good knight
  cout << endl;


  cb.submitMove("H2", "H3"); // good knight
  cout << endl;


  cb.submitMove("D8", "H4"); // good knight
  cout << endl;


  cb.submitMove("F4", "H2"); // good knight
  cout << endl;


 cb.submitMove("F8", "B4"); // good knight
  cout << endl;
  
   cb.submitMove("B1", "D2"); // good knight
  cout << endl;

   
   cb.submitMove("D7", "D6"); // good knight
  cout << endl;


  
   cb.submitMove("A1", "A3"); // good knight
  cout << endl;

   cb.submitMove("C8", "E6"); // good knight
  cout << endl;

   cb.submitMove("A3", "G3"); // good knight
  cout << endl;
  

 cb.submitMove("E6", "B3"); // good knight
  cout << endl;

   cb.submitMove("C2", "C4"); // good knight
  cout << endl;


  
   cb.submitMove("C7", "C5"); // good knight
  cout << endl;
  
  
   cb.submitMove("F2", "F3"); // good knight
  cout << endl;
  

  
   cb.submitMove("F5", "F4"); // good knight
  cout << endl;

     cb.submitMove("D4", "D5"); // good knight
  cout << endl;

     cb.submitMove("E4", "E3"); // good knight
  cout << endl;
  
  /*
  
  cb.submitMove("E2", "E4"); // good pawn two
  cout << endl;

  cb.submitMove("E7", "E6");  // good pawn one
  cout << endl;

  cb.submitMove("B1", "B3"); // false not right
  cout << endl;
  
  cb.submitMove("B1", "D2"); // full with own piece
  cout << endl;

  cb.submitMove("B1", "C3"); // good knight
  cout << endl;

  
  cb.submitMove("F8", "A3"); // slide bishop
  cout << endl;

  
  cb.submitMove("B2", "A3"); // pawn eats bishop
  cout << endl;


  cb.submitMove("G8", "H6"); // move knight balck
  cout << endl;

  cb.submitMove("C3", "A4"); // move knight white
  cout << endl;
  
  cb.submitMove("D8", "G5"); // move queen blak
  cout << endl;

  
  cb.submitMove("F2", "F4"); // move pawn
  cout << endl;
  
  cb.submitMove("G5", "H4"); // move blak queen
*/
  
  cb.resetBoard();
 

  return 0;
};
