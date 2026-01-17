#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>

// READ: `std::transform` <https://zh.cppreference.com/w/cpp/algorithm/transform>
// READ: `std::vector::begin` <https://zh.cppreference.com/w/cpp/container/vector/begin>

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    // TODO: 调用 `std::transform`，将 `v` 中的每个元素乘以 2，并转换为字符串，存入 `ans`
    std::vector<std::string> ans;
    /** OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                 OutputIt d_first, BinaryOp binary_op) **/
    /** back_inserter: add elements to the end of the container **/
    std::vector<int> res;
    std::transform(val.cbegin(), val.cend(), val.cbegin(), std::back_inserter(res), std::plus<>{});
    for (int i : res) {
        ans.push_back(std::to_string(i));
    }
    // std::copy(val.cbegin(), val.cend(),  std::back_inserter(ans));
    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");
    return 0;
}
