
#include <immer/vector.hpp>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size)
{
    immer::vector<std::uint8_t>{data, data + size};
    return 0;
}
