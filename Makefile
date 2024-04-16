SRC=$(wildcard ./*.c)
OBJS = $(patsubst %.c,%.o,$(SRC))  #将src里所有后缀为.c的文件替换为.o

%.o:%.c
	gcc -c $< -o $@

test: $(OBJS)
	gcc $(OBJS) -o $@

clean:
	rm -rf $(OBJS)    rm test

