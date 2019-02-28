#ifndef UndergroundH
#define UndergroundH 

#include <cassert>      // Used for debugging

#include <vector>

#include "Hole.h"

class Underground
{
public:
  static const Underground* const get_pUg();

  int get_hole_index(int x, int y) const;
  char get_hole_symbol(int holeIndex) const;
  int get_hole_x(int index) const;
  int get_hole_y(int index) const;
  int get_holes_size() const;
private:
  const std::vector<Hole> holes_;
  Underground();
};

#endif