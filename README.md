# 1. 编译过程

## 1.1 gcc/g++ 编译过程

### 1.1.1 hello_world

**文件名称：** `hello_world.c`

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    return 0;
}
```

**文件结构：**

> .
> ├── hello_world.c
> └── README.md

### 1.1.2 直接编译

该方式直接从源文件（`hello_world.c`）生成**可执行文件**

- `gcc hello_world.c`

  > .
  > ├── a.out
  > ├── hello_world.c
  > └── README.md

- `gcc hello_world.c -o hello_world`

  > .
  > ├── hello_world
  > ├── hello_world.c
  > └── README.md

### 1.1.3 分步编译

即把上一小节的**直接编译**进行拆分，按照标准步骤执行编译。共分为四个步骤，预处理，编译，汇编，链接。

#### 1.1.3.1 预处理

将源文件处理为`.ii/.i`，处理各种预处理指令，如`#include`、`#ifdef`、`#if`等等，同时也会清除注释。默认将结果输出到命令窗口，使用`-o`输出`hello_world.i`文件

- `gcc -E hello_world.c`

  > ```
  > # 1 "hello_world.c"
  > # 1 "<built-in>"
  > # 1 "<command-line>"
  > # 31 "<command-line>"
  > # 1 "/usr/include/stdc-predef.h" 1 3 4
  > # 32 "<command-line>" 2
  > # 1 "hello_world.c"
  > # 1 "/usr/include/stdio.h" 1 3 4
  > # 27 "/usr/include/stdio.h" 3 4
  > # 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
  > # 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
  > # 1 "/usr/include/features.h" 1 3 4
  > # 461 "/usr/include/features.h" 3 4
  > # 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
  > # 452 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
  > # 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
  > # 453 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
  > # 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
  > 
  > ......
  > 
  > # 2 "hello_world.c" 2
  > 
  > 
  > # 3 "hello_world.c"
  > int main(int argc, char *argv[])
  > {
  >     printf("Hello World!\n");
  >     return 0;
  > }
  > ```

- `gcc -E hello_world.c -o hello_world.i`

  > .
  > ├── hello_world.c
  > ├── hello_world.i
  > └── README.md

#### 1.1.3.2 编译

将`.c/.ii/.i`处理为`.S/.asm`，即机器语言的汇编文件。对文件执行预处理、编译，默认输出`hello_world.s`文件。可使用`-o`修改名称

- 源文件编译

  `gcc -S hello_world.c` >> `hello_world.s`

  `gcc -S hello_world.c -o hello_world.s` >> `hello_world.s`

  > .
  > ├── hello_world.c
  > ├── hello_world.s
  > └── README.md

- 预编译文件编译

  `gcc -S hello_world.i` >> `hello_world.s`

  `gcc -S hello_world.i -o hello_world.s` >> `hello_world.s`

  > .
  > ├── hello_world.c
  > ├── hello_world.i
  > ├── hello_world.s
  > └── README.md

#### 1.1.3.3 汇编

将`.c/.ii/.i/.asm/.S`处理为`.o`，把汇编文件变成机器码。对文件执行预处理、编译、汇编，默认输出`hello_world.o`文件。可使用`-o`修改名称

- 源文件汇编

  `gcc -c hello_world.c` >> `hello_world.o`

  `gcc -c hello_world.c -o hello_world.o` >> `hello_world.o`

  > .
  > ├── hello_world.c
  > ├── hello_world.o
  > └── README.md

- 预编译文件汇编

  `gcc -c hello_world.i` >> `hello_world.o`

  `gcc -c hello_world.i -o hello_world.o`

  > .
  > ├── hello_world.c
  > ├── hello_world.i
  > ├── hello_world.o
  > └── README.md

- 编译文件汇编

  `gcc -c hello_world.s` >> `hello_world.o`

  `gcc -c hello_world.s -o hello_world.o` >> `hello_world.o`

  > .
  > ├── hello_world.c
  > ├── hello_world.i
  > ├── hello_world.o
  > ├── hello_world.s
  > └── README.md

#### 1.1.3.4 链接

将各种依赖的`静态/动态库文件`、`.o文件`、`启动文件`链接成最终的`可执行文件`或者`库文件`。对文件执行预处理、编译、汇编、链接，默认输出`a.out`，可使用`-o`修改名称

- 源文件链接（`直接编译`）

  `gcc hello_world.c`

  `gcc hello_world.c -o a.out`

  > .
  > ├── a.out
  > ├── hello_world.c
  > └── README.md

- 预编译文件链接

  `gcc hello_world.i`

  `gcc hello_world.i -o a.out`

  > .
  > ├── a.out
  > ├── hello_world.c
  > ├── hello_world.i
  > └── README.md

- 编译文件链接

  `gcc hello_world.s`

  `gcc hello_world.s -o a.out`

  > .
  > ├── a.out
  > ├── hello_world.c
  > ├── hello_world.i
  > ├── hello_world.s
  > └── README.md

- 汇编文件链接

  `gcc hello_world.o`

  `gcc hello_world.o -o a.out`

  > .
  > ├── a.out
  > ├── hello_world.c
  > ├── hello_world.i
  > ├── hello_world.o
  > ├── hello_world.s
  > └── README.md

### 1.1.4 常用选项

