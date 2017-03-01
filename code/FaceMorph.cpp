/*

Devendra Pratap Yadav 
https://github.com/DevendraPratapYadav/
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;




Point pt11(-1,-1);
Point pt12(-1,-1);

Point pt31(-1,-1);
Point pt32(-1,-1);

Point pt21(-1,-1);
Point pt22(-1,-1);

double dist1=-1,dist2=-1,dist3=-1;

Mat img11,img22,img33;


Mat imgCurrent;

ofstream f1,f2,f3;


// mouse callback function for marking points on images
void mouse_callback(int  event, int  x, int  y, int  flag, void *param)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        // Store point coordinates
        pt11 = Point(x,y);

       // cout<<">> "<<pt.x<<", "<<pt.y<<endl;

       //circle(imgCurrent, pt,1,CV_RGB(255,0,0),3);
        // circle(imgCurrent, pt,1,CV_RGB(0,0,255),1);


    }

     if(event == EVENT_LBUTTONUP)
    {
    //cout<<"Drawing "<<endl;
        //Point center = Point(x,y);
        pt12 = Point(x,y);
        //circle(imgCurrent, pt2,1,CV_RGB(0,255,0),3);
         //circle(imgCurrent, pt2,1,CV_RGB(0,0,255),1);

         line(img11,pt11,pt12,(150,0,0),1);

         dist1=sqrt ( (pt11.x-pt12.x)*(pt11.x-pt12.x) + (pt11.y-pt12.y)*(pt11.y-pt12.y) ) ;

        dist1+=1;
         /*for (double i=0;i<=1;i=i+15.0/dist1)
         {

         double xx=(1-i)*pt.x+i*pt2.x;
         double yy = (1-i)*pt.y+i*pt2.y;
          */
          Point pnt=Point( (int )x, (int) y  );
         circle(img11, pnt,2,CV_RGB(0,0,0),-1);
          circle(img11, pnt,1,CV_RGB(0,0,255),-1);

          f1<<(int)x<<" "<<(int)y<<endl;



        imshow("1st Face", img11);
    }

}


// mouse callback function for marking points on images
void mouse_callback2(int  event, int  x, int  y, int  flag, void *param)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        // Store point coordinates
        pt21 = Point(x,y);

       // cout<<">> "<<pt.x<<", "<<pt.y<<endl;

       //circle(imgCurrent, pt,1,CV_RGB(255,0,0),3);
        // circle(imgCurrent, pt,1,CV_RGB(0,0,255),1);


    }

     if(event == EVENT_LBUTTONUP)
    {
    //cout<<"Drawing "<<endl;
        //Point center = Point(x,y);
        pt22 = Point(x,y);
        //circle(imgCurrent, pt2,1,CV_RGB(0,255,0),3);
         //circle(imgCurrent, pt2,1,CV_RGB(0,0,255),1);

         line(img22,pt21,pt22,(150,0,0),1);

         dist2=sqrt ( (pt21.x-pt22.x)*(pt21.x-pt22.x) + (pt21.y-pt22.y)*(pt21.y-pt22.y) ) ;

         double dist=dist1+dist2;
         dist/=2.0;
         dist+=1;
         //if (pt11.x!=-1 && pt12.x!=-1 && pt21.x!=-1 && pt22.x!=-1 )
         {
             for (double i=0;i<=1;i=i+15.0/dist)
             {

             double xx=(1-i)*pt11.x+i*pt12.x;
             double yy = (1-i)*pt11.y+i*pt12.y;
              Point pnt=Point( (int )xx, (int) yy  );
             circle(img11, pnt,2,CV_RGB(0,0,0),-1);
              circle(img11, pnt,1,CV_RGB(0,0,255),-1);

            //f1<<(int)xx<<" "<<(int)yy<<endl;

             }

             for (double i=0;i<=1;i=i+15.0/dist)
             {

             double xx=(1-i)*pt21.x+i*pt22.x;
             double yy = (1-i)*pt21.y+i*pt22.y;
              Point pnt=Point( (int )xx, (int) yy  );
             circle(img22, pnt,2,CV_RGB(0,0,0),-1);
              circle(img22, pnt,1,CV_RGB(0,0,255),-1);

             f2<<(int)xx<<" "<<(int)yy<<endl;
             }


             //pt11=pt12=pt21=pt22=Point(-1,-1);
         }

        imshow("1st Face", img11);
        imshow("2nd Face", img22);


    }

}



