CC=gcc
CCFLGS=-Wall -Werror -Wextra -std=c++17

LIST=containers/list/*.cc
VECTOR=containers/vector/*.cc
SET=containers/set/*.cc
MAP=containers/map/*.cc
TREE=containers/tree/*.cc
DEQUE=containers/deque/*.cc
QUEUE=containers/queue/*.cc
STACK=containers/stack/*.cc


MULTISET=containersplus/multiset/*.cc
ARRAY=containersplus/array/*.cc

SOURS=$(ARRAY) $(LIST) $(VECTOR) $(SET) $(MAP) $(TREE) $(MULTISET) $(DEQUE) $(QUEUE) $(STACK)
TESTS=unit_test/*.cc


ifeq ($(OS),Linux)
    det_OS =  -pthread -lgtest  -lm
else
    det_OS = -pthread -lgtest  -lm
endif


all: clean gcov_report

test: 
	$(CC) $(CCFLGS) $(SOURS) $(TESTS)  -o test -lstdc++ $(det_OS)
	./test

gcov_report: 
	$(CC) $(CCFLGS) --coverage $(SOURS) $(TESTS) -o coverage  -lstdc++ $(det_OS)
	./coverage
	lcov -t "result" -o res.info  --ignore-errors inconsistent -c -d .
	lcov --remove res.info /c++/13 /usr/local/include/gtest -o filtered_coverage.info
	genhtml -o report filtered_coverage.info
	open report/index.html

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

check_clang:
	cp ../materials/linters/.clang-format .
	clang-format -n containers/list/*  containers/vector/* containers/map/* containers/set/* containers/tree/*  
	clang-format -n containers/queue/*  containers/deque/* containers/stack/*
	clang-format -n containersplus/array/* containersplus/multiset/*
	clang-format -n unit_test/*
	clang-format -n *.h
	rm -rf .clang-format

correct_style:
	cp ../materials/linters/.clang-format .
	clang-format -i containers/list/*  containers/vector/* containers/map/* containers/set/* containers/tree/*   
	clang-format -i containers/queue/*  containers/deque/* containers/stack/*
	clang-format -i containersplus/array/* containersplus/multiset/*
	clang-format -i unit_test/*
	clang-format -i *.h
	rm -rf .clang-format

clean:
	rm -rf main test coverage *.gc* res.info filtered_coverage.info report *.o a.out tree/*.o set/*.o map/*.o