  #ifndef PLAYLISTOFINFORMATION_H
#define PLAYLISTOFINFORMATION_H

#include <iostream>
#include "Surah.h"
#include "data_structure.h"

class PlaylistOfInformation
{
public:
    std::string name;
    data_structure<Surah> surahs;

    // Default constructor
    PlaylistOfInformation() : name("") {}

    // Constructor with name
    PlaylistOfInformation(const std::string& n) : name(n) {}

    // Copy constructor with deep copy
    PlaylistOfInformation(const PlaylistOfInformation& other) : name(other.name), surahs() {
        Node<Surah>* current = other.surahs.getHead();
        while (current) {
            surahs.Add(current->data); // Deep copy each Surah
            current = current->next;
        }
    }

    void addSurah(const Surah& surah)
    {
        surahs.Add(surah);
    }

    void removeSurah(const std::string& surahName)
    {
        surahs.Delete(surahName);
    }

    void displayAllSurahs() const
    {
        Node<Surah>* current = surahs.getHead();
        while (current)
        {
            current->data.display();
            current = current->next;
        }
    }

    void displaySpecificSurah(const std::string& surahName) const
    {
        Node<Surah>* current = surahs.getHead();
        while (current)
        {
            if (current->data.getName() == surahName)
            {
                current->data.display();
                return;
            }
            current = current->next;
        }
        std::cout << "Surah with name " << surahName << " not found in the playlist.\n";
    }

    // Getter for the name
    std::string getName() const
    {
        return name;
    }
};

#endif // PLAYLISTOFINFORMATION_H
