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
unsigned char inputImage[SIZE][SIZE];
unsigned char outputImage[SIZE][SIZE];
char inputFileName[100];
char outputFileName[100];
char choice;

// function declarations here
//______________________________________
void applyBlackAndWhiteFilter();
//______________________________________
void applyInvertfilter();
//______________________________________
void merge();
//______________________________________
void flipImage();
//______________________________________
void darkenandlightenimage();
//______________________________________
void applyRotateImage();
//______________________________________
void applyEdgeDetection();
//______________________________________
void enlarge_Image();
//______________________________________
void shrinkImage();
//______________________________________
void mirrorImage();
//______________________________________
void shuffle_image();
//______________________________________
void blurImage();
//______________________________________
void crop_image();
//______________________________________
void skewImageH();
//______________________________________
void skewImageV();
//______________________________________
void menu()
{
    // Declare the variables here.

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
                int f = readGSBMP(inputFileName, inputImage);
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
                cout << "e. Skew Image horizontal (h)" << endl;
                cout << "f. Skew Image vertical (v)" << endl;

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
                        cout << "enter New order of quarters? ";
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
                        for (int i = 0; i < SIZE; i++)
                        {
                            for (int j = 0; j < SIZE; j++)
                            {
                                inputImage[i][j] = outputImage[i][j];
                            }
                        }

                        cout << "Blur filter applied." << endl;
                        break;
                    }
                    case 'd':
                    {
                        // Apply the crop filter
                        // ...
                        cout << "Please enter x y w l: ";

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

                writeGSBMP(outputFileName, outputImage);

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

// implement of all the functions here

void applyBlackAndWhiteFilter()
{


    // Calculate the average gray level
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            if (inputImage[i][j] > 127)
            {
                outputImage[i][j] = 255;
            }
            else
            {
                outputImage[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}

void applyInvertfilter()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            outputImage[i][j] = 255 - inputImage[i][j]; // Convert every black pixel(0) to white pixel(255)
            //  Convert every white pixel(255) to black pixel(0)
            //  and every gray pixel is turned to opposite level
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}
void merge()
{

    char inputFileName2[100];
    cin >> inputFileName2;

    unsigned char inputImag2[SIZE][SIZE];
    strcat(inputFileName2, ".bmp");
    readGSBMP(inputFileName2, inputImag2);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            outputImage[i][j] = (inputImage[i][j] + inputImag2[i][j]) / 2; // average of the two images
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}
void flipImage()
{
    char x;
    cin >> x;
    if (x == 'h' || x == 'H')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                outputImage[i][j] = inputImage[i][SIZE - 1 - j];
            }
        }
    }
    else if (x == 'v' || x == 'V')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                outputImage[i][j] = inputImage[SIZE - 1 - i][j];
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
            inputImage[i][j] = outputImage[i][j];
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
                outputImage[i][j] = inputImage[i][j] / 2;
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                outputImage[i][j] = inputImage[i][j] + ((255 - inputImage[i][j]) / 2);
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
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
            for (int j = 0; j < SIZE; ++j)
            {
                outputImage[i][j] = inputImage[j][SIZE - i - 1]; // to rotate the image clockwise by 90º;
            }
        }
    }
    else if (angle == 180)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                outputImage[i][j] = inputImage[SIZE - i - 1][SIZE - j - 1]; // to rotate the image clockwise by 180º;
            }
        }
    }
    else if (angle == 270)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                outputImage[i][j] = inputImage[SIZE - j - 1][i]; // to rotate the image clockwise by 270º;
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}