| 序号 | 选项      | 含义                                                         |
| ---- | --------- | ------------------------------------------------------------ |
| 1    | `-o`      | 指定输出文件路径，默认为`a.out`<br />`gcc source_name.c` >> `a.out`<br />`gcc source_name.c -o source_name` >> `source_name` |
| 2    | `-E`      | 仅对源文件进行预处理，默认将结果输出到命令窗口，使用`-o`输出`source_name.i`文件<br />`gcc -E source_name` >> 命令窗口<br />`gcc -E source_name -o source_name.i` >> `source_name.i` |
| 3    | `-S`      | 对文件执行预处理、编译，默认输出`source_name.s`文件。可使用`-o`修改名称<br />`gcc -S source_name.c` >> `source_name.s`<br />`gcc -S source_name.c -o source_name.s` >> `source_name.s`<br /><br />`gcc -S source_name.i` >> `source_name.s`<br />`gcc -S source_name.i -o source_name.s` >> `source_name.s` |
| 4    | `-c`      | 对文件执行预处理、编译、汇编，默认输出`source_name.o`文件。可使用`-o`修改名称<br />`gcc -c source_name.c` >> `source_name.o`<br />`gcc -c source_name.c -o source_name.o` >> `source_name.o`<br /><br />`gcc -c source_name.i` >> `source_name.o`<br />`gcc -c source_name.i -o source_name.o`<br /><br />`gcc -c source_name.s` >> `source_name.o`<br />`gcc -c source_name.s -o source_name.o` >> `source_name.o` |
| 5    | `-I`      | 指定头文件路径                                               |
| 6    | `-L`      | 指定库文件路径                                               |
| 7    | `-l`      | 指定库文件                                                   |
| 8    | `-fPIC`   | 生成位置无关代码                                             |
| 9    | `-Wall`   | 开启所有警告                                                 |
| 10   | `-g`      | 启用调试信息                                                 |
| 11   | `-static` | 创建静态库                                                   |
| 12   | `-shared` | 创建动态库                                                   |



## 1.2 库与可执行文件

### 1.2.1 程序源码

- 库头文件

  ```c
  // file name: my_math.h
  
  #ifndef __MY_MATH_H__
  #define __MY_MATH_H__
  int my_add(int a, int b);
  #endif
  ```

- 库源文件

  ```c
  // file name: my_math.c
  
  #include "my_math.h"
  
  int my_add(int a, int b)
  {
      return a + b;
  }
  ```

- 库测试文件

  ```c
  // file name: my_math_test.c
  
  #include <stdio.h>
  #include "my_math.h"
  
  int main(int argc, char *argv[])
  {
      printf("my_math >> my_add: 3 + 4 = %d\n", my_add(3, 4));
      return 0;
  }
  ```

- 文件结构

  > .
  > ├── libmy_math.a
  > ├── my_math.c
  > ├── my_math.h
  > ├── my_math_test.c
  > └── README.md

### 1.2.2 静态库

- 编译

  - 生成汇编文件

    `gcc -static -c my_math.c`

    > .
    > ├── my_math.c
    > ├── my_math.h
    > ├── my_math.o
    > ├── my_math_test.c
    > └── README.md

  - 打包静态库文件

    `ar -crv libmy_math.a my_math.o`

    > .
    > ├── libmy_math.a
    > ├── my_math.c
    > ├── my_math.h
    > ├── my_math.o
    > ├── my_math_test.c
    > └── README.md

- 链接

  `gcc my_math_test.c -I. -L. -lmy_math`

  > .
  > ├── a.out
  > ├── libmy_math.a
  > ├── my_math.c
  > ├── my_math.h
  > ├── my_math.o
  > ├── my_math_test.c
  > └── README.md

- 可执行文件运行结果

  `./a.out`

  > my_math >> my_add: 3 + 4 = 7

### 1.2.3 动态库

- 编译

  - 生成汇编文件

    `gcc -c -fPIC my_math.c`

    > .
    > ├── my_math.c
    > ├── my_math.h
    > ├── my_math.o
    > ├── my_math_test.c
    > └── README.md

  - 创建动态库文件

    `gcc -shared my_math.o -o libmy_math.so`

    > .
    > ├── libmy_math.so
    > ├── my_math.c
    > ├── my_math.h
    > ├── my_math.o
    > ├── my_math_test.c
    > └── README.md

- 链接

  `gcc my_math_test.c -I. -L. -lmy_math`

  > .
  > ├── a.out
  > ├── libmy_math.so
  > ├── my_math.c
  > ├── my_math.h
  > ├── my_math.o
  > ├── my_math_test.c
  > └── README.md

- 可执行文件运行结果

  `./a.out`

  > ./a.out: error while loading shared libraries: libmy_math.so: cannot open shared object file: No such file or directory

  `export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH`

  `./a.out`

  > my_math >> my_add: 3 + 4 = 7

#### 1.2.3.1 动态库搜索路径的先后顺序

- 编译目标代码时指定的动态库搜索路径
- 环境变量`LD_LIBRARY_PATH`指定的动态库搜索路径
- 配置文件`/etc/ld.so.conf`中指定的动态库搜索路径，只需要在该文件后追加一行完整路径如`/root/test/lib`即可，然后`ldconfig`使修改生效
- 默认的动态库搜索路径`/lib`
- 默认的动态库搜索路径`/usr/lib`

## 1.3 make与makefile

由上面的两小节的内容可知，根据源文件生成可执行文件，通过一系列的`gcc/g++`命令即可完成。以上的案例中使用的源文件都非常简单，使用命令直接生成，不算费事。但是，如果一个项目中包含成百上千个源文件，这些源文件又被划分为不同的模块，每个模块可能又依赖不同的第三方库文件，这时使用命令行进行编译就非常不方便了。

`makefile`文件承载了项目编译过程中的所有命令，同时具有命令行操作所不具有的特性。`make`是一个命令工具，用来解释与执行`makefile`文件中的指令。

### 1.3.1 makefile 规则

```
<target1 > <target2>.... : <prerequisites1> <prerequisites2>...
[TAB] <command1>
[TAB] <command2>
...
```

- `<target1 > <target2>....`

  可以是一个目标文件（object file），也可以是一个可执行文件（executable file），还可以是一个标签（label）

- `<prerequisites1> <prerequisites2>...`

  生成`target`所需的文件或目标

- `[TAB] <command1>`

  make 工具需要执行的命令

> **注意**
>
> 以上说明了一种依赖关系。
>
> 一个或多个的`<target>`依赖于`<prerequisites>`中的文件，其生成规则定义在`<command>`中。
>
> 此外，如果`<prerequisites>`中有一个以上的文件比上次生成`<target>`时新，那么将重新执行`<command>`，以重新生成`<target>`

### 1.3.2 hello_world

- 程序源码

  ```c
  // file name: hello_world.c
  
  #include <stdio.h>
  
  int main(int argc, char *argv[])
  {
      printf("Hello World!\n");
      return 0;
  }
  ```

