#include <opencv2/opencv.hpp>
#include <queue>

#include "buffer.hpp"

Buffer::Buffer(int fps2t){  //Constructeur
    this->size = fps2t;
}

Buffer::Buffer(){  //Constructeur
    this->size = 40;
}

Buffer::~Buffer(){
    this->buffer.~queue();
}

//Recupere la taille du buffer
int Buffer::getSize(){
    return size;
}

void Buffer::setSize(int size){
  this->size = size;
}

std::queue<cv::Mat> Buffer::getBuffer(){    //Obtenir le buffer en entier
  return this->buffer;
}


//Remettre le buffer à 0
void Buffer::clearBuffer(){
    while(!this->buffer.empty()){
      this->buffer.pop();
    }
}

//Verifier si le buffer est rempli
bool Buffer::isFull(){
    return (this->buffer.size()>=this->size);
}

//Verifier si le buffer est rempli
bool Buffer::isEmpty(){
    return (this->buffer.empty());

}

cv::Mat Buffer::getLastMat(){
    return this->buffer.back();
}

void Buffer::addMat(cv::Mat image){
    if(this->buffer.size()>=this->size){
      this->buffer.pop();
    }
    this->buffer.push(image);
}

int Buffer::currentSize(){
  return this->buffer.size();
}