// mouse callback function for marking points on images
void mouse_callback3(int  event, int  x, int  y, int  flag, void *param)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        // Store point coordinates
        pt31 = Point(x,y);

    }

     if(event == EVENT_LBUTTONUP)
    {
    //cout<<"Drawing "<<endl;
        //Point center = Point(x,y);
        pt32 = Point(x,y);

         line(img22,pt21,pt22,(150,0,0),1);

         dist3=sqrt ( (pt31.x-pt32.x)*(pt31.x-pt32.x) + (pt31.y-pt32.y)*(pt31.y-pt32.y) ) ;

         double dist=dist1+dist3;
         dist/=2.0;
        dist+=1;
         //if (pt11.x!=-1 && pt12.x!=-1 && pt21.x!=-1 && pt22.x!=-1 )
         {
             for (double i=0;i<=1;i=i+15.0/dist)
             {

             double xx=(1-i)*pt11.x+i*pt12.x;
             double yy = (1-i)*pt11.y+i*pt12.y;
              Point pnt=Point( (int )xx, (int) yy  );
             circle(img11, pnt,2,CV_RGB(0,0,0),-1);
              circle(img11, pnt,1,CV_RGB(0,0,255),-1);

            //f1<<(int)xx<<" "<<(int)yy<<endl;

             }

             for (double i=0;i<=1;i=i+15.0/dist)
             {

             double xx=(1-i)*pt31.x+i*pt32.x;
             double yy = (1-i)*pt31.y+i*pt32.y;
              Point pnt=Point( (int )xx, (int) yy  );
             circle(img33, pnt,2,CV_RGB(0,0,0),-1);
              circle(img33, pnt,1,CV_RGB(0,0,255),-1);

             f3<<(int)xx<<" "<<(int)yy<<endl;
             }


             //pt11=pt12=pt21=pt22=pt31=pt32=Point(-1,-1);
         }

        imshow("1st Face", img11);
        imshow("3rd Face", img33);


    }

}




// Read points from file

vector <Point2f> getPoints(string fName)
{
    vector<Point2f> coords;
    char * stri= (char*) fName.c_str();

    ifstream inp(stri);

    float x=0, y=0;


    while(inp >> x) // read points in pairs
    {
        inp>>y;

        coords.push_back(Point2f(x,y));
    }


    return coords;
}

// Apply affine transform calculated using srcTri and dstTri to src
void transformTriangle( vector<Point2f> &tri1, vector<Point2f> &tri2, Mat &src, Mat &output )
{

    Mat transMat = getAffineTransform( tri1, tri2 ); // get the affine transform using function for the triangles


    // transform the image based on transformation matrix obtained
    warpAffine( src, output, transMat, output.size(), INTER_LINEAR, BORDER_REFLECT_101);
}


// get a rectangle fully containing the triangle
Mat getRect(Mat img, vector<Point2f> &Tri)
{

    int mx=img.cols; int my=img.rows; int Mx=0; int My=0;

    for (int i=0;i<Tri.size();i++)
    {
      mx=min(mx,(int)Tri[i].x);   my=min(my,(int)Tri[i].y);
      Mx=max(Mx,(int)Tri[i].x);   My=max(My,(int)Tri[i].y);

     // cout<<Tri[i].x<<" "<<Tri[i].y<<", ";

    }
    //cout<<endl;

    Point pp( (Mx-mx)+1 , (My-my)+1  );

    Rect rect(mx, my, pp.x, pp.y);

    Mat rec = img(rect);



    return rec;


}