- makefile

  ```makefile
  # file name: Makefile
  
  hello_world:hello_world.c
  	gcc -E hello_world.c -o hello_world.i
  	gcc -S hello_world.i -o hello_world.s
  	gcc -c hello_world.s -o hello_world.o
  	gcc    hello_world.o -o hello_world
  	
  clean:
  	rm hello_world.i hello_world.s hello_world.o hello_world
  ```

- make

  - `make/make hello_world`

    > .
    > ├── hello_world
    > ├── hello_world.c
    > ├── hello_world.i
    > ├── hello_world.o
    > ├── hello_world.s
    > ├── Makefile
    > └── README.md

  - `make clean`

    > .
    > ├── hello_world.c
    > ├── Makefile
    > └── README.md

- 可执行文件运行结果

  `./hello_world`

  > Hello World!

### 1.3.3 分布生成版本

```makefile
# file name: Makefile

hello_world : hello_world.o
	gcc    hello_world.o -o hello_world

hello_world.o : hello_world.s
	gcc -c hello_world.s -o hello_world.o

hello_world.s : hello_world.i
	gcc -S hello_world.i -o hello_world.s

hello_world.i : hello_world.c
	gcc -E hello_world.c -o hello_world.i

clean:
	rm hello_world.i hello_world.s hello_world.o hello_world
```

### 1.3.4 Makefile 结构说明

Makefile里主要包含了五个东西：变量定义、显式规则、隐晦规则、文件指示和注释。

1. 变量的定义

   在Makefile中我们要定义一系列的变量，变量一般都是字符串，这个有点像C语言中的宏，当Makefile被执行时，其中的变量都会被扩展到相应的引用位置上。


   2. 显式规则

      显式规则说明了，如何生成一个或多的的目标文件。这是由Makefile的书写者明显指出，要生成的文件，文件的依赖文件，生成的命令。 

   3. 隐晦规则

      由于我们的make有自动推导的功能，所以隐晦的规则可以让我们比较粗糙地简略地书写Makefile，这是由make所支持的。

   4. 文件指示

      其包括了三个部分，一个是在一个Makefile中引用另一个Makefile，就像C语言中的include一样。

   5. 注释

      Makefile中只有行注释，和UNIX的Shell脚本一样，其注释是用**#**字符。

### 1.3.5 变量推导版本

```makefile
# file name: Makefile

target = hello_world
sources = hello_world.c

$(target):hello_world.o
	gcc    hello_world.o -o hello_world

hello_world.o : hello_world.s
	gcc -c hello_world.s -o hello_world.o

hello_world.s : hello_world.i
	gcc -S hello_world.i -o hello_world.s

hello_world.i : $(sources)
	gcc -E hello_world.c -o hello_world.i
    
clean:
	rm hello_world.i hello_world.s hello_world.o hello_world
```

### 1.3.6 自动推导版本

常用预定义变量

 | 序号 | 预定义变量 | 含义                                                         |
 | ---- | ---------- | ------------------------------------------------------------ |
 | 1    | `$*`       | 不包含扩展名的目标文件名称                                   |
 | 2    | `$+`       | 所有的依赖文件，以空格分开，并以出现的先后为序，可能包含重复的依赖文件 |
 | 3    | `$<`       | 第一个依赖文件的名称                                         |
 | 4    | `$?`       | 所有的依赖文件，以空格分开，这些依赖文件的修改日期比目标的创建日期晚 |
 | 5    | `$@`       | 目标的完整名称                                               |
 | 6    | `$^`       | 所有的依赖文件，以空格分开，不包含重复的依赖文件             |
 | 7    | `$%`       | 如果目标是归档成员，则该变量表示目标的归档成员名称           |

```makefile
# file name: Makefile

# 常用预定义变量
# $* 不包含扩展名的目标文件名称, 这个是GNU make特有的, 其它的make不一定支持
# $+ 所有的依赖文件，以空格分开，并以出现的先后为序，可能包含重复的依赖文件
# $< 第一个依赖文件的名称
# $? 所有的依赖文件，以空格分开，这些依赖文件的修改日期比目标的创建日期晚
# $@ 目标的完整名称
# $^ 所有的依赖文件，以空格分开，不包含重复的依赖文件
# $% 如果目标是归档成员，则该变量表示目标的归档成员名称
target = hello_world

$(target) : $(target).o
	gcc    $< -o $@

$(target).o : $(target).s
	gcc -c $< -o $@

$(target).s : $(target).i
	gcc -S $< -o $@

$(target).i : $(target).c
	gcc -E $< -o $@


clean:
	rm $(target).i $(target).s $(target).o $(target)
```

### 1.3.7 增量型编译

大型项目包含的源文件的数量较多，如果使用`shell`命令进行直接编译，则每个文件都需要重新编译。这样的方式导致，任何一处小小的改动，都需要大量的时间进行编译。makefile 与 make 提供了增量编译的功能，即仅重新编译改动或新增的文件，加快编译速度。

- 样例文件

  - my_math_add.h

    ```c
    #ifndef __MY_MATH_ADD_H__
    #define __MY_MATH_ADD_H__
    int my_math_add(int a, int b);
    #endif
    ```

  - my_math_add.c

    ```c
    #include "my_math_add.h"
    
    int my_math_add(int a, int b)
    {
        return a + b;
    }
    ```

  - my_math_sub.h

    ```c
    #ifndef __MY_MATH_SUB_H__
    #define __MY_MATH_SUB_H__
    int my_math_sub(int a, int b);
    #endif
    ```

  - my_math_sub.c

    ```c
    #include "my_math_sub.h"
    
    int my_math_sub(int a, int b)
    {
        return a - b;
    }
    ```

  - my_math_test

    ```c
    #include <stdio.h>
    #include "my_math_add.h"
    #include "my_math_sub.h"
    
    int main(int argc, char *argv[])
    {
        printf("my_math >> my_math_add: 3 + 4 = %d\n", my_math_add(3, 4));
        printf("my_math >> my_math_sub: 3 - 4 = %d\n", my_math_sub(3, 4));
        return 0;
    }
    ```

