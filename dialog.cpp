#include "dialog.h"
#include "ui_dialog.h"
#include "trainer_dialog.cpp"

#include<opencv/cv.h>
#include<opencv/highgui.h>


#include <QtCore>
#include <QDir>

using namespace cv;


Dialog::Dialog(QWidget *parent):
                       QDialog(parent),
                       ui(new Ui::Dialog)
                       {
                              ui->setupUi(this);

                              directory=getcwd(NULL,0);
                              home=getcwd(NULL,0);
                              strcat(directory,"\\data\\");

                              ui->lblOriginal->setText("Waiting for CAM feed");
                              ui->lblProcessed->setText("Waiting for CAM feed");
                              face_cascade_name = "C:/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";
                              dsize=cv::Size(384,288);

                              if( !face_cascade.load(face_cascade_name) ){
                                  ui->boxConsole->appendPlainText("Error : Cascade load unsuccessful!!");
                                  return;
                              };

                              capWebcam.open(0);

                              if(capWebcam.isOpened()==false)
                              {
                                        ui->boxConsole->appendPlainText("Error : capWebcam not successful!!");
                                        return;
                              }

                              tmrTimer =new QTimer(this);
                              tmrTimer->start(20);
                              connect(tmrTimer,SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI()));


                       }


                       Dialog::~Dialog()
                       {
                                        delete ui;
                       }

                       void Dialog::processFrameAndUpdateGUI(){


                        capWebcam.read(matOriginal);

                        if(matOriginal.empty()==true)
                           return;

                        cv::resize(matOriginal,matOriginal,dsize,0,0,cv::INTER_CUBIC);
                        cv::Mat gray;

                        face_cascade.detectMultiScale(matOriginal,faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(10,10));      //detect faces

                        cv::cvtColor(matOriginal, gray, CV_BGR2GRAY);

                        cv::cvtColor(matOriginal,matProcessed,CV_BGR2GRAY);

                        nof=faces.size();
                        for( int i = 0; i < nof; i++ )
                        {

                            cv::Rect face_i = faces[i];
                            //cv::Mat face = gray(face_i);
                            //cv::Mat face_resized;
                            //cv::resize(face, face_resized, cv::Size(80,80), 1.0, 1.0,cv::INTER_CUBIC);//resizing
                            //int prediction = model->predict(face_resized);
                            cv::rectangle(matProcessed, face_i, CV_RGB(0, 255,0), 1);

                        }

                        cv::cvtColor(matOriginal,matOriginal,CV_BGR2RGB);
                        cv::cvtColor(matProcessed,matProcessed,CV_GRAY2RGB);

                        QImage qimgOriginal((uchar*)matOriginal.data,matOriginal.cols,matOriginal.rows,matOriginal.step,QImage::Format_RGB888);
                        QImage qimgProcessed((uchar*)matProcessed.data,matProcessed.cols,matProcessed.rows,matProcessed.step,QImage::Format_RGB888);

                        ui->lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));
                        ui->lblProcessed->setPixmap(QPixmap::fromImage(qimgProcessed));

                       }


 void Dialog::on_btnPauseOrResume_clicked()
 {

      if(tmrTimer->isActive()==true)
      {

          tmrTimer->stop();
          ui->boxConsole->appendPlainText("Streaming Paused");
          ui->btnPauseOrResume->setText("Resume");
      }
      else
      {
          tmrTimer->start(20);
          ui->btnPauseOrResume->setText("Pause");
          ui->boxConsole->appendPlainText("Streaming Resumed");
      }
}

void Dialog::on_btnAdd_clicked()
{
    ui->boxConsole->appendPlainText("Add Button clicked");

    trainer_Dialog *new_dialog;
    new_dialog= new trainer_Dialog(this);
    new_dialog->show();
}

void Dialog::on_btnExit_clicked()
{
    capWebcam.release();
    this->close();
}


void Dialog::on_btnAdd_2_clicked()
{
    tmrTimer->stop();

    dir=QDir(directory);
    QFileInfoList files;
    QFileInfo file;
    QString filen;

    char name[10];
    int i,j;
    std::string str;
    std::string filename;

    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    files=dir.entryInfoList();
    int nofiles;

    nofiles=files.size();
    for(i=0;i<nofiles;i++)
        {
            file=files.at(i);
            filen=file.baseName();
            filename=filen.toStdString();
            strcpy(name,filename.c_str());

            for(j=0;name[j]!='-';j++);
            name[j]='\0';                                   //label value ends with '-' in image names

            filen=file.absoluteFilePath();
            str=filen.toStdString();

            /*
            cv::Mat offimage=cv::imread(str.c_str(),-1);

            cv::namedWindow("face",WINDOW_AUTOSIZE);        //show retrieved image in a window
            cv::imshow("face",offimage);
            cvvWaitKey(1000);
           */

            newImages.push_back(cv::imread(str.c_str(),-1));
            newLabels.push_back(atoi(name));


        }


    ui->boxConsole->appendPlainText("Training Started....!!");

    cv::Ptr<cv::FaceRecognizer> model = cv::createFisherFaceRecognizer();
    model->train(newImages,newLabels);

    //strcat(home,"\\data.xml");

    //model->save(home);

    ui->boxConsole->appendPlainText("Training Completed!!");
    tmrTimer->start();
}
