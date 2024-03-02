#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "DynamicVector.h"
#include "Movie.h"

typedef Movie TElem;

class Repository {
private:
    DynamicVector<TElem> entities;

public:

    /**
     * Destructor that cleans up any dynamically allocated memory.
     */
    ~Repository();

    /**
     * Adds the given entity to the repository.
     *
     * @param entity The entity to add.
     */
    void AddEntity(TElem entity);

    /**
     * Deletes the entity at the given index from the repository.
     *
     * @param index The index of the entity to delete.
     */
    void DeleteEntityAt(int index);

    /**
     * Updates the entity at the given index with the given new entity.
     *
     * @param index The index of the entity to update.
     * @param newEntity The new entity to replace the old one with.
     */
    void UpdateEntityAt(int index, TElem newEntity);

    /**
     * Returns a pointer to an array containing all the entities in the repository.
     *
     * @return A pointer to an array of TElem objects containing all the entities in the repository.
     */
    TElem* GetAllEntities();

    /**
     * Returns the number of entities in the repository.
     *
     * @return An integer representing the number of entities in the repository.
     */
    int GetSize();
};

#endif
