#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui>
#include<QDir>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include<opencv/cv.h>
#include<opencv/highgui.h>


namespace Ui{
class Dialog;
}


class Dialog : public QDialog{

Q_OBJECT

public:

explicit Dialog(QWidget *parent =0);
~Dialog();


private:
Ui::Dialog *ui;
cv::VideoCapture capWebcam;
cv::Mat matOriginal;
cv::Mat matProcessed;
cv::Size dsize;

int nof;
char *directory;
char *home;

cv::String face_cascade_name;
cv::CascadeClassifier face_cascade;

std::vector<cv::Rect>faces;


QDir dir;
std::vector<cv::Mat> newImages;
std::vector<int> newLabels;

QTimer* tmrTimer;

public slots:
    void processFrameAndUpdateGUI();


private slots:
    void on_btnPauseOrResume_clicked();

    void on_btnAdd_clicked();
    void on_btnExit_clicked();
    void on_btnAdd_2_clicked();
};

#endif