- Makefile

  ```makefile
  # file name: Makefile
  target = my_math_test
  obj = my_math_test.o my_math_add.o my_math_sub.o
  
  $(target):$(obj)
  	$(CC) $^ -o $@
  
  my_math_test.o: my_math_test.c
  	$(CC) -c $^
  
  my_math_add.o: my_math_add.c
  	$(CC) -c $^
  
  my_math_sub.o: my_math_sub.c
  	$(CC) -c $^
  
  clean:
  	$(RM) $(target) $(obj)
  ```

- 编译效果

  - 第一次编译

    > cc -c my_math_test.c
    > cc -c my_math_add.c
    > cc -c my_math_sub.c
    > cc my_math_test.o my_math_add.o my_math_sub.o -o my_math_test

  - 改动后编译

    修改`my_math_add.c`文件如下：

    ```c
    #include "my_math_add.h"
    
    int my_math_add(int a, int b)
    {
        return a + b + 0;
    }
    ```

    再次编译

    > cc -c my_math_add.c
    > cc my_math_test.o my_math_add.o my_math_sub.o -o my_math_test

  - 结论

    **make 与 makefile 配合使用，仅重新编译有变化的文件或依赖于有变化的文件的相关目标**

## 1.4 CMake

make 与 makefile给项目的编译带来了巨大方便，但是需要专门花时间去编写Makefile文件。由于Makefile的语法晦涩难懂，想写出一个跨平台的，多模块依赖，成千上万个源文件的项目，也需要花费大量的时间。为了解决这种困境，不同的组织开发不同的工具，例如，`nmake`，`qmake`，`automake`，`cmake`等等，其中`cmake`的普及度较高。

### 1.4.1 Hello World

- hello_world.c

  ```c
  #include <stdio.h>
  
  int main(int argc, char *argv[])
  {
      printf("Hello World!\n");
      return 0;
  }
  ```

- CMakeLists.txt

  ```cmake
  CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
  PROJECT(cmake_examples)
  
  add_executable(hello_world hello_world.c)
  ```

- cmake 命令生成的Makefile

  ```makefile
  # CMAKE generated file: DO NOT EDIT!
  # Generated by "Unix Makefiles" Generator, CMake Version 3.16
  
  # Default target executed when no arguments are given to make.
  default_target: all
  
  .PHONY : default_target
  
  # Allow only one "make -f Makefile2" at a time, but pass parallelism.
  .NOTPARALLEL:
  
  
  #=============================================================================
  # Special targets provided by cmake.
  
  # Disable implicit rules so canonical targets will work.
  .SUFFIXES:
  
  
  # Remove some rules from gmake that .SUFFIXES does not remove.
  SUFFIXES =
  
  .SUFFIXES: .hpux_make_needs_suffix_list
  
  
  # Suppress display of executed commands.
  $(VERBOSE).SILENT:
  
  
  # A target that is always out of date.
  cmake_force:
  
  .PHONY : cmake_force
  
  #=============================================================================
  # Set environment variables for the build.
  
  # The shell in which to execute make rules.
  SHELL = /bin/sh
  
  # The CMake executable.
  CMAKE_COMMAND = /usr/bin/cmake
  
  # The command to remove a file.
  RM = /usr/bin/cmake -E remove -f
  
  # Escaping for special characters.
  EQUALS = =
  
  # The top-level source directory on which CMake was run.
  CMAKE_SOURCE_DIR = /home/u20/BaiduSyncdisk/Sharing
  
  # The top-level build directory on which CMake was run.
  CMAKE_BINARY_DIR = /home/u20/BaiduSyncdisk/Sharing/build
  
  #=============================================================================
  # Targets provided globally by CMake.
  
  # Special rule for the target rebuild_cache
  rebuild_cache:
  	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
  	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
  .PHONY : rebuild_cache
  
  # Special rule for the target rebuild_cache
  rebuild_cache/fast: rebuild_cache
  
  .PHONY : rebuild_cache/fast
  
  # Special rule for the target edit_cache
  edit_cache:
  	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
  	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
  .PHONY : edit_cache
  
  # Special rule for the target edit_cache
  edit_cache/fast: edit_cache
  
  .PHONY : edit_cache/fast
  
  # The main all target
  all: cmake_check_build_system
  	$(CMAKE_COMMAND) -E cmake_progress_start /home/u20/BaiduSyncdisk/Sharing/build/CMakeFiles /home/u20/BaiduSyncdisk/Sharing/build/CMakeFiles/progress.marks
  	$(MAKE) -f CMakeFiles/Makefile2 all
  	$(CMAKE_COMMAND) -E cmake_progress_start /home/u20/BaiduSyncdisk/Sharing/build/CMakeFiles 0
  .PHONY : all
  
  # The main clean target
  clean:
  	$(MAKE) -f CMakeFiles/Makefile2 clean
  .PHONY : clean
  
  # The main clean target
  clean/fast: clean
  
  .PHONY : clean/fast
  
  # Prepare targets for installation.
  preinstall: all
  	$(MAKE) -f CMakeFiles/Makefile2 preinstall
  .PHONY : preinstall
  
  # Prepare targets for installation.
  preinstall/fast:
  	$(MAKE) -f CMakeFiles/Makefile2 preinstall
  .PHONY : preinstall/fast
  
  # clear depends
  depend:
  	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
  .PHONY : depend
  
  #=============================================================================
  # Target rules for targets named hello_world
  
  # Build rule for target.
  hello_world: cmake_check_build_system
  	$(MAKE) -f CMakeFiles/Makefile2 hello_world
  .PHONY : hello_world
  
  # fast build rule for target.
  hello_world/fast:
  	$(MAKE) -f CMakeFiles/hello_world.dir/build.make CMakeFiles/hello_world.dir/build
  .PHONY : hello_world/fast
  
  hello_world.o: hello_world.c.o
  
  .PHONY : hello_world.o
  
  # target to build an object file
  hello_world.c.o:
  	$(MAKE) -f CMakeFiles/hello_world.dir/build.make CMakeFiles/hello_world.dir/hello_world.c.o
  .PHONY : hello_world.c.o
  
  hello_world.i: hello_world.c.i
  
  .PHONY : hello_world.i
  
  # target to preprocess a source file
  hello_world.c.i:
  	$(MAKE) -f CMakeFiles/hello_world.dir/build.make CMakeFiles/hello_world.dir/hello_world.c.i
  .PHONY : hello_world.c.i
  
  hello_world.s: hello_world.c.s
  
  .PHONY : hello_world.s
  
  # target to generate assembly for a file
  hello_world.c.s:
  	$(MAKE) -f CMakeFiles/hello_world.dir/build.make CMakeFiles/hello_world.dir/hello_world.c.s
  .PHONY : hello_world.c.s
  
  # Help Target
  help:
  	@echo "The following are some of the valid targets for this Makefile:"
  	@echo "... all (the default if no target is provided)"
  	@echo "... clean"
  	@echo "... depend"
  	@echo "... rebuild_cache"
  	@echo "... edit_cache"
  	@echo "... hello_world"
  	@echo "... hello_world.o"
  	@echo "... hello_world.i"
  	@echo "... hello_world.s"
  .PHONY : help
  
  
  
  #=============================================================================
  # Special targets to cleanup operation of make.
  
  # Special rule to run CMake to check the build system integrity.
  # No rule that depends on this can have commands that come from listfiles
  # because they might be regenerated.
  cmake_check_build_system:
  	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
  .PHONY : cmake_check_build_system
  ```

