find_package(Threads)

link_libraries(Threads::Threads)
add_executable(thread-addvec-ptr addvec-ptr.cpp)
add_executable(thread-addvec-ref addvec-ref.cpp)
add_executable(thread-incvec-ref incvec-ref.cpp)