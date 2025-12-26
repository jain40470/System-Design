#include "bits/stdc++.h"
#define nline cout<<'\n';
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


// Many Client specific interfaces are better than 
// one general interface.

class MediaPlayer {
public:

    virtual void playAudio(const string& audioFile) = 0;
    virtual void stopAudio() = 0;
    virtual void adjustAudioVolume(int volume) = 0;

    virtual void playVideo(const string& videoFile) = 0;
    virtual void stopVideo() = 0;
    virtual void adjustVideoBrightness(int brightness) = 0;
    virtual void displaySubtitles(const string& subtitleFile) = 0;

    virtual ~MediaPlayer() = default;
};


class AudioOnlyPlayer : public MediaPlayer {
public:

    void playAudio(const string& audioFile) override {
        cout << "Playing audio file: " << audioFile << endl;
    }

    void stopAudio() override {
        cout << "Audio stopped." << endl;
    }

    void adjustAudioVolume(int volume) override {
        cout << "Audio volume set to: " << volume << endl;
    }

    // 👎 Unwanted methods forced by the interface
    void playVideo(const string& /*videoFile*/) override {
        throw runtime_error("Not supported.");
    }

    void stopVideo() override {
        // no-op
    }

    void adjustVideoBrightness(int /*brightness*/) override {
        throw runtime_error("Not supported.");
    }

    void displaySubtitles(const string& /*subtitleFile*/) override {
        throw runtime_error("Not supported.");
    }
};

// so here we have to override functions even that are not needed 
// that breaks ISP 

int main() {



   
}


//   g++ main.cpp && ./a.out