#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <iostream>
#include <string>
#include "data_structure.h"
#include "PlaylistOfInformation.h"
#include "Surah.h"
#include <fstream>

class PlaylistManager
{
private:
    data_structure<PlaylistOfInformation> playlists;

public:
    void addPlaylist(const PlaylistOfInformation& playlist)
    {
        playlists.Add(playlist);
    }

    void removePlaylist(const std::string& playlistName)
    {
        if (playlists.Search(playlistName))
        {
            playlists.Delete(playlistName);
        }
        else
        {
            std::cout << "Playlist not found.\n";
        }
    }

    void addSurahToPlaylist(const std::string& playlistName, const Surah& surah)
    {
        Node<PlaylistOfInformation>* playlistNode = playlists.getHead();
        while (playlistNode)
        {
            if (playlistNode->data.getName() == playlistName)
            {
                playlistNode->data.addSurah(surah);
                std::cout << "Surah \"" << surah.getName() << "\" added to playlist \"" << playlistName << "\".\n";
                return;
            }
            playlistNode = playlistNode->next;
        }
        std::cout << "Playlist \"" << playlistName << "\" not found.\n";
    }

    void removeSurahFromPlaylist(const std::string& playlistName, const std::string& surahName)
    {
        Node<PlaylistOfInformation>* playlistNode = playlists.getHead();
        while (playlistNode)
        {
            if (playlistNode->data.getName() == playlistName)
            {
                playlistNode->data.removeSurah(surahName);
                std::cout << "Surah \"" << surahName << "\" removed from playlist \"" << playlistName << "\".\n";
                return;
            }
            playlistNode = playlistNode->next;
        }
        std::cout << "Playlist \"" << playlistName << "\" not found.\n";
    }

    void displayAllPlaylists() const
    {
        Node<PlaylistOfInformation>* node = playlists.getHead();
        std::cout << "Playlists:\n";
        while (node)
        {
            std::cout << node->data.getName() << std::endl;
            node = node->next;
        }
    }

    void displayAllPlaylistsWithSurahs() const
    {
        Node<PlaylistOfInformation>* playlistNode = playlists.getHead();
        while (playlistNode)
        {
            std::cout << "Playlist: " << playlistNode->data.getName() << std::endl;
            playlistNode->data.displayAllSurahs();
            playlistNode = playlistNode->next;
        }
    }

    void saveToFile(const std::string& filename) const
    {
        std::ofstream outFile(filename);
        if (!outFile)
        {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        Node<PlaylistOfInformation>* playlistNode = playlists.getHead();
        while (playlistNode)
        {
            outFile << playlistNode->data.getName() << "\n";
            Node<Surah>* surahNode = playlistNode->data.surahs.getHead();
            while (surahNode)
            {
                outFile << surahNode->data.getName() << ","
                    << surahNode->data.getPath() << ","
                    << surahNode->data.getType() << "\n";
                surahNode = surahNode->next;
            }
            playlistNode = playlistNode->next;
        }

        outFile.close();
    }

    void searchPlaylist(const std::string& playlistName) const
    {
        Node<PlaylistOfInformation>* playlistNode = playlists.getHead();
        while (playlistNode)
        {
            if (playlistNode->data.getName() == playlistName)
            {
                std::cout << "Playlist \"" << playlistName << "\" found!\n";
                playlistNode->data.displayAllSurahs();
                return;
            }
            playlistNode = playlistNode->next;
        }
        std::cout << "Playlist \"" << playlistName << "\" not found.\n";
    }
};

#endif // PLAYLISTMANAGER_H
