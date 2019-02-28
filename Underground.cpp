#include "Underground.h"

const Underground * const Underground::get_pUg()
{
  static Underground sug;
  return &sug;
}

Underground::Underground() : holes_{ Hole(3,4), Hole(15,10), Hole(7,15) }
{
  assert(true);
}


int Underground::get_hole_x(int index) const
{
  return holes_.at(index).get_x();
}

int Underground::get_hole_y(int index) const
{
  return holes_.at(index).get_y();
}

int Underground::get_holes_size() const
{
  return holes_.size() - 1;
}

int Underground::get_hole_index(int x, int y) const
{
  assert(!(x < 0 || x > SIZE || y < 0 || y > SIZE));
  bool isHoleFound = false;
  int holeIterator = 0;
  while (!isHoleFound && holeIterator < holes_.size())
  {
    if (holes_.at(holeIterator).is_at_position(x, y))
    {
      isHoleFound = true;
    }
    else {
      ++holeIterator;
    }
  }
  if (!isHoleFound)
  {
    holeIterator = -1;
  }
  return holeIterator;
}

char Underground::get_hole_symbol(int holeIndex) const
{
  assert((holeIndex >= 0) && (holeIndex < holes_.size()));
  return holes_.at(holeIndex).get_symbol();
}
