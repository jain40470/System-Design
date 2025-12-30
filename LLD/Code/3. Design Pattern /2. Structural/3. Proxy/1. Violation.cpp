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


class ImageGalleryAppV1 {
public:
   static void main() {
       cout << "Application Started. Initializing images for gallery..." << endl;

       // Images are created eagerly – loaded even if not viewed!
       Image* image1 = new HighResolutionImage("photo1.jpg");
       Image* image2 = new HighResolutionImage("photo2.png");
       Image* image3 = new HighResolutionImage("photo3.gif");

       cout << "\nGallery initialized. User might view an image now." << endl;

       // User clicks on image1
       cout << "User requests to display " << image1->getFileName() << endl;
       image1->display();

       // User clicks on image3
       cout << "\nUser requests to display " << image3->getFileName() << endl;
       image3->display();

       cout << "\nApplication finished." << endl;

       delete image1;
       delete image2;
       delete image3;
   }
};


// Now here 
// if you use or not whenever
// you create the image instance , it just loads which 
// is an hheavy process. So if you have to make it 
// like load when needed , not when you declare.

// Also if you want to add restrictiosn on opening of an image?
// you have to modify code too.

// Also if you have to log the details , you need to 
// create method or made changes in code.

// Don't it breaks SRP , then u need to add so many new things.
// and OCP too.

// When to Use Proxy
// Use Proxy when you need:
// 1. Lazy initialization
// 2. Access control
// 3. Logging / monitoring
// 4. Caching
// 5. Remote objects (Client treats remote object as local , Network complexity hidden)

// Proxy intent
// “Control access to a real object while keeping the same interface.”
// Proxy answers:
// When should the object be created?
// Who is allowed to use it?
// Should we cache/log/remote it?

int main() {

    ImageGalleryAppV1::main();

}
