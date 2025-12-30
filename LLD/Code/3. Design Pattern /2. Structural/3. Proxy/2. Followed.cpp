#include <iostream>
#include <string>

using namespace std;

class Image {
public:
   virtual void display() = 0;
   virtual string getFileName() = 0;
   virtual ~Image() {}
};


class HighResolutionImage : public Image {
private:
   string fileName;
   char* imageData;

   void loadImageFromDisk() {
       cout << "Loading image: " << fileName << " from disk (Expensive Operation)..." << endl;
       imageData = new char[10 * 1024 * 1024]; // Simulate 10MB memory usage
       cout << "Image " << fileName << " loaded successfully." << endl;
   }

public:
   HighResolutionImage(string fileName) : fileName(fileName), imageData(nullptr) {
       loadImageFromDisk();
   }

   ~HighResolutionImage() {
       delete[] imageData;
   }

   void display() override {
       cout << "Displaying image: " << fileName << endl;
   }

   string getFileName() override {
       return fileName;
   }
};

class ImageProxy : public Image {

private:

   string fileName;
   HighResolutionImage* realImage;

public:

   ImageProxy(string fileName) : fileName(fileName), realImage(nullptr) {
       cout << "ImageProxy: Created for " << fileName << ". Real image not loaded yet." << endl;
   }

   ~ImageProxy() {
       delete realImage;
   }

   string getFileName() override {
       // Can safely return without loading the image
       return fileName;
   }

    void display() {

       time_t now = time(0);
       cout << "LoggingProxy: Attempting to display " << fileName << " at " << ctime(&now);

       // Lazy initialization: Load only when display() is called
       if (realImage == nullptr) {
           cout << "ImageProxy: display() requested for " << fileName << ". Loading high-resolution image..." << endl;
           realImage = new HighResolutionImage(fileName);
       } else {
           cout << "ImageProxy: Using cached high-resolution image for " << fileName << endl;
       }

       // Delegate the display call to the real image
       realImage->display();

       now = time(0);
       cout << "LoggingProxy: Finished displaying " << fileName << " at " << ctime(&now);
    }

   
};


class ImageGalleryApp {
public:
   static void main() {
       cout << "Application Started. Initializing image proxies for gallery..." << endl;

       // Create lightweight proxies instead of full image objects
       Image* image1 = new ImageProxy("photo1.jpg");
       Image* image2 = new ImageProxy("photo2.png"); // Never displayed
       Image* image3 = new ImageProxy("photo3.gif");

       cout << "\nGallery initialized. No images actually loaded yet." << endl;
       cout << "Image 1 Filename: " << image1->getFileName() << endl; // Does not trigger image load

       // User clicks on image1
       cout << "\nUser requests to display " << image1->getFileName() << endl;
       image1->display(); // Lazy loading happens here

       // User clicks on image1 again
       cout << "\nUser requests to display " << image1->getFileName() << " again." << endl;
       image1->display(); // Already loaded; no loading delay

       // User clicks on image3
       cout << "\nUser requests to display " << image3->getFileName() << endl;
       image3->display(); // Triggers loading for image3

       cout << "\nApplication finished. Note: photo2.png was never loaded." << endl;

       delete image1;
       delete image2;
       delete image3;
   }
};


// you can add restriction wala in 
// display too. , if you want.


// ImageProxy now performs multiple roles:
// 1.Acts as a stand-in for an expensive object (Virtual Proxy)
// 2.Delays initialization until needed (Lazy loading)
// 3.Restricts access to sensitive content (Protection Proxy)
// 4.Logs image access and usage patterns (Logging Proxy)
// All of this happens transparently, without the client or the real object being aware.

// The Proxy Design Pattern provides a stand-in or placeholder for 
// another object to control access to it. Instead of the client 
// interacting directly with the “real” object (e.g., HighResolutionImage), 
// it interacts with a Proxy that implements the same interface.

// Subject : Image
// RealObject : HighResolutionImage
// Proxy has a real object and proxy (class) is a image (class) .

int main() {
   
   ImageGalleryApp::main();
   return 0;

}