// point wise multiply matrices img and mask. Removes all points which do not fall under the mask by multiplication with 0
void pointMult(Mat &img, Mat &mask)
{

 for (int yy=0;yy<img.rows;yy++)
    {
        for (int xx=0;xx<img.cols;xx++)
        {



         img.at<Vec3f>(yy,xx)[0]=img.at<Vec3f>(yy,xx)[0]*( mask.at<Vec3f>(yy,xx)[0]);
         img.at<Vec3f>(yy,xx)[1]=img.at<Vec3f>(yy,xx)[1]*(mask.at<Vec3f>(yy,xx)[0]);
         img.at<Vec3f>(yy,xx)[2]=img.at<Vec3f>(yy,xx)[2]*( mask.at<Vec3f>(yy,xx)[0]);

        }

    }


}


// point wise multiply matrices but with an offset for index of mask
void pointMult2(Mat &img, Mat &mask, int rr, int cc)
{

 for (int yy=rr;yy<rr+mask.rows;yy++)
    {
        for (int xx=cc;xx<cc+mask.cols;xx++)
        {


         img.at<Vec3f>(yy,xx)[0]=img.at<Vec3f>(yy,xx)[0]*( mask.at<Vec3f>(yy-rr,xx-cc)[0]);
         img.at<Vec3f>(yy,xx)[1]=img.at<Vec3f>(yy,xx)[1]*(mask.at<Vec3f>(yy-rr,xx-cc)[0]);
         img.at<Vec3f>(yy,xx)[2]=img.at<Vec3f>(yy,xx)[2]*( mask.at<Vec3f>(yy-rr,xx-cc)[0]);
        //cout<<yy-rr<<" "<<xx-cc<<endl;
        }

    }


}





// compute the intermediate transformed triangle for both images and combine it based on imageRatio
void triMorphing( vector<Point2f> &sTri, vector<Point2f> &dTri, vector<Point2f> &iTri, Mat &img1, Mat &img2, Mat &img, double imageRatio)
{


    float mx=img1.cols; float my=img1.rows; float Mx=0; float My=0;

    for (int i=0;i<sTri.size();i++)
    {
      mx=min(mx,sTri[i].x);   my=min(my,sTri[i].y);
      Mx=max(Mx,sTri[i].x);   My=max(My,sTri[i].y);

    }

    Point sp( (mx) , (my)  );

    mx=img1.cols; my=img1.rows; Mx=0; My=0;

    for (int i=0;i<dTri.size();i++)
    {
      mx=min(mx,dTri[i].x);   my=min(my,dTri[i].y);
      Mx=max(Mx,dTri[i].x);   My=max(My,dTri[i].y);

    }
    Point dp( (mx) , (my)  );


    mx=img1.cols; my=img1.rows; Mx=0; My=0;

    for (int i=0;i<iTri.size();i++)
    {
      mx=min(mx,iTri[i].x);   my=min(my,iTri[i].y);
      Mx=max(Mx,iTri[i].x);   My=max(My,iTri[i].y);

    }

    Point ip( (mx) , (my)  );



    Mat sRec= getRect(img1,sTri);

    if (sRec.rows==0 || sRec.cols==0 )
        return;


    Mat dRec= getRect(img2,dTri);

    if (dRec.rows==0 || dRec.cols==0 )
        return;

    Mat iRec= getRect(img,iTri);

    if (iRec.rows==0 || iRec.cols==0 )
        return;



    vector <Point> maskTri;

    for(int i = 0; i < 3; i++)
    {

       // cout<<"     "<<iTri[i].x-r.x<<" "<<iTri[i].y-r.y<<"     ";
        iTri[i].x=iTri[i].x - ip.x;      iTri[i].y =iTri[i].y -  ip.y;

        sTri[i].x=sTri[i].x - sp.x;      sTri[i].y =sTri[i].y -  sp.y;

        dTri[i].x=dTri[i].x - dp.x;      dTri[i].y =dTri[i].y -  dp.y;


        maskTri.push_back( Point( iTri[i].x, iTri[i].y) );


        //cout<<"     "<<maskTri[i].x<<" "<<maskTri[i].y<<endl;

    }




    // create a mask
    Mat resultMask = Mat::zeros( iRec.rows,iRec.cols, CV_32FC3);

    // fill the triangle in mask with 1.0 value, rest 0
    fillConvexPoly(  resultMask,  maskTri, Scalar(1.0,1.0,1.0),  16, 0);


    // get warped matrices
    Mat sWarped = Mat::zeros(iRec.rows, iRec.cols, sRec.type());
    Mat dWarped = Mat::zeros(iRec.rows, iRec.cols, dRec.type());

    transformTriangle( sTri, iTri, sRec,sWarped );

    transformTriangle( dTri, iTri, dRec,dWarped );


    // combine the warped matrices by blending them based on ratio
    Mat imgRect = imageRatio*dWarped + (1.0-imageRatio)*sWarped ;


    pointMult(imgRect,resultMask);

    resultMask=Scalar(1.0,1.0,1.0)-resultMask;
    Rect resRec=Rect(ip.x, ip.y, iRec.cols, iRec.rows);


    pointMult2(img, resultMask, ip.y, ip.x);


    img(resRec)=img(resRec) +imgRect;


}

