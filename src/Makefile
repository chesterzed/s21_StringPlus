PROJECT_NAME = string

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
# -v
TEST_LIBS = -lcheck -lm #-lsubunit


all: clean s21_string.a test gcov_report m_clean

s21_string.a:
	$(CC) $(CFLAGS) -c ./cfiles/s21_*.c
	ar rcs s21_string.a s21_*.o
	rm ./s21_*.o

clean: m_clean
	rm -rf ./*.a ./a.out gcov_test *.html *.css ./GcovReport ./report ./*.info ./string_o ./*.dSYM ./test_s21_string ./test

m_clean:
	rm -rf ./*.o ./*.gcno ./*.gcda

format:
	clang-format -style=google -i ./*/*.c ./*/*.h

style:
	clang-format -style=google -n ./*/*.c ./*/*.h

test: s21_string.a
	$(CC) $(CFLAGS) -c ./tf/test*.c
	$(CC) *.o s21_string.a $(TEST_LIBS) -o test
	rm ./*.o

test_code: test
	./test
	rm ./test
	rm ./*.o
	rm ./*.a

gcov_report: s21_string.a
	$(CC) $(CFLAGS) --coverage ./tf/*.c ./cfiles/s21_*.c s21_string.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h
	cp ../materials/linters/.clang-format .clang-format
	clang-format -style=Google *.h *.c -i
	rm -rf .clang-format
	make test
	leaks --atExit -- test

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

rebuild: clean all
	open ./report/index.html
