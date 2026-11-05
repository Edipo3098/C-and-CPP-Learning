project(MotorTest)

add_executable(MotorTest src/main.cpp src/Car.cpp)
target_include_directories(MotorTest PRIVATE inc)