- 文件结构

  > ├── build
  > │   ├── CMakeCache.txt
  > │   ├── CMakeFiles
  > │   │   ├── 3.16.3
  > │   │   │   ├── CMakeCCompiler.cmake
  > │   │   │   ├── CMakeCXXCompiler.cmake
  > │   │   │   ├── CMakeDetermineCompilerABI_C.bin
  > │   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
  > │   │   │   ├── CMakeSystem.cmake
  > │   │   │   ├── CompilerIdC
  > │   │   │   │   ├── a.out
  > │   │   │   │   ├── CMakeCCompilerId.c
  > │   │   │   │   └── tmp
  > │   │   │   └── CompilerIdCXX
  > │   │   │       ├── a.out
  > │   │   │       ├── CMakeCXXCompilerId.cpp
  > │   │   │       └── tmp
  > │   │   ├── cmake.check_cache
  > │   │   ├── CMakeDirectoryInformation.cmake
  > │   │   ├── CMakeOutput.log
  > │   │   ├── CMakeTmp
  > │   │   ├── hello_world.dir
  > │   │   │   ├── build.make
  > │   │   │   ├── cmake_clean.cmake
  > │   │   │   ├── DependInfo.cmake
  > │   │   │   ├── depend.make
  > │   │   │   ├── flags.make
  > │   │   │   ├── link.txt
  > │   │   │   └── progress.make
  > │   │   ├── Makefile2
  > │   │   ├── Makefile.cmake
  > │   │   ├── progress.marks
  > │   │   └── TargetDirectories.txt
  > │   ├── cmake_install.cmake
  > │   └── Makefile
  > ├── CMakeLists.txt
  > ├── hello_world.c
  > └── README.md

### 1.4.2 库文件与可执行文件

- 源文件

  - my_math.h

    ```c
    #ifndef __MY_MATH_H__
    #define __MY_MATH_H__
    int my_add(int a, int b);
    #endif
    ```

  - my_math.c

    ```c
    #include "my_math.h"
    
    int my_add(int a, int b)
    {
        return a + b;
    }
    ```

  - my_math_test.c

    ```c
    #include <stdio.h>
    #include "my_math.h"
    
    int main(int argc, char *argv[])
    {
        printf("my_math >> my_math_add: 3 + 4 = %d\n", my_add(3, 4));
        return 0;
    }
    ```

- CMakeLists.txt

  ```cmake
  CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
  PROJECT(cmake_examples)
  
  # 注意：
  # 	在CMake中，命令不区分大小写，参数区分大小写
  SET(CMAKE_INCLUDE_CURRENT_DIR ON)
  
  add_library(my_math_static STATIC my_math.c)
  add_library(my_math_shared SHARED my_math.c)
  
  add_executable(my_math_static_test my_math_test.c)
  target_link_libraries(my_math_static_test PRIVATE my_math_static)
  
  add_executable(my_math_shared_test my_math_test.c)
  target_link_libraries(my_math_shared_test PRIVATE my_math_shared)
  ```

- 文件结构

  > ├── CMakeLists.txt
  > ├── my_math.c
  > ├── my_math.h
  > ├── my_math_test.c
  > └── README.md

### 1.4.3 库与可执行文件分层处理

- 源文件

  与上一节相同

- CMakeLists.txt

  ```cmake
  CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
  PROJECT(cmake_examples)
  
  SET(CMAKE_INCLUDE_CURRENT_DIR ON)
  
  add_subdirectory(my_math)
  
  add_executable(my_math_static_test my_math_test.c) 
  target_link_libraries(my_math_static_test PRIVATE my_math_static)
  
  add_executable(my_math_shared_test my_math_test.c)
  target_link_libraries(my_math_shared_test PRIVATE my_math_shared)
  ```

- my_math/CMakeLists.txt

  ```cmake
  add_library(my_math_static STATIC "")
  target_sources(my_math_static
                 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/my_math.c
                 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/my_math.h)
  
  add_library(my_math_shared SHARED "")
  target_sources(my_math_shared
                 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/my_math.c
                 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/my_math.h)
  
  # PRIVATE : 源文件只是在构建库文件是使用
  # PUBLIC  : 头文件在构建和编译时都会使用，则在使用该库是不需要显式包含my_math.h所在的文件夹
  ```

- 文件结构

  > .
  > ├── CMakeLists.txt
  > ├── my_math
  > │   ├── CMakeLists.txt
  > │   ├── my_math.c
  > │   └── my_math.h
  > ├── my_math_test.c
  > └── README.md

### 1.4.4 常用代码段

#### 1.4.4.1 判断平台类型

