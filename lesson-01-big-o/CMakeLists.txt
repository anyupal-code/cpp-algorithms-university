# Создаем две исполняемые программы: naive и optimal
add_executable(naive src/naive.cpp)
add_executable(optimal src/optimal.cpp)

# Оптимизация для релизной сборки (если нужно)
# target_compile_options(naive PRIVATE -O2)
# target_compile_options(optimal PRIVATE -O2)