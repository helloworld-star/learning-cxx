#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
/** static int func: 限制函数作用域在当前文件内 **/
/** static int static_: 将变量的作用域限制在当前函数内部，同时延长生命周期 **/
static int func(int param) {
    static int static_ = param;
    // std::cout << "static_ = " << static_ << std::endl;
    return static_++; // 先返回再加加
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    /** static 只初始化一次 **/
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect");
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
