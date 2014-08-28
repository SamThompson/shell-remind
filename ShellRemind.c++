#include <cstdlib>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

/*
 * Simple structure that holds command
 * line args
 */
struct cl {
    bool isOk;
	bool loopSound;
    string sound;
    string exec;
};

/*
 * Parse the command line args, return a command line
 * object
 */
cl parseCL(int argc, char **argv) {
    cl res;
    res.isOk = true;
	res.loopSound = false;

    if (argc > 1) {
        int i = 1;
        while (i < argc) {
            string s(argv[i]);

            if (s == "-s" && i + 1 < argc) {
                res.sound= argv[i+1];
                i += 2;
            } else if (s == "-e" && i + 1 < argc) {
                res.exec = argv[i+1];
                i += 2;
			} else if (s == "-l") {
				res.loopSound = true;
				i++;
            } else {
                res.isOk = false;
            }
        }
    } else {
        res.isOk = false;
    }

    return res;
}

/*
 * Main routine
 */
int main(int argc, char **argv) {
    cl commandLine = parseCL(argc, argv);

    if (commandLine.isOk) {
        sf::SoundBuffer buffer;
        if (commandLine.sound != "" && buffer.LoadFromFile(commandLine.sound)) {
            sf::Sound sound(buffer);
            int res = system(commandLine.exec.c_str());
            cout << "Process complete." << endl;
            cout << "Process returned value: " << res << endl;
			cout << "Wait for sound to end, or press Ctrl-Z" << endl;

			// I found a use for a do-while!
			do {
				sound.Play();
				while (sound.GetStatus() == sf::Sound::Playing) {}
			} while (commandLine.loopSound);

        } else {
            cout << argv[0] << ": " << "could not load sound file \"" 
                << commandLine.sound << "\"" << endl;
        }
    } else {
        cout << argv[0] << ": usage:" << endl << endl;
        cout << "\t" << "-e: executable to run" << endl;
        cout << "\t" << "-s: sound to play upon completion" << endl;
    }

    return 0;
}
