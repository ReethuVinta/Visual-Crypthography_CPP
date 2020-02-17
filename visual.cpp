#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/core/core.hpp>
#include <bits/stdc++.h>
#include<time.h>
#include<ctime>
using namespace std;
using namespace cv;

void visual(Mat bnw)
{
    
    Mat S1,S2,S,S1_final,S2_final,S_final; 

    Size s = bnw.size();
    int rows = s.height;
    int columns = s.width;

    cout<<"bnw rows"<<rows<<endl;
    cout<<"bnw rows"<<columns<<endl;
    
    S1 = Mat::ones(2*rows,2*columns,CV_64F);
    S2 = Mat::ones(2*rows,2*columns,CV_64F);
    S = Mat::ones(2*rows,2*columns,CV_64F);

    vector<Point>black;   // output, locations of non-zero pixels
    cv::findNonZero(bnw,black);

    int r=0;
    int a,b;

    for(auto itr=black.begin();itr<black.end();itr++)
    {
        a=itr->x;
        b=itr->y;
        
        
                if(r==0)
                {
                    S1.at<double>(2*a,2*b)=1;
                    S1.at<double>(2*a+1,2*b)=1;
                    S1.at<double>(2*a,2*b+1)=0;
                    S1.at<double>(2*a+1,2*b+1)=0;

                    S2.at<double>(2*a,2*b)=0;
                    S2.at<double>(2*a+1,2*b)=0;
                    S2.at<double>(2*a,2*b+1)=1;
                    S2.at<double>(2*a+1,2*b+1)=1;
                }
                else
                {
                    S1.at<double>(2*a,2*b)=0;
                    S1.at<double>(2*a+1,2*b)=0;
                    S1.at<double>(2*a,2*b+1)=1;
                    S1.at<double>(2*a+1,2*b+1)=1;

                    S2.at<double>(2*a,2*b)=1;
                    S2.at<double>(2*a+1,2*b)=1;
                    S2.at<double>(2*a,2*b+1)=0;
                    S2.at<double>(2*a+1,2*b+1)=0;
                }

    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            auto found = find(black.begin(), black.end(), Point(i,j));

            a=i;
            b=j;

            if(found == black.end())
            {

                if(r==0)
                {
                    S1.at<double>(2*a,2*b)=1;
                    S1.at<double>(2*a+1,2*b)=1;
                    S1.at<double>(2*a,2*b+1)=0;
                    S1.at<double>(2*a+1,2*b+1)=0;

                    S2.at<double>(2*a,2*b)=1;
                    S2.at<double>(2*a+1,2*b)=1;
                    S2.at<double>(2*a,2*b+1)=0;
                    S2.at<double>(2*a+1,2*b+1)=0;
                }
                else
                {
                    S1.at<double>(2*a,2*b)=0;
                    S1.at<double>(2*a+1,2*b)=0;
                    S1.at<double>(2*a,2*b+1)=1;
                    S1.at<double>(2*a+1,2*b+1)=1;

                    S2.at<double>(2*a,2*b)=0;
                    S2.at<double>(2*a+1,2*b)=0;
                    S2.at<double>(2*a,2*b+1)=1;
                    S2.at<double>(2*a+1,2*b+1)=1;
                }

            }
        }
    }
    
    
    cv::rotate(S1, S1, cv::ROTATE_90_CLOCKWISE);
    cv::flip(S1, S1_final, 1);

    cv::rotate(S2, S2, cv::ROTATE_90_CLOCKWISE);
    cv::flip(S2, S2_final, 1);

    S=S1_final^S2_final;

    imshow("S1",S1_final);
    imshow("S2",S2_final);
    imshow("S_final",S);

}


int main() 
{

  srand(time(NULL));
  Mat image,bnw,gray;
  image = imread("pdff.bmp" ,CV_LOAD_IMAGE_COLOR);

  Size s = image.size();
  int rows = s.height;
  int columns = s.width;
  
  cout<<"no of rows are "<<rows<<endl;
  cout<<"no of columns are "<<columns<<endl;

  cvtColor(image,gray,COLOR_BGR2GRAY); 
  adaptiveThreshold(gray,bnw,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,13,0);
  
  Size a = bnw.size();
  cout<<"no of rows in black and white "<<a.height<<endl;
  cout<<"no of columns in black and white "<<a.width<<endl;

  imshow("Secret Message",image);  
  imshow("Black and white image",bnw);
  

  waitKey();
  visual(bnw);
  waitKey();
  return 0;
}
