# Base64 Encoder/Decoder for OpenCV Mat

This project provides a C++ library for encoding and decoding images using the Base64 encoding scheme, with specific support for OpenCV's `cv::Mat` image format. It's designed to facilitate easy conversion between images and Base64 strings, useful for applications that need to encode images for web transfer or embed them in XML or JSON.

## Features

- Encode OpenCV `cv::Mat` images to Base64 strings.
- Decode Base64 strings back to OpenCV `cv::Mat` images.
- Efficient and easy-to-use interface.

## Prerequisites

- OpenCV (4.x or later recommended)
- C++ compiler with C++11 support

## Building and Running the Demo

1. **Install OpenCV:** Ensure that OpenCV is installed and properly configured on your system. This library has been tested with OpenCV 4.x.

2. **Compile the Demo:** Use the following command to compile the demo application:

    ```sh
    g++ main.cpp -o base64Test `pkg-config --cflags --libs opencv4`
    ```

3. **Run the Demo:** After compiling, you can run the demo application with:

    ```sh
    ./base64Test
    ```

    Ensure you have an image named `dog.png` in the same directory as the executable, or modify the `imagePath` in `main.cpp` to point to a valid image file.

## Usage

### Encoding an Image to Base64

```cpp
cv::Mat image = cv::imread("path/to/your/image.png", cv::IMREAD_COLOR);
std::string encodedImage = Base64::encodeMat(image);
Decoding a Base64 String to an Image
cpp
Copy code
auto decodedImageOpt = Base64::decodeToMat(encodedImage);
if (decodedImageOpt) {
    cv::Mat decodedImage = *decodedImageOpt;
    // Use decodedImage as needed
}
```
## Contributing

Contributions are welcome! Please feel free to submit pull requests, create issues for bugs and feature requests, or offer suggestions to improve the library.

## License
This project is open-source and available under the MIT License.