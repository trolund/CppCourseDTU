#include <iostream>
#include "ex03-library.h"

using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

void printSong(string songTitle, Info info){
    // title=songTitle ; url=songUrl ; score=songScore
    cout << "title=" << songTitle << "; " << "url=" << info.url << "; " << "score=" << info.score;
    cout << endl;
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    // Write your code here
    for (int i = 0; i < this->songs.size(); ++i) // access by reference to avoid copying
    {
        string name = this->songs[i];
        Info info = this->songsInfo[name];
        printSong(name, info);
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    // Write your code here
    /*
       (a) if title is already in the database, do not change anything and return false;
       (b) if score is greater than 10, do not change the database and return false;
       (c) otherwise, when neither (a) nor (b) above apply: add the given title at the
           end of the songs vector, map it to the given url and score (by updating
           songsInfo), and return true.
     */
    Info info = this->songsInfo[title];
    bool b = std::count(this->songs.begin(), this->songs.end(), title) >= 1;

    if (b){
        return false;
    }else if(score > 10){
        return false;
    }else {
        this->songs.push_back(title);
        this->songsInfo[title] = {url, score};

        return true;
    }

}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    for (auto it = this->songs.begin(); it != this->songs.end(); it++) {
        Info &info = this->songsInfo[*it];
        if (((howGood == "abysmal") && (info.score < 3)) ||
            ((howGood == "lousy") && (info.score >= 3) && (info.score < 5)) ||
            ((howGood == "meh") && (info.score >= 5) && (info.score < 7)) ||
            ((howGood == "cool") && (info.score >= 7) && (info.score < 9)) ||
            ((howGood == "OMG") && (info.score >= 9))) {
            printSong(*it, info);
        }
    }

}