```cmake
MESSAGE(STATUS "###################################")
MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
    SET(vsomeip3_DIR C:/3rdParts/vsomeip/vc16/CMake)
    SET(Qt5_DIR C:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
    SET(BOOST_ROOT       C:/3rdParts/boost_1_74_0)
    SET(BOOST_INCLUDEDIR C:/3rdParts/boost_1_74_0/boost)
    SET(BOOST_LIBRARYDIR C:/3rdParts/boost_1_74_0/lib64-msvc-14.2)
    set(Boost_LIB_PREFIX "lib")
    set(Boost_ARCHITECTURE "-x64")
else()
    SET(Qt5_DIR /opt/Qt5.12.12/5.12.12/gcc_64/lib/cmake/Qt5)
ENDIF()
MESSAGE(STATUS "###################################")
```

#### 1.4.4.2 判断配置类型

```cmake
IF (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL Debug))
    ADD_COMPILE_DEFINITIONS(DEBUG)
ENDIF()
```

#### 1.4.4.3 查找库

```cmake
FIND_PACKAGE(Boost REQUIRED COMPONENTS filesystem system regex)
MESSAGE(STATUS =================================)
if(Boost_FOUND)
    MESSAGE(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
    MESSAGE(STATUS "Boost_LIBRARIES    = ${Boost_LIBRARIES}")
    MESSAGE(STATUS "Boost_LIB_VERSION  = ${Boost_LIB_VERSION}")
    MESSAGE(STATUS "Boost_LIBRARY_DIRS = ${Boost_LIBRARY_DIRS}")
endif()
MESSAGE(STATUS =================================)

find_package( OpenCV  REQUIRED)
MESSAGE(STATUS =================================)
if(OpenCV_FOUND)
    MESSAGE(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
    MESSAGE(STATUS "OpenCV_LIBRARIES    = ${OpenCV_LIBRARIES}")
endif()
MESSAGE(STATUS =================================)
```

#### 1.4.4.4 文件拷贝

```cmake
# 拷贝文件夹到项目编译输出目录
FILE(COPY data DESTINATION ${PROJECT_BINARY_DIR})

# 拷贝文件到项目编译输出目录
FILE(COPY text.json DESTINATION ${PROJECT_BINARY_DIR})
```

#### 1.4.4.5 文件按类型聚合

```cmake
FILE(GLOB_RECURSE TEST_HEADER LIST_DIRECTORIES false ./test/*.h)
FILE(GLOB_RECURSE TEST_SOURCE LIST_DIRECTORIES false ./test/*.c)

add_executable(test test.cpp ${LOG_DATA_HEADER} ${LOG_DATA_SOURCE})
```

### 1.4.5 VSCode 与 CMake

1. 安装`CMake`与`VSCode`

2. 安装扩展 `C/C++ Extension Pack`

3. 创建一个放置项目的文件夹并进入，例如：`mkdir test && cd test` 

4. 执行`code .` 以当前目录为工作空间打开`VSCode`

5. `ctrl + shift + p` 打开命令面板

6. 输入`CMake`，并选择`CMake: Quick Start`

7. 根据提示`选择编译器`，`输入项目名称`

8. 生成的文件如下：

   - main.cpp

     ```cpp
     #include <iostream>
     
     int main(int, char**) {
         std::cout << "Hello, world!\n";
     }
     ```

   - CMakeLists.txt

     ```cmake
     cmake_minimum_required(VERSION 3.0.0)
     project(tests VERSION 0.1.0)
     
     include(CTest)
     enable_testing()
     
     add_executable(tests main.cpp)
     
     set(CPACK_PROJECT_NAME ${PROJECT_NAME})
     set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
     include(CPack)
     ```

9. 调试

   - 在期望的位置增加断点

   - `ctrl + shift + p` 打开命令面板

   - 输入`CMake`，并选择`CMake: Debug`

     ![](/home/u20/Pictures/2022-08-09_14-14.png)

# 2. CPP

## 2.1 代码可读性

- 减少不必要的作用于嵌套，建议作用于嵌套不超过三层

  ```cpp
  #define LOOP_COUNT (10)
  
  int test()
  {
      for(int i = 0; i < LOOP_COUNT; i++)
      {
          if( i % 2)
          {
              std::cout << "even" << std::endl;
          }
          else
          {
              std::cout << "odd" << std::endl;
          }
      }
  }
  
  int test()
  {
      for(int i = 0; i < LOOP_COUNT; i++)
      {
          if( i % 2)
          {
              std::cout << "even" << std::endl;
              continue;
          }
          
          std::cout << "odd" << std::endl;
      }
  }
  ```

- 标识符的见名知意，除循环变量外尽量避免无意义的标识符

  ```cpp
  #define LOOP_COUNT (10)
  
  int a[LOOP_COUNT]{0};
  int test()
  {
      for(int i = 0; i < LOOP_COUNT; i++)
      {
          a[i] = i;
      }
  }
  
  int int_arr[10]{0};
  int test()
  {
      for(int i = 0; i < LOOP_COUNT; i++)
      {
          int_arr[i] = i;
      }
  }
  ```

- 活用类型别名

  ```cpp
  int price;
  int number;
  int total = price * number;
  
  #typedef int product_price
  #typedef int product_number;
  #typedef int prodect_total;
  
  product_price price;
  product_number number;
  prodect_total total = price * number;
  ```

- 让**魔法数**见鬼去吧

  ```cpp
  int arr[10];
  for(int i = 0; i < 5; i++)
  {
      
  }
  
  #define ARRAY_LENGTH (10)
  #define LOOP_COUNT (5)
  int arr[ARRAY_LENGTH];
  for(int i = 0; i < LOOP_COUNT; i++)
  {
      
  }
  ```

- 必要的注释

  ```cpp
  int adfafasf(int a, int b)  // 无注释，标识符定义又没做到见名知意
  {
      return a + b;
  }
  
  /// 计算两个int类型数的和，并返回计算结果
  int adfafasf(int a, int b)
  {
      return a + b;
  }
  
  int Add(int a, int b)
  {
      return a + b;
  }
  ```

- 活用**宏函数**

  需要多次重复使用，且短小的函数，尽量定义成宏函数。既增加了代码的复用，又减少了函数调用的开销

  ```cpp
  int Add(int a, int b)
  {
      return a + b;
  }
  
  int test()
  {
      ...
      Add(1, 2);
      ...
      Add(1, 2);
      ...
      Add(1, 2);
      ...
  }
  
  #define ADD(a, b) \
      {             \
          a + b     \
      }
  
  int test()
  {
      ...
      ADD(1, 2);
      ...
      ADD(1, 2);
      ...
      ADD(1, 2);
      ...
  }
  ```

