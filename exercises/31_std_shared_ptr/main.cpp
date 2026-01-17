#include "../exercise.h"
#include <memory>

// READ: `std::shared_ptr` <https://zh.cppreference.com/w/cpp/memory/shared_ptr>
// READ: `std::weak_ptr` <https://zh.cppreference.com/w/cpp/memory/weak_ptr>

// TODO: 将下列 `?` 替换为正确的值
/** shared_ptr: 可以读写 自动释放 引用计数 **/
/** weak_ptr: 只能访问对象本身 仅观察 不计数 **/
int main(int argc, char **argv) {
    auto shared = std::make_shared<int>(10);
    std::shared_ptr<int> ptrs[]{shared, shared, shared};

    std::weak_ptr<int> observer = shared;
    ASSERT(observer.use_count() == 4, "");

    ptrs[0].reset();
    ASSERT(observer.use_count() == 3, "");

    ptrs[1] = nullptr;
    ASSERT(observer.use_count() == 2, "");

    ptrs[2] = std::make_shared<int>(*shared); // 指向新对象 值相同
    ASSERT(observer.use_count() == 1, "");

    ptrs[0] = shared;
    ptrs[1] = shared;
    ptrs[2] = std::move(shared);
    ASSERT(observer.use_count() == 3, "");

    std::cout << *ptrs[0] << std::endl;
    std::ignore = std::move(ptrs[0]); // 忽略赋值
    std::cout << *ptrs[0] << std::endl;
    ptrs[1] = std::move(ptrs[1]); // self move 值不变
    ptrs[1] = std::move(ptrs[2]); // 2 变空
    ASSERT(observer.use_count() == 2, "");

    shared = observer.lock(); // 如果对象存在 返回的 shared_ptr 会增加引用计数
    ASSERT(observer.use_count() == 3, "");

    shared = nullptr;
    for (auto &ptr : ptrs) ptr = nullptr;
    ASSERT(observer.use_count() == 0, "");

    shared = observer.lock();
    ASSERT(observer.use_count() == 0, ""); // 对象不存在

    return 0;
}
