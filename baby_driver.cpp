#include <iostream>
#include <thread>

#include "misc/Estd/algorithm.h"
#include "misc/Estd/thread.h"

#include "sketches.h"
#include "updateQueue.h"

using namespace std;
using namespace Estd;
using namespace MusicGrid;

int main() {
    TrackList trackList;
    trackList.populate("testtree", "");
    UpdateQueue queue;

    guarded_thread writeThread {[&queue]{ queue();} };

    for(;;) {
        cout << trackList.debugPrint();
        cout << "Enter a title: ";
        string str;
        getline(cin, str);
        if (cin.fail() || cin.eof()) {
            break;
        }
        cout << str << endl;

        if (str == "quit")
            break;

        TrackList::iterator selection = find_if(trackList,
                [str](const Track& track){ return track.title() == str; });
        if (selection == trackList.end()) {
            cout << "bad choice\n";
            continue;
        }
        cout << "Tags: " << "title: " << selection->title() << "\n";
        cout << "Enter a new title: ";
        string title;
        getline(cin, title);
        cout << title << endl;
        selection->setTitle(title);
        queue.push(*selection);
        //queue.write();
    }
    queue.stop();

    TagLib::PropertyMap tags;
    tags.insert(TagLib::String("TITLE"),{TagLib::String("Eskimo")});
    tags.insert(TagLib::String("ARTIST"),{TagLib::String("Wiley")});

    Any any{tags};
    All all{tags};
    cout << any_of(trackList, any) << endl;
    cout << any_of(trackList, all) << endl;
    cout << all_of(trackList, any) << endl;
    cout << all_of(trackList, all) << endl;
    Track eski{"testtree/Wiley - Eskimo.mp3"};
    cout << any(eski);
    cout << all(eski) << endl;

    for (auto& tag : eski.properties() ){
        cout << tag.first << ": " << (!tag.second.isEmpty() ? tag.second[0] : "<empty>") << endl;
    }

    return 0;
}
