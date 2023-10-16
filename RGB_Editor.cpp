/*
                        "بسم الله"

    اللهمَّ صَلِّ وَسَلِّمْ وَبَارِكْ عَلَى سَيِّدِنَا مُحَمَّدٍ وَعَلَى آلِهِ عَدَدَ كَمَالِ اللهِ وَكَمَا يَلِيقُ بِكَمَالِهِ

------------------------------------------------------------------------------------------
FCAI – OOP Programming – 2023 - Assignment 1

Course:  CS213

Project: Image Editor with C++

Description: This program is an image editor that can apply different filters to images.

made by:

1-Abdulrahman Salah    ID:20220176              email: sa8640205@gmail.com

2-OmarSaeed            ID:20220225              email:  os9073020@gmail.com

3:SohaylaMohamed       ID:20220159              email:  anmo9232@gmail.com

------------------------------------------------------------------------------------------

*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
// Declare the variables here.
unsigned char inputImage[SIZE][SIZE][RGB];
unsigned char outputImage[SIZE][SIZE][RGB];
char inputFileName[100];
char outputFileName[100];
char choice;


void applyBlackAndWhiteFilter();
void applyInvertfilter();
void merge();
void flipImage();
void mirrorImage();
void applyRotateImage();
void applyEdgeDetection();
void enlarge_Image();
void shrinkImage();
void shuffle_image();
void crop_image();
void darkenandlightenimage();
void blurImage();
void skewImageH();
void skewImageV();
void applygray(unsigned char temp[SIZE][SIZE][RGB]);



void menu()
{

    while (true)
    {
        // Display the menu.

        cout << "Menu:" << endl;
        cout << "1. Load an image" << endl;
        cout << "2. Apply a filter" << endl;
        cout << "3. Save the image" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            // Load an image
            case '1':
            {
                cout << "Please enter the file name of the image to load: ";
                cin >> inputFileName;

                // Load the image using readRGBBMP into inputImage
                strcat(inputFileName, ".bmp");
                int f = readRGBBMP(inputFileName, inputImage);
                if (f != 0)
                {
                    cout << "Error loading file" << endl;
                    break;
                }
                else

                {
                    cout << "Image loaded successfully." << endl;
                }

                break;
            }
            case '2':
            {
                // filter menu here

                if (inputFileName[0] == '\0') // if the user didn't load an image
                {
                    cout << "Please load an image first." << endl;
                    break;
                }

                cout << "Filter Options:" << endl;
                cout << "1. Black & White" << endl;
                cout << "2. Invert" << endl;
                cout << "3. merge" << endl;
                cout << "4. Flip" << endl;
                cout << "5. Darken and Lighten Image" << endl;
                cout << "6. Rotate Image" << endl;
                cout << "7. Detect Image Edges" << endl;
                cout << "8. Enlarge Image" << endl;
                cout << "9. Shrink Image" << endl;
                cout << "a.  Mirror 1/2 Image" << endl;
                cout << "b.  Shuffle Image" << endl;
                cout << "c. Blur Image" << endl;
                cout << "d.  Crop Image" << endl;
                cout << "e. Skew Image Right" << endl;
                cout << "f. Skew Image Up" << endl;

                // Add more filter options here...

                char filterChoice;
                cout << "Please select a filter to apply: ";
                cin >> filterChoice;

                switch (filterChoice)
                {
                    case '1':
                    {
                        // Apply the Black and White filter


                        applyBlackAndWhiteFilter();
                        cout << "Black and White filter applied." << endl;
                        break;
                    }
                    case '2':
                    {
                        // Apply the Invert filter
                        applyInvertfilter();


                        cout << "Invert filter applied." << endl;
                        break;
                    }
                    case '3':
                    {
                        // Apply the merge filter

                        cout << "Please enter name of image file to merge with: " << inputFileName << endl;


                        merge();


                        cout << "Merge filter applied." << endl;
                        break;
                    }
                    case '4':
                    {
                        // Apply the flip filter
                        cout << "choose h for horizontal flip or v for vertical flip: ";

                        flipImage();


                        cout << "Flip filter applied." << endl;
                        break;
                    }
                    case '5':
                    {
                        // Apply the darken and lighten filter

                        cout << "Please enter d for darken or l for lighten: ";

                        darkenandlightenimage();

                        cout << "Darken and Lighten filter applied." << endl;
                        break;
                    }
                    case '6':
                    {
                        // Apply the rotate filter

                        cout << "Please enter the angle to rotate the image (90, 180, 270): ";


                        applyRotateImage();
                        cout << "Rotate filter applied." << endl;
                        break;
                    }
                    case '7':
                    {
                        // Apply the edge detection filter

                        applyEdgeDetection();



                        cout << "Edge detection filter applied." << endl;
                        break;
                    }
                    case '8':
                    {
                        // Apply the enlarge filter


                        cout << "please enter the quarter to enlarge : ";
                        enlarge_Image();

                        cout << "Enlarge filter applied." << endl;
                        break;
                    }
                    case '9':
                    {
                        // Apply the shrink filter


                        cout << "please enter the size (0.5 , 0.25 , 0.3) to shrink : ";
                        shrinkImage();




                        cout << "Shrink filter applied." << endl;
                        break;
                    }
                    case 'a':
                    {
                        // Apply the mirror 1/2 filter

                        cout << "Please enter l for left or r for right or u for up or d for down: ";

                        mirrorImage();
                        cout << "Mirror 1/2 filter applied." << endl;
                        break;
                    }
                    case 'b':
                    {
                        // Apply the shuffle filter
                        // ...
                        cout << "please enter the order you want to the quarters in the new image :";
                        shuffle_image();
                        cout << "Shuffle filter applied." << endl;
                        break;
                    }
                    case 'c':
                    {
                        // Apply the blur filter
                        // ...
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        blurImage();
                        for (int i = 0; i < SIZE; i++)
                        {
                            for (int j = 0; j < SIZE; j++)
                            {
                                for (int k = 0; k <RGB ; ++k) {

                                    inputImage[i][j][k] = outputImage[i][j][k];
                                }
                            }
                        }
                        blurImage();


                        cout << "Blur filter applied." << endl;
                        break;
                    }
                    case 'd':
                    {
                        // Apply the crop filter
                        // ...




                        crop_image();
                        cout << "Crop filter applied." << endl;
                        break;
                    }

                    case 'e':
                    {
                        // Apply the skew right filter
                        // ...
                        cout << "Please enter the degree to skew the image 'degree must belong to ]0,90[' : ";
                        skewImageH();
                        cout << "Skew right filter applied." << endl;
                        break;
                    }
                    case 'f':
                    {
                        // Apply the skew up filter
                        // ...
                        cout << "Please enter the degree to skew the image 'degree must belong to ]0,90[' : ";
                        skewImageV();
                        cout << "Skew up filter applied." << endl;
                        break;
                    }

                    default:
                        cout << "Invalid filter choice. Please try again." << endl;
                }
                break;
            }
            case '3':
            {
                if (inputFileName[0] == '\0')
                {
                    cout << "Please load an image first." << endl;
                    break;
                }

                cout << "Please enter the target file name to save the image: ";
                cin >> outputFileName;

                // Write the filtered image using writeRGBBMP
                strcat(outputFileName, ".bmp");

                writeRGBBMP(outputFileName, outputImage);

                cout << "Image saved as " << outputFileName << endl;

                break;
            }
            case '0':
            {
                cout << "Exiting the program." << endl;
                return;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main()
{
    cout << "Welcome to the Image Editor!" << endl;

    menu(); // Display menu that has all the operations

    cout << "Thank you for using the Image Editor!" << endl;

    return 0;
}

// function definitions



// Add more filter function definitions here...
void applyBlackAndWhiteFilter()
{


    unsigned char temp[SIZE][SIZE][RGB];

    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            for (int k = 0; k < RGB; ++k) {
                temp[i][j][k]=inputImage[i][j][k];
            }
        }
    }
    applygray(temp);




    // Calculate the average gray level
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {


                if (temp[i][j][k]> 127)
                {
                    outputImage[i][j][k] = 255;
                }
                else
                {
                    outputImage[i][j][k] = 0;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }

}
void applyInvertfilter()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k) {


                outputImage[i][j][k] = 255 - inputImage[i][j][k]; // Convert every black pixel(0) to white pixel(255)
                //  Convert every white pixel(255) to black pixel(0)

                //  and every gray pixel is turned to opposite level
            }
        }
    }
}
void merge()
{
    char inputFileName2[100];
    cin >> inputFileName2;
    unsigned char inputImage2[SIZE][SIZE][RGB];
    strcat(inputFileName2, ".bmp");

    readRGBBMP(inputFileName2, inputImage2);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {


                outputImage[i][j][k] = (inputImage[i][j][k] + inputImage2[i][j][k]) / 2; // average of the two images
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void flipImage()
{
    char flipChoice;
    cin >> flipChoice;
    if (flipChoice == 'h' || flipChoice == 'H')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    outputImage[i][j][k] = inputImage[i][SIZE - 1 - j][k];
                }
            }
        }
    }
    else if (flipChoice == 'v' || flipChoice == 'V')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    outputImage[i][j][k] = inputImage[SIZE - 1 - i][j][k];
                }
            }
        }
    }
    else
    {
        cout << "invalid input" << endl;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void darkenandlightenimage()
{
    char c;
    cin >> c;

    if (c == 'd')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    outputImage[i][j][k] = inputImage[i][j][k] / 2;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    outputImage[i][j][k] = inputImage[i][j][k] + ((255 - inputImage[i][j][k]) / 2);
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void applyRotateImage()
{
    int angle;
    cin >> angle;

    if (angle == 90)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k <RGB; ++k) {


                    outputImage[i][j][k] = inputImage[j][SIZE - i - 1][k]; // to rotate the image clockwise by 90º;
                }
            }
        }
    }

    else if (angle == 180)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k) {


                    outputImage[i][j][k] = inputImage[SIZE - i - 1][SIZE - j - 1][k]; // to rotate the image clockwise by 180º;
                }
            }
        }
    }
    else if (angle == 270)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k) {


                    outputImage[i][j][k]= inputImage[SIZE - j - 1][i][k]; // to rotate the image clockwise by 270º;
                }
            }
        }
    }

}
void applyEdgeDetection() {
    for (int i = 1; i < SIZE - 1; ++i) {
        for (int j = 1; j < SIZE - 1; ++j) {
            // Calculate the gradient for each channel (R, G, B)
            int gradient[RGB] = {0};
            for (int k = 0; k < RGB; ++k) {
                // Apply Sobel operator to calculate the gradient toward the x-axis
                int gx = inputImage[i + 1][j - 1][k] + 2 * inputImage[i + 1][j][k] + inputImage[i + 1][j + 1][k] -
                         inputImage[i - 1][j - 1][k] - 2 * inputImage[i - 1][j][k] - inputImage[i - 1][j + 1][k];
                // Apply Sobel operator to calculate the gradient toward the y-axis
                int gy = inputImage[i - 1][j + 1][k] + 2 * inputImage[i][j + 1][k] + inputImage[i + 1][j + 1][k] -
                         inputImage[i - 1][j - 1][k] - 2 * inputImage[i][j - 1][k] - inputImage[i + 1][j - 1][k];

                gradient[k] = abs(gx) + abs(gy);
            }

            // Set the output image to black for the detected edges
            if (gradient[0] > 128 || gradient[1] > 128 || gradient[2] > 128) {
                outputImage[i][j][0] = 0;  // Red
                outputImage[i][j][1] = 0;  // Green
                outputImage[i][j][2] = 0;  // Blue
            } else {
                outputImage[i][j][0] = 255;  // Red
                outputImage[i][j][1] = 255;  // Green
                outputImage[i][j][2] = 255;  // Blue
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void enlarge_Image()
{
    int quarter;

    cin >> quarter;
    if (quarter == 1)
    {
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    outputImage[i * 2][j * 2][k] = inputImage[i][j][k];
                }
            }
        }
    }
    else if (quarter == 2)
    {
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    outputImage[i * 2][j * 2][k] = inputImage[i][j + 128][k];
                }
            }
        }
    }
    else if (quarter == 3)
    {
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    outputImage[i * 2][j * 2] [k]= inputImage[i + 128][j][k];
                }
            }
        }
    }
    if (quarter == 4)
    {

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    outputImage[i][j][k] = inputImage[(i / 2) + 127][(j / 2) + 127][k];
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void shrinkImage()
{
    float size;

    cin >> size;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            for (int k = 0; k < RGB; ++k) {
                outputImage[i][j][k]=255;
            }
        }
    }
    if (size == 0.5)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {


                    if (i * 2 <= 255 && j * 2 <= 255)
                    {
                        outputImage[i][j][k] = inputImage[i * 2][j * 2][k];
                    }
                }
            }
        }
    }
    else if (size == 0.25)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    int x = i * 4, s = j * 4;
                    if (x <= 255 && j * 4 <= 255)
                    {
                        outputImage[i][j][k] = inputImage[x][s][k];
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; ++k) {

                    int s = i * 3;
                    int x = j * 3;
                    if (s <= 255 && x <= 255)
                    {
                        outputImage[i][j][k] = inputImage[s][x][k];
                    }
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void shuffle_image() {

    unsigned char image1[128][128][RGB];
    unsigned char image2[128][128][RGB];
    unsigned char image3[128][128][RGB];
    unsigned char image4[128][128][RGB];

    // to divide the image into four small images


    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 128; ++j) {
            for (int k = 0; k < RGB; ++k) {


                image1[i][j][k] = inputImage[i][j][k];
            }
        }
    }
    for (int i = 0; i < 128; ++i) {
        for (int j = 128; j < 256; ++j) {
            for (int k = 0; k < RGB; ++k) {

                image2[i][j - 128][k] = inputImage[i][j][k];
            }
        }
    }
    for (int i = 128; i < 256; ++i) {
        for (int j = 0; j < 128; ++j) {
            for (int k = 0; k < RGB; ++k) {

                image3[i - 128][j][k] = inputImage[i][j][k];
            }
        }
    }
    for (int i = 128; i < 256; ++i) {
        for (int j = 128; j < 256; ++j) {
            for (int k = 0; k < RGB; ++k) {

                image4[i - 128][j - 128][k] = inputImage[i][j][k];
            }
        }
    }




    //  To shuffle small images as the user wants
    int r=4;

    int z=1;
    while (r--){
        int y=0;
        int x=0;
        if (z==2||z==4){
            y=128;
        }
        if (z==3||z==4){
            x=128;
        }
        int n;
        cin>>n;
        if (n==1){
            for (int i = 0; i < 128; ++i) {
                for (int j = 0; j < 128; ++j) {
                    for (int k = 0; k < RGB; ++k) {

                        outputImage[i+x][j+y][k]=image1[i][j][k];
                    }
                }
            }
        } else if (n==2){
            for (int i = 0; i < 128; ++i) {
                for (int j = 0; j < 128; ++j) {
                    for (int k = 0; k < RGB; ++k) {

                        outputImage[i+x][j+y][k]=image2[i][j][k];
                    }
                }
            }
        } else if (n==3){
            for (int i = 0; i < 128; ++i) {
                for (int j = 0; j < 128; ++j) {
                    for (int k = 0; k < RGB; ++k) {

                        outputImage[i+x][j+y][k]=image3[i][j][k];
                    }
                }
            }
        } else if (n==4){
            for (int i = 0; i < 128; ++i) {
                for (int j = 0; j < 128; ++j) {
                    for (int k = 0; k <RGB ; ++k) {

                        outputImage[i+x][j+y][k]=image4[i][j][k];
                    }
                }
            }
        }
        z++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void crop_image(){
    int x,y,w,l;
    cout<<"Please enter x and y 'the psoition' :";
    cin>>x>>y;

    cout<<"Please enter l and w 'length and width' :";
    cin>>w>>l;

    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            for (int k = 0; k < RGB ; ++k) {



                outputImage[i][j][k]=255;
            }
        }
    }
    //To determine the position and the dimensions
    for (int i = y; i < 256; ++i) {
        for (int j = x; j < 256; ++j) {
            for (int k = 0; k <RGB ; ++k) {


                if (j <= w + x + 1 && i <= l + y) {
                    outputImage[i][j][k] = inputImage[i][j][k];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void mirrorImage()
{
    char x;
    cin >> x;

    if (x == 'l' || x == 'L')
    {
        int width = SIZE;
        int height = SIZE;

        for (int y = 0; y < height / 2; y++)
        {
            for (int x = 0; x < width; x++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    outputImage[x][y][k] = inputImage[x][y][k];
                    outputImage[x][height - 1 - y][k] = inputImage[x][y][k];
                }
            }
        }
    }
    else if (x == 'r' || x == 'R')
    {
        int width = SIZE;
        int height = SIZE;

        for (int y = 0; y < height / 2; y++)
        {
            for (int x = 0; x < width; x++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    outputImage[x][y][k] = inputImage[x][height - 1 - y][k];
                    outputImage[x][height - 1 - y][k] = inputImage[x][height - 1 - y][k];
                }
            }
        }
    }
    else if (x == 'u' || x == 'U')
    {

        int width = SIZE;
        int height = SIZE;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width / 2; x++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    outputImage[x][y][k] = inputImage[x][y][k];
                    outputImage[width - 1 - x][y][k] = inputImage[x][y][k];
                }
            }
        }
    }
    else if (x == 'd' || x == 'D')
    {

        int width = SIZE;
        int height = SIZE;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width / 2; x++)
            {
                for (int k = 0; k <RGB ; ++k) {

                    outputImage[x][y][k] = inputImage[width - 1 - x][y][k];
                    outputImage[width - 1 - x][y][k] = inputImage[width - 1 - x][y][k];
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

                inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }
}
void blurImage()
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

                sum = inputImage[i][j][k] + inputImage[i][j + 1][k] + inputImage[i][j + 2][k] + inputImage[i + 1][j][k] + inputImage[i + 1][j + 1][k] + inputImage[i + 1][j + 2][k]+ inputImage[i + 2][j][k] + inputImage[i + 2][j + 1] [k]+ inputImage[i + 2][j + 2][k] + inputImage[i + 3][j][k] + inputImage[i + 3][j + 1][k] + inputImage[i + 3][j + 2][k] + inputImage[i + 3][j + 3] [k]+ inputImage[i + 4][j][k] + inputImage[i + 4][j + 1][k] + inputImage[i + 4][j + 2][k] + inputImage[i + 4][j + 3][k] + inputImage[i + 4][j + 4][k];
                outputImage[i][j][k] = sum / 18;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

                sum = inputImage[i][j][k] + inputImage[i][j + 1][k] + inputImage[i][j + 2][k] + inputImage[i + 1][j][k] + inputImage[i + 1][j + 1][k] + inputImage[i + 1][j + 2][k]+ inputImage[i + 2][j][k] + inputImage[i + 2][j + 1] [k]+ inputImage[i + 2][j + 2][k] + inputImage[i + 3][j][k] + inputImage[i + 3][j + 1][k] + inputImage[i + 3][j + 2][k] + inputImage[i + 3][j + 3] [k]+ inputImage[i + 4][j][k] + inputImage[i + 4][j + 1][k] + inputImage[i + 4][j + 2][k] + inputImage[i + 4][j + 3][k] + inputImage[i + 4][j + 4][k];
                outputImage[i][j][k] = sum / 18;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

                sum = inputImage[i][j][k] + inputImage[i][j + 1][k] + inputImage[i][j + 2][k] + inputImage[i + 1][j][k] + inputImage[i + 1][j + 1][k] + inputImage[i + 1][j + 2][k]+ inputImage[i + 2][j][k] + inputImage[i + 2][j + 1] [k]+ inputImage[i + 2][j + 2][k] + inputImage[i + 3][j][k] + inputImage[i + 3][j + 1][k] + inputImage[i + 3][j + 2][k] + inputImage[i + 3][j + 3] [k]+ inputImage[i + 4][j][k] + inputImage[i + 4][j + 1][k] + inputImage[i + 4][j + 2][k] + inputImage[i + 4][j + 3][k] + inputImage[i + 4][j + 4][k];
                outputImage[i][j][k] = sum / 18;
            }
        }
    }


}
void skewImageH()
{
    unsigned char temp[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k <RGB ; ++k) {

            outputImage[i][j][k]=255;
            }
        }
    }
    double degree;
    cin >> degree;
    degree=90-degree;
    double radians = degree * M_PI / 180.0;
    double skewFactor = tan(radians);

    double x=256/(256/(1+(1/skewFactor)));
    double s=SIZE-(256/(1+(1/skewFactor)));
    double m=s/SIZE;


    // to shrink the photo
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k <RGB ; ++k) {

            if (i * x <= 255){
                temp[i][j][k]=inputImage[i* (int)x][j][k];
            }

            }
        }
    }
    // to shift the shrinked image pixels
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <(256/(1+(1/skewFactor))) ; ++j) {
            for (int k = 0; k <RGB ; ++k) {

            outputImage[j+(int )s][i][k]=temp[j][i][k];

            }
        }
        s-=m;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

            inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }


}
void skewImageV()
{
    unsigned char temp[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {

            outputImage[i][j][k]=255;
            }
        }
    }
    double degree;
    cin >> degree;
    degree=90-degree;
    double radians = degree * M_PI / 180.0;
    double skewFactor = tan(radians);

    double x=256/(256/(1+(1/skewFactor)));
    double s=SIZE-(256/(1+(1/skewFactor)));
    double m=s/SIZE;

    // to shrink the photo
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (j * x <= 255){
                for (int k = 0; k <RGB ; ++k) {

                temp[i][j][k]=inputImage[i][j* (int)x][k];
                }
            }

        }
    }
    // to shift the shrinked image pixels
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <(256/(1+(1/skewFactor))) ; ++j) {
            for (int k = 0; k <RGB ; ++k) {

            outputImage[i][j+(int )s][k]=temp[i][j][k];
            }

        }
        s-=m;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k <RGB ; ++k) {

            inputImage[i][j][k] = outputImage[i][j][k];
            }
        }
    }




}



void applygray(unsigned char temp[SIZE][SIZE][RGB])
{


    int sum = 0;
    // Calculate the average gray level
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sum = 0;
            for (int k = 0; k < RGB; ++k) {
                sum += inputImage[i][j][k];
            }
            unsigned char averageGray = sum / RGB;
            for (int k = 0; k < RGB; ++k) {
                temp[i][j][k] = averageGray;
            }
        }
    }

}

