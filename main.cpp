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

void menu()
{
    unsigned char inputImage[SIZE][SIZE];
    unsigned char outputImage[SIZE][SIZE];
    string inputFileName;
    string outputFileName;
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

            readGSBMP(inputFileName.c_str(), inputImage);

            cout << "Image loaded successfully." << endl;

            break;
        }
        case '2':
        {
            // filter menu here

            if (inputFileName.empty())
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
            cout << "8. - Enlarge Image" << endl;
            cout << "9. - Shrink Image" << endl;
            cout << "a. - Mirror 1/2 Image" << endl;
            cout << "b. -  Shuffle Image" << endl;
            cout << "c. - Blur Image" << endl;
            cout << "d. - Crop Image" << endl;
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
                // Apply the Black and White filter (similar to your previous code)
                // ...
                applyBlackAndWhiteFilter(inputImage, outputImage);
                cout << "Black and White filter applied." << endl;
                break;
            }
            case '2':
            {
                // Apply the Invert filter (similar to your previous code)
                // ...
                cout << "Invert filter applied." << endl;
                break;
            }
            case '3':
            {
                // Apply the merge filter (similar to your previous code)
                // ...
                cout << "Merge filter applied." << endl;
                break;
            }
            case '4':
            {
                // Apply the flip filter (similar to your previous code)
                // ...
                cout << "Flip filter applied." << endl;
                break;
            }
            case '5':
            {
                // Apply the darken and lighten filter (similar to your previous code)
                // ...
                cout << "Darken and Lighten filter applied." << endl;
                break;
            }
            case '6':
            {
                // Apply the rotate filter (similar to your previous code)
                // ...
                cout << "Rotate filter applied." << endl;
                break;
            }
            case '7':
            {
                // Apply the edge detection filter (similar to your previous code)
                // ...
                cout << "Edge detection filter applied." << endl;
                break;
            }
            case '8':
            {
                // Apply the enlarge filter (similar to your previous code)
                // ...
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
                // Apply the shuffle filter (similar to your previous code)
                // ...
                cout << "Shuffle filter applied." << endl;
                break;
            }
            case 'c':
            {
                // Apply the blur filter (similar to your previous code)
                // ...
                cout << "Blur filter applied." << endl;
                break;
            }
            case 'd':
            {
                // Apply the crop filter (similar to your previous code)
                // ...
                cout << "Crop filter applied." << endl;
                break;
            }

            case 'e':
            {
                // Apply the skew right filter (similar to your previous code)
                // ...
                cout << "Skew right filter applied." << endl;
                break;
            }
            case 'f':
            {
                // Apply the skew up filter (similar to your previous code)
                // ...
                cout << "Skew up filter applied." << endl;
                break;
            }

                // Add cases for other filters...

            default:
                cout << "Invalid filter choice. Please try again." << endl;
            }
            break;
        }
        case '3':
        {
            if (inputFileName.empty())
            {
                cout << "Please load an image first." << endl;
                break;
            }

            cout << "Please enter the target file name to save the image: ";
            cin >> outputFileName;

            // Write the filtered image using writeRGBBMP
            writeGSBMP(outputFileName.c_str(), outputImage);

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
    menu();

    return 0;
}
