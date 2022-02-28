CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MMD
DIR_GUARD = @mkdir -p $(@D)

all: bin/geometry

-include obj/input_read.d obj/circle.d obj/point.d obj/triangle.d obj/main.d

bin/geometry: obj/input_read.o obj/circle.o obj/point.o obj/triangle.o obj/main.o obj/libgeometry.a
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/libgeometry.a: obj/circle.o obj/point.o obj/triangle.o
	ar rcs $@ $^

obj/input_read.o: src/geometry/input_read.c
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/circle.o: src/libgeometry/circle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/point.o: src/libgeometry/point.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/triangle.o: src/libgeometry/triangle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/main.o: src/geometry/main.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm bin/* obj/*