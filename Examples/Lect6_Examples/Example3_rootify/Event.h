#ifndef __Event__
#define __Event__

#include "Track.h"
#include <vector>

class Event: public TObject {
  public:
    Event();
    ~Event();

    std::vector<Track> tracks;

  private:
    ClassDef(Event, 1) // The macro
};

#endif
