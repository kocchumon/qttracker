#ifndef TRAINER_DIALOG_H
#define TRAINER_DIALOG_H

#include <QDialog>
#include<QDir>

#include<opencv2/core/core.hpp>
#include<opencv2/contrib/contrib.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<opencv2/legacy/legacy.hpp>

#include<opencv/cv.h>

#include<opencv/highgui.h>

#include<fstream>

namespace Ui {
class trainer_Dialog;
}

class trainer_Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit trainer_Dialog(QWidget *parent = 0);
    ~trainer_Dialog();
    void closeEvent();

    
private:
    Ui::trainer_Dialog *trainer_ui;
    cv::VideoCapture trainer_capWebcam;
    cv::Mat trainer_matOriginal;
    cv::Size trainer_dsize;

    cv::String t_face_cascade_name;
    cv::CascadeClassifier t_face_cascade;

    CvRect pFaceRect;
    IplImage *pvideoframeCopy;
    CvCamShiftTracker myTracker;

    std::vector<cv::Rect>t_faces;

    FILE *fp;
    char *directory_images;
    int nofs;
    int nof;
    int start;

    QTimer* trainer_Timer;
    QTimer* trainer_timeout;

public slots:
 void trainer_processFrameAndUpdateGUI();


private slots:
 void on_trainer_btnpr_clicked();
 void on_trainer_btnOK_clicked();

};

#endif // TRAINER_DIALOG_H
