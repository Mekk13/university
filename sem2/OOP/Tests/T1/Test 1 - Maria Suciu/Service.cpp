#include "Service.h"
#include <cstring>
#include <string.h>

Service::Service()
{
}

Service::Service(Repository r)
{
	this->repo = r;
}

/// <summary>
/// adds movie
/// </summary>
/// <param name="title"></param>
/// <param name="director"></param>
/// <param name="keywords"></param>
/// <returns></returns> 1 if successful, 0 otherwise
int Service::add_film(std::string title, std::string director, std::string keywords)
{
	Film f(title, director, keywords);
	return this->repo.add_film(f);
}

DynamicVector<Film> Service::get_all_films()
{
	return this->repo.getAll();
}

DynamicVector<Film> Service::get_films_with_keyword(std::string keyword)
{
    DynamicVector<Film> all = this->repo.getAll();
    DynamicVector<Film> filtered;

    for (int i = 0; i < all.getSize(); i++) {
        Film f = all.getElement(i);
        if (f.get_keywords().find(keyword) != std::string::npos) {  
            filtered.add(f);
        }
    }

    for (int i = 0; i < filtered.getSize() - 1; i++) {
        for (int j = 0; j < filtered.getSize() - i - 1; j++) { 
            if (filtered.getElement(j).get_director() > filtered.getElement(j + 1).get_director()) {
                
                Film aux = filtered.getElement(j);
                filtered.update_element(j, filtered.getElement(j + 1));
                filtered.update_element(j + 1, aux);
            }
        }
    }

    return filtered;
}

//int Service::count_d(std::string dir, std::string key)
//{
//    DynamicVector<Film> all = this->repo.getAll();
//    int c = 0;
//
//    for (int i = 0; i < all.getSize(); i++) {
//        Film f = all.getElement(i);
//        if (f.get_keywords().find(key) != std::string::npos) {
//            c++;
//        }
//    }
//    return c;
//}

