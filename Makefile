CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -I thirdparty -MMD
DIR_GUARD = @mkdir -p $(@D)

.PHONY: all
all: bin/geometry

-include obj/*.d obj/test/*.d

bin/geometry: obj/main.o obj/libgeometry.a
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/libgeometry.a: obj/circle.o obj/point.o obj/triangle.o obj/intersection.o obj/object.o obj/input_read.o
	ar rcs $@ $^

obj/main.o: src/geometry/main.c
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/input_read.o: src/geometry/input_read.c
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/circle.o: src/libgeometry/circle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/point.o: src/libgeometry/point.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/triangle.o: src/libgeometry/triangle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/intersection.o: src/libgeometry/intersection.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/object.o: src/libgeometry/object.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf bin/* obj/* obj/test/*

.PHONY: test
test: bin/geometry-test

bin/geometry-test: obj/test/main.o obj/test/test.o obj/libgeometry.a
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/test/main.o: test/main.c
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/test/test.o: test/test.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<