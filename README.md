## ***\*跨平台编译说明\****

为将本系统部署至华为鲲鹏等 ARM 架构的设备，需在基于 Windows x86 架构的开发环境中进行交叉编译。以下为完整的编译流程说明：

### ***\*1. 工具链准备（建议使用 WSL）\****

在 Windows 系统中使用 WSL（Windows 子系统 Linux，推荐 Ubuntu）进行编译，需先安装交叉编译器：

bash

sudo apt update

sudo apt install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu

### ***\*2. 编译命令（命令行方式）\****

进入项目根目录，使用如下命令将程序编译为 ARM 架构可执行文件：

bash

aarch64-linux-gnu-g++ -std=c++17 -Iinclude -o omni_core_arm main.cpp src/*.cpp

如需更明确地指定平台 ABI 和指令集，可使用：

bash

aarch64-linux-gnu-g++ -std=c++17 -march=armv8-a -mabi=lp64 -Iinclude -o omni_core_arm main.cpp src/*.cpp

编译成功后生成 omni_core_arm 可执行文件。

### ***\*3. 上传并运行于鲲鹏平台\****

使用 SCP 上传至目标 ARM 平台服务器（如鲲鹏）：

bash

scp omni_core_arm username@kunpeng_ip:/home/username/

ssh username@kunpeng_ipchmod +x omni_core_arm

./omni_core_arm

### ***\*4. 可选：使用 CMake 构建（推荐）\****

新建文件 toolchain-arm64.cmake：

cmake

SET(CMAKE_SYSTEM_NAME Linux)

SET(CMAKE_SYSTEM_PROCESSOR aarch64)

SET(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)

SET(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

执行构建：

bash

cmake -DCMAKE_TOOLCHAIN_FILE=toolchain-arm64.cmake .

make

### ***\*5. 平台差异处理建议（参考补充材料）\****

使用 GCC 提供的预定义宏，编写跨平台兼容代码：

cpp

\#ifdef __x86_64__// x86 平台特定代码#elif defined(__aarch64__)// ARM 平台特定代码（如华为鲲鹏）#endif# -
