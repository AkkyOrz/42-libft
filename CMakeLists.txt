cmake_minimum_required(VERSION 3.0)
project(cmake_example C CXX)

find_package(GTest REQUIRED)

add_compile_options(-Wall -Wextra -Werror)

file(GLOB LIBFT "ft_*.c")
add_library(libft STATIC ${LIBFT})

# add_executable(main main.cpp)

# target_link_libraries(main
#   PRIVATE
#     GTest::GTest
#     GTest::Main   # GTest::Mainをリンクすると自分でmain関数を書く必要がなくなる
#     ft_printf
# )