- 有效代码函数不超过 **50**行

## 2.2 代码健壮性

- 宏常量需要用`()`封装

  ```cpp
  #define A (10)
  #define B (20)
  #define C A+B
  #define D (A + B)
  
  int main(int argc, char *argv[])
  {
      printf("C = %d, D = %d\n", C * 5, D * 5); // C = 110, D = 150
      return 0;
  }
  ```

- 宏函数注意事项

  ```cpp
  // 正确形式
  #define ADD(a, b) \
      {             \
          a + b     \
      }
  
  // 错误，宏函数名与(之间存在空格
  #define ADD (a, b) \
      {              \
          a + b      \
      }
  
  // 错误，不能使用 return 返回结果值
  #define ADD(a, b)        \
      {                    \
          return a + b     \
      }
  
  // 错误，有返回值，语句不能使用分好(;)
  #define ADD(a, b)  \
      {              \
          a + b;     \
      }
  ```

- 自定义功能块，需要经过单元测试，至少是功能测试

  ```cpp
  int add(int a, int b)
  {
      return a + b;
  }
  
  // 功能测试
  void TEST_add()
  {
      std::cout << add(3 , 4) << std::endl;
  }
  
  // 单元测试，一般需要有专门的测试人员进行测试，开发人员亦可以使用测试框架完成相对检测的单元测试
  ```

- 注意**局部静态变量**

  ```cpp
  #include <stdio.h>
  
  int add(int a, int b)
  {
      static int c = 0;
      printf("c = %d\n", ++c);
      return a + b;
  }
  
  int main(int argc, char *argv[])
  {
      for (size_t i = 0; i < 5; i++)
      {
          add(3, 4);
      }
      
      return 0;
  }
  
  // c = 1
  // c = 2
  // c = 3
  // c = 4
  // c = 5
  ```

- CPP调用C库，编译时报错**undefined reference**

  - C库

    - my_math.h

      ```c
      #ifndef __MY_MATH_H__
      #define __MY_MATH_H__
      int my_add(int a, int b);
      #endif
      ```

    - my_math.c

      ```c
      #include "my_math.h"
      
      int my_add(int a, int b)
      {
          return a + b;
      }
      ```

    - CMakeLists.txt

      ```cmake
      CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
      PROJECT(cmake_examples LANGUAGES C)
      
      SET(CMAKE_INCLUDE_CURRENT_DIR ON)
      
      add_library(my_math_static STATIC "")
      target_sources(my_math_static
                     PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/my_math.c
                     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/my_math.h)
      ```

  - CPP调用

    - my_math_test.cpp

      ```cpp
      #include <stdio.h>
      #include "my_math.h"
      
      int main(int argc, char *argv[])
      {
          printf("my_math >> my_math_add: 3 + 4 = %d\n", my_add(3, 4));
          return 0;
      }
      ```

    - CMakeLists.txt

      ```cmake
      CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
      PROJECT(cmake_examples LANGUAGES CXX)
      
      SET(CMAKE_INCLUDE_CURRENT_DIR ON)
      
      add_executable(my_math_static_test my_math_test.cpp)
      target_include_directories(my_math_static_test PRIVATE libs)
      target_link_directories(my_math_static_test PRIVATE libs)
      target_link_libraries(my_math_static_test PRIVATE my_math_static)
      ```

    - 编译报错

      > ```
      > (base) u20@u20:~/BaiduSyncdisk/Sharing/cmake-build-debug$ cmake ..
      > -- Configuring done
      > -- Generating done
      > -- Build files have been written to: /home/u20/BaiduSyncdisk/Sharing/cmake-build-debug
      > (base) u20@u20:~/BaiduSyncdisk/Sharing/cmake-build-debug$ make
      > [ 50%] Linking CXX executable my_math_static_test
      > /usr/bin/ld: CMakeFiles/my_math_static_test.dir/my_math_test.cpp.o: in function `main':
      > /home/u20/BaiduSyncdisk/Sharing/my_math_test.cpp:6: undefined reference to `my_add(int, int)'
      > collect2: error: ld returned 1 exit status
      > make[2]: *** [CMakeFiles/my_math_static_test.dir/build.make:84: my_math_static_test] Error 1
      > make[1]: *** [CMakeFiles/Makefile2:76: CMakeFiles/my_math_static_test.dir/all] Error 2
      > make: *** [Makefile:84: all] Error 2
      > ```

    - 原因分析

      **C**编译时，函数名称原样导出。这可以使用工具`nm`进行查看：

      - `nm libmy_math_static.a`

        > my_math.c.o:
        > 0000000000000000 T my_add

      **CPP**由于实现函数重载，所以在编译时会对函数名进行重整。将库的`CMakeLists.txt`文件内容进行如下替换，以便用**CPP**进行编译。编译后再次查看导出函数名称。

      ```cmake
      CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
      PROJECT(cmake_examples LANGUAGES CXX)
      
      SET(CMAKE_INCLUDE_CURRENT_DIR ON)
      
      add_library(my_math_static STATIC "")
      target_sources(my_math_static
                     PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/my_math.cpp
                     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/my_math.h)
      ```

      - `nm libmy_math_static.a`

        > my_math.cpp.o:
        > 0000000000000000 T _Z6my_addii

      用**nm**命令查看**nm my_math_static_test**，确认调用时使用的函数名称。

      - `nm my_math_static_test`

        > ```
        > 0000000000004010 B __bss_start
        > 0000000000004010 b completed.8061
        >                  w __cxa_finalize@@GLIBC_2.2.5
        > 0000000000004000 D __data_start
        > 0000000000004000 W data_start
        > 0000000000001090 t deregister_tm_clones
        > 0000000000001100 t __do_global_dtors_aux
        > 0000000000003db0 d __do_global_dtors_aux_fini_array_entry
        > 0000000000004008 D __dso_handle
        > 0000000000003db8 d _DYNAMIC
        > 0000000000004010 D _edata
        > 0000000000004018 B _end
        > 0000000000001218 T _fini
        > 0000000000001140 t frame_dummy
        > 0000000000003da8 d __frame_dummy_init_array_entry
        > 000000000000219c r __FRAME_END__
        > 0000000000003fb8 d _GLOBAL_OFFSET_TABLE_
        >                  w __gmon_start__
        > 000000000000202c r __GNU_EH_FRAME_HDR
        > 0000000000001000 t _init
        > 0000000000003db0 d __init_array_end
        > 0000000000003da8 d __init_array_start
        > 0000000000002000 R _IO_stdin_used
        >                  w _ITM_deregisterTMCloneTable
        >                  w _ITM_registerTMCloneTable
        > 0000000000001210 T __libc_csu_fini
        > 00000000000011a0 T __libc_csu_init
        >                  U __libc_start_main@@GLIBC_2.2.5
        > 0000000000001149 T main
        >                  U printf@@GLIBC_2.2.5
        > 00000000000010c0 t register_tm_clones
        > 0000000000001060 T _start
        > 0000000000004010 D __TMC_END__
        > 0000000000001185 T _Z6my_addii
        > ```

        **最后一行指明了调用过程中实际使用的函数名称**

    - 解决方案

      - 方案一

        在编译库时，使用`extern C`包含导出函数

        ```c
        #ifndef __MY_MATH_H__
        #define __MY_MATH_H__
        
        #ifdef __cplusplus
        extern "C" {
        #endif
        
        int my_add(int a, int b);
        
        #ifdef __cplusplus
        }
        #endif
        #endif
        ```

      - 方案二

        在使用库时，使用`extern C`包含库的头文件

        ```cpp
        #include <stdio.h>
        
        #ifdef __cplusplus
        extern "C" {
        #endif
            
        #include "my_math.h"
            
        #ifdef __cplusplus
        }
        #endif
        int main(int argc, char *argv[])
        {
            printf("my_math >> my_math_add: 3 + 4 = %d\n", my_add(3, 4));
            return 0;
        }
        ```

