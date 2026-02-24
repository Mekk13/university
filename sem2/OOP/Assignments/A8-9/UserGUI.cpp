#include "UserGUI.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QVariant>
#include <qstringlistmodel.h>


// Constructor
UserGUI::UserGUI(std::shared_ptr<User_Service> userService, QWidget* parent)
    : QWidget(parent), user_service(userService) {
   
    ui.setupUi(this);
	
	connect(ui.SearchByGenreButton, &QPushButton::clicked, this, &UserGUI::OnSearchByGenreButtonClicked);
	connect(ui.NextMovieFromWatchlistButton, &QPushButton::clicked, this, &UserGUI::OnNextMovieFromWatchlistButtonClicked);
	connect(ui.AddToWatchlistButton, &QPushButton::clicked, this, &UserGUI::OnAddToWatchlistButtonClicked);
	connect(ui.DeleteFromWatchlistButton, &QPushButton::clicked, this, &UserGUI::OnDeleteFromWatchlistButtonClicked);
	connect(ui.LikeMovieButton, &QPushButton::clicked, this, &UserGUI::OnLikeMovieButtonClicked);
	connect(ui.OpenWatchlistInSavedFileButton, &QPushButton::clicked, this, &UserGUI::OnOpenWatchlistInSavedFileButtonClicked);
	connect(ui.tableViewButton, &QPushButton::clicked, this, &UserGUI::showWatchlistHandler);
}

void UserGUI::OnSearchByGenreButtonClicked()
{
    std::string genre = ui.GenreLineEdit->text().toStdString();
    this->MoviesByGenre = this->user_service->get_movies_from_genre(genre);
    this->index = 0;
    ui.DisplayMovieTextEdit->clear();

	if (this->MoviesByGenre.empty()) {
		QMessageBox::information(this, "No Movies", "No movies found for this genre.");
		return;
	}

	QString movie = this->movie_to_string(this->MoviesByGenre[this->index]);
    ui.DisplayMovieTextEdit->setPlainText(movie);
	this->show_in_browser(this->MoviesByGenre[index].getTrailer());
}

void UserGUI::OnNextMovieFromWatchlistButtonClicked()
{
	if (this->index < this->MoviesByGenre.size() - 1) {
		this->index++;
		QString movie = this->movie_to_string(this->MoviesByGenre[this->index]);
		ui.DisplayMovieTextEdit->setPlainText(movie);
		this->show_in_browser(this->MoviesByGenre[index].getTrailer());
	}
	else {
		this->index = 0;
		QString movie = this->movie_to_string(this->MoviesByGenre[this->index]);
		ui.DisplayMovieTextEdit->setPlainText(movie);
		this->show_in_browser(this->MoviesByGenre[index].getTrailer());
	}
}

void UserGUI::OnAddToWatchlistButtonClicked()
{
	QString text = ui.DisplayMovieTextEdit->toPlainText();
	QStringList parts = text.split("|", Qt::SkipEmptyParts);

	if (parts.size() >= 2) {
		std::string title = parts[0].trimmed().toStdString();
		std::string genre = parts[1].trimmed().toStdString();
		this->user_service->add_movie_to_watchlist(title, genre);
		PopulateWatchlistView();
	}
	else {
		// Handle error: unexpected format
		QMessageBox::warning(this, "Error", "Invalid movie format.");
	}

}

void UserGUI::OnDeleteFromWatchlistButtonClicked()
{
	QModelIndexList selectedIndexes = ui.WatchlistView->selectionModel()->selectedIndexes();
	if (!selectedIndexes.isEmpty()) {
		QModelIndex index = selectedIndexes.first();
		QString itemText = index.data().toString();
		QStringList parts = itemText.split("|", Qt::SkipEmptyParts);
		std::string genre = parts[1].trimmed().toStdString();
		std::string title = parts[0].trimmed().toStdString();
		this->user_service->delete_movie_from_watchlist(title, genre);
		PopulateWatchlistView();
	}
	else
	{
		QMessageBox::warning(this, "Error", "No selected movie!");
	}
}

void UserGUI::OnLikeMovieButtonClicked()
{
	QModelIndexList selectedIndexes = ui.WatchlistView->selectionModel()->selectedIndexes();
	if (!selectedIndexes.isEmpty()) {
		QModelIndex index = selectedIndexes.first();
		QString itemText = index.data().toString();
		QStringList parts = itemText.split("|", Qt::SkipEmptyParts);
		std::string genre = parts[1].trimmed().toStdString();
		std::string title = parts[0].trimmed().toStdString();
		this->user_service->like_a_movie(title, genre);
		PopulateWatchlistView();
	}
	else {
		QMessageBox::warning(this, "error", "No selected movie!");
	}
}

void UserGUI::OnOpenWatchlistInSavedFileButtonClicked()
{
	if (this->user_service->get_file_type() == "csv") {
		system("start watchlist.csv");
	}
	else {
		system("start watchlist.html");
	}
}

void UserGUI::PopulateWatchlistView()
{
	ui.WatchlistView->setModel(nullptr);
	QStringList qwatchlist;
	for (Movie& m : user_service->get_watchlist()) {
		qwatchlist.append(movie_to_string(m));
	}
	QStringListModel* model = new QStringListModel(this);
	model->setStringList(qwatchlist);
	ui.WatchlistView->setModel(model);
}

QString UserGUI::movie_to_string(Movie& movie) const
{
	return QString::fromStdString( movie.getTitle() + " | " + movie.getGenre() + " | " + std::to_string(movie.getYear()) + " | " + std::to_string(movie.getLikes()) + " | " + movie.getTrailer() + " | ");
}

void UserGUI::show_in_browser(std::string trailer)
{
	std::string command = "start " + trailer;
	system(command.c_str());
}
