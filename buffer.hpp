
#include <opencv2/core/core.hpp>
#include <queue>

#ifndef BUFFER_H
#define BUFFER_H

class Buffer {

  private:
    //Stockage des images
    std::queue<cv::Mat> buffer;

    //Taille du tableau
    int size;


  public:

     Buffer(int size);
     Buffer();
     ~Buffer();

    int getSize();
    void setSize(int size);

    std::queue<cv::Mat> getBuffer();


     void clearBuffer();

     bool isFull();
     bool isEmpty();

     cv::Mat getLastMat();
     void addMat(cv::Mat image);

     int currentSize();
};

#endif
