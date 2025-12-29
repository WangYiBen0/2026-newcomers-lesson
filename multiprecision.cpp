#include <type_traits>
#include <vector>

namespace W1ngD1nGa5ter {

template <typename T, typename Int,
          typename = typename std::enable_if<std::is_integral<Int>::value>>
constexpr T pow(T a, Int p) {
  T res = a;
  for (--p; p; p >>= 1) {
    if (p & 1) {
      a *= a;
    }
    res *= a;
  }
  return res;
}

namespace multiprecision {

template <typename T = int,
          T len = 4> // T: 高精度每位的类型 ; len: 压位位数 ; Base = 10^{len}
class cpp_int {
public:
  cpp_int();
  cpp_int(cpp_int &&) = default;
  cpp_int(const cpp_int &) = default;
  cpp_int &operator=(cpp_int &&) = default;
  cpp_int &operator=(const cpp_int &) = default;
  ~cpp_int();

private:
  static constexpr T base = pow(T(10), len);
  std::vector<T> data;
};

template <typename T, T len> cpp_int<T, len>::cpp_int() {}

template <typename T, T len> cpp_int<T, len>::~cpp_int() {}

} // namespace multiprecision

} // namespace W1ngD1nGa5ter
