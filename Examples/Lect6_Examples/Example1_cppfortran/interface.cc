#include <string>
#include <cstring>

extern "C" void test_();

struct fBlockCOMX{
  int i;
  float r[3][3];
  double d;
};

extern "C" {
  extern fBlockCOMX comx_;
}

struct fBlockCOMC{
  char chtext[10][80];
};

extern "C" {
  extern fBlockCOMC comc_;
}

void FortranInterface(std::string text){
  strcpy(comc_.chtext[0],text.c_str());
  test_();
}
