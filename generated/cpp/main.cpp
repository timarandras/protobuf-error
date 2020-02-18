#include <iostream>
#include <string>
#include <iomanip>
#include "floats.pb.h"

std::string ToHex(const std::string& s, bool upper_case = false)
{
    std::ostringstream ret;

    for (std::string::size_type i = 0; i < s.length(); ++i)
        ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << (int)s[i];

    return ret.str();
}

int main() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  Floats floats;
  
  floats.add_samples(1.5);
  floats.add_samples(2.5);
  floats.add_samples(3.5);

  auto msg = floats.SerializeAsString();

  std::cout << ToHex(msg) << std::endl;  
  return 0;
}