# 3. 参考资料

- [GCC, the GNU Compiler Collection](https://gcc.gnu.org/)
- [Learn Makefiles](https://makefiletutorial.com/)
- [快速的理解MakeFile](https://zhuanlan.zhihu.com/p/350297509)
- [B站 makefile从入门到项目编译实战](https://www.bilibili.com/video/BV1Xt4y1h7rH?p=1&vd_source=f3043e81272fef5a5303bcede7a4661a)
- [GNU make](https://www.gnu.org/software/make/manual/make.html)
- [B站 从零开始详细介绍CMake](https://www.bilibili.com/video/BV1vR4y1u77h?p=1&vd_source=f3043e81272fef5a5303bcede7a4661a)
- [书籍 CMake Cookbook 源码](https://github.com/dev-cafe/cmake-cookbook)
- [书籍 CMake Cookbook 中文版](https://github.com/xiaoweiChen/CMake-Cookbook)
- [CMake Online Documentation](https://cmake.org/cmake/help/latest/)
- [B站 CPP入门](https://www.bilibili.com/video/BV1et411b73Z?spm_id_from=333.880.my_history.page.click&vd_source=f3043e81272fef5a5303bcede7a4661a)
- [B站 CPP进阶之面向对象高级开发](https://www.bilibili.com/video/BV1Cg411k7eS?spm_id_from=333.337.search-card.all.click&vd_source=f3043e81272fef5a5303bcede7a4661a)
- [B站 CPP进阶之STL和泛型编程](https://www.bilibili.com/video/BV1DT411A7xf?spm_id_from=333.337.search-card.all.click&vd_source=f3043e81272fef5a5303bcede7a4661a)
- [B站 CPP进阶之C11](https://www.bilibili.com/video/BV1vd4y1P7W1?spm_id_from=333.337.search-card.all.click&vd_source=f3043e81272fef5a5303bcede7a4661a)
- [网站 cplusplus](https://cplusplus.com/)
- [网站 LearnCpp](https://www.learncpp.com/)
- [网站 cppreference](https://en.cppreference.com/w/)
- [Boost](https://www.boost.org/)
- [GNU C Library, GLIBC](https://www.gnu.org/software/libc/libc.html)
- [GLib](https://docs.gtk.org/glib/index.html)

# 4. 样例说明

- 001: 直接编译

  ```shell
  gcc hello_world.c
  gcc hello_world.c -o hello_world
  ```

- 002: 分步编译
  - 预处理

       ```shell
       gcc -E hello_world.c 将结果显示到终端
       gcc -E hello_world.c -o hello_world.i 将结果输出到文件
       ```

  - 编译

    ```shell
    gcc -S hello_world.c
    gcc -S hello_world.c -o hello_world.s
    
    gcc -S hello_world.i
    gcc -S hello_world.i -o hello_world.s
    ```

  - 汇编

      ```shell
      gcc -c hello_world.c
      gcc -c hello_world.c -o hello_world.o
      
      gcc -c hello_world.i
      gcc -c hello_world.i -o hello_world.o
      
      gcc -c hello_world.s
      gcc -c hello_world.s -o hello_world.o
      ```

  - 链接

      ```shell
      gcc hello_world.c
      gcc hello_world.c -o a.out
      
      gcc hello_world.i
      gcc hello_world.i -o a.out
      
      gcc hello_world.s
      gcc hello_world.s -o a.out
      
      gcc hello_world.o
      gcc hello_world.o -o a.out
      ```

- 003 ： 静态库

  ```shell
  gcc -static -c my_math.c
  ar -crv libmy_math.a my_math.o
  
  gcc my_math_test.c -I. -L. -lmy_math
  ```

- 004 : 动态库

  ```shell
  gcc -c -fPIC my_math.c
  gcc -shared my_math.o -o libmy_math.so
  
  gcc my_math_test.c -I. -L. -lmy_math
  
  export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
  ./a.out
  ```

- 005 : 整体生成版本
- 006 : 分布生成版本
- 007 : 变量推导版本
- 008 : 自动推导版本
- 009 : 增量编译版本
- 010 : CMake生成可执行文件
- 011 : CMake生成库
- 012 : CMake分层生成库

