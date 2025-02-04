// Copyright (c) Leon Freist <freist@informatik.uni-freiburg.de>
// This software is part of HWBenchmark

#include "hwinfo/platform.h"

#ifdef HWINFO_APPLE

#include <sys/sysctl.h>

#include <sstream>
#include <string>

#include "hwinfo/mainboard.h"

namespace hwinfo {

// _____________________________________________________________________________________________________________________
MainBoard::MainBoard() {
  size_t size = 1024;
  _vendor = "Apple";

  std::string model_name;
  model_name.resize(size);
  if (sysctlbyname("hw.model", static_cast<void*>(const_cast<char*>(model_name.data())), &size, nullptr, 0) == 0) {
    model_name.resize(size);  // trim the string to the actual size
    model_name.pop_back();    // remove unprintable character at the end
    _name = model_name;
  } else {
    _name = "<unknown>";
  }

  _version = "<unknown>";
  _serialNumber = "<unknown>";
}

}  // namespace hwinfo

#endif  // HWINFO_APPLE