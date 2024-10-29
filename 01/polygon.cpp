#include <simplecpp>

main_program{
  turtleSim();
  cout << "How many sides? ";
  int nsides; 
  cin >> nsides;
  repeat(nsides){
    forward(400.0/nsides);
    right(360.0/nsides);
  }
  getClick();
}
