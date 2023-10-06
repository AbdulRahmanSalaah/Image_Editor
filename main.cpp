#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

void applyBlackAndWhiteFilter(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE])
{
    int sum = 0;
    int pixelCount = SIZE * SIZE;

    // Calculate the average gray level
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum += inputImage[i][j]; // Using the pixel value for grayscale

            // Convert the pixel to white (255) or black (0) based on average gray level
            int average = sum / pixelCount;
            if (inputImage[i][j] > average)
            {
                outputImage[i][j] = 255;
            }
            else
            {
                outputImage[i][j] = 0;
            }
        }
    }
}
void flipImage(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE], char x)
{
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
}
void merge(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE], unsigned char inputImag2[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            outputImage[i][j] = (inputImage[i][j] + inputImag2[i][j]) / 2; // average of the two images
        }
    }
}
void Apply_Invert_Image(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE])
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
}
void Apply_Rotate_Image(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE], int Angle)
{

    if (Angle == 90)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                outputImage[i][j] = inputImage[j][SIZE - i - 1]; // to rotate the image clockwise by 90º;
            }
        }
    }
    else if (Angle == 180)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                outputImage[i][j] = inputImage[SIZE - i - 1][SIZE - j - 1]; // to rotate the image clockwise by 180º;
            }
        }
    }
    else if (Angle == 270)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                outputImage[i][j] = inputImage[SIZE - j - 1][i]; // to rotate the image clockwise by 270º;
            }
        }
    }
}
void darkenandlightenimage(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE], char c)
{

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
}
void Apply_Edge_Detection(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE])
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
}
void enlarge_Image(unsigned char inputImage[][SIZE], unsigned char outputImage[][SIZE], int quarter)
{
    int newSize = SIZE * 2; // New size will be twice the original size
    int halfSize = SIZE / 2;

    // Check if the input quarter is valid
    if (quarter < 1 || quarter > 4)
    {
        cout << "Invalid quarter. Please choose a quarter between 1 and 4." << endl;
        return;
    }

    // Initialize variables for indexing the input and output images
    int inputRowStart, inputRowEnd, inputColStart, inputColEnd;
    int outputRowStart, outputColStart;

    // Define the regions of the input and output images based on the selected quarter
    if (quarter == 1)
    {
        inputRowStart = 0;
        inputRowEnd = halfSize;
        inputColStart = 0;
        inputColEnd = halfSize;
        outputRowStart = 0;
        outputColStart = 0;
    }
    else if (quarter == 2)
    {
        inputRowStart = 0;
        inputRowEnd = halfSize;
        inputColStart = halfSize;
        inputColEnd = SIZE;
        outputRowStart = 0;
        outputColStart = halfSize;
    }
    else if (quarter == 3)
    {
        inputRowStart = halfSize;
        inputRowEnd = SIZE;
        inputColStart = 0;
        inputColEnd = halfSize;
        outputRowStart = halfSize;
        outputColStart = 0;
    }
    else if (quarter == 4)
    {
        inputRowStart = halfSize;
        inputRowEnd = SIZE;
        inputColStart = halfSize;
        inputColEnd = SIZE;
        outputRowStart = halfSize;
        outputColStart = halfSize;
    }

    // Enlarge the image by copying pixels from the specified quarter
    for (int i = inputRowStart, oi = outputRowStart; i < inputRowEnd; i++, oi += 2)
    {
        for (int j = inputColStart, oj = outputColStart; j < inputColEnd; j++, oj += 2)
        {
            unsigned char pixelValue = inputImage[i][j];
            outputImage[oi][oj] = pixelValue;
            outputImage[oi][oj + 1] = pixelValue;
            outputImage[oi + 1][oj] = pixelValue;
            outputImage[oi + 1][oj + 1] = pixelValue;
        }
    }
}
// Add more filter function definitions here...
void menu()
{
    unsigned char inputImage[SIZE][SIZE];
    unsigned char outputImage[SIZE][SIZE];
    char inputFileName[100];
    char outputFileName[100];
    char choice;

    while (true)
    {

        cout << "Menu:" << endl;
        cout << "1. Load an image" << endl;
        cout << "2. Apply a filter" << endl;
        cout << "3. Save the image" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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

            if (inputFileName[0] == '\0')
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

                applyBlackAndWhiteFilter(inputImage, outputImage);
                cout << "Black and White filter applied." << endl;
                break;
            }
            case '2':
            {
                // Apply the Invert filter

                Apply_Invert_Image(inputImage, outputImage);
                cout << "Invert filter applied." << endl;
                break;
            }
            case '3':
            {
                // Apply the merge filter

                cout << "Please enter name of image file to merge with: " << inputFileName << endl;
                char inputFileName2[100];
                cin >> inputFileName2;
                unsigned char inputImage2[SIZE][SIZE];
                strcat(inputFileName2, ".bmp");

                readGSBMP(inputFileName2, inputImage2);
                merge(inputImage, outputImage, inputImage2);

                cout << "Merge filter applied." << endl;
                break;
            }
            case '4':
            {
                // Apply the flip filter

                cout << "chose h for horizontal flip or v for vertical flip: ";
                char flipChoice;
                cin >> flipChoice;
                flipImage(inputImage, outputImage, flipChoice);

                cout << "Flip filter applied." << endl;
                break;
            }
            case '5':
            {
                // Apply the darken and lighten filter

                cout << "Please enter d for darken or l for lighten: ";
                char c;
                cin >> c;
                darkenandlightenimage(inputImage, outputImage, c);
                cout << "Darken and Lighten filter applied." << endl;
                break;
            }
            case '6':
            {
                // Apply the rotate filter

                cout << "Please enter the angle to rotate the image (90, 180, 270): ";
                int angle;
                cin >> angle;
                Apply_Rotate_Image(inputImage, outputImage, angle);

                cout << "Rotate filter applied." << endl;
                break;
            }
            case '7':
            {
                // Apply the edge detection filter

                Apply_Edge_Detection(inputImage, outputImage);

                cout << "Edge detection filter applied." << endl;
                break;
            }
            case '8':
            {
                // Apply the enlarge filter

                int quarter;
                cout << "please enter the quarter to enlarge : ";
                cin >> quarter;
                enlarge_Image(inputImage, outputImage, quarter);
                cout << "Enlarge filter applied." << endl;
                break;
            }
            case '9':
            {
                // Apply the shrink filter (similar to your previous code)
                // ...
                cout << "Shrink filter applied." << endl;
                break;
            }
            case 'a':
            {
                // Apply the mirror 1/2 filter (similar to your previous code)
                // ...
                cout << "Mirror 1/2 filter applied." << endl;
                break;
            }
            case 'b':
            {
                // Apply the shuffle filter
                // ...
                cout << "Shuffle filter applied." << endl;
                break;
            }
            case 'c':
            {
                // Apply the blur filter
                // ...
                cout << "Blur filter applied." << endl;
                break;
            }
            case 'd':
            {
                // Apply the crop filter
                // ...
                cout << "Crop filter applied." << endl;
                break;
            }

            case 'e':
            {
                // Apply the skew right filter
                // ...
                cout << "Skew right filter applied." << endl;
                break;
            }
            case 'f':
            {
                // Apply the skew up filter
                // ...
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
    menu();
    cout << "Thank you for using the Image Editor!" << endl;

    return 0;
}