void applyEdgeDetection()
{
    for (int i = 1; i < SIZE - 1; ++i)
    {
        for (int j = 1; j < SIZE - 1; ++j)
        {

            // apply sobel opearator to calculate the gradient toward x-axis
            int gx = inputImage[i + 1][j - 1] + 2 * inputImage[i + 1][j] + inputImage[i + 1][j + 1] - inputImage[i - 1][j - 1] - 2 * inputImage[i - 1][j] - inputImage[i - 1][j + 1];
            // apply sobel opearator to calculate the gradient toward y-axis
            int gy = inputImage[i - 1][j + 1] + 2 * inputImage[i][j + 1] + inputImage[i + 1][j + 1] - inputImage[i - 1][j - 1] - 2 * inputImage[i][j - 1] - inputImage[i + 1][j - 1];

            int gradient = abs(gx) + abs(gy);
            outputImage[i][j] = (gradient > 128) ? 0 : 255;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
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
                outputImage[i * 2][j * 2] = inputImage[i][j];
            }
        }
    }
    else if (quarter == 2)
    {
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                outputImage[i * 2][j * 2] = inputImage[i][j + 128];
            }
        }
    }
    else if (quarter == 3)
    {
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                outputImage[i * 2][j * 2] = inputImage[i + 128][j];
            }
        }
    }
    if (quarter == 4)
    {

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                outputImage[i][j] = inputImage[(i / 2) + 127][(j / 2) + 127];
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}
void shrinkImage()
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            outputImage[i][j] = 255;
        }
    }
    float size;

    cin >> size;
    if (size == 0.5)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                if (i * 2 <= 255 && j * 2 <= 255)
                {
                    outputImage[i][j] = inputImage[i * 2][j * 2];
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
                int x = i * 4, s = j * 4;
                if (x <= 255 && j * 4 <= 255)
                {
                    outputImage[i][j] = inputImage[x][s];
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
                int s = i * 3;
                int x = j * 3;
                if (s <= 255 && x <= 255)
                {
                    outputImage[i][j] = inputImage[s][x];
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
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
                outputImage[x][y] = inputImage[x][y];
                outputImage[x][height - 1 - y] = inputImage[x][y];
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
                outputImage[x][y] = inputImage[x][height - 1 - y];
                outputImage[x][height - 1 - y] = inputImage[x][height - 1 - y];
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
                outputImage[x][y] = inputImage[x][y];
                outputImage[width - 1 - x][y] = inputImage[x][y];
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
                outputImage[x][y] = inputImage[width - 1 - x][y];
                outputImage[width - 1 - x][y] = inputImage[width - 1 - x][y];
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}

void shuffle_image()
{
    unsigned char image1[128][128];
    unsigned char image2[128][128];
    unsigned char image3[128][128];
    unsigned char image4[128][128];
    for (int i = 0; i < 128; ++i)
    {
        for (int j = 0; j < 128; ++j)
        {
            image1[i][j] = inputImage[i][j];
        }
    }
    for (int i = 0; i < 128; ++i)
    {
        for (int j = 128; j < 256; ++j)
        {
            image2[i][j - 128] = inputImage[i][j];
        }
    }
    for (int i = 128; i < 256; ++i)
    {
        for (int j = 0; j < 128; ++j)
        {
            image3[i - 128][j] = inputImage[i][j];
        }
    }
    for (int i = 128; i < 256; ++i)
    {
        for (int j = 128; j < 256; ++j)
        {
            image4[i - 128][j - 128] = inputImage[i][j];
        }
    }

    int r = 4;

    int z = 1;
    while (r--)
    {
        int y = 0;
        int x = 0;
        if (z == 2 || z == 4)
        {
            y = 128;
        }
        if (z == 3 || z == 4)
        {
            x = 128;
        }
        int n;
        cin >> n;
        if (n == 1)
        {
            for (int i = 0; i < 128; ++i)
            {
                for (int j = 0; j < 128; ++j)
                {
                    outputImage[i + x][j + y] = image1[i][j];
                }
            }
        }
        else if (n == 2)
        {
            for (int i = 0; i < 128; ++i)
            {
                for (int j = 0; j < 128; ++j)
                {
                    outputImage[i + x][j + y] = image2[i][j];
                }
            }
        }
        else if (n == 3)
        {
            for (int i = 0; i < 128; ++i)
            {
                for (int j = 0; j < 128; ++j)
                {
                    outputImage[i + x][j + y] = image3[i][j];
                }
            }
        }
        else if (n == 4)
        {
            for (int i = 0; i < 128; ++i)
            {
                for (int j = 0; j < 128; ++j)
                {
                    outputImage[i + x][j + y] = image4[i][j];
                }
            }
        }
        z++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}

void crop_image()
{
    int x, y, w, l;

    cin >> x >> y >> w >> l;
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            outputImage[i][j] = 255;
        }
    }
    for (int i = y; i < 256; ++i)
    {
        for (int j = x; j < 256; ++j)
        {
            if (j <= w + x + 1 && i <= l + y)
            {
                outputImage[i][j] = inputImage[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }
}

void blurImage()
{
    int sum ;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum = inputImage[i][j] + inputImage[i][j + 1] + inputImage[i][j + 2] + inputImage[i + 1][j] + inputImage[i + 1][j + 1] + inputImage[i + 1][j + 2] + inputImage[i + 2][j] + inputImage[i + 2][j + 1] + inputImage[i + 2][j + 2] + inputImage[i + 3][j] + inputImage[i + 3][j + 1] + inputImage[i + 3][j + 2] + inputImage[i + 3][j + 3] + inputImage[i + 4][j] + inputImage[i + 4][j + 1] + inputImage[i + 4][j + 2] + inputImage[i + 4][j + 3] + inputImage[i + 4][j + 4];
            outputImage[i][j] = sum / 18;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum = inputImage[i][j] + inputImage[i][j + 1] + inputImage[i][j + 2] + inputImage[i + 1][j] + inputImage[i + 1][j + 1] + inputImage[i + 1][j + 2] + inputImage[i + 2][j] + inputImage[i + 2][j + 1] + inputImage[i + 2][j + 2] + inputImage[i + 3][j] + inputImage[i + 3][j + 1] + inputImage[i + 3][j + 2] + inputImage[i + 3][j + 3] + inputImage[i + 4][j] + inputImage[i + 4][j + 1] + inputImage[i + 4][j + 2] + inputImage[i + 4][j + 3] + inputImage[i + 4][j + 4];
            outputImage[i][j] = sum / 18;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum = inputImage[i][j] + inputImage[i][j + 1] + inputImage[i][j + 2] + inputImage[i + 1][j] + inputImage[i + 1][j + 1] + inputImage[i + 1][j + 2] + inputImage[i + 2][j] + inputImage[i + 2][j + 1] + inputImage[i + 2][j + 2] + inputImage[i + 3][j] + inputImage[i + 3][j + 1] + inputImage[i + 3][j + 2] + inputImage[i + 3][j + 3] + inputImage[i + 4][j] + inputImage[i + 4][j + 1] + inputImage[i + 4][j + 2] + inputImage[i + 4][j + 3] + inputImage[i + 4][j + 4];
            outputImage[i][j] = sum / 18;
        }
    }

}
void skewImageH()
{
    unsigned char temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            outputImage[i][j]=255;
        }
    }
    double degree;
    cin >> degree;
    degree=90-degree;
    double radians = degree * M_PI / 180.0;
    double skewFactor = tan(radians);

    double x=255/(255/(1+(1/skewFactor)));
    double s=SIZE-(255/(1+(1/skewFactor)));
    double m=s/SIZE;


    // to shrink the photo
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i * x <= 255){
                temp[i][j]=inputImage[i* (int)x][j];
            }

        }
    }
    // to shift the shrinked image pixels
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <(255/(1+(1/skewFactor))) ; ++j) {
            outputImage[j+(int )s][i]=temp[j][i];

        }
        s-=m;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }


}
void skewImageV()
{
    unsigned char temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            outputImage[i][j]=255;
        }
    }
    double degree;
    cin >> degree;
    degree=90-degree;
    double radians = degree * M_PI / 180.0;
    double skewFactor = tan(radians);

    double x=255/(255/(1+(1/skewFactor)));
    double s=SIZE-(255/(1+(1/skewFactor)));
    double m=s/SIZE;

    // to shrink the photo
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (j * x <= 255){
                temp[i][j]=inputImage[i][j* (int)x];
            }

        }
    }
    // to shift the shrinked image pixels
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <(255/(1+(1/skewFactor))) ; ++j) {
            outputImage[i][j+(int )s]=temp[i][j];

        }
        s-=m;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            inputImage[i][j] = outputImage[i][j];
        }
    }




}
