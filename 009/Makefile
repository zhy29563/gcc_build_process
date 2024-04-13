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