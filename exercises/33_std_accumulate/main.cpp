#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    /**
     *  T accumulate( InputIt first, InputIt last, T init, BinaryOp op );
     * first, last	-	the pair of iterators defining the range of elements to accumulate
     * init	-	initial value of the accumulate
     * op	-	binary operation function object that will be applied.
    **/
    int size = std::accumulate(&shape[0], &shape[3] + 1, 4, std::multiplies<DataType>());
    std::cout << size << std::endl;
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
