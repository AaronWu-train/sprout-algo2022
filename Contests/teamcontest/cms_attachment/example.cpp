#include "Mahjong.h"

void play() {
  check({"1m", "9m", "1p", "9p", "1s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z", "1m"});
  check({"1m", "9m", "1p", "9p", "1s", "1z", "2z", "3z", "3z", "4z", "5z", "6z", "7z", "9s"});
  check({"9m", "1p", "9p", "1s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z", "7z", "1m"});
  check({"1m", "1p", "9p", "1s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z", "7z", "9m"});
  check({"1m", "9m", "1p", "9p", "1s", "9s", "1z", "2z", "3z", "5z", "6z", "7z", "7z", "4z"});
}

