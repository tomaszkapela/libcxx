//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//

#include <memory>
#include <type_traits>

template<typename T>
class wrapper {
};

template<typename T>
class custom_ptr {
public:
	using persistency_type = wrapper<T>;
};

int main() {
    static_assert((std::is_same<std::pointer_traits<custom_ptr<char>>::persistency_type, wrapper<char>>::value), "");
    static_assert((std::is_same<std::pointer_traits<char*>::persistency_type, char>::value), "");
}