int main( int argc, char** argv)
{


    // read images
    string image1("1.jpg");
    Mat imS = imread(image1);
    Mat orig = imread(image1);

    string image2("2.jpg");
    Mat imD = imread(image2);

    string image3("3.jpg");
    Mat imM = imread(image3);



    int mode=0;
    cout<<"Enter program mode (corresponding number):\n 1. Mark points on images and find Delaunay Triangulation \n 2. Morph two images: '1.jpg' to '2.jpg'\n 3. Morph three images: '1.jpg' to '2.jpg' to '3.jpg'\n";
    cin>>mode;


    int cc=0;

    if (mode == 2 || mode==3)
    {
        double iters=30;

        for (int i=0;i<iters;i++)
        {
            //cout<<"~~"<<i<<endl;

            double I_ratio = 1.0/iters*i;

            // read images
            Mat imS = imread(image1);
            Mat imD = imread(image2);


            imS.convertTo(imS, CV_32F); // convert to float for morphing operations
            imD.convertTo(imD, CV_32F);


            // allocate space for final image
            Mat morphedImage=Mat::zeros(imS.size(),CV_32FC3);


            //Get coordinated of points from file
            vector<Point2f> sPoints=getPoints( image1 + ".txt");

            vector<Point2f> dPoints=getPoints( image2 + ".txt");

            vector<Point2f> points;


            // get the new points for morphed image based on ratio
            for (int i = 0; i < sPoints.size(); i++)
            {
                float xx, yy;
                xx = I_ratio *dPoints[i].x+ (1 - I_ratio)*sPoints[i].x;

                yy =  ( 1 - I_ratio )*sPoints[i].y +I_ratio * dPoints[i].y;

                points.push_back(Point2f(xx,yy));

            }


            // get triangles indices from file and resolve coordinates
            ifstream ifs("mytri.txt");
            int xc,yc,zc;

            while(ifs >> xc >> yc >> zc)
            {

                vector<Point2f> iTri, sTri, dTri ;

                dTri.push_back( dPoints[xc] );  dTri.push_back( dPoints[yc] );  dTri.push_back( dPoints[zc] );

                sTri.push_back( sPoints[xc] ); sTri.push_back( sPoints[yc] );   sTri.push_back( sPoints[zc] );

                iTri.push_back( points[xc] ); iTri.push_back( points[yc] ); iTri.push_back( points[zc] );


                // morph each triangle in image to form final morphed image
                triMorphing(sTri, dTri, iTri, imS, imD, morphedImage, I_ratio);

            }


            // show the intermediate morphed image for animated view
            imshow("Morphed Face", morphedImage / 255.0);
            waitKey(10);
            imgCurrent=morphedImage;

            char st[5];

            st[2]=0;
            st[0]=cc/10+'0';
            st[1]=cc%10+'0';

            //itoa(cc, st,10);

            string ss(st);

            Mat ress=morphedImage;
            ress.convertTo(ress, orig.type());

            imwrite(ss+".jpeg",ress);
            cc++;

        }

            // if morphing between three images, start a new morph from image 2 to image 3
            if (mode == 3)
            {
                double iters=30;

                for (int i=0;i<iters;i++)
                {
                    //cout<<"~~"<<i<<endl;

                    double I_ratio = 1.0/iters*i;

                     // read images
                    Mat imS = imread(image2);
                    Mat imD = imread(image3);


                    imS.convertTo(imS, CV_32F); // convert to float for morphing operations
                    imD.convertTo(imD, CV_32F);

                    // allocate space for final image
                    Mat morphedImage=Mat::zeros(imS.size(),CV_32FC3);


                    //Get coordinated of points from file
                    vector<Point2f> sPoints=getPoints( image2 + ".txt");

                    vector<Point2f> dPoints=getPoints( image3 + ".txt");

                    vector<Point2f> points;


                    // get the new points for morphed image based on ratio
                    for (int i = 0; i < sPoints.size(); i++)
                    {
                        float xx, yy;
                        xx = I_ratio *dPoints[i].x+ (1 - I_ratio)*sPoints[i].x;

                        yy =  ( 1 - I_ratio )*sPoints[i].y +I_ratio * dPoints[i].y;

                        points.push_back(Point2f(xx,yy));

                    }


                    // get triangles indices from file and resolve coordinates
                    ifstream ifs("mytri.txt");
                    int xc,yc,zc;

                    while(ifs >> xc >> yc >> zc)
                    {

                        vector<Point2f> iTri, sTri, dTri ;

                        dTri.push_back( dPoints[xc] );  dTri.push_back( dPoints[yc] );  dTri.push_back( dPoints[zc] );

                        sTri.push_back( sPoints[xc] ); sTri.push_back( sPoints[yc] );   sTri.push_back( sPoints[zc] );

                        iTri.push_back( points[xc] ); iTri.push_back( points[yc] ); iTri.push_back( points[zc] );


                        triMorphing(sTri, dTri, iTri, imS, imD, morphedImage, I_ratio);

                    }


                    // show the intermediate morphed image for animated view
                    imshow("Morphed Face", morphedImage / 255.0);
                    waitKey(10);
                    imgCurrent=morphedImage;


                    char st[5];

                    st[2]=0;
                    st[0]=cc/10+'0';
                    st[1]=cc%10+'0';

                    //itoa(cc, st,10);

                    string ss(st);

                    Mat ress=morphedImage;
                    ress.convertTo(ress, orig.type());

                    imwrite(ss+".jpeg",ress);
                    cc++;

                }



                waitKey(0);

            }


        waitKey(0);




    }

    else
    {
        /*
        This allows you to mark tie points on images. Mark points one by one on each image. There must be a one to one mapping between marked points
        in each image. i.e. the 5th point in image 1 corresponds to nose tip, then the 5th point for other images must also mark the nose tip.
        Number of points in all text files must be same and have one to one mapping.

        These points are used to calculate Denaulay triangulation.
        */

         // open a new text file for each image. Show each image in window and allocate mousecall function for each window
          string ss=image1+".txt";
          char * nam= (char*)ss.c_str();

          f1.open(nam,ios::app);

          ss=image2+".txt";
          nam= (char*) ss.c_str();

         f2.open(nam,ios::app);

          imshow("1st Face", imS);

          setMouseCallback("1st Face", mouse_callback);

           imshow("2nd Face", imD);

          setMouseCallback("2nd Face", mouse_callback2);





         ss=image3+".txt";
          nam= (char*) ss.c_str();

         f3.open(nam,ios::app);

          imshow("3rd Face", imM);

          setMouseCallback("3rd Face", mouse_callback3);

            img11=imS; img22=imD; img33=imM;


           //f1=f11; f2=f22;
            waitKey(0);

    }


} // end main
