from src.repository import MemoryRepository
from src.services import TaxiService
from src.ui import UI

if __name__ == "__main__":

    repository = MemoryRepository()
    services = TaxiService(repository)
    UserInterface = UI(services)

    UserInterface.menu()
