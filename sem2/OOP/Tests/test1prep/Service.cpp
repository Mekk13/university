#include "Service.h"

Service::Service(Repository& repo) : repo(repo) {}

/// <summary>
/// Adds a car given by individual components through the repository
/// </summary>
/// <param name="name"></param> Name of manufacturer
/// <param name="model"></param> Car model
/// <param name="colour"></param> Colour
/// <param name="year"></param> Fabrication year
/// <returns></returns> true if successful, false otherwise
bool Service::add_car(std::string name, std::string model, std::string colour, int year)
{
	Car car(name, model, colour, year);
	int ok = this->repo.add_car(car);
	if (ok)
		return true;
	else
		return false;
}

bool Service::remove_car(std::string model, int year)
{
	int i = this->repo.get_car_index_by_model_and_year(model, year);
	int ok = this->repo.remove_car(i);
	if (ok)
		return true;
	else
		return false;
}

DynamicVector<Car> Service::get_all_cars_sorted()
{
	DynamicVector<Car> c = this->repo.get_all_cars();
	for (int i = 0; i < c.getSize() - 1; i++)
	{
		for (int j = 0; j < c.getSize() - i - 1; j++)
		{
			if (c.getElement(j).getManName() > c.getElement(j + 1).getManName()) {
				Car aux = c.getElement(j);
				c.update_element(j, c.getElement(j + 1));
				c.update_element(j+1, aux);
			}
			else {
				if (c.getElement(j).getManName() == c.getElement(j + 1).getManName()) {
					if (c.getElement(j).getModel() > c.getElement(j + 1).getModel()) {
						Car aux = c.getElement(j);
						c.update_element(j, c.getElement(j + 1));
						c.update_element(j + 1, aux);
					}
				}
			}
		}
	}

	return c;

}



DynamicVector<Car> Service::get_all_vintage_sorted()
{
	DynamicVector<Car> c = get_all_vintage();
	for (int i = 0; i < c.getSize() - 1; i++)
	{
		for (int j = 0; j < c.getSize() - i - 1; j++)
		{
			if (c.getElement(j).getColour() > c.getElement(j + 1).getColour()) {
				Car aux = c.getElement(j);
				c.update_element(j, c.getElement(j + 1));
				c.update_element(j + 1, aux);
			}
			
		}
	}
	return c;
}

DynamicVector<Car> Service::get_all_vintage()
{
	DynamicVector<Car> all = this->repo.get_all_cars();
	DynamicVector<Car> vintage;
	for (int i = 0; i < all.getSize(); i++) {
		Car c = all.getElement(i);
		if (2025 - c.getFabYear() > 45)
			vintage.add(c);
	}
	return vintage;
}

