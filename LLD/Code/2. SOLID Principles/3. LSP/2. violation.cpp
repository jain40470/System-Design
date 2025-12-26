#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
 

class Document {
protected:
    string data;
public:

    Document(const string& data) : data(data) {}

    virtual void open() const {
        cout << "Document opened. Data: " << endl;
    }

    virtual void save(const string& newData) {
        data = newData;
        cout << "Document saved." << endl;
    }

    string getData() const {
        return data;
    }

    virtual ~Document() = default;
};

class ReadOnlyDocument : public Document {
public:

    ReadOnlyDocument(const string& data) : Document(data) {}

    void save(const string& newData) override {
        throw runtime_error("Cannot save a read-only document!");
    }
};


class DocumentProcessor {
public:
    void processAndSave(Document* doc, const string& additionalInfo) {

        doc->open();
        string currentData = doc->getData();
        string newData = currentData + " | Processed: " + additionalInfo;
        doc->save(newData); // Assumes all Documents are savable
        cout << "Document processing complete." << endl;
    
    }
};


// Remember :
// If you ever find yourself overriding a method just to throw an exception,
// or adding subtype-specific conditions in client code—it’s a red flag and 
// you might be violating LSP. 

int main() {

    Document* regularDoc = new Document("Initial project proposal content.");
    Document* confidentialReport = new ReadOnlyDocument("Top secret government data.");

    DocumentProcessor processor;

    cout << "--- Processing Regular Document ---" << endl;
    processor.processAndSave(regularDoc, "Reviewed by Alice");

    cout << "\n--- Processing ReadOnly Document ---" << endl;
    try {
        processor.processAndSave(confidentialReport, "Reviewed by Bob");
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    delete regularDoc;
    delete confidentialReport;

    return 0;
}


//   g++ main.cpp && ./a.out