#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <queue>
#include <vector>

#include <pthread.h>

#include <opencv2/core/core.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "buffer.hpp"


#ifndef TRAITEMENTVIDEO_H
#define TRAITEMENTVIDEO_H

using namespace std;
using namespace cv;

class ToWrite{

private:

  queue<Mat> imgToWrite;
  bool continueWrite;
  pthread_mutex_t mutex;
public:
  ToWrite();
  ~ToWrite();

  void setContinueWrite(bool);
  bool getContinueWrite();

  void mutexInit();
  void mutexBlock();
  void mutexOpen();

  queue<Mat>* getQueue();
  queue<Mat> duplicateQueue();

  void Purge();
};




class TraitementVideo {

private:
  //variable pour la capture video
  VideoCapture capture;
  String url;

  //variable pour l'écriture de la video
  VideoWriter writer;
  String cameraname;
  Size size;
  double fps;
  int codec;

  //stock les images
  Buffer buffer;

  //variable de detection du mouvement
  Mat oldframe;
  Mat newframe;
  double sensibility;
  int seuil;
  int imgParTraitement;

  // queue des images a écrire : utilisé dans les threading
  ToWrite writeQueue;

  //variable pour la gestion du threading
  pthread_t thread[2];
  int compteurThread;

  //variable de gestion du traitement
  bool continueTraitement;
  bool lastFlush;


public:

void init(String url);
TraitementVideo();
TraitementVideo(String url);
TraitementVideo(String url, String name);
TraitementVideo(String url, int seuil, double sensibility);
TraitementVideo(String url, String name, int seuil, double sensibility);
TraitementVideo(String url, int seuil, double sensibility, int imgParTraitement);
TraitementVideo(String url, String name, int seuil, double sensibility, int imgParTraitement);
~TraitementVideo();

bool presenceMouvement();
void flushBuffer();
static void *traitement(void * arg);
void toToWrite(queue<Mat> temp);
static void *writeThread(void * arg);
void stop();
void initstop();
string getIp();
bool pingIp(string ipAdress);
void readNextFrame();
void readNextFrameSimple();

VideoCapture* getCapture();
void setCapture(VideoCapture cap);

VideoWriter* getWriter();
void setWriter(VideoWriter writer);

Buffer* getBuffer();
void setBuffer(Buffer buffer);

Mat* getOldframe();
void setOldframe(Mat oldframe);
void setOldframeCopy(Mat oldframe);

Mat* getNewframe();
void setNewframe(Mat newframe);
void setNewframeCopy(Mat newframe);

int getSeuil();
void setSeuil(int seuil);

double getSensibility();
void setSensibility(double sensibility);

String getUrl();
void setUrl(String url);

String getCameraName();
void setCameraName(String cameraname);

Size getSize();
void setSize(Size size);
void setSize(int length, int height);

double getFps();
void setFps(double fps);

int getCodec();
void setCodec(int codec);

int getCompteurThread();
void setCompteurThread(int i);

bool getContinueTraitement();

bool getLastFlush();
void setLastFlush(bool value);

pthread_t * getThread(int i);

ToWrite* getWriteQueue();
/*
bool isCaptureOpened();
bool isWriterOpened();

bool writerOpen(string nomfichier);*/

int getImgParTraitement();
void setImgParTraitement(int nbImg);


};

class  MultiTraitement{
private:
  vector<TraitementVideo*> vecteurTraitement;
  vector<pthread_t*> vecteurThread;

public:
  MultiTraitement();
  MultiTraitement(string path);
  ~MultiTraitement();

 void stopAll();

  TraitementVideo* getTraitementVideo(int i);
  pthread_t * getThread(int i);
  int getNbElem();

  void threadAll();
  void waitAll();

  static vector<String> getUrls();
  static vector<String> getUrls(String path);


};
#endif
