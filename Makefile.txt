CCC=g++
CFLAGS=-g -I /usr/local/include/opencv4
LDFLAGS=-fPIC -Wl,-rpath,"/usr/local/lib"

all: detecteur

detecteur: main.o buffer.o traitementvideo.o
	$(CCC) $(LDFLAGS) -o $@ $^ -lopencv_videoio -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lpthread

%.o: %.cpp
	$(CCC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f detecteur *.o
