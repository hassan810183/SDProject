#include <iostream>
#include <string>
#include "PlaylistManager.h"
#include "PlaylistOfInformation.h"
#include "Surah.h"

void displayMenu() {
    std::cout << "                   =================================================================\n";
    std::cout << "                   |                    Quraan Playlist Manager Menu               |\n";
    std::cout << "                   =================================================================\n";
    std::cout << "                   |1. Add a new playlist                                          |\n";
    std::cout << "                   |2. Add Surah to an existing playlis                            |\n";
    std::cout << "                   |3. Remove Surah from an existing playlist                      |\n";
    std::cout << "                   |4. Update the order of existing playlist                       |\n";
    std::cout << "                   |5. Display All Current Playlists                               |\n";
    std::cout << "                   |6. Display all Playlists Surah                                 |\n";
    std::cout << "                   |7. Display Surah in a specific playlist                        |\n";
    std::cout << "                   |8. Play Surah from specific playlist                           |\n";
    std::cout << "                   |  Use left arrow (<-) to play the previous surah               |\n";
    std::cout << "                   |  Use right arrow (->) to play the next surah                  |\n";
    std::cout << "                   | Use up arrow (^) to pause the current surah                   |\n";
    std::cout << "                   | Use down arrow (v) to resume the current surah                |\n";
    std::cout << "                   | Press q to exit current playlist & return back to menu        |\n";
    std::cout << "                   |9. Save an existing playlist to a file                         |\n";
    std::cout << "                   |10. Load an existing playlist from a file                      |\n";
    std::cout << "                   |11. Remove an existing playlist                                |\n";
    std::cout << "                   |12. Exit                                                       |\n";
    std::cout << "                   ================================================================\n";
    std::cout << "                   Your choice: ";
}

int main() {
    PlaylistManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::cout << "Enter Playlist Name: ";
                std::string playlistName;
                std::getline(std::cin, playlistName);
                manager.addPlaylist(PlaylistOfInformation(playlistName));
                std::cout << "Playlist \"" << playlistName << "\" added successfully!\n";
                break;
            }

            case 2: {
                std::cin.ignore();
                std::cout << "Enter Playlist Name: ";
                std::string playlistName;
                std::getline(std::cin, playlistName);
                std::cout << "Enter Surah Details (Name, Path, Type): ";
                std::string surahName, path, type;
                std::cin >> surahName >> path >> type;
                manager.addSurahToPlaylist(playlistName, Surah(surahName, path, type));
                break;
            }

            case 3: {
                std::cin.ignore();
                std::cout << "Enter Playlist Name: ";
                std::string playlistName;
                std::getline(std::cin, playlistName);
                std::cout << "Enter Surah Name to remove: ";
                std::string surahName;
                std::getline(std::cin, surahName);
                manager.removeSurahFromPlaylist(playlistName, surahName);
                break;
            }

            case 4: {
                std::cout << "Feature to update the order is not yet implemented.\n";
                break;
            }

            case 5: {
                manager.displayAllPlaylists();
                break;
            }

            case 6: {
                manager.displayAllPlaylistsWithSurahs();
                break;
            }

            case 7: {
                std::cin.ignore();
                std::cout << "Enter Playlist Name: ";
                std::string playlistName;
                std::getline(std::cin, playlistName);
                manager.searchPlaylist(playlistName);
                break;
            }

            case 8: {
                std::cout << "Playing Surahs is not implemented in this console-based program.\n";
                break;
            }

            case 9: {
                std::cin.ignore();
                std::cout << "Enter filename to save playlists: ";
                std::string filename;
                std::getline(std::cin, filename);
                manager.saveToFile(filename);
                std::cout << "Playlists saved to \"" << filename << "\" successfully.\n";
                break;
            }

            case 10: {
                std::cin.ignore();
                std::cout << "Enter filename to load playlists: ";
                std::string filename;
                std::getline(std::cin, filename);
                std::cout << "Feature to load playlists is not yet implemented.\n";
                break;
            }

            case 11: {
                std::cin.ignore();
                std::cout << "Enter Playlist Name to remove: ";
                std::string playlistName;
                std::getline(std::cin, playlistName);
                manager.removePlaylist(playlistName);
                std::cout << "Playlist \"" << playlistName << "\" removed successfully!\n";
                break;
            }

            case 12: {
                std::cout << "Exiting program. Goodbye!\n";
                break;
            }

            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 12);

    return 0;
}
