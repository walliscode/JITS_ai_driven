#include "startup.h"

#include <system_error>

namespace jits {

std::filesystem::path baseMapPath(const std::filesystem::path& dataFolder)
{
  return dataFolder / "base_map.json";
}

bool baseMapExists(const std::filesystem::path& dataFolder)
{
  std::error_code ec;
  return std::filesystem::is_regular_file(baseMapPath(dataFolder), ec);
}

} // namespace jits
