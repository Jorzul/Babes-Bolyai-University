#include "Repository.h"

Repository::~Repository()
{

}

void Repository::AddEntity(TElem entity)
{
	entities.push_back(entity);
}

void Repository::DeleteEntityAt(int index)
{
	entities.remove(index);
}

void Repository::UpdateEntityAt(int index, TElem newEntity)
{
	entities.update(index, newEntity);
}

TElem* Repository::GetAllEntities()
{
	return entities.getAllElements();
}

int Repository::GetSize()
{
	return entities.getSize();
}