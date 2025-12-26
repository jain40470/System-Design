#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
 

// child class shoudl be substitable for its parent class

class Document {
public:
    virtual void open() const = 0;
    virtual string getData() const = 0;
    virtual ~Document() = default;
};

class Editable {
public:
    virtual void save(const string& newData) = 0;
    virtual ~Editable() = default;
};


class EditableDocument : public Document, public Editable {

private:

    string data;

public:

    EditableDocument(const string& data) : data(data) {}

    void open() const override {
        cout << "Editable Document opened. Data: " << endl;
    }

    void save(const string& newData) override {
        data = newData;
        cout << "Document saved." << endl;
    }

    string getData() const override {
        return data;
    }

};

class ReadOnlyDocument : public Document {
private:
    string data;
public:
    ReadOnlyDocument(const string& data) : data(data) {}
    void open() const override {
        cout << "Read-Only Document opened. Data: " << endl;
    }
    string getData() const override {
        return data;
    }
};


class DocumentProcessor {

public:

    void process(const Document* doc) const { // first const so that not modify parametr , second const so that not modify its own object
        doc->open();
        cout << "Document processed." << endl; 
    }

    void processAndSave(Document* doc, Editable* editableDoc, const string& additionalInfo) const {
        if (!doc || !editableDoc) {
            throw invalid_argument("Document is not editable.");
        }
        doc->open();
        string currentData = doc->getData();
        string newData = currentData + " | Processed: " + additionalInfo;
        editableDoc->save(newData);
        cout << "Editable document processed and saved." << endl;
    }

};

// child class is substitutable for base class.

int main() {

    EditableDocument editable("Draft proposal for Q3.");
    ReadOnlyDocument readOnly("Top secret strategy.");
    DocumentProcessor processor;

    cout << "--- Processing Editable Document ---" << endl;
    processor.processAndSave(&editable, &editable, "Reviewed by Alice");

    cout << "\n--- Processing Read-Only Document ---" << endl;
    processor.process(&readOnly); // This works fine

    // alt way 

    EditableDocument* editable_ = new EditableDocument("Draft proposal for Q3.");
    ReadOnlyDocument* readOnly_ = new ReadOnlyDocument("Top secret strategy.");
    DocumentProcessor* processor_ = new DocumentProcessor();

    cout << "--- Processing Editable Document ---" << endl;
    processor_->processAndSave(editable_, editable_, "Reviewed by Alice");

    cout << "\n--- Processing Read-Only Document ---" << endl;
    processor_->process(readOnly_); // This works fine


    return 0;
}


//   g++ main.cpp && ./a.out