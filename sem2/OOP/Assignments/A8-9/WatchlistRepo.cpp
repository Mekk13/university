#include "WatchlistRepo.h"
#include <fstream>

Watch_Repository::Watch_Repository(std::vector<Movie> m)
{
}

bool Watch_Repository::add_to_list(Movie m)
{
	auto it = std::find(this->Watchlist.begin(), this->Watchlist.end(), m);
	if (it != this->Watchlist.end())
		return 0;
	this->Watchlist.push_back(m);
	save_to_file();
	return 1;
}

bool Watch_Repository::remove_from_list(std::string title, std::string genre)
{
	auto it = std::find_if(this->Watchlist.begin(), this->Watchlist.end(),
		[&](Movie& m) {
			return m.getTitle() == title && m.getGenre() == genre;
		});
	if (it == this->Watchlist.end())
		return 0;
	this->Watchlist.erase(it);
	save_to_file();
	return 1;
}

void Watch_Repository::update(std::string title, std::string genre, Movie new_m)
{
	auto it = std::find_if(this->Watchlist.begin(), this->Watchlist.end(), [&](Movie& m) {
		return m.getTitle() == title && m.getGenre() == genre;
		});
	if (it == this -> Watchlist.end()) {
		return;
	}
	*it = new_m;
	save_to_file();
}

std::vector<Movie> Watch_Repository::get_watchlist_content()
{
	return this->Watchlist;
}

void Watch_Repository::set_filetype(std::string t)
{
	if (t == "csv")
		this->filetype = "csv";
	else
		this->filetype = "html";
}

void Watch_Repository::export_csv()
{
	std::ofstream File("watchlist.csv");
	for (auto m : this->Watchlist) {
		File << m.getTitle() << "," << m.getGenre() << "," << m.getTrailer() << "," << std::to_string(m.getYear()) << "," << std::to_string(m.getLikes()) << '\n';
	}
	File.close();
}

void Watch_Repository::export_html()
{
	std::ofstream out("watchlist.html");
	out << "<!DOCTYPE html>\n";
	out << "<html>\n";
	out << "<head>\n";
	out << "    <title>Watchlist</title>\n";
	out << "    <style>\n";
	out << "        body {\n";
	out << "            background: url('7.jpg') no-repeat center center fixed;\n";
	out << "            background-size: cover;\n";
	out << "            margin: 0;\n";
	out << "            padding: 0;\n";
	out << "            font-family: Arial, sans-serif;\n";
	out << "        }\n";
	out << "        table {\n";
	out << "            margin: 50px auto;\n";
	out << "            color: white;\n";
	out << "            background-color: rgba(0, 100, 255, 0.6);\n";
	out << "            padding: 10px;\n";
	out << "            border-collapse: collapse;\n";
	out << "            box-shadow: 0 0 10px rgba(0,0,0,0.3);\n";
	out << "            border-radius: 10px;\n";
	out << "        }\n";
	out << "        td {\n";
	out << "            padding: 10px 15px;\n";
	out << "            border: 1px solid white;\n";
	out << "        }\n";
	out << "        th {\n";
	out << "            padding: 10px 15px;\n";
	out << "            border: 1px solid white;\n";
	out << "            background-color: rgba(0, 60, 180, 0.8);\n";
	out << "        }\n";
	out << "    </style>\n";
	out << "</head>\n";
	out << "<body>\n";
	out << "<table>\n";
	out << "    <tr>\n";
	out << "        <th>Title</th>\n";
	out << "        <th>Genre</th>\n";
	out << "        <th>Year</th>\n";
	out << "        <th>Likes</th>\n";
	out << "        <th>Trailer</th>\n";
	out << "    </tr>\n";

	for (const auto& m : this->Watchlist) {
		out << "    <tr>\n";
		out << "        <td>" << m.getTitle() << "</td>\n";
		out << "        <td>" << m.getGenre() << "</td>\n";
		out << "        <td>" << m.getYear() << "</td>\n";
		out << "        <td>" << m.getLikes() << "</td>\n";
		out << "        <td><a href=\"" << m.getTrailer() << "\" style=\"color: white;\">Link</a></td>\n";
		out << "    </tr>\n";
	}

	out << "</table>\n";
	out << "<div style=\"text-align: center; margin-top: 20px;\">\n";
	out << "    <img src=\"garfield.jpg\" alt=\"Garfield\" width=\"344\" height=\"343\">\n";
	out << "</div>\n";
	out << "</body>\n";
	out << "</html>\n";

}

void Watch_Repository::save_to_file()
{
	if (this->filetype == "csv")
		export_csv();
	else
		export_html();
}

std::string Watch_Repository::get_file_type()
{
	return this->filetype;
}


