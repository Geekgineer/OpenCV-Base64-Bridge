#include <iostream>
#include <fstream> // Include for file operations
#include "include/base64.hpp"


int main() {
    // Path to your image
    std::string imagePath = "dog.png";

    // Load the image
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Error loading image: " << imagePath << std::endl;
        return -1;
    }

    // Encode the image to a Base64 string
    std::string encodedImage = Base64::encodeMat(image);

    // Dump the Base64 encoded string to a text file
    std::ofstream outFile("encodedImage.txt");
    if (!outFile) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return -1;
    }

    outFile << encodedImage;
    outFile.close();
    std::cout << "Encoded image dumped to encodedImage.txt" << std::endl;

    // Decode the Base64 string back to an image
    auto decodedImageOpt = Base64::decodeToMat(encodedImage);
    if (!decodedImageOpt) {
        std::cerr << "Failed to decode image from Base64." << std::endl;
        return -1;
    }
    cv::Mat decodedImage = *decodedImageOpt;

    // For demonstration, let's save the decoded image
    cv::imwrite("decodedImage.jpg", decodedImage);
    std::cout << "Decoded image saved as decodedImage.jpg" << std::endl;

    return 0;
}

