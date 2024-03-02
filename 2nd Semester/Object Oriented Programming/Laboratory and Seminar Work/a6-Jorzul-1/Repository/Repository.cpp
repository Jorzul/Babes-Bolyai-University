//
// Created by User on 5/4/2023.
//

#include "Repository.h"

Repository::~Repository()
= default;
/*
* Destructor that cleans up any dynamically allocated memory.
*/

void Repository::add_entity(const TElem& entity)
/*
* Adds the given entity to the repository.
*
* parameters: entity: The entity to add.
*/
{
    entities.push_back(entity);
}

void Repository::delete_entity_at(int index)
/*
* Deletes the entity at the given index from the repository.
*
* parameters: index: The index of the entity to delete.
*/
{
    entities.erase(entities.begin() + index);
}

void Repository::update_entity_at(int index, const TElem& newEntity)
/*
* Updates the entity at the given index with the given new entity.
*
* parameters: index: The index of the entity to update, newEntity: The new entity to replace the old one with.
*/
{
    entities[index] = newEntity;
}

TElem* Repository::get_all_entities()
/*
* Returns a pointer to an array containing all the entities in the repository.
*
* return: A pointer to an array of TElem objects containing all the entities in the repository.
*/
{
    return entities.data();
}

vector<TElem> Repository::get_all_entities_STL()
/*
 * Returns all entities from the vector.
 *
 * return: A vector containing all the entities.
 */
{
    return entities;
}

int Repository::get_size()
/*
* Returns the number of entities in the repository.
*
* return: An integer representing the number of entities in the repository.
*/
{
    return entities.size();
}