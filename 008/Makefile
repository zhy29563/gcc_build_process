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