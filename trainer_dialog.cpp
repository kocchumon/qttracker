#include "trainer_dialog.h"
#include "ui_trainer_dialog.h"


#include<QtGui/QApplication>
#include<QTextFormat>

#include<opencv/cv.h>
#include<opencv/highgui.h>

#include <QtCore>
#include<direct.h>

#include<stdio.h>
#include<string.h>

int vmin = 10, vmax = 256, smin = 30;

/*
** Saturation values
*/
int MINS             = 60;
int MAXS             = 255;

/*
** V values
*/
int MINV             = 78;
int MAXV             = 255;



int dims[] = { 50 };

trainer_Dialog::trainer_Dialog(QWidget *parent) :
    QDialog(parent),
    trainer_ui(new Ui::trainer_Dialog)
    {

        fp=fopen("data.txt","r+");
        fscanf(fp,"%d",&nofs);
        nof=0;

        directory_images=getcwd(NULL,0);
        strcat(directory_images,"\\data\\");

        trainer_ui->setupUi(this);

        trainer_ui->trainer_box->appendPlainText(directory_images);

        t_face_cascade_name = "C:/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";

        if( !t_face_cascade.load(t_face_cascade_name) ){
            trainer_ui->trainer_box->appendPlainText("Error : Cascade load unsuccessful!!");
            return;
        };

        trainer_dsize=cv::Size(384,288);

        myTracker.set_hist_dims( 1, dims );
        myTracker.set_hist_bin_range(10, 0, 255 );
        myTracker.set_threshold(0);

        /*
        **  The Saturation value, just change the min value
        */
        myTracker.set_min_ch_val( 1,MINS);   // S MIN
        myTracker.set_max_ch_val( 1,MAXS);  // S MAX


        /*
        ** The V values are from the Cam Shift Demo twiddleing.
        */
        myTracker.set_min_ch_val( 2,MINV);   // V MIN
        myTracker.set_max_ch_val( 2,MAXV );  // V MAX

        /*
        ** Clear out any junk in the histogram to load in our values
        */
        myTracker.reset_histogram();

        ////////////////////////////

        start=0;
        trainer_capWebcam.open(-1);

        if(trainer_capWebcam.isOpened()==false)
        {
            trainer_ui->trainer_box->appendPlainText("trainer_capWebcam error!!");
            return;
        }

        int nof1=0;

        while(nof1==0)
        {
            trainer_capWebcam.read(trainer_matOriginal);

            if(trainer_matOriginal.empty()==true)
               return;

            t_face_cascade.detectMultiScale(trainer_matOriginal, t_faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(20,20));

            nof1=t_faces.size();
            if(nof1>0 )
            {
                pFaceRect = cvRect(t_faces[0].x,t_faces[0].y,t_faces[0].width,t_faces[0].height);
                trainer_ui->trainer_box->appendPlainText("Face detected!");
                break;
            }
            cvWaitKey(100);

        }

        /////////////////////////////////////

         cv::Point pt1( t_faces[0].x, t_faces[0].y );
         cv::Point pt2(t_faces[0].x+t_faces[0].width,t_faces[0].y+t_faces[0].height);

         bool rc;

          /*
          ** Draw a box on the image.  This is important!  You just can't se the Window.
          ** Set the window and get a histogram.
          */

        cv::rectangle(trainer_matOriginal,pt1,pt2,CV_RGB(255,0,0),2,0);
        pvideoframeCopy=new IplImage(trainer_matOriginal);

        rc=myTracker.set_window(pFaceRect);
        rc=myTracker.update_histogram(pvideoframeCopy);

        if(rc==0)
        {
            trainer_ui->trainer_box->appendPlainText("Problems in setting up the histogram!");
            return;
        }



        trainer_Timer =new QTimer(this);
        trainer_timeout=new QTimer(this);


        //connect(trainer_timeout,SIGNAL(timeout()),this,SLOT(on_trainer_btnOK_clicked()));

        connect(trainer_Timer,SIGNAL(timeout()),this,SLOT(trainer_processFrameAndUpdateGUI()));
        //trainer_timeout->start(10000);
        trainer_Timer->start(100);

    }


trainer_Dialog::~trainer_Dialog()
    {
        delete trainer_ui;
    }


void trainer_Dialog::trainer_processFrameAndUpdateGUI(){



 MINV=trainer_ui->lcdNumber_2->intValue();
 MINS=trainer_ui->lcdNumber->intValue();
 MAXS=trainer_ui->lcdNumber_3->intValue();
 MAXV=trainer_ui->lcdNumber_4->intValue();

 myTracker.set_min_ch_val( 2,MINV);   // V MIN
 myTracker.set_min_ch_val( 1,MINS);   // S MIN

 trainer_capWebcam.read(trainer_matOriginal);

 if(trainer_matOriginal.empty()==true)
    return;

 cv::resize(trainer_matOriginal,trainer_matOriginal,trainer_dsize,0,0,cv::INTER_CUBIC);

 pvideoframeCopy=new IplImage(trainer_matOriginal);

 myTracker.track_object(pvideoframeCopy);
 CvRect rect = myTracker.get_window();

 cv::Point pt1( rect.x,rect.y );
 cv::Point pt2(rect.x+rect.width,rect.y+rect.height);

 cv::rectangle(trainer_matOriginal,pt1,pt2,CV_RGB(255,0,0),2,0);

/////////////////////
 if(start!=0)
 {
       char a[10],b[10];
         cv::Mat temp=trainer_matOriginal(cv::Rect(pt1,pt2));
         cv::resize(temp,temp,cv::Size(80,80),0,0,cv::INTER_LINEAR);
         cv::cvtColor(temp,temp,CV_BGR2GRAY);
         cv::cvtColor(temp,temp,CV_GRAY2RGB);
         strcpy(a,directory_images);
         itoa(nofs,b,10);
         strcat(a,b);
         strcat(a,"-");
         itoa(nof,b,10);
         strcat(a,b);
         strcat(a,".jpg");
         cv::imwrite(a,temp);
         nof++;
  }


 ///////////////////////
 cv::cvtColor(trainer_matOriginal,trainer_matOriginal,CV_BGR2RGB);

 QImage trainer_qimgOriginal((uchar*)trainer_matOriginal.data,trainer_matOriginal.cols,trainer_matOriginal.rows,trainer_matOriginal.step,QImage::Format_RGB888);

 trainer_ui->trainerDisp->setPixmap(QPixmap::fromImage(trainer_qimgOriginal));

}

void trainer_Dialog::on_trainer_btnpr_clicked()
{
    if(trainer_Timer->isActive()==true)
    {
        trainer_Timer->stop();
        trainer_timeout->stop();
        trainer_ui->trainer_btnpr->setText("RESUME");
        trainer_ui->trainer_box->appendPlainText("Streaming Paused!!");
    }
    else
    {
        start=1;
        trainer_timeout->start(10000);
        trainer_Timer->start(200);
        trainer_ui->trainer_btnpr->setText("PAUSE");
        trainer_ui->trainer_box->appendPlainText("Streaming Resumed!!");

    }
}

void trainer_Dialog::on_trainer_btnOK_clicked()
{
    if(start)
        nofs++;
    fclose(fp);
    remove("data.txt");
    fp=fopen("data.txt","w");
    fprintf(fp,"%d",nofs);
    fclose(fp);
    trainer_capWebcam.release();
    this->close();
}
